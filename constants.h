//Predefined int map:
std::pair<std::string, int> predef_int_data[] = {
	std::make_pair("baocc", 1),
	std::make_pair("bavirt", 6),
	std::make_pair("bavirtorb", 19),
	std::make_pair("bbocc", 1),
	std::make_pair("bbvirt", 7),
	std::make_pair("bbvirtorb", 19),
	std::make_pair("bocc", 1),
	std::make_pair("cc_iter", 100),
	std::make_pair("eaocc", 5),
	std::make_pair("eavirt", 7),
	std::make_pair("eavirtorb", 36),
	std::make_pair("ebocc", 5),
	std::make_pair("ebvirt", 8),
	std::make_pair("ebvirtorb", 36),
	std::make_pair("eocc", 5),
	std::make_pair("fromvar", 0),
	std::make_pair("intspherical", 1),
	std::make_pair("max_shells", 5000),
	std::make_pair("nalpha_occupied", 18),
	std::make_pair("nalpha_virtual", 18),
	std::make_pair("nalphas", 42),
	std::make_pair("naocc", 18),
	std::make_pair("nbeta_occupied", 18),
	std::make_pair("nbeta_virtual", 18),
	std::make_pair("nbocc", 18),
	std::make_pair("ncenters", 2),
	std::make_pair("nfrags", 1),
	std::make_pair("norb", 5),
	std::make_pair("npcoeffs", 146),
	std::make_pair("nshells", 6),
	std::make_pair("ntotshells", 6),
	std::make_pair("scf_beg", 2),
	std::make_pair("scf_hist", 6),
	std::make_pair("scf_iter", 150)};
std::map<std::string, int> predef_int_map(predef_int_data + 0, predef_int_data + 34);
//Predefined scalar map:
const double cc_conv=1e-07;
const double damp=0.2;
const double nn_repulsion=81;
const double scalar1=33.456;
const double scf_conv=1e-08;
const double scfeneg=0;
const double totenerg=0;
std::pair<std::string, double> predef_scalar_data[] = {
	std::make_pair("cc_conv", 1e-07),
	std::make_pair("damp", 0.2),
	std::make_pair("nn_repulsion", 81),
	std::make_pair("scalar1", 33.456),
	std::make_pair("scf_conv", 1e-08),
	std::make_pair("scfeneg", 0),
	std::make_pair("totenerg", 0)};
std::map<std::string, double> predef_scalar_map(predef_scalar_data + 0, predef_scalar_data + 7);
// Segment table info:
const int aoindex[] = {4,9,9,9,5};
const int moindex[] = {4,4,4,4,2,9,9};
const int moaindex[] = {4,4,4,4,2,9,9};
const int mobindex[] = {3,3,3,3,3,3,9,9};
std::pair<std::string, double*> segment_table_data[] = {
	std::make_pair("aoindex", aoindex),
	std::make_pair("moindex", moindex),
	std::make_pair("moaindex", moaindex),
	std::make_pair("mobindex", mobindex)};
