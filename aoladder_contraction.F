      subroutine aoladder_contraction(
     c array_slot_0, rank_0, index_values_0, size_0, extents_0, data_0,
     c array_slot_1, rank_1, index_values_1, size_1, extents_1, data_1,
     c array_slot_2, rank_2, index_values_2, size_2, extents_2, data_2,
     c  ierr) BIND(C)
      use, intrinsic :: ISO_C_BINDING
      implicit none

c Interface added BUT should be include NOT added in the future

      include 'sip_interface.fh'
      include 'imemory.h'

!     first argument array --> integrals 
      integer(C_INT), intent(in)::array_slot_0
      integer(C_INT), intent(in)::rank_0
      integer(C_INT), intent(in)::index_values_0(1:rank_0)
      integer(C_INT), intent(in)::size_0
      integer(C_INT), intent(in)::extents_0(1:rank_0)
      real(C_DOUBLE), intent(out)::data_0(1:size_0)

!     second argument array --> 'old' amplitude block  
      integer(C_INT), intent(in)::array_slot_1
      integer(C_INT), intent(in)::rank_1
      integer(C_INT), intent(in)::index_values_1(1:rank_1)
      integer(C_INT), intent(in)::size_1
      integer(C_INT), intent(in)::extents_1(1:rank_1)
      real(C_DOUBLE), intent(out)::data_1(1:size_1)

!     third argument array --> 'new' amplitude block  
      integer(C_INT), intent(in)::array_slot_2
      integer(C_INT), intent(in)::rank_2
      integer(C_INT), intent(in)::index_values_2(1:rank_2)
      integer(C_INT), intent(in)::size_2
      integer(C_INT), intent(in)::extents_2(1:rank_2)
      real(C_DOUBLE), intent(out)::data_2(1:size_2)

      integer(C_INT), intent(out)::ierr

!     one dimensional array of atomic coordinates  
c      TYPE(C_PTR) :: sDimCoords 
c      TYPE(C_PTR) :: coords 
c      integer, pointer :: pdim_coords(:)  
c      real(C_DOUBLE), pointer :: pcoords(:,:)

!     tw0 dimensional array mapping atomic coordinates to shells  
c     TYPE(C_PTR) :: sDimTCoords 
c     TYPE(C_PTR) :: Tcoords 
c     integer, pointer :: pdim_Tcoords(:)  
c     real(C_DOUBLE), pointer :: pTcoords(:,:)

!     one dimensional arrays containg ccbeg and ccend  
c      TYPE(C_PTR) :: icc, ccbeg, ccend  
c      integer, pointer :: picc(:), pccbeg(:), pccend(:)  

!     one dimensional array containg alphas(exponents)   
c      TYPE(C_PTR) :: ntot_alpha, ixalphas 
c      integer, pointer :: pntot_alpha(:), pixalphas(:) 
c      TYPE(C_PTR) :: alphas
c      real(C_DOUBLE) , pointer :: palphas(:)

!     one dimensional array containing coefficients  
c      TYPE(C_PTR) :: ntot_pcoeff, ixpcoeffs 
c      TYPE(C_PTR) :: pcoeffs  
c      integer, pointer :: pntot_pcoeff(:), pixpcoeffs(:) 
c      real(C_DOUBLE), pointer :: ppcoeffs(:)

!     integer scratch array. HARD coded size should be changed  
c     integer(C_INT) iscr(5000000)   
c     real(C_DOUBLE) scr(5000000)   

c      real(C_DOUBLE), pointer :: scr(:) 
c      integer, pointer :: iscr(:)
c      TYPE(C_PTR) :: cscr 
c      TYPE(C_PTR) :: ciscr 
!     offsets of atomic indeces  
      integer(C_INT) offset_1, offset_2, offset_3, offset_4  
      integer(C_INT) i, one, two   

