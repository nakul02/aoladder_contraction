//============================================================================
// Name        : aoladder_contraction_cu.cu
// For declaration similar to data[a1][a0], extents was defined as {a0,a1}.
// This is with respect to the last test code received
// If this definition of extents is changed to {a1,a0}, interchange the use 
// of extents[0] and extents[1].
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sip_interface.h"
#include "gpu_super_instructions.h"
#include <time.h>

#define PZP //Enable for PZP and LEC+PZP
//#define LEC//Enable for LEC and LEC+PZP

//CUDA block dimensions
#define BLOCK_SIZE 21

//define this to debug
//#define DEBUG

// Define this to turn on sparsity check
#define SPARSITY_CHECK


//Get the sub-matrix position
__device__ double* GetSubMatrix(double* M, int b_row, int b_col, int stride) {
	return &M[b_col * stride * BLOCK_SIZE + b_row * BLOCK_SIZE];
}

//Get an element from a sub-matrix
__device__ double GetElement(double* M, int block_x, int block_y, int row, int col, int stride_col, int stride_row) {
	return M[col * stride_row + row];
}

//Set result value in global memory
__device__ void SetElement(double* M, int row, int col, double value, int stride) {
	M[col * stride + row] = value;
}

// Block partitioned CUDA implementation
__global__ void contract_part(double* x1, double* x2, double* y,
	 const int* d_extents0, int* d_extents1, int* d_extents2, int b_rows, int b_cols) {
	//calculate the position of sub-block 
	int b_row = blockIdx.x % b_rows;
	int b_col = blockIdx.x / b_rows;

	//Retrieve the sub-block 
	double* y_sub = GetSubMatrix (y, b_row, b_col, d_extents2[1]);

	// Each thread computes one element of y_sub by accumulating results into y_value
    double y_value = 0.0;
	
    // Row no. and Column no. of the element the thread is designated to access
    int row = threadIdx.x % BLOCK_SIZE;
    int col = threadIdx.x / BLOCK_SIZE;

	//Calculate the number of blocks in x1 along the direction to be reduced
	int r_blocks = ceilf((float)d_extents0[0] / (float)BLOCK_SIZE);
	
    // Loop over all the sub-matrices of x1 and x2 that are required to compute y_sub
    // Multiply each pair of sub-matrices together and accumulate the results
    for (int m = 0; m < r_blocks; ++m) {

        // Get sub-matrix Asub of x1 
        double* x1_sub = GetSubMatrix (x1, b_row, m, d_extents0[1]);

        // Get sub-matrix Bsub of x2 
        double* x2_sub = GetSubMatrix (x2, m, b_col, d_extents1[1]);

        // Shared memory used to store Asub and Bsub respectively
        __shared__ double x1s[BLOCK_SIZE][BLOCK_SIZE];
        __shared__ double x2s[BLOCK_SIZE][BLOCK_SIZE];
		__shared__ double x1s_sum[BLOCK_SIZE];
	
        // Load x1_sub from device memory to shared memory Each thread loads one element of the sub-matrix
		#ifdef PZP
		// If thread is designated to access a element out of the extent boundaries(overflow)
		// then use zero instead of the element in memory (zero pad).
		if(m * BLOCK_SIZE + col >= d_extents0[0])
			x1s[row][col] = 0.0;
		else
		#endif
        	x1s[row][col] = GetElement(x1_sub, b_col, b_row, row, col, d_extents0[0], d_extents0[1]);

        // Synchronize to make sure the sub-matrices are loaded
        // before starting the computation
        __syncthreads();

/****************************** Sparsity Check START **********************************/
#ifdef SPARSITY_CHECK
		// Perform a reduction sum and check if this sub-block is sparse
		// Each thread in row 0 will collect sums of its corresponding columns and then the row will be summed up in x1s_sum[0]
		if (row == 0) {
			x1s_sum[col] = 0.0;
			for (int i = 0; i < BLOCK_SIZE; i++)
				x1s_sum[col] += x1s[i][col];
		}
		__syncthreads();

		if ((row || col) == 0) {
			for (int i = 1; i < BLOCK_SIZE; i++)
				x1s_sum[0] += x1s_sum[i];
		}
		__syncthreads();
		if (x1s_sum[0] == 0)
			continue;
#endif
/****************************** Sparsity Check END **********************************/

        // Load x2_sub from device memory to shared memory
        // Each thread loads one element of the sub-matrix 
#ifdef PZP
		if(m * BLOCK_SIZE + row >= d_extents1[1])
		  	x2s[row][col] = 0.0;
		else
#endif
	      	x2s[row][col] = GetElement(x2_sub,b_col, b_row, row, col, d_extents1[0], d_extents1[1]);

		__syncthreads();
		
	 	int emax = BLOCK_SIZE;
#ifdef LEC
		// Contain leakage to avoid multiplying unnecessary values
		
		// Position of sub-blocks
		int x1_xpos = m * BLOCK_SIZE + BLOCK_SIZE;
		int x2_ypos = m * BLOCK_SIZE + BLOCK_SIZE;
		
		// Calculating the length of sub-block to iterate over
		int e1 = x1_xpos - d_extents0[0]  ;
	
		if (e1 > 0)
			emax -= e1;
#endif		 
		// Multiply x1_sub and x2_sub together
	    for (int e = 0; e < emax; ++e)
	        y_value += x1s[row][e] * x2s[e][col];
	
	    // Synchronize to make sure that the preceding
	    // computation is done before loading two new
	    // sub-matrices of A and B in the next iteration
	    __syncthreads();
    }

    // Write y_sub to device memory
    // Each correctly mapper thread writes one element
	if (((b_row * BLOCK_SIZE + row) < d_extents2[1]) && ((b_col * BLOCK_SIZE + col) < d_extents2[0])) 
		SetElement(y_sub, row, col, y_value, d_extents2[1]);
}


