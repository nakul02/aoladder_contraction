#include <map>
#include <string>
#include <utility>

//Sial program list:
const char * prog0 = "scf_rhf_coreh.siox";
const char * prog1 = "tran_rhf_no4v.siox";
const char * prog2 = "rccsd_rhf.siox";
//Predefined int map:
std::pair<std::string, int> predef_int_data[] = {
	std::make_pair(std::string("baocc"), 1),
	std::make_pair(std::string("bavirt"), 6),
	std::make_pair(std::string("bavirtorb"), 19),
	std::make_pair(std::string("bbocc"), 1),
	std::make_pair(std::string("bbvirt"), 7),
	std::make_pair(std::string("bbvirtorb"), 19),
	std::make_pair(std::string("bocc"), 1),
	std::make_pair(std::string("cc_iter"), 100),
	std::make_pair(std::string("eaocc"), 5),
	std::make_pair(std::string("eavirt"), 7),
	std::make_pair(std::string("eavirtorb"), 36),
	std::make_pair(std::string("ebocc"), 5),
	std::make_pair(std::string("ebvirt"), 8),
	std::make_pair(std::string("ebvirtorb"), 36),
	std::make_pair(std::string("eocc"), 5),
	std::make_pair(std::string("fromvar"), 0),
	std::make_pair(std::string("intspherical"), 1),
	std::make_pair(std::string("max_shells"), 5000),
	std::make_pair(std::string("nalpha_occupied"), 18),
	std::make_pair(std::string("nalpha_virtual"), 18),
	std::make_pair(std::string("nalphas"), 42),
	std::make_pair(std::string("naocc"), 18),
	std::make_pair(std::string("nbeta_occupied"), 18),
	std::make_pair(std::string("nbeta_virtual"), 18),
	std::make_pair(std::string("nbocc"), 18),
	std::make_pair(std::string("ncenters"), 2),
	std::make_pair(std::string("nfrags"), 1),
	std::make_pair(std::string("norb"), 5),
	std::make_pair(std::string("npcoeffs"), 146),
	std::make_pair(std::string("nshells"), 6),
	std::make_pair(std::string("ntotshells"), 6),
	std::make_pair(std::string("scf_beg"), 2),
	std::make_pair(std::string("scf_hist"), 6),
	std::make_pair(std::string("scf_iter"), 150)};
std::map<std::string, int> predef_int_map(predef_int_data + 0, predef_int_data + 34);
//Predefined scalar map:
 double cc_conv=1e-07;
 double damp=0.2;
 double nn_repulsion=81;
 double scalar1=33.456;
 double scf_conv=1e-08;
 double scfeneg=0;
 double totenerg=0;
std::pair<std::string, double> predef_scalar_data[] = {
	std::make_pair(std::string("cc_conv"), 1e-07),
	std::make_pair(std::string("damp"), 0.2),
	std::make_pair(std::string("nn_repulsion"), 81),
	std::make_pair(std::string("scalar1"), 33.456),
	std::make_pair(std::string("scf_conv"), 1e-08),
	std::make_pair(std::string("scfeneg"), 0),
	std::make_pair(std::string("totenerg"), 0)};
std::map<std::string, double> predef_scalar_map(predef_scalar_data + 0, predef_scalar_data + 7);
// Segment table info:
 int aoindex[] = {4,9,9,9,5};
 int moindex[] = {4,4,4,4,2,9,9};
 int moaindex[] = {4,4,4,4,2,9,9};
 int mobindex[] = {3,3,3,3,3,3,9,9};
std::pair<std::string, int*> segment_table_data[] = {
	std::make_pair(std::string("aoindex"), aoindex),
	std::make_pair(std::string("moindex"), moindex),
	std::make_pair(std::string("moaindex"), moaindex),
	std::make_pair(std::string("mobindex"), mobindex)};
