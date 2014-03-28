#ifndef CONSTANTS_DATA_TYPES_H_
#define CONSTANTS_DATA_TYPES_H_

#include <map>
#include <string>

class IntArrData{
public : 
    int rank; 
    int *dims; 
    int *data;
    IntArrData(int r, int *d, int *d2) 
        : rank(r), dims(d), data(d2) {}
};

std::map<std::string, int>& get_predef_int_map();

std::map<std::string, IntArrData>& get_predef_int_array_map();

#endif //CONSTANTS_DATA_TYPES_H_

