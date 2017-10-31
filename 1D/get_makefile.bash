#!/bin/bash
## Note: the environment variable MITGCMROOT needs to be set outside this script
#module load intel-parallel-studio/2017
#module load netcdf-fortran/4.4.4

# VARIABLE NAMES
ROOT='/rigel/ocp/users/tu2140/MITgcm/Southern-Ocean/1D/'
MODS=$ROOT'modify/1d_base_case'
OPTFILE=$ROOT'linux_ia64_ifort+mpi_habanero'
ROOTDIR=$ROOT'source'
GENMAKE=$ROOT'source/tools/genmake2'

# GENERATE MAKE FILE
cd build
${GENMAKE} -mpi -mods=${MODS} -optfile=${OPTFILE} -rootdir=${ROOTDIR}
make depend
make
