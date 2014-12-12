#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include "io_utils.h"

extern "C" {
    void aoladder_contraction(
            int& array_slot_1, int& rank_1, int * index_values_1, int& size_1, 
            int * extents_1, double * data_1, 
            int& array_slot_2, int& rank_2, int * index_values_2, int& size_2, 
            int * extents_2, double * data_2, 
            int& array_slot_3, int& rank_3, int * index_values_3, int& size_3, 
            int * extents_3, double * data_3, int& ierr);
}


void read_from_file(std::string filename, int &rank, int*& extents_read, double*& data, int& data_size){

    setup::BinaryInputFile data_stream(filename);
    rank = data_stream.read_int(); // Read rank

    // Read extents
    int extents_size;
    extents_read = data_stream.read_int_array(&extents_size);
    assert (extents_size == rank);

    // Read data    
    data = data_stream.read_double_array(&data_size);
    
}

int main (int argc, char **argv){

    //dump_contents_of_block_file("data0.blk");
    //dump_contents_of_block_file("data1.blk");
    //dump_contents_of_block_file("data2.blk");

    const double THRESHOLD = 1e-12;

    int ierr;

    int dummy_slot = -1;
    int dummy_index_values[4] = {-1, -1, -1, -1};

    int rank_0;
    int size_0;
    int *extents_0;
    double *data_0;
    
    int rank_1;
    int size_1;
    int *extents_1;
    double *data_1;
    
    int rank_2;
    int size_2;
    int *extents_2;
    double *data_2;

    double *data_2_ref;

    read_from_file("data0.blk", rank_0, extents_0, data_0, size_0);
    read_from_file("data1.blk", rank_1, extents_1, data_1, size_1);
    read_from_file("data2.blk", rank_2, extents_2, data_2_ref, size_2);
    
    data_2 = new double[size_2]();

    
    aoladder_contraction(dummy_slot, rank_0, &dummy_index_values[0], 
            size_0, extents_0, data_0,
            dummy_slot, rank_1, &dummy_index_values[0], 
            size_1, extents_1, data_1,
            dummy_slot, rank_2, &dummy_index_values[0], 
            size_2, extents_2, data_2,
            ierr);


    for (int i=0; i<size_2; ++i){
        double diff = data_2_ref[i] - data_2[i];
        double absdiff = diff < 0 ? diff * -1 : diff;
        if (absdiff > THRESHOLD)
            std::cerr << "Error !, diff at location :["<< i <<"]"<<std::endl;
    }

    return 0;
}