std::map<std::string, int*> segment_table_map(segment_table_data + 0, segment_table_data + 4);
//Predefined arrays:
 double alphas[ 42] = {145700, 21840, 4972, 1408, 459.7, 165.9, 64.69, 26.44, 7.628, 2.996, 0.6504, 0.2337, 453.7, 106.8, 33.73, 12.13, 4.594, 1.678, 0.5909, 0.1852, 0.738, 145700, 21840, 4972, 1408, 459.7, 165.9, 64.69, 26.44, 7.628, 2.996, 0.6504, 0.2337, 453.7, 106.8, 33.73, 12.13, 4.594, 1.678, 0.5909, 0.1852, 0.738};
 int alphas_dims []= {42};
 double c[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int c_dims []= {36, 36};
 double ca[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int ca_dims []= {36, 36};
 double cb[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int cb_dims []= {36, 36};
 double charge[ 2] = {18, 18};
 int charge_dims []= {2};
 double coords[ 3][2] = {-0, -0, 2, 0, -0, -2};
 int coords_dims []= {3, 2};
 double e[ 36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int e_dims []= {36};
 double ea[ 36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int ea_dims []= {36};
 double eb[ 36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int eb_dims []= {36};
 double fock_a[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int fock_a_dims []= {36, 36};
 double fock_b[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int fock_b_dims []= {36, 36};
 double oed_kin[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int oed_kin_dims []= {36, 36};
 double oed_nai[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int oed_nai_dims []= {36, 36};
 double oed_ovl[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
 int oed_ovl_dims []= {36, 36};
 double pcoeffs[ 146] = {0.0002367, 0.0018352, 0.0095286, 0.0386283, 0.124081, 0.296471, 0.422068, 0.241711, 0.0200509, -0.00361, 0.0009756, -0.0004113, -6.75e-05, -0.0005185, -0.0027483, -0.0111007, -0.038482, -0.0997599, -0.203088, -0.135608, 0.507195, 0.612898, 0.0442968, -0.0089928, 2.1e-05, 0.0001626, 0.0008555, 0.0034975, 0.0120156, 0.0321368, 0.0655279, 0.049937, -0.229769, -0.421006, 0.642331, 0.56754, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0.0057056, 0.043046, 0.176591, 0.406863, 0.452549, 0.122801, -0.00446, 0.0020523, -0.0016066, -0.0121714, -0.0520789, -0.123737, -0.151619, 0.142425, 0.584501, 0.43754, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0.0002367, 0.0018352, 0.0095286, 0.0386283, 0.124081, 0.296471, 0.422068, 0.241711, 0.0200509, -0.00361, 0.0009756, -0.0004113, -6.75e-05, -0.0005185, -0.0027483, -0.0111007, -0.038482, -0.0997599, -0.203088, -0.135608, 0.507195, 0.612898, 0.0442968, -0.0089928, 2.1e-05, 0.0001626, 0.0008555, 0.0034975, 0.0120156, 0.0321368, 0.0655279, 0.049937, -0.229769, -0.421006, 0.642331, 0.56754, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0.0057056, 0.043046, 0.176591, 0.406863, 0.452549, 0.122801, -0.00446, 0.0020523, -0.0016066, -0.0121714, -0.0520789, -0.123737, -0.151619, 0.142425, 0.584501, 0.43754, 0, 0, 0, 0, 0, 0, 0, 1, 1};
 int pcoeffs_dims []= {146};
 double tcoords[ 3][6] = {-0, -0, 2, -0, -0, 2, -0, -0, 2, 0, -0, -2, 0, -0, -2, 0, -0, -2};
 int tcoords_dims []= {3, 6};
class ScalarArrData{
 public : int rank; int *dims; double *data;
 ScalarArrData(int r, int *d, double *d2) : rank(r), dims(d), data(d2) {}
};
std::pair<std::string, ScalarArrData> predef_array_data[] = {
	std::make_pair(std::string("alphas"), ScalarArrData(1, &alphas_dims[0], &alphas[0])),
	std::make_pair(std::string("c"), ScalarArrData(2, &c_dims[0], &c[0][0])),
	std::make_pair(std::string("ca"), ScalarArrData(2, &ca_dims[0], &ca[0][0])),
	std::make_pair(std::string("cb"), ScalarArrData(2, &cb_dims[0], &cb[0][0])),
	std::make_pair(std::string("charge"), ScalarArrData(1, &charge_dims[0], &charge[0])),
	std::make_pair(std::string("coords"), ScalarArrData(2, &coords_dims[0], &coords[0][0])),
	std::make_pair(std::string("e"), ScalarArrData(1, &e_dims[0], &e[0])),
	std::make_pair(std::string("ea"), ScalarArrData(1, &ea_dims[0], &ea[0])),
	std::make_pair(std::string("eb"), ScalarArrData(1, &eb_dims[0], &eb[0])),
	std::make_pair(std::string("fock_a"), ScalarArrData(2, &fock_a_dims[0], &fock_a[0][0])),
	std::make_pair(std::string("fock_b"), ScalarArrData(2, &fock_b_dims[0], &fock_b[0][0])),
	std::make_pair(std::string("oed_kin"), ScalarArrData(2, &oed_kin_dims[0], &oed_kin[0][0])),
	std::make_pair(std::string("oed_nai"), ScalarArrData(2, &oed_nai_dims[0], &oed_nai[0][0])),
	std::make_pair(std::string("oed_ovl"), ScalarArrData(2, &oed_ovl_dims[0], &oed_ovl[0][0])),
	std::make_pair(std::string("pcoeffs"), ScalarArrData(1, &pcoeffs_dims[0], &pcoeffs[0])),
	std::make_pair(std::string("tcoords"), ScalarArrData(2, &tcoords_dims[0], &tcoords[0][0]))};
std::map<std::string, ScalarArrData> predef_array_map(predef_array_data + 0, predef_array_data + 16);
//Predefined integer arrays:
 int ao_seg_ranges[5] = {4, 13, 22, 31, 36};
 int ao_seg_ranges_dims []= {5};
 int baocc_frag[1][1] = {1};
 int baocc_frag_dims []= {1, 1};
 int bavirt_frag[1][1] = {19};
 int bavirt_frag_dims []= {1, 1};
 int bbocc_frag[1][1] = {1};
 int bbocc_frag_dims []= {1, 1};
 int bbvirt_frag[1][1] = {19};
 int bbvirt_frag_dims []= {1, 1};
 int bocc_frag[1][1] = {1};
 int bocc_frag_dims []= {1, 1};
 int bvirt_frag[1][1] = {1};
 int bvirt_frag_dims []= {1, 1};
 int ccbeg[16] = {1, 1, 1, 12, 1, 1, 8, 1, 1, 1, 1, 12, 1, 1, 8, 1};
 int ccbeg_dims []= {16};
 int ccend[16] = {12, 12, 12, 12, 8, 8, 8, 1, 12, 12, 12, 12, 8, 8, 8, 1};
 int ccend_dims []= {16};
 int eaocc_frag[1][1] = {4};
 int eaocc_frag_dims []= {1, 1};
 int eavirt_frag[1][1] = {27};
 int eavirt_frag_dims []= {1, 1};
 int ebocc_frag[1][1] = {3};
 int ebocc_frag_dims []= {1, 1};
 int ebvirt_frag[1][1] = {27};
 int ebvirt_frag_dims []= {1, 1};
 int end_nfps[6] = {4, 13, 18, 22, 31, 36};
 int end_nfps_dims []= {6};
 int eocc_frag[1][1] = {3};
 int eocc_frag_dims []= {1, 1};
 int evirt_frag[1][1] = {9};
 int evirt_frag_dims []= {1, 1};
 int fragao[1] = {0};
 int fragao_dims []= {1};
 int indx_cc[6] = {1, 5, 8, 9, 13, 16};
 int indx_cc_dims []= {6};
 int ivangmom[6] = {0, 1, 2, 0, 1, 2};
 int ivangmom_dims []= {6};
 int ixalphas[6] = {1, 13, 21, 22, 34, 42};
 int ixalphas_dims []= {6};
 int ixpcoeffs[6] = {1, 49, 73, 74, 122, 146};
 int ixpcoeffs_dims []= {6};
 int mo_seg_ranges[7] = {4, 4, 4, 4, 2, 9, 9};
 int mo_seg_ranges_dims []= {7};
 int moa_seg_ranges[7] = {4, 4, 4, 4, 2, 9, 9};
 int moa_seg_ranges_dims []= {7};
 int mob_seg_ranges[8] = {3, 3, 3, 3, 3, 3, 9, 9};
 int mob_seg_ranges_dims []= {8};
 int n_aocc[1] = {5};
 int n_aocc_dims []= {1};
 int n_avirt[1] = {2};
 int n_avirt_dims []= {1};
 int n_bocc[1] = {6};
 int n_bocc_dims []= {1};
 int n_bvirt[1] = {2};
 int n_bvirt_dims []= {1};
 int n_occ[1] = {0};
 int n_occ_dims []= {1};
 int n_virt[1] = {0};
 int n_virt_dims []= {1};
 int natoms_frag[1] = {0};
 int natoms_frag_dims []= {1};
 int ncfps[6] = {4, 3, 1, 4, 3, 1};
 int ncfps_dims []= {6};
 int npfps[6] = {12, 8, 1, 12, 8, 1};
 int npfps_dims []= {6};
 int w_frag_ao[5] = {0, 0, 0, 0, 0};
 int w_frag_ao_dims []= {5};
 int w_frag_aocc[5] = {0, 0, 0, 0, 0};
 int w_frag_aocc_dims []= {5};
 int w_frag_avirt[2] = {0, 0};
 int w_frag_avirt_dims []= {2};
 int w_frag_bocc[6] = {0, 0, 0, 0, 0, 0};
 int w_frag_bocc_dims []= {6};
 int w_frag_bvirt[2] = {0, 0};
 int w_frag_bvirt_dims []= {2};
 int w_frag_occ[5] = {0, 0, 0, 0, 0};
 int w_frag_occ_dims []= {5};
 int w_frag_virt[2] = {0, 0};
 int w_frag_virt_dims []= {2};
 int watom_frag[1][1] = {0};
 int watom_frag_dims []= {1, 1};
class IntArrData{
 public : int rank; int *dims; int *data;
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

