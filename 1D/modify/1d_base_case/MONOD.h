C $Header: /u/gcmpack/MITgcm_contrib/darwin2/pkg/monod/MONOD.h,v 1.5 2012/05/31 21:08:25 stephd Exp $
C $Name:  $

c MONOD.h
c description: Key parameter arrays for generalized ecosystem model
c      Mick Follows, Scott Grant Fall/Winter 2005
c      Stephanie Dutkiewicz Spring/Summer 2006
c
c
c npmax = no of "functional groups" of phytoplankton
c nzmax = no of "functional groups" of zooplankton
c
c
c NOTE: list not complete!!
c mu = max growth rate (s-1)
c ksat = half sat coeff, phyto specific for each nutrient
c ksatlight = half sat coeff wrt light, phyto specific 
c graze = grazing rate, phyto specific for each zooplankton
c mortzoo = mortality rate for each zooplankton
c mortzoo2 = quadratic mortality rate for each zooplankton
c wsink = sinking speed, phyto specific
c R_XY = stoichiometric ratios of nutrients in phytoplankton
c        specific to each functional group, relative to Phos
c physize = size class of phytoplankton; 0.0="small", 1.0="big"
c diacoc: 1.0 uses silica, 0.0 does not use silica
c diacoc: 2.0 uses PIC, 0.0 does not use PIC
c diazotrph: 1.0 fixes nitrogen, 0.0 does not fix nitrogen
c zoosize = size class of zooplankton; 0.0="small", 1.0="big"
c ExportFracZ(nzmax) = fraction of Z mortality sinking out:
c                      rest remineralizes locally 
c Kpremin_xx = remin rate constant for particulate detritus
c ngroups = tracks how many different "functional groups" of phyto
c           have been tried


         COMMON/darwin_ecoparam/mu,ksatPO4,ksatNO3,ksatNO2,ksatNH4,
     &          ksatSi,ksatFeT,ksatPAR,
     &          mortzoo,wsink,R_NP,R_FeP,R_SiP,R_PC,R_PICPOC, physize,
     &          diacoc,diazotroph,zoosize,ExportFracZ,
     &          Kpremin_P, Kpremin_N, Kpremin_Fe, Kpremin_Si,
     &          sig1,sig2,sig3,
     &          phytoTempCoeff, phytoTempExp1, 
     &          phytoTempExp2, phytoTempOptimum, phytoDecayPower,
     &          zooTempCoeff, zooTempExp, zooTempOptimum, kinhib,
     &          diatomgraz, coccograz, olargegraz,
     &          mortphy, ExportFracP,
     &          mortzoo2,
     &          Smallgrow, Biggrow, Smallmort, Bigmort,
     &          Smallgrowrange, Biggrowrange, Smallmortrange, 
     &          Bigmortrange,
     &          Smallexport, Bigexport,
     &          smallksatpar, smallksatparstd,
     &          smallkinhib, smallkinhibstd,
     &          Bigksatpar, Bigksatparstd,
     &          Bigkinhib, Bigkinhibstd,
     &          tempcoeff1, tempcoeff2_small, 
     &          tempcoeff2_big, tempcoeff3,
     &          tempmax, temprange, tempnorm, tempdecay,
     &          SmallPsat, BigPsat, ProcPsat,
     &          SmallPsatrange, BigPsatrange, ProcPsatrange,
     &          prochlPsat,
     &          UniDzPsat, UniDzPsatrange, 
     &          depthdenit, o2crit, denit_np,
     &          M_poc, M_caco3, M_sio3, M_fe,
     &          omega_pcaco3, omega_psio3, omega_dust,
     &          lambda_poc, lambda_caco3,
     &          lambda_sio3, lambda_dust,
     &          lambda_hard,
     &          f_pcaco3_hard, f_psio3_hard, 
     &          Qsi_diat,
     &          f_dust_bio, f_dust_hard,
     &          Kpremin_hard, Kdissc_hard,
     &          zeu, zeuFe,
     &          Kpremin_DUSTs, Kpremin_DUSTh,
#ifdef OLD_GRAZE
     &          graze,
     &          kgrazesat,
     &          GrazeEffsmall, GrazeEffbig, GrazeFast, GrazeSlow,
#else
     &          grazemax, palat, asseff,
     &          kgrazesat,
     &          GrazeEfflow, GrazeEffmod, GrazeEffhi,
     &          GrazeFast, GrazeSlow,
     &          palathi, palatlo,
     &          phygrazmin,
     &          ExportFracGraz,
     &          ExGrazfracbig, ExGrazfracsmall,
     &          hollexp,