#ifdef __cplusplus
extern "C" {
#endif

void aoladder_contraction_cu_nosparse(
	int& array_slot_0, int& rank_0, int *index_values_0, int& size_0, int *extents_0, double *data_0,
	int& array_slot_1, int& rank_1, int *index_values_1, int& size_1, int *extents_1, double *data_1,
	int& array_slot_2, int& rank_2, int *index_values_2, int& size_2, int *extents_2, double *data_2,
	int& ierr) {

	int devid;
	int rank = 0;
	double* p_y;
	double* p_x1;
	double* p_x2;
	int label_py[]={2,5,4,6};
	int label_x1[]={1,2,3,4};
	int label_x2[]={1,5,3,6};

	//Initialize GPU
	_init_gpu(&devid, &rank);

	//Allocate memory on GPU
	p_y = _gpu_allocate (size_2);
	p_x1 = _gpu_allocate (size_0);
	p_x2 = _gpu_allocate (size_1);

	//Transfer blocks to the GPU	
	_gpu_host_to_device(data_0, p_x1, size_0);
	_gpu_host_to_device(data_1, p_x2, size_1);
	
	//Perform the contraction operation on GPU
	_gpu_contract(p_y, rank_2, extents_2, &label_py[0],
		p_x1, rank_0, extents_0, &label_x1[0], p_x2, rank_1,
		extents_1, &label_x2[0]);

	//Get results from GPU to CPU
	_gpu_device_to_host(data_2, p_y, size_2);
	
	//De-allocate memory on GPU
	_gpu_free(p_y);
	_gpu_free(p_x1);
	_gpu_free(p_x2);
}

void compute_aoladder_with_sparsity_gpu(
		int a1, int a2, int b1, int b2,
		double* integrals, int i1, int j1, int size_0, int rank_0, int* extents_0,
		double* t2old, int ii1, int jj1, int size_1, int rank_1, int* extents_1,
		double* t2new, int size_2, int rank_2, int* extents_2) {


/************************************ GPU START *************************************************/
	double* d_y;
	double* d_x1;
	double* d_x2;
	int* d_extents0;
	int* d_extents1;
	int* d_extents2;
	double* check_result = (double*) malloc(sizeof(double) * size_2);

	//Labels Needed in the original CPU version
/*
	int label_py[]={2,5,4,6};
	int label_x1[]={1,2,3,4};
	int label_x2[]={1,5,3,6};
*/
	float time,timeTransfer;
	cudaEvent_t start, stop, startTransfer, stopTransfer;

	//Call and time the CUDA kernel
	cudaEventCreate(&startTransfer);
	cudaEventCreate(&stopTransfer);
	cudaEventRecord(startTransfer, 0);


	//Allocate memory on GPU
	cudaMalloc ((void **) &d_x1, size_0 * sizeof(double));
	cudaMalloc ((void **) &d_x2, size_1 * sizeof(double));
	cudaMalloc ((void **) &d_y, size_2 * sizeof(double));
	cudaMalloc ((void **) &d_extents0, rank_0 * sizeof(int));
	cudaMalloc ((void **) &d_extents1, rank_1 * sizeof(int));
	cudaMalloc ((void **) &d_extents2, rank_2 * sizeof(int));

	//Copy the data to GPU	
	cudaMemcpy (d_x1, integrals, size_0 * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy (d_x2, t2old, size_1 * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy (d_extents0, extents_0, rank_0 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy (d_extents1, extents_1, rank_1 * sizeof(int), cudaMemcpyHostToDevice);
	cudaMemcpy (d_extents2, extents_2, rank_2 * sizeof(int), cudaMemcpyHostToDevice);

	
	//Calculate the block dimensions (one dimension less than that of the matrices)
	//Total threads per block 
	int block_dim_x = BLOCK_SIZE * BLOCK_SIZE;

	//Calculate the grid dimensions 
	int grid_dim_x = ceil((double)extents_2[0] / (double)BLOCK_SIZE) * ceil((double)extents_2[1] / (double)BLOCK_SIZE);
	int block_rows = ceil((double)extents_2[1] / (double)BLOCK_SIZE);
	int block_cols = ceil((double)extents_2[0] / (double)BLOCK_SIZE);

#ifdef DEBUG
	printf("block rows: %d\n", block_rows);
	printf("block cols: %d\n", block_cols);
	printf("block_dim_x = %d\n", block_dim_x);
	printf("grid_dim_x = %d\n", grid_dim_x);
	int r_blocks = ceil(extents_0[0] / BLOCK_SIZE);
	printf("Number of blocks in contraction (r_blocks) = %d\n", r_blocks );
#endif

	//Create dim3 objects
	dim3 dimBlock(block_dim_x);
	dim3 dimGrid(grid_dim_x);

	//Call and time the CUDA kernel
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start, 0);
	contract_part<<<dimGrid, dimBlock>>>(d_x1, d_x2, d_y, d_extents0, d_extents1, d_extents2, block_rows, block_cols);
	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	cudaEventElapsedTime(&time, start, stop);

	//Get results from GPU to CPU
	cudaMemcpy (t2new, d_y, size_2 * sizeof(double), cudaMemcpyDeviceToHost);

#ifdef DEBUG
	int j;
	printf("t2old :\n\n");
	for (i = 0; i < extents_1[1]; i++) {
		for (j = 0; j < extents_1[0]; j++) {
			int index = j * extents_1[1] + i;
			printf("%g " , t2old[index]);
		}
		printf("\n");
	}

	printf("integrals :\n\n");
	for (i = 0; i < extents_0[1]; i++) {
		for (j = 0; j < extents_0[0]; j++) {
			int index = j * extents_0[1] + i;
			printf("%g " , integrals[index]);
		}
		printf("\n");
	}

	printf("t2new (gpu block partition):\n\n");
	for (i = 0; i < extents_2[1]; i++) {
		for (j = 0; j < extents_2[0]; j++) {
			int index = j * extents_2[1] + i;
			printf("%g " , t2new[index]);
		}
		printf("\n");
	}
#endif
					
	//Free the memory up on gpu
	cudaFree(d_y);
	cudaFree(d_x1);
	cudaFree(d_x2);
	
	cudaEventRecord(stopTransfer, 0);
	cudaEventSynchronize(stopTransfer);
	cudaEventElapsedTime(&timeTransfer, startTransfer, stopTransfer);
	std::cout.precision(10);
	std::cout<<"Time taken for contraction is "<<time<<" msec"<<std::endl;
	std::cout<<"Time taken for contraction with data transfer time is "<<timeTransfer<<" msec"<<std::endl;


/************************************ GPU END *************************************************/

}


void aoladder_contraction_cu(
	int& array_slot_0, int& rank_0, int *index_values_0, int& size_0, int *extents_0, double *data_0,
	int& array_slot_1, int& rank_1, int *index_values_1, int& size_1, int *extents_1, double *data_1,
	int& array_slot_2, int& rank_2, int *index_values_2, int& size_2, int *extents_2, double *data_2,
	int& ierr) {

    //offsets of atomi//indeces
    int offset_1, offset_2;
    int one;

    // aosegments
    //     integer(C_INT) n_ao_segs(1), aosegs(6)
    int* pn_ao_segs;
    int* paosegs;


    one = 0; // 1
    ierr = 0;

    // Get the predefined data

    // ----------------------------------------------------------------------
    // Get the ao segment ranges
    predefined_int_array("ao_seg_ranges", one, &pn_ao_segs, &paosegs);
    //     write(6,*) ' NAO_SEGS', pn_ao_segs(1), (paosegs(i), i=1,
    //    *                                             pn_ao_segs(1))
    // ----------------------------------------------------------------------


    // Set offsets for the integral array. These also set the offsets for the
    // ao indices of the amplitude arrays.
    offset_1 = 0;
    offset_2 = 0;

    if (index_values_0[0] > 1)
        offset_1 = paosegs[index_values_0[0] - 1];
    if (index_values_0[1] > 1)
        offset_2 = paosegs[index_values_0[1] - 1];
	
	
	//Call code to contract 2D matrices using block partitioning
    compute_aoladder_with_sparsity_gpu(offset_1, extents_0[0] + offset_1, offset_2,
            extents_0[1] + offset_2,
            data_0, //      integrals data_0
            extents_1[0], extents_1[1], size_0, rank_0, extents_0,
            data_1, //old amplitudes data_1
            extents_2[0], extents_2[1], size_1, rank_1, extents_1,
            data_2, size_2, rank_2, extents_2); //new amplitudes data_2



}
#ifdef __cplusplus
}
#endif
 	
