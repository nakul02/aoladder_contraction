#include <map>
#include <string>
#include <utility>
#include <random>
#include <chrono>
#include "gtest/gtest.h"
#include "constants_data_types.h"

static std::map<std::string, int>& predef_int_map = get_predef_int_map();
static std::map<std::string, IntArrData>& predef_int_array_map = get_predef_int_array_map();

extern "C" {
    void aoladder_contraction(
            int& array_slot_1, int& rank_1, int * index_values_1, int& size_1, 
            int * extents_1, double * data_1, 
            int& array_slot_2, int& rank_2, int * index_values_2, int& size_2, 
            int * extents_2, double * data_2, 
            int& array_slot_3, int& rank_3, int * index_values_3, int& size_3, 
            int * extents_3, double * data_3, int& ierr);
}

const double THRESHOLD = 1e-8;

TEST(AOLADDER,test1){
    
    int ierr;

    const int a0 = 36;
    const int a1 = 36;
    const int a2 = 36;
    const int a3 = 36;

    const int b0 = 36;
    const int b1 = 36;
    const int b2 = 36;
    const int b3 = 36;

    const int c0 = 36;
    const int c1 = 36;
    const int c2 = 36;
    const int c3 = 36;
    
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
    
    double data_0[a3][a2][a1][a0];
    double data_1[b3][b2][b1][b0];
    double data_2[c3][c2][c1][c0];
    
    int ao_seg_ranges[1] = {36};
    int ao_seg_ranges_dims [1]= {1};
    int end_nfps[6] = {4, 13, 18, 22, 31, 36};
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
    
    for (int b=0; b<6-1; b++){
    
        // Each sub-block is filled with 0 or some 
        // random numbers
        
        for (int i=end_nfps[b]; i<end_nfps[b+1] && i<ao_seg_ranges[0]; i++){
            for (int j=end_nfps[b]; j<end_nfps[b+1] && j<ao_seg_ranges[0]; j++){
                for (int k=end_nfps[b]; k<end_nfps[b+1] && k<ao_seg_ranges[0]; k++){
                    for(int l=end_nfps[b]; l<end_nfps[b+1] && l<ao_seg_ranges[0]; l++){
                        data_0[l][k][j][i] = distribution(generator);
                        data_1[l][k][j][i] = distribution(generator);
                        data_2[l][k][j][i] = 0.0;
                    }
                }
            }
        }
    }
    
    aoladder_contraction(dummy_slot, rank_0, &dummy_index_values[0], 
            size_0, &extents_0[0], &data_0[0][0][0][0],
            dummy_slot, rank_1, &dummy_index_values[0], 
            size_1, &extents_1[0], &data_1[0][0][0][0],
            dummy_slot, rank_2, &dummy_index_values[0], 
            size_2, &extents_2[0], &data_2[0][0][0][0],
            ierr);
            
            
    for (int i=0; i<c0; i++){
        for (int j=0; j<c1; j++){
            for (int k=0; k<c2; k++){
                for (int l=0; l<c3; l++){
                    //double diff = data_2_ref[i][j][k][l] - data_2[i][j][k][l];
                    //double absdiff = diff < 0 ? diff * -1 : diff;
                    //if (absdiff > THRESHOLD)
                    //    std::cerr << "Error !, diff at location :["
                    //        <<i<<","<<j<<","<<k<<","<<l<<"]"<<std::endl;
                }
            }
        }
    }
    
    
}


int main(int argc, char **argv) {

	printf("Running main() from master_test_main.cpp\n");
	testing::InitGoogleTest(&argc, argv);
	int result = RUN_ALL_TESTS();

	return result;

}