#endif
     &          ZoomortSmall, ZoomortBig, ZooexfacSmall, ZooexfacBig,
     &          ZoomortSmall2, ZoomortBig2,
     &          val_R_SiP_diatom, val_R_NP_diaz, val_RFeP_diaz,
     &          val_R_NP, val_RFeP, val_R_PC,
     &          val_R_PICPOC,
     &          ksatNH4fac, ksatNO2fac, val_ksatsi,
     &          ngrowfac, ilight,
     &          phymin, PAR0, diaz_growfac,
     &          phyto_esd, phyto_vol,
     &          zoo_esd, zoo_vol
#ifdef IRON_SED_SOURCE
     &         ,depthfesed,fesedflux,fesedflux_pcm
#endif
#ifdef PART_SCAV
     &         ,scav_rat, scav_inter, scav_exp
#endif
#ifdef ALLOW_CDOM
     &         , fraccdom, cdomdegrd, cdombleach, PARcdom
     &         , rnp_cdom, rfep_cdom, rcp_cdom
     &         , cdomcoeff
#endif
     &         ,nsource,ngroups
    
         _RL mu(npmax)
         _RL ksatPO4(npmax)
         _RL ksatNO3(npmax)
         _RL ksatNO2(npmax)
         _RL ksatNH4(npmax)
         _RL ksatSi(npmax)
         _RL ksatFeT(npmax)
         _RL ksatPAR(npmax)
         _RL mortzoo(nzmax)
         _RL mortzoo2(nzmax)
         _RL wsink(npmax)
         _RL R_NP(npmax)
         _RL R_FeP(npmax)
         _RL R_SiP(npmax)
         _RL R_PC(npmax)
         _RL R_PICPOC(npmax)
         _RL physize(npmax)
         _RL diacoc(npmax)
         _RL diazotroph(npmax)
         _RL zoosize(nzmax)
         _RL ExportFracZ(nzmax)
         _RL Kpremin_P
         _RL Kpremin_N
         _RL Kpremin_Fe
         _RL Kpremin_Si
         _RL phytoTempCoeff(npmax)
         _RL phytoTempExp1(npmax)
         _RL phytoTempExp2(npmax)     
         _RL phytoTempOptimum(npmax)
         _RL phytoDecayPower(npmax)
         _RL zooTempCoeff(nzmax)
         _RL zooTempExp(nzmax) 
         _RL zooTempOptimum(nzmax)
         _RL diatomgraz, coccograz, olargegraz
         _RL kinhib(npmax)
         _RL mortphy(npmax)
         _RL ExportFracP(npmax)
         _RL Smallgrow, Biggrow
         _RL Smallmort, Bigmort
         _RL Smallgrowrange, Biggrowrange
         _RL Smallmortrange, Bigmortrange
         _RL Smallexport, Bigexport
         _RL smallksatpar, smallksatparstd
         _RL smallkinhib, smallkinhibstd
         _RL tempcoeff1, tempcoeff2_big
         _RL tempcoeff2_small, tempcoeff3
         _RL tempmax, temprange, tempnorm,tempdecay
         _RL Bigksatpar, Bigksatparstd
         _RL Bigkinhib, Bigkinhibstd
         _RL SmallPsat, BigPsat, ProcPsat
         _RL SmallPsatrange, BigPsatrange, ProcPsatrange
         _RL prochlPsat
         _RL UniDzPsat, UniDzPsatrange
         _RL depthdenit
         _RL o2crit
         _RL denit_np
         _RL ksatNH4fac, ksatNO2fac
         _RL sig1,sig2,sig3
         _RL val_ksatsi
         _RL M_poc, M_caco3, M_sio3, M_fe
         _RL omega_pcaco3, omega_psio3, omega_dust
         _RL lambda_poc, lambda_caco3
         _RL lambda_sio3, lambda_dust
         _RL lambda_hard
         _RL f_pcaco3_hard
         _RL f_psio3_hard 
         _RL Qsi_diat
         _RL f_dust_bio, f_dust_hard
         _RL Kpremin_hard, Kdissc_hard
         _RL zeu, zeuFe
         _RL Kpremin_DUSTs, Kpremin_DUSTh
#ifdef OLD_GRAZE
         _RL graze(npmax,nzmax)
         _RL kgrazesat
         _RL GrazeEffsmall, GrazeEffbig, GrazeFast, GrazeSlow
#else
         _RL grazemax(nzmax)
         _RL palat(npmax,nzmax)
         _RL asseff(npmax,nzmax)
         _RL kgrazesat
         _RL GrazeEfflow, GrazeEffmod, GrazeEffhi
         _RL GrazeFast, GrazeSlow
         _RL palathi, palatlo
         _RL phygrazmin
         _RL ExportFracGraz(nzmax)
         _RL ExGrazfracbig, ExGrazfracsmall
         _RL hollexp
