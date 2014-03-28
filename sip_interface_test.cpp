/*
 * interpreter_interface.cpp
 *
 * Wrapper to allow routines to be called from fortran and/or provide a result
 * without requiring the caller to include interpreter.h or deal with namespaces
 * or classes.
 *
 */

#include "sip_interface.h"
#include "constants_data_types.h"
#include <map>
#include <stdexcept>
#include <string>


static std::map<std::string, int>& predef_int_map = get_predef_int_map();
static std::map<std::string, IntArrData>& predef_int_array_map = get_predef_int_array_map();

#ifdef __cplusplus
extern "C" {
#endif

    /**
     * Get an integer constant from initialization data
     * @param cname [in]  Name of the constant
     * @return Value of the constant
     */
    int int_constant(const char*cname) {
        return predef_int_map.at(std::string(cname));
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
        *dims = a.dims;
        *values = a.data;
        return;
    }
    //NOT YET IMPLEMENTED
    //void get_config_info(const char* sialfile, const char* key, const char* value);

#ifdef __cplusplus
}
#endif