c aosegments 
c      integer(C_INT) n_ao_segs(1), aosegs(6)    
      TYPE(C_PTR) :: n_ao_segs, aosegs    
      integer, pointer :: pn_ao_segs(:), paosegs(:)    

c ----------------------------------------------------------------------
c  END_NFPS 
      TYPE(C_PTR) :: pnalpha, pend_nfps
      integer, pointer :: nalpha(:)
      integer, pointer :: end_nfps(:)
c ----------------------------------------------------------------------

c      integer(C_INT) norb, nscr, niscr   
c
      one = 0 ! 1
      two = 0 ! 2
      ierr = 0 

c Get the predefined data 

c ----------------------------------------------------------------------
c  CC_BEG    
c      call predefined_int_array("ccbeg"//C_NULL_CHAR, one, icc, 
c     *                                   ccbeg)
c      call c_f_pointer(icc, picc,[1]) 
c      call c_f_pointer(ccbeg,pccbeg,picc) 
c     write(6,*) ' CC_BEG', picc(1), (pccbeg(i), i=1, 
c    *                                           picc(1)) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  CC_END    
c      call predefined_int_array("ccend"//C_NULL_CHAR, one, icc, 
c     *                                   ccend)
c      call c_f_pointer(icc, picc,[1]) 
c      call c_f_pointer(ccend,pccend,picc) 
c     write(6,*) ' CC_END', picc(1), (pccend(i), i=1, 
c    *                                           picc(1)) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  IXALPHAS(exponents)     
c      call predefined_int_array("ixalphas"//C_NULL_CHAR, one, 
c     *                                   ntot_alpha, ixalphas) 
c      call c_f_pointer(ntot_alpha, pntot_alpha,[1]) 
c      call c_f_pointer(ixalphas, pixalphas, pntot_alpha) 
c     write(6,*) ' IXALPHAS', pntot_alpha(1), (pixalphas(i), i=1, 
c    *                                         pntot_alpha(1)) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  IXCOEFFICIENTS   
c      call predefined_int_array("ixpcoeffs"//C_NULL_CHAR,one,
c     *                                   ntot_pcoeff, ixpcoeffs) 
c      call c_f_pointer(ntot_pcoeff, pntot_pcoeff,[1]) 
c      call c_f_pointer(ixpcoeffs, pixpcoeffs, pntot_pcoeff) 
c     write(6,*) ' IXPCOEFFS', pntot_pcoeff(1), (pixpcoeffs(i), i=1, 
c    *                                         pntot_pcoeff(1)) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  ALPHAS(exponents)     
c      call predefined_scalar_array("alphas"//C_NULL_CHAR,
c     *                              one, ntot_alpha, alphas)
c      call c_f_pointer(ntot_alpha, pntot_alpha,[1]) 
c      call c_f_pointer(alphas, palphas, pntot_alpha) 
c     write(6,*) ' ALPHAS', pntot_alpha(1) , (palphas(i), i=1,
c    *                pntot_alpha(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  COEFFICIENTS   
c      call predefined_scalar_array("pcoeffs"//C_NULL_CHAR,
c     *                               one, ntot_pcoeff,pcoeffs)
c      call c_f_pointer(ntot_pcoeff, pntot_pcoeff,[1]) 
c      call c_f_pointer(pcoeffs, ppcoeffs, pntot_pcoeff) 
c     write(6,*) ' PCOEFFS', pntot_pcoeff(1) , (ppcoeffs(i), i=1,
c    *                pntot_pcoeff(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  ATOMIC COORDINATES  
c      call predefined_scalar_array("coords"//C_NULL_CHAR,
c     *                                  two, sDimCoords,  coords)
c      call c_f_pointer(sDimCoords, pdim_coords,[2]) 
c      call c_f_pointer(coords, pcoords, pdim_coords) 
c     write(6,*) ' COORDS',  (pcoords(1,i), i=1, pdim_coords(2),
c    *                pntot_pcoeff(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  ATOMIC COORDINATES MAPPED TO SHELLS   
c      call predefined_scalar_array("tcoords"//C_NULL_CHAR,
c     *                                  two, sDimTCoords, tcoords)
c      call c_f_pointer(sDimTCoords, pdim_Tcoords,[2]) 
c      call c_f_pointer(tcoords, ptcoords, pdim_tcoords) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c Get the ao segment ranges  
      call predefined_int_array("ao_seg_ranges"//C_NULL_CHAR, one, 
     *                           n_ao_segs, aosegs)  
      call c_f_pointer(n_ao_segs,pn_ao_segs,[1]) 
      call c_f_pointer(aosegs,paosegs,pn_ao_segs) 
c      write(6,*) ' NAO_SEGS', pn_ao_segs(1), (paosegs(i), i=1, 
c    *                                             pn_ao_segs(1)) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  END_NFPS 
c      call predefined_int_array("end_nfps"//C_NULL_CHAR, one,
c     *                                   pnalpha, pend_nfps)
c      call c_f_pointer(pnalpha, nalpha, [1])
c      call c_f_pointer(pend_nfps, end_nfps, nalpha)
c     write(6,*) ' END_NFPS', nalpha(1), (end_nfps(i), i=1, 
c    *                                           nalpha(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c
c  Set scratch space  
c      nscr  = zmax ! 5000000 
c      niscr = imax ! 5000000 
c     nscr  = 5000000 
c     niscr = 5000000 

c      call scratch_array(nscr, cscr) 
c      call c_f_pointer(cscr, scr, [nscr]) 

c      call scratch_array(niscr, ciscr) 
c      call c_f_pointer(ciscr, iscr, [niscr]) 

c Set offsets for the integral array. These also set the offsets for the
c ao indices of the amplitude arrays. 
      offset_1 = 0 
      offset_2 = 0 
      offset_3 = 0 
      offset_4 = 0 
      if (index_values_0(1).gt.1) offset_1=paosegs(index_values_0(1)-1) 
      if (index_values_0(2).gt.1) offset_2=paosegs(index_values_0(2)-1) 
      if (index_values_0(3).gt.1) offset_3=paosegs(index_values_0(3)-1) 
      if (index_values_0(4).gt.1) offset_4=paosegs(index_values_0(4)-1)
c
      call compute_aoladder(1+offset_1, extents_0(1)+offset_1,
     *                      1+offset_2, extents_0(2)+offset_2,
     *                      1+offset_3, extents_0(3)+offset_3,
     *                      1+offset_4, extents_0(4)+offset_4,
     *                      data_0, !     integrals data_0  
     *                      extents_1(1), extents_1(2), extents_1(3), 
     *                      extents_1(4), data_1, !old amplitudes data_1  
     *                      extents_2(1), extents_2(2), extents_2(3), 
     *                      extents_2(4), data_2) !new amplitudes data_2  
c 
c     *                      pcoords, ptcoords, 
c     *                      ppcoeffs, pixpcoeffs, palphas, pixalphas,
c     *                      pccbeg, pccend)
c 
c ----------------------------------------------------------------------
c
c  Remove scratch space  
c      call delete_scratch_array(cscr) 
c      call delete_scratch_array(ciscr) 

c     do i = 1, (extents_0(1)-1)*(extents_0(2)-1)*  
c    *          (extents_0(3)-1)*(extents_0(4)-1)  
c        write(6,*) 'INT6', i, data_0(i), scr(i)  
c     enddo 
c     stop 
      return
      end
C  Copyright (c) 2003-2010 University of Florida
C
C  This program is free software; you can redistribute it and/or modify
C  it under the terms of the GNU General Public License as published by
C  the Free Software Foundation; either version 2 of the License, or
C  (at your option) any later version.

C  This program is distributed in the hope that it will be useful,
C  but WITHOUT ANY WARRANTY; without even the implied warranty of
C  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
C  GNU General Public License for more details.

C  The GNU General Public License is included in this distribution
C  in the file COPYRIGHT.
      subroutine compute_aoladder(a1,a2,b1,b2,c1,c2,d1,d2,integrals, 
     *                 i1, i2, j1, j2, t2old, 
     *                 ii1, ii2, jj1, jj2, t2new) 
c     *                 coords, tcoords ,coeffs, 
c     *                 ixpcoef,alphas, 
c     *                 ixalpha, ccbeg, ccend)
c---------------------------------------------------------------------------
c   The block of integrals (a1:a2,b1:b2,c1:c2,d1:d2) is computed for the 
c   following 'types' of integrals based on atomic labels.
c---------------------------------------------------------------------------

      use, intrinsic :: ISO_C_BINDING 
      implicit none
      
c---------------------------------------------------------------------------
c Interface added but should be included instead 

      include 'sip_interface.fh' 
c      include 'imemory.h'

c---------------------------------------------------------------------------

      integer a1, a2, b1, b2, c1, c2, d1, d2 
      integer i1, i2, j1, j2 
      integer ii1, ii2, jj1, jj2 
      integer aa1,aa2,bb1,bb2,cc1,cc2,dd1,dd2
c      integer adim, bdim, cdim, ddim  
      integer m1, m2, n1, n2, r1, r2, s1, s2
      integer i, j, n, m, r, s
      integer a,b,c,d
      integer iout, jout 

      integer num_to_do
      integer nints 
      integer nalpha_pack, npcoeff_pack
      integer ncsum, next, nfirst
      integer me, ierr
      integer nc1, nc2, nd1, nd2 

c      integer imin, zmin, iblk, zblk

c      double precision x1,y1,z1
c      double precision x2,y2,z2
c      double precision x3,y3,z3
c      double precision x4,y4,z4

c     double precision coords(3,*), coeffs(*), alphas(*)
c      double precision tcoords(3,*)
      double precision integrals(a1:a2,b1:b2,c1:c2,d1:d2) 
      double precision t2old(a1:a2,1:i2,c1:c2,1:j2) 
      double precision t2new(b1:b2,1:ii2,d1:d2,1:jj2) 
      double precision max_int, etemp   

c     double precision scr(*)   
c     integer iscr(*)

c      integer ccbeg(*), ccend(*)
c      integer ixalpha(*), ixpcoef(*) 

c      integer max_dim_coeff
c      parameter (max_dim_coeff = 5000)
c      integer ccbeg_pack(max_dim_coeff), ccend_pack(max_dim_coeff)
c      integer*8 ccbeg_pack64(max_dim_coeff), ccend_pack64(max_dim_coeff)
c      double precision alpha_pack(max_dim_coeff), 
c     *                 pcoeff_pack(max_dim_coeff)
c      integer*8 arg64(25)

c VFL TO BE COMPLETED       common /Imax_com/sz_max(nshells,nshells), delta 
c      double precision sz_max, delta
c      double precision itol, bmax, dtemp, emax    

c     common /d2int_com/jatom, jx, jcenter
c     integer jatom, jx, jcenter  
      integer one 

      integer (C_INT) nshells, nalpha_occupied, nbeta_occupied
      integer (C_INT) nalpha_virtual, nbeta_virtual
      integer (C_INT) intSpherical  


c ----------------------------------------------------------------------
c  END_NFPS 
      TYPE(C_PTR) :: pnalpha, pend_nfps 
      integer, pointer :: nalpha(:) 
      integer, pointer :: end_nfps(:) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  NCFPS 
c      TYPE(C_PTR) :: pishells, pncfps 
c      integer, pointer :: ishells(:) 
c      integer, pointer :: ncfps(:) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  NPFPS 
c      TYPE(C_PTR) :: pnpfps 
c      integer, pointer :: npfps(:) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  NPFPS 
c      TYPE(C_PTR) :: pindex_cc  
c      integer, pointer :: index_cc(:) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  INDX_CC   
c      TYPE(C_PTR) :: pindx_cc    
c      integer, pointer :: indx_cc(:) 
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  IVANGMOM  
c      TYPE(C_PTR) :: pivangmom   
c      integer, pointer :: ivangmom(:) 
c ----------------------------------------------------------------------

c      adim = a2-a1+1
c      bdim = b2-b1+1
c      cdim = c2-c1+1
c      ddim = d2-d1+1 

c Get the predefined data 

      one = 1 

c ----------------------------------------------------------------------
c  END_NFPS 
      call predefined_int_array("end_nfps"//C_NULL_CHAR, one, 
     *                                   pnalpha, pend_nfps) 
      call c_f_pointer(pnalpha, nalpha, [1]) 
      call c_f_pointer(pend_nfps, end_nfps, nalpha) 
c     write(6,*) ' END_NFPS', nalpha(1), (end_nfps(i), i=1, 
c    *                                           nalpha(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  NCFPS 
c      call predefined_int_array("ncfps"//C_NULL_CHAR, one, 
c     *                                   pishells, pncfps) 
c      call c_f_pointer(pishells, ishells, [1]) 
c      call c_f_pointer(pncfps, ncfps, ishells) 
c     write(6,*) ' NCFPS', ishells(1), (ncfps(i), i=1, 
c    *                                           ishells(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  NPFPS 
c      call predefined_int_array("npfps"//C_NULL_CHAR, one, 
c     *                                   pishells, pnpfps) 
c      call c_f_pointer(pishells, ishells, [1]) 
c      call c_f_pointer(pnpfps, npfps, ishells) 
c     write(6,*) ' NCFPS', ishells(1), (npfps(i), i=1, 
c    *                                           ishells(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  INDX_CC  
c      call predefined_int_array("indx_cc"//C_NULL_CHAR, one, 
c     *                                   pishells, pindx_cc) 
c      call c_f_pointer(pishells, ishells, [1]) 
c      call c_f_pointer(pindx_cc, indx_cc, ishells) 
c     write(6,*) ' INDX_CC', ishells(1), (indx_cc(i), i=1, 
c    *                                           ishells(1))  
c ----------------------------------------------------------------------

c ----------------------------------------------------------------------
c  IVANGMOMO   
c      call predefined_int_array("ivangmom"//C_NULL_CHAR, one, pishells, 
c     *                                   pivangmom) 
c      call c_f_pointer(pishells, ishells, [1]) 
c      call c_f_pointer(pivangmom, ivangmom, ishells) 
c     write(6,*) ' IVANGMOMOM', ishells(1), (ivangmom(i), i=1, 
c    *                                           ishells(1))  
c ----------------------------------------------------------------------

      nshells = int_constant("nshells"//C_NULL_CHAR)
c     nalpha_occupied = int_constant("nalpha_occupied"//C_NULL_CHAR)
c     nbeta_occupied = int_constant("nbeta_occupied"//C_NULL_CHAR)
c     nalpha_virtual = int_constant("nalpha_virtual"//C_NULL_CHAR)
c     nbeta_virtual = int_constant("nbeta_virtual"//C_NULL_CHAR)

c Set the integral tolerance 

c Skip screening for now 
c     call set_itol(delta,itol)
c      itol = -1000. 

c-----------------------------------------------------------------------
c   Find the shell blocks for which we shall loop through.
c-----------------------------------------------------------------------

         call lookup_shell(end_nfps, nshells, a1, m1)
         call lookup_shell(end_nfps, nshells, a2, m2)
         call lookup_shell(end_nfps, nshells, b1, n1)
         call lookup_shell(end_nfps, nshells, b2, n2)
         call lookup_shell(end_nfps, nshells, c1, r1)
         call lookup_shell(end_nfps, nshells, c2, r2)
         call lookup_shell(end_nfps, nshells, d1, s1)
         call lookup_shell(end_nfps, nshells, d2, s2)

         do m = m1, m2
            if (m .eq. 1) then
               aa1 = 1
            else
               aa1 = end_nfps(m-1) + 1
            endif
            aa2 = end_nfps(m)

c            x1 = tcoords(1,m)
c            y1 = tcoords(2,m)
c            z1 = tcoords(3,m)
         do n = n1, n2
            if (n .eq. 1) then
               bb1 = 1
            else
               bb1 = end_nfps(n-1) + 1
            endif
            bb2 = end_nfps(n)

c            x2 = tcoords(1,n)
c            y2 = tcoords(2,n)
c            z2 = tcoords(3,n)
         do r = r1, r2
            if (r .eq. 1) then
               cc1 = 1
            else
               cc1 = end_nfps(r-1) + 1
            endif
            cc2 = end_nfps(r)

c            x3 = tcoords(1,r)
c            y3 = tcoords(2,r)
c            z3 = tcoords(3,r)
         do s = s1, s2
            if (s .eq. 1) then
               dd1 = 1
            else
               dd1 = end_nfps(s-1) + 1
            endif
            dd2 = end_nfps(s)

c-----------------------------------------------------------------------
c   Determine the largest density element.
c-----------------------------------------------------------------------

c           emax = 1.0 
c           bmax = 1000000.0 ! VFL TO DO 
c           bmax = sz_max(m,n)*sz_max(r,s) 
c           bmax = dsqrt(bmax)*emax  

c           if (bmax .lt. itol) go to 30 
c               x4 = tcoords(1,s)
c               y4 = tcoords(2,s)
c               z4 = tcoords(3,s)

c---------------------------------------------------------------------------
c   Determine the maximum integral in the shell quad  
c---------------------------------------------------------------------------

      max_int = 10.0 
c      do d = d1, d2 
c      do c = c1, c2 
c      do b = b1, b2 
c      do a = a1, a2 
c         if ((a .ge. aa1 .and. a .le. aa2) .and.
c     *       (b .ge. bb1 .and. b .le. bb2) .and.
c     *       (c .ge. cc1 .and. c .le. cc2) .and.
c     *       (d .ge. dd1 .and. d .le. dd2)) then  
c             if (dabs(integrals(a,b,c,d)) .gt. max_int) 
c     *                 max_int = dabs(integrals(a,b,c,d))  
c         endif 
c      enddo 
c      enddo 
c      enddo 
c      enddo 

c     write(6,*) ' MAX_INT = ', max_int

c             call return_maxint(nalpha_occupied, nbeta_occupied, 
c    *                             a1,a2,b1,b2,
c    *                             c1,c2,d1,d2,
c    *                             integrals, 
c    *                             scr(nfirst),   
c    *                             aa1,aa2,bb1,bb2,cc1,cc2,dd1,dd2
c    *                             )
 
      do d = d1, d2 
      do c = c1, c2 
      do b = b1, b2 
      do a = a1, a2 
         if ((a .ge. aa1 .and. a .le. aa2) .and.
     *       (b .ge. bb1 .and. b .le. bb2) .and.
     *       (c .ge. cc1 .and. c .le. cc2) .and.
     *       (d .ge. dd1 .and. d .le. dd2) .and. 
     *       (max_int .gt. 1.0d-15)) then  
             etemp = integrals(a,b,c,d) 
             do iout = 1, i2 
             do jout = 1, j2 
                t2new(b,iout,d,jout) = t2new(b,iout,d,jout) 
     *                               + etemp * t2old(a,iout,c,jout) 
c    *          + integrals(a,b,c,d) * t2old(a,iout,c,jout) 
             enddo 
             enddo 
         endif 
      enddo 
      enddo 
      enddo 
      enddo 

30       continue 
         enddo   ! s
20       continue 
         enddo   ! r

10       continue 
         enddo   ! n
100      continue 
         enddo   ! m
 
      return
      end
