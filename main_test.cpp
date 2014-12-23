#include <map>
#include <string>
#include <utility>
#include <random>
#include <chrono>
#include "gtest/gtest.h"
#include "constants_data_types.h"
//#include <iostream>
//#include <fstream>
//#include <cassert>
//#include "io_utils.h"
//

//2
// define this to include CUDA implementation
#define CUDA

// For CUDA Super Instruction
#ifdef HAVE_CUDA
#include "gpu_super_instructions.h"
#endif


static std::map<std::string, int>& predef_int_map = get_predef_int_map();
static std::map<std::string, IntArrData>& predef_int_array_map = get_predef_int_array_map();

extern "C" {
	void aoladder_contraction_new(
//	void aoladder_contraction(
			int& array_slot_1, int& rank_1, int * index_values_1, int& size_1, 
			int * extents_1, double * data_1, 
			int& array_slot_2, int& rank_2, int * index_values_2, int& size_2, 
			int * extents_2, double * data_2, 
			int& array_slot_3, int& rank_3, int * index_values_3, int& size_3, 
			int * extents_3, double * data_3, int& ierr);

	void aoladder_contraction_cpp(
			int& array_slot_1, int& rank_1, int * index_values_1, int& size_1, 
			int * extents_1, double * data_1, 
			int& array_slot_2, int& rank_2, int * index_values_2, int& size_2, 
			int * extents_2, double * data_2, 
			int& array_slot_3, int& rank_3, int * index_values_3, int& size_3, 
			int * extents_3, double * data_3, int& ierr);

	// C implementation without sparsity check
	void aoladder_contraction_cu_nosparse(
			int& array_slot_1, int& rank_1, int * index_values_1, int& size_1,
			int * extents_1, double * data_1,
			int& array_slot_2, int& rank_2, int * index_values_2, int& size_2,
			int * extents_2, double * data_2,
			int& array_slot_3, int& rank_3, int * index_values_3, int& size_3,
			int * extents_3, double * data_3, int& ierr, int blockNum);

}

/*void read_from_file(std::string filename, int &rank, int*& extents_read, double*& data, int& data_size){

    setup::BinaryInputFile data_stream(filename);
    rank = data_stream.read_int(); // Read rank

    // Read extents
    int extents_size;
    extents_read = data_stream.read_int_array(&extents_size);
    assert (extents_size == rank);

    // Read data    
    data = data_stream.read_double_array(&data_size);
    
}
*/
const double THRESHOLD = 1e-10;


