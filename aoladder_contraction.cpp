//============================================================================
// Name        : aoladder_contraction.cpp
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sip_interface.h"
#ifdef __cplusplus
extern "C" {
#endif

void compute_aoladder(int a1, int a2, int b1, int b2, int c1, int c2, int d1,
		int d2, double* integrals, int i1, int i2, int j1, int j2,
		double* t2old, int ii1, int ii2, int jj1, int jj2, double* t2new,
		double* coords, double* tcoords, double* coeffs, int* ixpcoef,
		double* alphas, int* ixalpha, int* ccbeg, int* ccend,double* ans) {
	//---------------------------------------------------------------------------
	// The block of integrals (a1:a2,b1:b2,c1:c2,d1:d2) is computed for the
	// following 'types' of integrals based on atomi//labels.
	//---------------------------------------------------------------------------

	//---------------------------------------------------------------------------
	// Interface added but should be included instead

	//include 'sip_interface.f'
	//include 'imemory.h'

	//---------------------------------------------------------------------------

	int aa1, aa2, bb1, bb2, cc1, cc2, dd1, dd2;
	int adim, bdim, cdim, ddim;
	int m1, m2, n1, n2, r1, r2, s1, s2;
	int j, n, m, r, s;
	int a, b, c, d;
	int iout, jout;

	int num_to_do;
	int nints;
	int nalpha_pack, npcoeff_pack;
	int ncsum, next, nfirst;
	int me, ierr;
	int nc1, nc2, nd1, nd2;

	int imin, zmin, iblk, zblk;

	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;
	double x4, y4, z4;

	//double precision coords(3,*), coeffs(*), alphas(*)
	//double precision tcoords(3,*)
	//double precision integrals(a1:a2,b1:b2,c1:c2,d1:d2)
	//double precision t2old(a1:a2,1:i2,c1:c2,1:j2)
	//double precision t2new(b1:b2,1:ii2,d1:d2,1:jj2)
	double max_int, etemp;

	// double precision scr(*)
	// integer iscr(*)

	// integer ccbeg(*), ccend(*)
	// integer ixalpha(*), ixpcoef(*)

	const int max_dim_coeff = 5000;
	int ccbeg_pack[max_dim_coeff], ccend_pack[max_dim_coeff];
	int ccbeg_pack64[max_dim_coeff], ccend_pack64[max_dim_coeff]; //ToDo integer*8
	double alpha_pack[max_dim_coeff], pcoeff_pack[max_dim_coeff];
	int arg64[25]; //ToDo integer *8
	// VFL TO BE COMPLETED common / Imax_com / sz_max(nshells, nshells), delta
	double sz_max, delta;
	double itol, bmax, dtemp, emax;

	// common / d2int_com / jatom, jx, jcenter
	// integer jatom, jx, jcenter
	int one;

	int nshells, nalpha_occupied, nbeta_occupied;
	int nalpha_virtual, nbeta_virtual;
	int intSpherical;

	//----------------------------------------------------------------------

	// END_NFPS
	int* nalpha;
	int* end_nfps;
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------

	// NCFPS
	int* ishells;
	int* ncfps;
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	// NPFPS
	int* npfps;
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	// NPFPS
	int* index_cc;
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	// INDX_C//
	int* indx_cc;
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	// IVANGMOM
	int* ivangmom;
	// ----------------------------------------------------------------------

	int i, sum;
	bool flag[8] = { true, true, true, true, true, true, true, true };
	int flag_cnt = 0;
	//ToDo Implement lines 382 onwards
// Get the predefined data

	one = 1;
//ToDO Implement line numbers 391 to 445
	// ----------------------------------------------------------------------
	//  END_NFPS
	predefined_int_array("end_nfps", one, &nalpha, &end_nfps);
	//     write(6,*) ' END_NFPS', nalpha(1), (end_nfps(i), i=1,
	//    *                                           nalpha(1))
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	//  NCFPS
	predefined_int_array("ncfps", one, &ishells, &ncfps);
	//   write(6,*) ' NCFPS', ishells(1), (ncfps(i), i=1,
	//    *                                           ishells(1))
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	//  NPFPS
	predefined_int_array("npfps", one, &ishells, &npfps);
	//     write(6,*) ' NCFPS', ishells(1), (npfps(i), i=1,
	//    *                                           ishells(1))
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	//  INDX_CC
	predefined_int_array("indx_cc", one, &ishells, &indx_cc);
	//     write(6,*) ' INDX_CC', ishells(1), (indx_cc(i), i=1,
	//    *                                           ishells(1))
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	//  IVANGMOMO
	predefined_int_array("ivangmom", one, &ishells, &ivangmom);
	//     write(6,*) ' IVANGMOMOM', ishells(1), (ivangmom(i), i=1,
	//    *                                           ishells(1))
	// ----------------------------------------------------------------------

	nshells = int_constant("nshells");
	//     nalpha_occupied = int_constant("nalpha_occupied"//C_NULL_CHAR)
	//     nbeta_occupied = int_constant("nbeta_occupied"//C_NULL_CHAR)
	//     nalpha_virtual = int_constant("nalpha_virtual"//C_NULL_CHAR)
	//     nbeta_virtual = int_constant("nbeta_virtual"//C_NULL_CHAR)

// Set the integral tolerance

// Skip screening for now
	//call set_itol(delta,itol)
	itol = -1000;

	//-----------------------------------------------------------------------
	//   Find the shell blocks for which we shall loop through.
	//-----------------------------------------------------------------------
	//call lookup_shell(end_nfps, nshells, a1, m1)

	m1 = m2 = n1 = n2 = r1 = r2 = s1 = s2 = nshells;

	for (i = 0; i < nshells; i++) {
		if (end_nfps[i] >= a1 && flag[0]) {
			m1 = i;
			flag[0] = false;
			flag_cnt++;
		}

		if (end_nfps[i] >= a2 && flag[1]) {
			m2 = i;
			flag[1] = false;
			flag_cnt++;
		}

		if (end_nfps[i] >= b1 && flag[2]) {
			n1 = i;
			flag[2] = false;
			flag_cnt++;
		}

		if (end_nfps[i] >= b2 && flag[3]) {
			n2 = i;
			flag[3] = false;
			flag_cnt++;
		}

		if (end_nfps[i] >= c1 && flag[4]) {
			r1 = i;
			flag[4] = false;
			flag_cnt++;
		}

		if (end_nfps[i] >= c2 && flag[5]) {
			r2 = i;
			flag[5] = false;
			flag_cnt++;
		}

		if (end_nfps[i] >= d1 && flag[6]) {
			s1 = i;
			flag[6] = false;
			flag_cnt++;
		}

		//printf("%d", end_nfps[i] > d2 && flag[7]);
		//printf("\t%d", i);

		if (end_nfps[i] >= d2 && flag[7]) {
			//printf("\tGet of of here");
			s2 = i;
			flag[7] = false;
			flag_cnt++;
		}

		if (flag_cnt == 8)
			break;
	}

	for (m = m1; m <= m2; m++) {
		if (m == 0)
			aa1 = 0; //ToDo Ask if its 0 or 1
		else
			aa1 = end_nfps[m - 1]; //ToDo is Plus 1 required?
		aa2 = end_nfps[m];
		//printf("\naa1:%d, aa2:%d",aa1,aa2);
		for (n = n1; n <= n2; n++) {
			if (n == 0)
				bb1 = 0; //ToDo Ask if its 0 or 1
			else
				bb1 = end_nfps[n - 1]; //ToDo is Plus 1 required?
			bb2 = end_nfps[n];
			//printf("\nbb1:%d, bb2:%d",bb1,bb2);
			for (r = r1; r <= r2; r++) {
				if (r == 0)
					cc1 = 0; //ToDo Ask if its 0 or 1
				else
					cc1 = end_nfps[r - 1]; //ToDo is Plus 1 required?
				cc2 = end_nfps[r];
				//printf("\ncc1:%d, cc2:%d",cc1,cc2);
				for (s = s1; s <= s2; s++) {
					if (s == 0)
						dd1 = 0; //ToDo Ask if its 0 or 1
					else
						dd1 = end_nfps[s - 1]; //ToDo is Plus 1 required?
					dd2 = end_nfps[s];
					//printf("\ndd1:%d, dd2:%d",dd1,dd2);
					//-----------------------------------------------------------------------
					//  Determine the largest density element.
					//-----------------------------------------------------------------------

					//   emax = 1.0
					//   bmax = 1000000.0 ! VFL TO DO
					//   bmax = sz_max(m,n)*sz_max(r,s)
					//   bmax = dsqrt(bmax)*emax

					//   if (bmax .lt. itol) go to 30
					//---------------------------------------------------------------------------
					//  Determine the maximum integral in the shell quad
					//---------------------------------------------------------------------------

					/*if((a >= aa1 && a <= aa2) &&
					(b >= bb1 && b <= bb2) &&
					(c >= cc1 && c <= cc2) &&
					(d >= dd1 && d <= dd2))*/
					aa1=a1>=aa1?a1:aa1;
					bb1=b1>=bb1?b1:bb1;
					cc1=c1>=cc1?c1:cc1;
					dd1=d1>=dd1?d1:dd1;

					aa2=a2<=aa2?a2:aa2;
					bb2=b2<=bb2?b2:bb2;
					cc2=c2<=cc2?c2:cc2;
					dd2=d2<=dd2?d2:dd2;
					max_int = 0.0;

					for (d = dd1; d < dd2; d++) {
						for (c = cc1; c < cc2; c++) {
							for (b = bb1; b < bb2; b++) {
								for (a = aa1; a < aa2; a++) {
									int n1 = a;
									int N1 = (a2 - a1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
									int n2 = b;
									int N2 = (b2 - b1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
									int n3 = c;
									int N3 = (c2 - c1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
									int n4 = d;
									//int N4 = (d2 - d1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
									double val = integrals[n1 + N1 * (n2 + N2 * (n3 + n4 * N3))];
									double absVal = val < 0 ? -val : val;
									if (absVal > max_int)
										max_int = absVal;
								}
							}
						}
					}


					//  write(6,*) ' MAX_INT = ', max_int

					//          call return_maxint(nalpha_occupied, nbeta_occupied,
					// *                             a1,a2,b1,b2,
					// *                             c1,c2,d1,d2,
					// *                             integrals,
					// *                             scr(nfirst),
					// *                             aa1,aa2,bb1,bb2,cc1,cc2,dd1,dd2
					// *                             )
					if (max_int > 1.0e-15) {
						for (d = dd1; d < dd2; d++) {
							for (c = cc1; c < cc2; c++) {
								for (b = bb1; b < bb2; b++) {
									for (a = aa1; a < aa2; a++) {
										int n1 = a;
										int N1 = (a2 - a1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
										int n2 = b;
										int N2 = (b2 - b1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
										int n3 = c;
										int N3 = (c2 - c1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
										int n4 = d;
										//int N4 = (d2 - d1); // ToDo Plus 1 goes away if the arguments passed do not have a plus 1
										etemp =integrals[n1+ N1* (n2+ N2* (n3+ n4* N3))];
										for (iout = 0; iout < i2; iout++) {
											for (jout = 0; jout < j2; jout++) {
												int t2new_index =b+ ii1* (iout+ ii2* (d+ jout* jj1));
												int t2old_index =a+ i1 * (iout+ i2* (c+ jout* j1));

												t2new[t2new_index] += etemp
														* t2old[t2old_index];
												//	 +integrals(a, b, c, d)*t2old(a, iout, c,jout)
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

	}
	printf("\n%f",ans[255]);
	//exit(0);

}

/*
 *    first argument array --> integrals
 *    second argument array --> 'old' amplitude block
 *    third argument array --> 'new' amplitude block
 */
void aoladder_contraction(int& array_slot_0, int& rank_0, int * index_values_0,
		int& size_0, int * extents_0, double * data_0, int& array_slot_1,
		int& rank_1, int * index_values_1, int& size_1, int * extents_1,
		double * data_1, int& array_slot_2, int& rank_2, int * index_values_2,
		int& size_2, int * extents_2, double * data_2, int& ierr,double* ans) {

	//one dimensional array of atomi//coordinates
	int* pdim_coords;
	double* pcoords;

	//two dimensional array mapping atomi//coordinates to shells
	int* pdim_Tcoords;
	double* pTcoords;

	//one dimensional arrays containg ccbeg and ccend
	int* picc;
	int* pccbeg;
	int* pccend;

	//one dimensional array containg alphas(exponents)
	int* pntot_alpha;
	int* pixalphas;
	double* palphas;

	//one dimensional array containing coefficients
	int* pntot_pcoeff;
	int* pixpcoeffs;
	double* ppcoeffs;

	/*integer scratch array. HARD coded size should be changed
	 integer(C_INT) iscr(5000000)
	 real(C_DOUBLE) scr(5000000)
	 */

	//double* scr;
	//int* iscr;
	double* cscr;
	double* ciscr;

	//offsets of atomi//indeces
	int offset_1, offset_2, offset_3, offset_4;
	int i, one, two;

	// aosegments
	//     integer(C_INT) n_ao_segs(1), aosegs(6)
	int* pn_ao_segs;
	int* paosegs;

	// ----------------------------------------------------------------------
	//  END_NFPS
	int* pnalpha, pend_nfps;
	int* nalpha;
	int* end_nfps;
	// ----------------------------------------------------------------------

	int norb, nscr, niscr;

	one = 0; // 1
	two = 0; // 2
	ierr = 0;

	//ToDo Implement lines 98 to 196
	// Get the predefined data

	// ----------------------------------------------------------------------
	//  CC_BEG
	predefined_int_array("ccbeg", one, &picc, &pccbeg);
	//     write(6,*) ' CC_BEG', picc(1), (pccbeg(i), i=1,
	//    *                                           picc(1))
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	//  CC_END
	predefined_int_array("ccend", one, &picc, &pccend);
	//    write(6,*) ' CC_END', picc(1), (pccend(i), i=1,
	//   *                                           picc(1))
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// IXALPHAS(exponents)
	predefined_int_array("ixalphas", one, &pntot_alpha, &pixalphas);
	//    write(6,*) ' IXALPHAS', pntot_alpha(1), (pixalphas(i), i=1,
	//   *                                         pntot_alpha(1))
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// IXCOEFFICIENTS
	predefined_int_array("ixpcoeffs", one, &pntot_pcoeff, &pixpcoeffs);

	//    write(6,*) ' IXPCOEFFS', pntot_pcoeff(1), (pixpcoeffs(i), i=1,
	//   *                                         pntot_pcoeff(1))
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// ALPHAS(exponents)
	predefined_scalar_array("alphas", one, &pntot_alpha, &palphas);
	//    write(6,*) ' ALPHAS', pntot_alpha(1) , (palphas(i), i=1,
	//   *                pntot_alpha(1))
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// COEFFICIENTS
	predefined_scalar_array("pcoeffs", one, &pntot_pcoeff, &ppcoeffs);
	//    write(6,*) ' PCOEFFS', pntot_pcoeff(1) , (ppcoeffs(i), i=1,
	//   *                pntot_pcoeff(1))
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// ATOMI//COORDINATES
	predefined_scalar_array("coords", two, &pdim_coords, &pcoords);
	//    write(6,*) ' COORDS',  (pcoords(1,i), i=1, pdim_coords(2),
	//   *                pntot_pcoeff(1))
	//----------------------------------------------------------------------

	//----------------------------------------------------------------------
	// ATOMI//COORDINATES MAPPED TO SHELLS
	predefined_scalar_array("tcoords", two, &pdim_Tcoords, &pTcoords);
	//----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	// Get the ao segment ranges
	predefined_int_array("ao_seg_ranges", one, &pn_ao_segs, &paosegs);
	//     write(6,*) ' NAO_SEGS', pn_ao_segs(1), (paosegs(i), i=1,
	//    *                                             pn_ao_segs(1))
	// ----------------------------------------------------------------------

	// ----------------------------------------------------------------------
	//  END_NFPS
	predefined_int_array("end_nfps", one, &nalpha, &end_nfps);

	//     write(6,*) ' END_NFPS', nalpha(1), (end_nfps(i), i=1,
	//    *                                           nalpha(1))
	// ----------------------------------------------------------------------

	//----------------------------------------------------------------------

	//  Set scratch space
	//ToDo after clarification of imax,zmax in imemory.h
	// nscr  = zmax; // 5000000
	//niscr = imax; // 5000000
	nscr = 5000000;
	niscr = 5000000;

	cscr = (double*) calloc(nscr, sizeof(double));
	ciscr = (double*) calloc(niscr, sizeof(double));

	// Set offsets for the integral array. These also set the offsets for the
	// ao indices of the amplitude arrays.
	offset_1 = 0;
	offset_2 = 0;
	offset_3 = 0;
	offset_4 = 0;

	if (index_values_0[0] > 1)
		offset_1 = paosegs[index_values_0[0] - 1];
	if (index_values_0[1] > 1)
		offset_2 = paosegs[index_values_0[1] - 1];
	if (index_values_0[2] > 1)
		offset_3 = paosegs[index_values_0[2] - 1];
	if (index_values_0[3] > 1)
		offset_4 = paosegs[index_values_0[3] - 1];



	//ToDo Implement compute_aoladder
	//ToDo Arguments with Plus 1 - is the Plus 1 required since offset was initialized to 0?
	compute_aoladder(offset_1, extents_0[0] + offset_1, offset_2,
			extents_0[1] + offset_2, offset_3, extents_0[2] + offset_3,
			offset_4, extents_0[3] + offset_4,
			data_0, //      integrals data_0
			extents_1[0], extents_1[1], extents_1[2], extents_1[3],
			data_1, //old amplitudes data_1
			extents_2[0], extents_2[1], extents_2[2], extents_2[3],
			data_2, //new amplitudes data_2

			pcoords, pTcoords, ppcoeffs, pixpcoeffs, palphas, pixalphas, pccbeg,
			pccend,ans);


	// ----------------------------------------------------------------------
	//  Remove scratch space
	free(cscr);
	free(ciscr);

	//Comments from line 243 to 263 missing
}

#ifdef __cplusplus
}
#endif