std::map<std::string, double*> segment_table_map(segment_table_data + 0, segment_table_data + 4);
//Predefined arrays:
const double alphas[ 42] = {145700, 21840, 4972, 1408, 459.7, 165.9, 64.69, 26.44, 7.628, 2.996, 0.6504, 0.2337, 453.7, 106.8, 33.73, 12.13, 4.594, 1.678, 0.5909, 0.1852, 0.738, 145700, 21840, 4972, 1408, 459.7, 165.9, 64.69, 26.44, 7.628, 2.996, 0.6504, 0.2337, 453.7, 106.8, 33.73, 12.13, 4.594, 1.678, 0.5909, 0.1852, 0.738};
const int alphas_dims = {42};
const double c[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int c_dims = {36, 36};
const double ca[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int ca_dims = {36, 36};
const double cb[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int cb_dims = {36, 36};
const double charge[ 2] = {18, 18};
const int charge_dims = {2};
const double coords[ 3][2] = {-0, -0, 2, 0, -0, -2};
const int coords_dims = {3, 2};
const double e[ 36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int e_dims = {36};
const double ea[ 36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int ea_dims = {36};
const double eb[ 36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int eb_dims = {36};
const double fock_a[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int fock_a_dims = {36, 36};
const double fock_b[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int fock_b_dims = {36, 36};
const double oed_kin[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int oed_kin_dims = {36, 36};
const double oed_nai[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int oed_nai_dims = {36, 36};
const double oed_ovl[ 36][36] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const int oed_ovl_dims = {36, 36};
const double pcoeffs[ 146] = {0.0002367, 0.0018352, 0.0095286, 0.0386283, 0.124081, 0.296471, 0.422068, 0.241711, 0.0200509, -0.00361, 0.0009756, -0.0004113, -6.75e-05, -0.0005185, -0.0027483, -0.0111007, -0.038482, -0.0997599, -0.203088, -0.135608, 0.507195, 0.612898, 0.0442968, -0.0089928, 2.1e-05, 0.0001626, 0.0008555, 0.0034975, 0.0120156, 0.0321368, 0.0655279, 0.049937, -0.229769, -0.421006, 0.642331, 0.56754, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0.0057056, 0.043046, 0.176591, 0.406863, 0.452549, 0.122801, -0.00446, 0.0020523, -0.0016066, -0.0121714, -0.0520789, -0.123737, -0.151619, 0.142425, 0.584501, 0.43754, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0.0002367, 0.0018352, 0.0095286, 0.0386283, 0.124081, 0.296471, 0.422068, 0.241711, 0.0200509, -0.00361, 0.0009756, -0.0004113, -6.75e-05, -0.0005185, -0.0027483, -0.0111007, -0.038482, -0.0997599, -0.203088, -0.135608, 0.507195, 0.612898, 0.0442968, -0.0089928, 2.1e-05, 0.0001626, 0.0008555, 0.0034975, 0.0120156, 0.0321368, 0.0655279, 0.049937, -0.229769, -0.421006, 0.642331, 0.56754, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0.0057056, 0.043046, 0.176591, 0.406863, 0.452549, 0.122801, -0.00446, 0.0020523, -0.0016066, -0.0121714, -0.0520789, -0.123737, -0.151619, 0.142425, 0.584501, 0.43754, 0, 0, 0, 0, 0, 0, 0, 1, 1};
const int pcoeffs_dims = {146};
const double tcoords[ 3][6] = {-0, -0, 2, -0, -0, 2, -0, -0, 2, 0, -0, -2, 0, -0, -2, 0, -0, -2};
const int tcoords_dims = {3, 6};
typedef struct {int rank; int *dims; double *data} ScalarArrData;
std::pair<std::string, scalar_arr_data> predef_array_data[] = {
	std::make_pair("alphas", {1, alphas_dims, alphas}),
	std::make_pair("c", {2, c_dims, c}),
	std::make_pair("ca", {2, ca_dims, ca}),
	std::make_pair("cb", {2, cb_dims, cb}),
	std::make_pair("charge", {1, charge_dims, charge}),
	std::make_pair("coords", {2, coords_dims, coords}),
	std::make_pair("e", {1, e_dims, e}),
	std::make_pair("ea", {1, ea_dims, ea}),
	std::make_pair("eb", {1, eb_dims, eb}),
	std::make_pair("fock_a", {2, fock_a_dims, fock_a}),
	std::make_pair("fock_b", {2, fock_b_dims, fock_b}),
	std::make_pair("oed_kin", {2, oed_kin_dims, oed_kin}),
	std::make_pair("oed_nai", {2, oed_nai_dims, oed_nai}),
	std::make_pair("oed_ovl", {2, oed_ovl_dims, oed_ovl}),
	std::make_pair("pcoeffs", {1, pcoeffs_dims, pcoeffs}),
	std::make_pair("tcoords", {2, tcoords_dims, tcoords})};
std::map<std::string, scalar_arr_data> predef_array_map(predef_array_data + 0, predef_array_data + 16);
//Predefined integer arrays:
const int ao_seg_ranges[5] = {4, 13, 22, 31, 36};
const int ao_seg_ranges_dims = {5};
const int baocc_frag[1][1] = {1};
const int baocc_frag_dims = {1, 1};
const int bavirt_frag[1][1] = {19};
const int bavirt_frag_dims = {1, 1};
const int bbocc_frag[1][1] = {1};
const int bbocc_frag_dims = {1, 1};
const int bbvirt_frag[1][1] = {19};
const int bbvirt_frag_dims = {1, 1};
const int bocc_frag[1][1] = {1};
const int bocc_frag_dims = {1, 1};
const int bvirt_frag[1][1] = {1};
const int bvirt_frag_dims = {1, 1};
const int ccbeg[16] = {1, 1, 1, 12, 1, 1, 8, 1, 1, 1, 1, 12, 1, 1, 8, 1};
const int ccbeg_dims = {16};
const int ccend[16] = {12, 12, 12, 12, 8, 8, 8, 1, 12, 12, 12, 12, 8, 8, 8, 1};
const int ccend_dims = {16};
const int eaocc_frag[1][1] = {4};
const int eaocc_frag_dims = {1, 1};
const int eavirt_frag[1][1] = {27};
const int eavirt_frag_dims = {1, 1};
const int ebocc_frag[1][1] = {3};
const int ebocc_frag_dims = {1, 1};
const int ebvirt_frag[1][1] = {27};
const int ebvirt_frag_dims = {1, 1};
const int end_nfps[6] = {4, 13, 18, 22, 31, 36};
const int end_nfps_dims = {6};
const int eocc_frag[1][1] = {3};
const int eocc_frag_dims = {1, 1};
const int evirt_frag[1][1] = {9};
const int evirt_frag_dims = {1, 1};
const int fragao[1] = {0};
const int fragao_dims = {1};
const int indx_cc[6] = {1, 5, 8, 9, 13, 16};
const int indx_cc_dims = {6};
const int ivangmom[6] = {0, 1, 2, 0, 1, 2};
const int ivangmom_dims = {6};
const int ixalphas[6] = {1, 13, 21, 22, 34, 42};
const int ixalphas_dims = {6};
const int ixpcoeffs[6] = {1, 49, 73, 74, 122, 146};
const int ixpcoeffs_dims = {6};
const int mo_seg_ranges[7] = {4, 4, 4, 4, 2, 9, 9};
const int mo_seg_ranges_dims = {7};
const int moa_seg_ranges[7] = {4, 4, 4, 4, 2, 9, 9};
const int moa_seg_ranges_dims = {7};
const int mob_seg_ranges[8] = {3, 3, 3, 3, 3, 3, 9, 9};
const int mob_seg_ranges_dims = {8};
const int n_aocc[1] = {5};
const int n_aocc_dims = {1};
const int n_avirt[1] = {2};
const int n_avirt_dims = {1};
const int n_bocc[1] = {6};
const int n_bocc_dims = {1};
const int n_bvirt[1] = {2};
const int n_bvirt_dims = {1};
const int n_occ[1] = {0};
const int n_occ_dims = {1};
const int n_virt[1] = {0};
const int n_virt_dims = {1};
const int natoms_frag[1] = {0};
const int natoms_frag_dims = {1};
const int ncfps[6] = {4, 3, 1, 4, 3, 1};
const int ncfps_dims = {6};
const int npfps[6] = {12, 8, 1, 12, 8, 1};
const int npfps_dims = {6};
const int w_frag_ao[5] = {0, 0, 0, 0, 0};
const int w_frag_ao_dims = {5};
const int w_frag_aocc[5] = {0, 0, 0, 0, 0};
const int w_frag_aocc_dims = {5};
const int w_frag_avirt[2] = {0, 0};
const int w_frag_avirt_dims = {2};
const int w_frag_bocc[6] = {0, 0, 0, 0, 0, 0};
const int w_frag_bocc_dims = {6};
const int w_frag_bvirt[2] = {0, 0};
const int w_frag_bvirt_dims = {2};
const int w_frag_occ[5] = {0, 0, 0, 0, 0};
const int w_frag_occ_dims = {5};
const int w_frag_virt[2] = {0, 0};
const int w_frag_virt_dims = {2};
const int watom_frag[1][1] = {0};
const int watom_frag_dims = {1, 1};
typedef struct {int rank; int *dims; int *data} IntArrData;
std::pair<std::string, int_arr_data> predef_int_array_data[] = {
	std::make_pair("ao_seg_ranges", {1, ao_seg_ranges_dims, ao_seg_ranges}),
	std::make_pair("baocc_frag", {2, baocc_frag_dims, baocc_frag}),
	std::make_pair("bavirt_frag", {2, bavirt_frag_dims, bavirt_frag}),
	std::make_pair("bbocc_frag", {2, bbocc_frag_dims, bbocc_frag}),
	std::make_pair("bbvirt_frag", {2, bbvirt_frag_dims, bbvirt_frag}),
	std::make_pair("bocc_frag", {2, bocc_frag_dims, bocc_frag}),
	std::make_pair("bvirt_frag", {2, bvirt_frag_dims, bvirt_frag}),
	std::make_pair("ccbeg", {1, ccbeg_dims, ccbeg}),
	std::make_pair("ccend", {1, ccend_dims, ccend}),
	std::make_pair("eaocc_frag", {2, eaocc_frag_dims, eaocc_frag}),
	std::make_pair("eavirt_frag", {2, eavirt_frag_dims, eavirt_frag}),
	std::make_pair("ebocc_frag", {2, ebocc_frag_dims, ebocc_frag}),
	std::make_pair("ebvirt_frag", {2, ebvirt_frag_dims, ebvirt_frag}),
	std::make_pair("end_nfps", {1, end_nfps_dims, end_nfps}),
	std::make_pair("eocc_frag", {2, eocc_frag_dims, eocc_frag}),
	std::make_pair("evirt_frag", {2, evirt_frag_dims, evirt_frag}),
	std::make_pair("fragao", {1, fragao_dims, fragao}),
	std::make_pair("indx_cc", {1, indx_cc_dims, indx_cc}),
	std::make_pair("ivangmom", {1, ivangmom_dims, ivangmom}),
	std::make_pair("ixalphas", {1, ixalphas_dims, ixalphas}),
	std::make_pair("ixpcoeffs", {1, ixpcoeffs_dims, ixpcoeffs}),
	std::make_pair("mo_seg_ranges", {1, mo_seg_ranges_dims, mo_seg_ranges}),
	std::make_pair("moa_seg_ranges", {1, moa_seg_ranges_dims, moa_seg_ranges}),
	std::make_pair("mob_seg_ranges", {1, mob_seg_ranges_dims, mob_seg_ranges}),
	std::make_pair("n_aocc", {1, n_aocc_dims, n_aocc}),
	std::make_pair("n_avirt", {1, n_avirt_dims, n_avirt}),
	std::make_pair("n_bocc", {1, n_bocc_dims, n_bocc}),
	std::make_pair("n_bvirt", {1, n_bvirt_dims, n_bvirt}),
	std::make_pair("n_occ", {1, n_occ_dims, n_occ}),
	std::make_pair("n_virt", {1, n_virt_dims, n_virt}),
	std::make_pair("natoms_frag", {1, natoms_frag_dims, natoms_frag}),
	std::make_pair("ncfps", {1, ncfps_dims, ncfps}),
	std::make_pair("npfps", {1, npfps_dims, npfps}),
	std::make_pair("w_frag_ao", {1, w_frag_ao_dims, w_frag_ao}),
	std::make_pair("w_frag_aocc", {1, w_frag_aocc_dims, w_frag_aocc}),
	std::make_pair("w_frag_avirt", {1, w_frag_avirt_dims, w_frag_avirt}),
	std::make_pair("w_frag_bocc", {1, w_frag_bocc_dims, w_frag_bocc}),
	std::make_pair("w_frag_bvirt", {1, w_frag_bvirt_dims, w_frag_bvirt}),
	std::make_pair("w_frag_occ", {1, w_frag_occ_dims, w_frag_occ}),
	std::make_pair("w_frag_virt", {1, w_frag_virt_dims, w_frag_virt}),
	std::make_pair("watom_frag", {2, watom_frag_dims, watom_frag})};
std::map<std::string, int_arr_data> predef_int_array_map(predef_int_array_data + 0, predef_int_array_data + 41);

