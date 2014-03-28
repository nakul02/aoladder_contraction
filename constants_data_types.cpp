#include "constants_data_types.h"

std::map<std::string, int>& get_predef_int_map(){
    static std::map<std::string, int> predef_int_map;
    return predef_int_map;
}

std::map<std::string, IntArrData>& get_predef_int_array_map(){
    static std::map<std::string, IntArrData> predef_int_array_map;
    return predef_int_array_map;
}