#endif
         _RL ZoomortSmall, ZoomortBig, ZooexfacSmall, ZooexfacBig
         _RL ZoomortSmall2, ZoomortBig2
         _RL val_R_SiP_diatom, val_R_NP_diaz, val_RFeP_diaz,
     &          val_R_NP, val_RFeP, val_R_PC, val_R_PICPOC
         _RL ngrowfac,ilight
         _RL phymin
         _RL PAR0
         _RL phyto_esd(npmax)
         _RL phyto_vol(npmax)
         _RL zoo_esd(nzmax)
         _RL zoo_vol(nzmax)
#ifdef IRON_SED_SOURCE
         _RL depthfesed, fesedflux, fesedflux_pcm
#endif
#ifdef PART_SCAV
         _RL scav_rat, scav_inter, scav_exp
#endif
#ifdef ALLOW_CDOM
         _RL fraccdom, cdomdegrd, cdombleach, PARcdom
         _RL rnp_cdom, rfep_cdom, rcp_cdom
         _RL cdomcoeff
#endif
         INTEGER nsource(npmax)
         INTEGER ngroups


         COMMON/darwin_detritus/wp_sink,wn_sink,wfe_sink,wsi_sink,
     &          Kdop,Kdon,KdoFe,SmallSink,BigSink,
     &          Knita, Knitb
         _RL wp_sink
         _RL wn_sink
         _RL wfe_sink
         _RL wsi_sink
         _RL Kdop
         _RL Kdon
         _RL KdoFe
         _RL SmallSink
         _RL BigSink
         _RL Knita
         _RL Knitb
         _RL diaz_growfac

c    k0, kc         - light coefficients
         COMMON/darwin_lightparam/ k0, kc, parfrac, parconv
         _RL k0, kc, parfrac, parconv

c    chlpmax        - chl:p max ratio
c    chlpmin        - chl:p min ratio
c    istar          - photoadaptation light limit
         COMMON/darwin_chlparam/ chlpmax, chlpmin, istar
         _RL chlpmax, chlpmin, istar

         COMMON/darwin_diags_param/
     &          diver_thresh0, diver_thresh1,
     &          diver_thresh2, diver_thresh3,
     &          diver_thresh4, shannon_thresh

         _RL diver_thresh0, diver_thresh1
         _RL diver_thresh2, diver_thresh3
         _RL diver_thresh4, shannon_thresh

#ifdef GEIDER
c ANNA geider by mQyield instead of alpha
        COMMON/geider_vars/
     &         pcmax, alphachl, chl2cmax, chl2cmin,
     &         mQyield,aphy_chl_ave,
     &         inhibcoef_geid, inhibcoef_geid_val,
#ifdef WAVEBANDS
     &         alpha_mean,
#endif
#ifdef DYNAMIC_CHL
     &         acclimtimescl,
#endif
c     &         Bigalphachl, Bigalphachlrange,
c     &         Smallalphachl, Smallalphachlrange,
     &         BigmQyield, BigmQyieldrange,
     &         SmallmQyield, SmallmQyieldrange,
     &         Bigchl2cmax, Bigchl2cmaxrange,
     &         Smallchl2cmax, Smallchl2cmaxrange
c        _RL phychl(npmax)
         _RL pcmax(npmax)
         _RL alphachl(npmax)
         _RL mQyield(npmax)
         _RL chl2cmax(npmax)
         _RL chl2cmin(npmax)
         _RL inhibcoef_geid(npmax)
         _RL inhibcoef_geid_val
#ifdef WAVEBANDS
         _RL alpha_mean(npmax)
#endif
#ifdef DYNAMIC_CHL
         _RL acclimtimescl
#endif


c         _RL Bigalphachl, Bigalphachlrange,
c     &         Smallalphachl, Smallalphachlrange,
         _RL BigmQyield, BigmQyieldrange,
     &         SmallmQyield, SmallmQyieldrange,
     &         Bigchl2cmax, Bigchl2cmaxrange,
     &         Smallchl2cmax, Smallchl2cmaxrange,
     &         aphy_chl_ave
#endif
#ifdef DAR_DIAG_CHL
      COMMON/DAR_DIAG_CHL_VARS/
     &       Geider_alphachl, Geider_chl2cmin, Geider_chl2cmax
      _RL Geider_alphachl(npmax)
      _RL Geider_chl2cmin(npmax)
      _RL Geider_chl2cmax(npmax)
#endif /* DAR_DIAG_CHL */


#ifdef ALLOW_CARBON
         COMMON/darwin_carbon/ R_OP, wc_sink, wpic_sink,
     &                 Kdoc, Kpremin_C, Kdissc
         _RL R_OP
         _RL wc_sink
         _RL wpic_sink
         _RL Kdoc
         _RL Kpremin_C
         _RL Kdissc
#endif


