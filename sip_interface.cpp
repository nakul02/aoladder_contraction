/*
 * interpreter_interface.cpp
 *
 * Wrapper to allow routines to be called from fortran and/or provide a result
 * without requiring the caller to include interpreter.h or deal with namespaces
 * or classes.
 *
 */

#include "sip_interface.h"
#include "constants.h"
#include <map>
#include <stdexcept>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Get a double constant from initialization data
 * @param cname [in]  Name of the constant
 * @return Value of the constant
 */
double scalar_constant(const char*cname) {
	return predef_scalar_data.at(std::string(name));
}

/**
 * Get an integer constant from initialization data
 * @param cname [in]  Name of the constant
 * @return Value of the constant
 */
int int_constant(const char*cname) {
    return predef_int_data.at(std::string(name));
}

/**
 * Get predefined scalar array from initialization data
 * @param aname [in]  Name of the array
 * @param num_dims [out]
 * @param dims [out] array of extents
 * @param values [out] the data contained in the array
 */

void predefined_scalar_array(const char*aname, int& num_dims, int **dims,
		double **values) {
		ScalarArrData a = predef_array_map.at(std::string(aname));
		num_dims = a.rank;
		*dims = a.dims
		*values = a.data;
		return;
}

void scratch_array(int& num_elements, double **array){

	//uble * scratch = new double[num_elements]();  //initialize to zero
	TAU_START("array_init");
	double *scratch = new double[num_elements]();
	TAU_STOP("array_init");

//	TAU_START("array_to_0");
//	//std::fill(scratch + 0, scratch + num_elements, 0);
//	memset(scratch, 0, num_elements * sizeof(double));
//#pragma GCC ivdep
//	for (int i=0; i<num_elements; i++)
//		scratch[i] = 0;
//	TAU_STOP("array_to_0");

//	TAU_START("array_to_1");
//	memset(scratch, 0, num_elements * sizeof(double));
//	TAU_STOP("array_to_1");

	*array = scratch;
}

void delete_scratch_array(double **array){
	delete [] *array;
}

/**
 * Get predefined integer array from intitialization data
 *
 * @param aname [in] Name of the array
 * @param [out] num_dims
 * @param [out] dims array of extents
 * @param [out] values 1-d array containing the data contained in the array
 */
void predefined_int_array(const char*aname, int& num_dims, int **dims,
		int **values) {
		IntArrData a = predef_int_array_map.at(std::string(aname));
		num_dims = a.rank;
		*dims = a.dims
		*values = a.data;
		return;

	}
}

/**
 * Gets the current SIALX line number begin executed
 * @return
 */
int current_line() {
	return sip::get_line_number();
}

//NOT YET IMPLEMENTED
//void get_config_info(const char* sialfile, const char* key, const char* value);

#ifdef __cplusplus
}
#endif

}
