//SETUP READER DATA : 
#include <map>
#include <string>
#include <utility>


//Sial program list:
const char * prog0 = "scf_rhf_coreh.siox";
const char * prog1 = "tran_rhf_no4v.siox";
const char * prog2 = "rccsd_rhf.siox";
const char * prog3 = "rccsdpt_aaa.siox";
const char * prog4 = "rccsdpt_aab.siox";

//Predefined int map:
std::pair<std::string, int> predef_int_data[] = {
std::make_pair(std::string("baocc"), 1),
std::make_pair(std::string("bavirt"), 2),
std::make_pair(std::string("bavirtorb"), 6),
std::make_pair(std::string("bbocc"), 1),
std::make_pair(std::string("bbvirt"), 2),
std::make_pair(std::string("bbvirtorb"), 6),
std::make_pair(std::string("bocc"), 1),
std::make_pair(std::string("cc_iter"), 100),
std::make_pair(std::string("eaocc"), 1),
std::make_pair(std::string("eavirt"), 2),
std::make_pair(std::string("eavirtorb"), 14),
std::make_pair(std::string("ebocc"), 1),
std::make_pair(std::string("ebvirt"), 2),
std::make_pair(std::string("ebvirtorb"), 14),
std::make_pair(std::string("eocc"), 1),
std::make_pair(std::string("fromvar"), 0),
std::make_pair(std::string("intspherical"), 1),
std::make_pair(std::string("max_shells"), 5000),
std::make_pair(std::string("nalpha_occupied"), 5),
std::make_pair(std::string("nalpha_virtual"), 9),
std::make_pair(std::string("nalphas"), 14),
std::make_pair(std::string("naocc"), 5),
std::make_pair(std::string("nbeta_occupied"), 5),
std::make_pair(std::string("nbeta_virtual"), 9),
std::make_pair(std::string("nbocc"), 5),
std::make_pair(std::string("ncenters"), 1),
std::make_pair(std::string("nfrags"), 1),
std::make_pair(std::string("norb"), 1),
std::make_pair(std::string("npcoeffs"), 36),
std::make_pair(std::string("nshells"), 3),
std::make_pair(std::string("ntotshells"), 3),
std::make_pair(std::string("scf_beg"), 2),
std::make_pair(std::string("scf_hist"), 6),
std::make_pair(std::string("scf_iter"), 150)};
std::map<std::string, int> predef_int_map(predef_int_data + 0, predef_int_data +34);


//Predefined scalar map:
std::pair<std::string, double> predef_scalar_data[] = {
std::make_pair(std::string("cc_conv"), 1e-07),
std::make_pair(std::string("damp"), 0.2),
std::make_pair(std::string("nn_repulsion"), 0),
std::make_pair(std::string("scalar1"), 33.456),
std::make_pair(std::string("scf_conv"), 1e-08),
std::make_pair(std::string("scfeneg"), 0),
std::make_pair(std::string("totenerg"), 0)};std::map<std::string, double> predef_scalar_map(predef_scalar_data + 0, predef_scalar_data + 7);

//Segment table info:
int aoindex[] = {14};
int moindex[] = {5,9};
int moaindex[] = {5,9};
int mobindex[] = {5,9};
std::pair<std::string, int*> segment_table_data[] = {
std::make_pair(std::string("aoindex"),aoindex),
std::make_pair(std::string("moindex"),moindex),
std::make_pair(std::string("moaindex"),moaindex),
std::make_pair(std::string("mobindex"),mobindex)};
std::map<std::string, int*> segment_table_map(segment_table_data + 0, segment_table_data + 4);

// Predefined arrays:
double alphas[14] = { 17880,2683,611.5,173.5,56.64,20.42,7.81,1.653,0.4869,28.39,6.27,1.695,0.4317,2.202};
int alphas_dims[] = {14};
double charge[1] = { 10};
int charge_dims[] = {1};
double coords[3][1] = { 0,0,0};
int coords_dims[] = {3,1};
double pcoeffs[36] = { 0.000738,0.005677,0.028883,0.10854,0.290907,0.448324,0.258026,0.015063,-0.0021,-0.000172,-0.001357,-0.006737,-0.027663,-0.076208,-0.175227,-0.107038,0.56705,0.565216,0,0,0,0,0,0,0,0,1,0.046087,0.240181,0.508744,0.45566,0,0,0,1,1};
int pcoeffs_dims[] = {36};
double tcoords[3][3] = { 0,0,0,0,0,0,0,0,0};
int tcoords_dims[] = {3,3};
struct ScalarArrData{
	int rank; int *dims; double *data;
 ScalarArrData(int r, int *d, double *d2) : rank(r), dims(d), data(d2) {}
};
std::pair<std::string, ScalarArrData> predef_array_data[] = {
std::make_pair(std::string("alphas"), ScalarArrData(1, &alphas_dims[0], &alphas[0])),
std::make_pair(std::string("charge"), ScalarArrData(1, &charge_dims[0], &charge[0])),
std::make_pair(std::string("coords"), ScalarArrData(2, &coords_dims[0], &coords[0][0])),
std::make_pair(std::string("pcoeffs"), ScalarArrData(1, &pcoeffs_dims[0], &pcoeffs[0])),
std::make_pair(std::string("tcoords"), ScalarArrData(2, &tcoords_dims[0], &tcoords[0][0]))};
std::map<std::string, ScalarArrData> predef_array_map(predef_array_data + 0, predef_array_data + 5);