TEST(AOLADDER,test1){

	int ierr;

	const int a0 = 36;//*2;
	const int a1 = 36;//*2;
	const int a2 = 36;//*2;
	const int a3 = 36;//*2;

	const int b0 = 36;//*2;
	const int b1 = 36;//*2;
	const int b2 = 36;//*2;
	const int b3 = 36;//*2;

	const int c0 = 36;//*2;
	const int c1 = 36;//*2;
	const int c2 = 36;//*2;
	const int c3 = 36;//*2;
       
        const int blockNum=2;

	// A way to get huge arrays to be in global data
	static double data_0[blockNum][a3][a2][a1][a0];
	static double data_1[blockNum][b3][b2][b1][b0];
	static double data_2_ref[blockNum][c3][c2][c1][c0];
	static double data_2[blockNum][c3][c2][c1][c0];

//	static double data2_0[a3][a2][a1][a0];
//	static double data2_1[b3][b2][b1][b0];
//	static double data2_2_ref[c3][c2][c1][c0];
//	static double data2_2[c3][c2][c1][c0];

	int dummy_slot = -1;
	int dummy_index_values[4] = {-1, -1, -1, -1};

	int rank_0 = 4;
	int size_0 = a0 * a1 * a2 * a3;
	int extents_0[] = {a0, a1, a2, a3};

	int rank_1 = 4;
	int size_1 = b0 * b1 * b2 * b3;
	int extents_1[] = {b0, b1, b2, b3};

	int rank_2 = 4;
	int size_2 = c0 * c1 * c2 * c3;
	int extents_2[] = {c0, c1, c2, c3};


	//double data_0 = new double[size_0];
	//double data_1 = new double[size_1];
	//double data_2 = new double[size_2];

	int ao_seg_ranges[1] = {a0};
	int ao_seg_ranges_dims [1]= {1};
	int end_nfps[6] = {4, 13, 18, 22, 31, 36};
	const int sb_range[7] = {0, 4, 13, 18, 22, 31, 36}; // Sub Block Range
	int end_nfps_dims [1]= {6};

	int nshells = 6;

	predef_int_map.clear();
	predef_int_array_map.clear();

	predef_int_map.insert(std::make_pair(std::string("nshells"), nshells));
	IntArrData end_nfps_arrdata(1, &end_nfps_dims[0], &end_nfps[0]);
	predef_int_array_map.insert(std::make_pair(std::string("end_nfps"),end_nfps_arrdata));
	IntArrData ao_seg_ranges_data(1, &ao_seg_ranges_dims[0], &ao_seg_ranges[0]);               
	predef_int_array_map.insert(std::make_pair(std::string("ao_seg_ranges"), ao_seg_ranges_data));



	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_real_distribution<double> distribution (-20.0,20.0);

      for(int bi=0;bi<blockNum;bi++){
	for (int a=0; a<6; a++){
		for (int b=0; b<6; b++){
			for (int c=0; c<6; c++){
				for (int d=0; d<6; d++){
					// Each sub-block is filled with 0 or some 
					// random numbers

					for (int i=sb_range[a]; i<sb_range[a+1] && i<ao_seg_ranges[0]; i++){
						for (int j=sb_range[b]; j<sb_range[b+1] && j<ao_seg_ranges[0]; j++){
							for (int k=sb_range[c]; k<sb_range[c+1] && k<ao_seg_ranges[0]; k++){
								for(int l=sb_range[d]; l<sb_range[d+1] && l<ao_seg_ranges[0]; l++){
									data_0[bi][l][k][j][i] = distribution(generator);
									data_1[bi][l][k][j][i] = distribution(generator);
									data_2_ref[bi][l][k][j][i] = 0.0;
									data_2[bi][l][k][j][i] = 0.0;
									
  //                                                                      data2_0[l][k][j][i] = data_0[l][k][j][i];
//									data2_1[l][k][j][i] = data_1[l][k][j][i];
//									data2_2_ref[l][k][j][i] = 0.0;
//									data2_2[l][k][j][i] = 0.0;
								}
							}
						}
					}
				}
			}
		}
	}
}
	std::clock_t start;
	double duration;   
	start = std::clock();
       for(int bi=0;bi<blockNum;bi++){
	aoladder_contraction_new(dummy_slot, rank_0, &dummy_index_values[0], 
//	aoladder_contraction(dummy_slot, rank_0, &dummy_index_values[0], 
			size_0, &extents_0[0], &data_0[bi][0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0], 
			size_1, &extents_1[0], &data_1[bi][0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0], 
			size_2, &extents_2[0], &data_2_ref[bi][0][0][0][0],
			ierr);
}
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: Fortran"<< duration <<'\n';
	//            
	//    aoladder_contraction_cpp(dummy_slot, rank_0, &dummy_index_values[0], 
	//        size_0, &extents_0[0], &data_0[0][0][0][0],
	//        dummy_slot, rank_1, &dummy_index_values[0], 
	//        size_1, &extents_1[0], &data_1[0][0][0][0],
	//        dummy_slot, rank_2, &dummy_index_values[0], 
	//        size_2, &extents_2[0], &data_2[0][0][0][0],
	//        ierr);        

	start = std::clock();
	aoladder_contraction_cu_nosparse(dummy_slot, rank_0, &dummy_index_values[0],
			size_0, &extents_0[0], &data_0[0][0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0],
			size_1, &extents_1[0], &data_1[0][0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0],
			size_2, &extents_2[0], &data_2[0][0][0][0][0],
			ierr,blockNum);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: GPU"<< duration <<'\n';
double errSum=0;
      for(int bi=0;bi<blockNum;bi++){
	for (int i=0; i<c0; i++){
		for (int j=0; j<c1; j++){
			for (int k=0; k<c2; k++){
				for (int l=0; l<c3; l++){
  errSum+=std::abs(data_2_ref[bi][i][j][k][l]-data_2[bi][i][j][k][l]);
					ASSERT_NEAR(data_2_ref[bi][i][j][k][l], data_2[bi][i][j][k][l], THRESHOLD);
				}
			}
		}
	}
}

std::cout<<"errSum: "<<std::scientific<<errSum/(double)blockNum<<'\n';
}