// Predefined integer arrays:
int ao_seg_ranges[1] = { 14};
int ao_seg_ranges_dims[] = {1};
int baocc_frag[1][1] = { 1};
int baocc_frag_dims[] = {1,1};
int bavirt_frag[1][1] = { 6};
int bavirt_frag_dims[] = {1,1};
int bbocc_frag[1][1] = { 1};
int bbocc_frag_dims[] = {1,1};
int bbvirt_frag[1][1] = { 6};
int bbvirt_frag_dims[] = {1,1};
int bocc_frag[1][1] = { 1};
int bocc_frag_dims[] = {1,1};
int bvirt_frag[1][1] = { 1};
int bvirt_frag_dims[] = {1,1};
int ccbeg[6] = { 1,1,9,1,4,1};
int ccbeg_dims[] = {6};
int ccend[6] = { 9,9,9,4,4,1};
int ccend_dims[] = {6};
int eaocc_frag[1][1] = { 5};
int eaocc_frag_dims[] = {1,1};
int eavirt_frag[1][1] = { 14};
int eavirt_frag_dims[] = {1,1};
int ebocc_frag[1][1] = { 5};
int ebocc_frag_dims[] = {1,1};
int ebvirt_frag[1][1] = { 14};
int ebvirt_frag_dims[] = {1,1};
int end_nfps[3] = { 3,9,14};
int end_nfps_dims[] = {3};
int eocc_frag[1][1] = { 5};
int eocc_frag_dims[] = {1,1};
int evirt_frag[1][1] = { 9};
int evirt_frag_dims[] = {1,1};
int fragao[1] = { 0};
int fragao_dims[] = {1};
int indx_cc[3] = { 1,4,6};
int indx_cc_dims[] = {3};
int ivangmom[3] = { 0,1,2};
int ivangmom_dims[] = {3};
int ixalphas[3] = { 1,10,14};
int ixalphas_dims[] = {3};
int ixpcoeffs[3] = { 1,28,36};
int ixpcoeffs_dims[] = {3};
int mo_seg_ranges[2] = { 5,9};
int mo_seg_ranges_dims[] = {2};
int moa_seg_ranges[2] = { 5,9};
int moa_seg_ranges_dims[] = {2};
int mob_seg_ranges[2] = { 5,9};
int mob_seg_ranges_dims[] = {2};
int n_aocc[1] = { 1};
int n_aocc_dims[] = {1};
int n_avirt[1] = { 1};
int n_avirt_dims[] = {1};
int n_bocc[1] = { 1};
int n_bocc_dims[] = {1};
int n_bvirt[1] = { 1};
int n_bvirt_dims[] = {1};
int n_occ[1] = { 0};
int n_occ_dims[] = {1};
int n_virt[1] = { 0};
int n_virt_dims[] = {1};
int natoms_frag[1] = { 0};
int natoms_frag_dims[] = {1};
int ncfps[3] = { 3,2,1};
int ncfps_dims[] = {3};
int npfps[3] = { 9,4,1};
int npfps_dims[] = {3};
int w_frag_ao[1] = { 0};
int w_frag_ao_dims[] = {1};
int w_frag_aocc[1] = { 0};
int w_frag_aocc_dims[] = {1};
int w_frag_avirt[1] = { 0};
int w_frag_avirt_dims[] = {1};
int w_frag_bocc[1] = { 0};
int w_frag_bocc_dims[] = {1};
int w_frag_bvirt[1] = { 0};
int w_frag_bvirt_dims[] = {1};
int w_frag_occ[1] = { 0};
int w_frag_occ_dims[] = {1};
int w_frag_virt[1] = { 0};
int w_frag_virt_dims[] = {1};
int watom_frag[1][1] = { 0};
int watom_frag_dims[] = {1,1};
struct IntArrData{
	int rank; int *dims; int *data;
 IntArrData(int r, int *d, int *d2) : rank(r), dims(d), data(d2) {}
}; 
std::pair<std::string, IntArrData> predef_int_array_data[] = {
std::make_pair(std::string("ao_seg_ranges"), IntArrData(1, &ao_seg_ranges_dims[0], &ao_seg_ranges[0])),
std::make_pair(std::string("baocc_frag"), IntArrData(2, &baocc_frag_dims[0], &baocc_frag[0][0])),
std::make_pair(std::string("bavirt_frag"), IntArrData(2, &bavirt_frag_dims[0], &bavirt_frag[0][0])),
std::make_pair(std::string("bbocc_frag"), IntArrData(2, &bbocc_frag_dims[0], &bbocc_frag[0][0])),
std::make_pair(std::string("bbvirt_frag"), IntArrData(2, &bbvirt_frag_dims[0], &bbvirt_frag[0][0])),
std::make_pair(std::string("bocc_frag"), IntArrData(2, &bocc_frag_dims[0], &bocc_frag[0][0])),
std::make_pair(std::string("bvirt_frag"), IntArrData(2, &bvirt_frag_dims[0], &bvirt_frag[0][0])),
std::make_pair(std::string("ccbeg"), IntArrData(1, &ccbeg_dims[0], &ccbeg[0])),
std::make_pair(std::string("ccend"), IntArrData(1, &ccend_dims[0], &ccend[0])),
std::make_pair(std::string("eaocc_frag"), IntArrData(2, &eaocc_frag_dims[0], &eaocc_frag[0][0])),
std::make_pair(std::string("eavirt_frag"), IntArrData(2, &eavirt_frag_dims[0], &eavirt_frag[0][0])),
std::make_pair(std::string("ebocc_frag"), IntArrData(2, &ebocc_frag_dims[0], &ebocc_frag[0][0])),
std::make_pair(std::string("ebvirt_frag"), IntArrData(2, &ebvirt_frag_dims[0], &ebvirt_frag[0][0])),
std::make_pair(std::string("end_nfps"), IntArrData(1, &end_nfps_dims[0], &end_nfps[0])),
std::make_pair(std::string("eocc_frag"), IntArrData(2, &eocc_frag_dims[0], &eocc_frag[0][0])),
std::make_pair(std::string("evirt_frag"), IntArrData(2, &evirt_frag_dims[0], &evirt_frag[0][0])),
std::make_pair(std::string("fragao"), IntArrData(1, &fragao_dims[0], &fragao[0])),
std::make_pair(std::string("indx_cc"), IntArrData(1, &indx_cc_dims[0], &indx_cc[0])),
std::make_pair(std::string("ivangmom"), IntArrData(1, &ivangmom_dims[0], &ivangmom[0])),
std::make_pair(std::string("ixalphas"), IntArrData(1, &ixalphas_dims[0], &ixalphas[0])),
std::make_pair(std::string("ixpcoeffs"), IntArrData(1, &ixpcoeffs_dims[0], &ixpcoeffs[0])),
std::make_pair(std::string("mo_seg_ranges"), IntArrData(1, &mo_seg_ranges_dims[0], &mo_seg_ranges[0])),
std::make_pair(std::string("moa_seg_ranges"), IntArrData(1, &moa_seg_ranges_dims[0], &moa_seg_ranges[0])),
std::make_pair(std::string("mob_seg_ranges"), IntArrData(1, &mob_seg_ranges_dims[0], &mob_seg_ranges[0])),
std::make_pair(std::string("n_aocc"), IntArrData(1, &n_aocc_dims[0], &n_aocc[0])),
std::make_pair(std::string("n_avirt"), IntArrData(1, &n_avirt_dims[0], &n_avirt[0])),
std::make_pair(std::string("n_bocc"), IntArrData(1, &n_bocc_dims[0], &n_bocc[0])),
std::make_pair(std::string("n_bvirt"), IntArrData(1, &n_bvirt_dims[0], &n_bvirt[0])),
std::make_pair(std::string("n_occ"), IntArrData(1, &n_occ_dims[0], &n_occ[0])),
std::make_pair(std::string("n_virt"), IntArrData(1, &n_virt_dims[0], &n_virt[0])),
std::make_pair(std::string("natoms_frag"), IntArrData(1, &natoms_frag_dims[0], &natoms_frag[0])),
std::make_pair(std::string("ncfps"), IntArrData(1, &ncfps_dims[0], &ncfps[0])),
std::make_pair(std::string("npfps"), IntArrData(1, &npfps_dims[0], &npfps[0])),
std::make_pair(std::string("w_frag_ao"), IntArrData(1, &w_frag_ao_dims[0], &w_frag_ao[0])),
std::make_pair(std::string("w_frag_aocc"), IntArrData(1, &w_frag_aocc_dims[0], &w_frag_aocc[0])),
std::make_pair(std::string("w_frag_avirt"), IntArrData(1, &w_frag_avirt_dims[0], &w_frag_avirt[0])),
std::make_pair(std::string("w_frag_bocc"), IntArrData(1, &w_frag_bocc_dims[0], &w_frag_bocc[0])),
std::make_pair(std::string("w_frag_bvirt"), IntArrData(1, &w_frag_bvirt_dims[0], &w_frag_bvirt[0])),
std::make_pair(std::string("w_frag_occ"), IntArrData(1, &w_frag_occ_dims[0], &w_frag_occ[0])),
std::make_pair(std::string("w_frag_virt"), IntArrData(1, &w_frag_virt_dims[0], &w_frag_virt[0])),
std::make_pair(std::string("watom_frag"), IntArrData(2, &watom_frag_dims[0], &watom_frag[0][0]))};
std::map<std::string, IntArrData> predef_int_array_map(predef_int_array_data + 0, predef_int_array_data + 41);

//END OF SETUP READER DATA 