/*
TEST(AOLADDER,DISABLED_test2){

	int ierr;

	const int a0 = 18;
	const int a1 = 18;
	const int a2 = 18;
	const int a3 = 18;

	const int b0 = 18;
	const int b1 = 18;
	const int b2 = 18;
	const int b3 = 18;

	const int c0 = 18;
	const int c1 = 18;
	const int c2 = 18;
	const int c3 = 18;

	// A way to get huge arrays to be in global data
	static double data_0[a3][a2][a1][a0];
	static double data_1[b3][b2][b1][b0];
	static double data_2_ref[c3][c2][c1][c0];
	static double data_2[c3][c2][c1][c0];

	int dummy_slot = -1;
	int dummy_index_values[4] = {-1, -1, -1, -1};

	int rank_0 = 4;
	int size_0 = a0 * a1 * a2 * a3;
	int extents_0[] = {a0, a1, a2, a3};

	int rank_1 = 4;
	int size_1 = b0 * b1 * b2 * b3;
	int extents_1[] = {b0, b1, b2, b3};

	int rank_2 = 4;
	int size_2 = c0 * c1 * c2 * c3;
	int extents_2[] = {c0, c1, c2, c3};


	//double data_0 = new double[size_0];
	//double data_1 = new double[size_1];
	//double data_2 = new double[size_2];

	int ao_seg_ranges[1] = {a0};
	int ao_seg_ranges_dims [1]= {1};
	int end_nfps[6] = {4, 13, 18, 22, 31, 36};
	const int sb_range[7] = {0, 4, 13, 18, 22, 31, 36}; // Sub Block Range
	int end_nfps_dims [1]= {6};

	int nshells = 6;

	predef_int_map.clear();
	predef_int_array_map.clear();

	predef_int_map.insert(std::make_pair(std::string("nshells"), nshells));
	IntArrData end_nfps_arrdata(1, &end_nfps_dims[0], &end_nfps[0]);
	predef_int_array_map.insert(std::make_pair(std::string("end_nfps"),end_nfps_arrdata));
	IntArrData ao_seg_ranges_data(1, &ao_seg_ranges_dims[0], &ao_seg_ranges[0]);               
	predef_int_array_map.insert(std::make_pair(std::string("ao_seg_ranges"), ao_seg_ranges_data));



	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_real_distribution<double> distribution (-20.0,20.0);

	for (int a=0; a<6; a++){
		for (int b=0; b<6; b++){
			for (int c=0; c<6; c++){
				for (int d=0; d<6; d++){
					// Each sub-block is filled with 0 or some 
					// random numbers

					for (int i=sb_range[a]; i<sb_range[a+1] && i<ao_seg_ranges[0]; i++){
						for (int j=sb_range[b]; j<sb_range[b+1] && j<ao_seg_ranges[0]; j++){
							for (int k=sb_range[c]; k<sb_range[c+1] && k<ao_seg_ranges[0]; k++){
								for(int l=sb_range[d]; l<sb_range[d+1] && l<ao_seg_ranges[0]; l++){
									data_0[l][k][j][i] = distribution(generator);
									data_1[l][k][j][i] = distribution(generator);
									data_2_ref[l][k][j][i] = 0.0;
									data_2[l][k][j][i] = 0.0;
								}
							}
						}
					}
				}
			}
		}
	}
	std::clock_t start;
	double duration;
	start = std::clock();    
	aoladder_contraction_new(dummy_slot, rank_0, &dummy_index_values[0], 
//	aoladder_contraction(dummy_slot, rank_0, &dummy_index_values[0], 
			size_0, &extents_0[0], &data_0[0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0], 
			size_1, &extents_1[0], &data_1[0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0], 
			size_2, &extents_2[0], &data_2_ref[0][0][0][0],
			ierr);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: Fortune "<< duration <<'\n';
	//    aoladder_contraction_cpp(dummy_slot, rank_0, &dummy_index_values[0], 
	//        size_0, &extents_0[0], &data_0[0][0][0][0],
	//        dummy_slot, rank_1, &dummy_index_values[0], 
	//        size_1, &extents_1[0], &data_1[0][0][0][0],
	//        dummy_slot, rank_2, &dummy_index_values[0], 
	//        size_2, &extents_2[0], &data_2[0][0][0][0],
	//        ierr);        
	start = std::clock();
	aoladder_contraction_cu_nosparse(dummy_slot, rank_0, &dummy_index_values[0],
			size_0, &extents_0[0], &data_0[0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0],
			size_1, &extents_1[0], &data_1[0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0],
			size_2, &extents_2[0], &data_2[0][0][0][0],
			ierr, blockNum);

	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: GPU "<< duration <<'\n';

	for (int i=0; i<c0; i++){
		for (int j=0; j<c1; j++){
			for (int k=0; k<c2; k++){
				for (int l=0; l<c3; l++){
					ASSERT_NEAR(data_2_ref[i][j][k][l], data_2[i][j][k][l], THRESHOLD);
				}
			}
		}
	}
}

TEST(AOLADDER,DISABLED_test4){

	int ierr;

	const int a0 = 1;
	const int a1 = 1;
	const int a2 = 1;
	const int a3 = 1;

	const int b0 = 1;
	const int b1 = 1;
	const int b2 = 1;
	const int b3 = 1;

	const int c0 = 1;
	const int c1 = 1;
	const int c2 = 1;
	const int c3 = 1;

	// A way to get huge arrays to be in global data
	static double data_0[a3][a2][a1][a0];
	static double data_1[b3][b2][b1][b0];
	static double data_2_ref[c3][c2][c1][c0];
	static double data_2[c3][c2][c1][c0];

	int dummy_slot = -1;
	int dummy_index_values[4] = {-1, -1, -1, -1};

	int rank_0 = 4;
	int size_0 = a0 * a1 * a2 * a3;
	int extents_0[] = {a0, a1, a2, a3};

	int rank_1 = 4;
	int size_1 = b0 * b1 * b2 * b3;
	int extents_1[] = {b0, b1, b2, b3};

	int rank_2 = 4;
	int size_2 = c0 * c1 * c2 * c3;
	int extents_2[] = {c0, c1, c2, c3};


	//double data_0 = new double[size_0];
	//double data_1 = new double[size_1];
	//double data_2 = new double[size_2];

	int ao_seg_ranges[1] = {a0};
	int ao_seg_ranges_dims [1]= {1};
	int end_nfps[6] = {4, 13, 18, 22, 31, 36};
	const int sb_range[7] = {0, 4, 13, 18, 22, 31, 36}; // Sub Block Range
	int end_nfps_dims [1]= {6};

	int nshells = 6;

	predef_int_map.clear();
	predef_int_array_map.clear();

	predef_int_map.insert(std::make_pair(std::string("nshells"), nshells));
	IntArrData end_nfps_arrdata(1, &end_nfps_dims[0], &end_nfps[0]);
	predef_int_array_map.insert(std::make_pair(std::string("end_nfps"),end_nfps_arrdata));
	IntArrData ao_seg_ranges_data(1, &ao_seg_ranges_dims[0], &ao_seg_ranges[0]);               
	predef_int_array_map.insert(std::make_pair(std::string("ao_seg_ranges"), ao_seg_ranges_data));



	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_real_distribution<double> distribution (0.0,100.0);

	for (int a=0; a<6; a++){
		for (int b=0; b<6; b++){
			for (int c=0; c<6; c++){
				for (int d=0; d<6; d++){
					// Each sub-block is filled with 0 or some 
					// random numbers

					for (int i=sb_range[a]; i<sb_range[a+1] && i<ao_seg_ranges[0]; i++){
						for (int j=sb_range[b]; j<sb_range[b+1] && j<ao_seg_ranges[0]; j++){
							for (int k=sb_range[c]; k<sb_range[c+1] && k<ao_seg_ranges[0]; k++){
								for(int l=sb_range[d]; l<sb_range[d+1] && l<ao_seg_ranges[0]; l++){
									data_0[l][k][j][i] = distribution(generator);
									data_1[l][k][j][i] = distribution(generator);
									data_2_ref[l][k][j][i] = 0.0;
									data_2[l][k][j][i] = 0.0;
								}
							}
						}
					}
				}
			}
		}
	}

	std::clock_t start;
	double duration;   
	start = std::clock();
	aoladder_contraction_new(dummy_slot, rank_0, &dummy_index_values[0], 
//	aoladder_contraction(dummy_slot, rank_0, &dummy_index_values[0], 
			size_0, &extents_0[0], &data_0[0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0], 
			size_1, &extents_1[0], &data_1[0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0], 
			size_2, &extents_2[0], &data_2_ref[0][0][0][0],
			ierr);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: "<< duration <<'\n';
	//            
	//    aoladder_contraction_cpp(dummy_slot, rank_0, &dummy_index_values[0], 
	//        size_0, &extents_0[0], &data_0[0][0][0][0],
	//        dummy_slot, rank_1, &dummy_index_values[0], 
	//        size_1, &extents_1[0], &data_1[0][0][0][0],
	//        dummy_slot, rank_2, &dummy_index_values[0], 
	//        size_2, &extents_2[0], &data_2[0][0][0][0],
	//        ierr);        
	start = std::clock();
	aoladder_contraction_cu_nosparse(dummy_slot, rank_0, &dummy_index_values[0],
			size_0, &extents_0[0], &data_0[0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0],
			size_1, &extents_1[0], &data_1[0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0],
			size_2, &extents_2[0], &data_2[0][0][0][0],
			ierr);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: "<< duration <<'\n';
	for (int i=0; i<c0; i++){
		for (int j=0; j<c1; j++){
			for (int k=0; k<c2; k++){
				for (int l=0; l<c3; l++){
					ASSERT_NEAR(data_2_ref[i][j][k][l], data_2[i][j][k][l], THRESHOLD);
				}
			}
		}
	}
}

TEST(AOLADDER,DISABLED_test3){

	int ierr;

	const int a0 = 18;
	const int a1 = 18;
	const int a2 = 18;
	const int a3 = 18;

	const int b0 = 18;
	const int b1 = 18;
	const int b2 = 18;
	const int b3 = 18;

	const int c0 = 18;
	const int c1 = 18;
	const int c2 = 18;
	const int c3 = 18;

	// A way to get huge arrays to be in global data
	static double data_0[a3][a2][a1][a0];
	static double data_1[b3][b2][b1][b0];
	static double data_2_ref[c3][c2][c1][c0];
	static double data_2[c3][c2][c1][c0];

	int dummy_slot = -1;
	int dummy_index_values[4] = {-1, -1, -1, -1};

	int rank_0 = 4;
	int size_0 = a0 * a1 * a2 * a3;
	int extents_0[] = {a0, a1, a2, a3};

	int rank_1 = 4;
	int size_1 = b0 * b1 * b2 * b3;
	int extents_1[] = {b0, b1, b2, b3};

	int rank_2 = 4;
	int size_2 = c0 * c1 * c2 * c3;
	int extents_2[] = {c0, c1, c2, c3};


	//double data_0 = new double[size_0];
	//double data_1 = new double[size_1];
	//double data_2 = new double[size_2];

	int ao_seg_ranges[1] = {a0};
	int ao_seg_ranges_dims [1]= {1};
	int end_nfps[6] = {4, 13, 18, 22, 31, 36};
	const int sb_range[7] = {0, 4, 13, 18, 22, 31, 36}; // Sub Block Range
	int end_nfps_dims [1]= {6};

	int nshells = 6;

	predef_int_map.clear();
	predef_int_array_map.clear();

	predef_int_map.insert(std::make_pair(std::string("nshells"), nshells));
	IntArrData end_nfps_arrdata(1, &end_nfps_dims[0], &end_nfps[0]);
	predef_int_array_map.insert(std::make_pair(std::string("end_nfps"),end_nfps_arrdata));
	IntArrData ao_seg_ranges_data(1, &ao_seg_ranges_dims[0], &ao_seg_ranges[0]);               
	predef_int_array_map.insert(std::make_pair(std::string("ao_seg_ranges"), ao_seg_ranges_data));



	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator (seed);
	std::uniform_real_distribution<double> distribution (0.0,0.001);

	for (int a=0; a<6; a++){
		for (int b=0; b<6; b++){
			for (int c=0; c<6; c++){
				for (int d=0; d<6; d++){
					// Each sub-block is filled with 0 or some 
					// random numbers

					for (int i=sb_range[a]; i<sb_range[a+1] && i<ao_seg_ranges[0]; i++){
						for (int j=sb_range[b]; j<sb_range[b+1] && j<ao_seg_ranges[0]; j++){
							for (int k=sb_range[c]; k<sb_range[c+1] && k<ao_seg_ranges[0]; k++){
								for(int l=sb_range[d]; l<sb_range[d+1] && l<ao_seg_ranges[0]; l++){
									data_0[l][k][j][i] = distribution(generator);
									data_1[l][k][j][i] = distribution(generator);
									data_2_ref[l][k][j][i] = 0.0;
									data_2[l][k][j][i] = 0.0;
								}
							}
						}
					}
				}
			}
		}
	}

	std::clock_t start;
	double duration;   
	start = std::clock();
	aoladder_contraction_new(dummy_slot, rank_0, &dummy_index_values[0], 
//	aoladder_contraction(dummy_slot, rank_0, &dummy_index_values[0], 
			size_0, &extents_0[0], &data_0[0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0], 
			size_1, &extents_1[0], &data_1[0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0], 
			size_2, &extents_2[0], &data_2_ref[0][0][0][0],
			ierr);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: "<< duration <<'\n';
	//            
	//    aoladder_contraction_cpp(dummy_slot, rank_0, &dummy_index_values[0], 
	//        size_0, &extents_0[0], &data_0[0][0][0][0],
	//        dummy_slot, rank_1, &dummy_index_values[0], 
	//        size_1, &extents_1[0], &data_1[0][0][0][0],
	//        dummy_slot, rank_2, &dummy_index_values[0], 
	//        size_2, &extents_2[0], &data_2[0][0][0][0],
	//        ierr);        
	start = std::clock();
	aoladder_contraction_cu_nosparse(dummy_slot, rank_0, &dummy_index_values[0],
			size_0, &extents_0[0], &data_0[0][0][0][0],
			dummy_slot, rank_1, &dummy_index_values[0],
			size_1, &extents_1[0], &data_1[0][0][0][0],
			dummy_slot, rank_2, &dummy_index_values[0],
			size_2, &extents_2[0], &data_2[0][0][0][0],
			ierr);
	duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

	std::cout<<"printf: "<< duration <<'\n';
	
	/*
	std::cout << " Actual : " <<std::endl;
	for (int i=0; i<c0; i++){
		for (int j=0; j<c1; j++){
			for (int k=0; k<c2; k++){
				for (int l=0; l<c3; l++){
					std::cout<<data_2[i][j][k][l] << " ";
				}
			}
		}
		std::cout<<std::endl;
	}
	std::cout << " Reference : " << std::endl;
	for (int i=0; i<c0; i++){
		for (int j=0; j<c1; j++){
			for (int k=0; k<c2; k++){
				for (int l=0; l<c3; l++){
					std::cout<<data_2_ref[i][j][k][l] << " ";
				}
			}
		}
		std::cout<<std::endl;
	}
	//
	for (int i=0; i<c0; i++){
		for (int j=0; j<c1; j++){
			for (int k=0; k<c2; k++){
				for (int l=0; l<c3; l++){
					ASSERT_NEAR(data_2_ref[i][j][k][l], data_2[i][j][k][l], THRESHOLD);
				}
			}
		}
	}

}
*/

int main(int argc, char **argv) {

	printf("Running main() from master_test_main.cpp\n");
	testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();

	return result;

}
