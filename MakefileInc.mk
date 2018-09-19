#LINK= $(CXX)

# optimized
#CXXFLAGS= 
##CXXFLAGS= $(CXXFLAGS_PVFMM) 
#LINKFLAGS= $(CXXFLAGS) 
#LINKFLAGS= $(CXXFLAGS) $(LDLIBS_PVFMM) $(Trilinos_EXTRA_LD_FLAGS) #-lm -ldl

# remove some flags for debugging
# if Trilinos and pvfmm are compiled with ipo, removing this may cause linking failures

# debug
DEBUGMODE:= no

# debug flags
# CXXFLAGS += -DFMMTIMING 
# CXXFLAGS += -DFMMDEBUG
# CXXFLAGS += -DDEBUGLCPCOL 
# CXXFLAGS += -DZDDDEBUG 
# CXXFLAGS += -DIFPACKDEBUG 
# CXXFLAGS += -DMYDEBUGINFO 
# CXXFLAGS += -DHYRDRODEBUG

#ifeq ($(DEBUGMODE), yes)
#CXXFLAGS:= $(subst -O3, ,$(CXXFLAGS))
#LINKFLAGS:= $(subst -O3, ,$(LINKFLAGS))
#CXXFLAGS := $(CXXFLAGS) -O0 -g
#LINKFLAGS := $(LINKFLAGS) -O0 -g
#else
#CXXFLAGS:= $(CXXFLAGS) -DNDEBUG
#LINKFLAGS:= $(LINKFLAGS) -DNDEBUG
#endif

# SCTL Configs

# almost always yes
#WITHMPI ?= yes

#ifeq ($(WITHMPI), yes)
#CXXFLAGS += -DSCTL_HAVE_MPI
#endif

## CXXFLAGS += -DSCTL_MEMDEBUG # Enable memory checks
#CXXFLAGS += -DSCTL_GLOBAL_MEM_BUFF=256 # Global memory buffer size in MB
## CXXFLAGS += -DSCTL_PROFILE=5 -DSCTL_VERBOSE # Enable profiling
## CXXFLAGS += -DSCTL_QUAD_T=__float128 # Enable quadruple precision

#CXXFLAGS += -DSCTL_HAVE_BLAS # use BLAS
#CXXFLAGS += -DSCTL_HAVE_LAPACK # use LAPACK
#CXXFLAGS += -DSCTL_HAVE_FFTW
## CXXFLAGS += -DSCTL_HAVE_FFTWF

# CXXFLAGS += -mkl -DSCTL_HAVE_BLAS -DSCTL_HAVE_LAPACK # use MKL BLAS and LAPACK
# CXXFLAGS += -lblas -DSCTL_HAVE_BLAS # use BLAS
# CXXFLAGS += -llapack -DSCTL_HAVE_LAPACK # use LAPACK
# CXXFLAGS += -lfftw3 -DSCTL_HAVE_FFTW
# CXXFLAGS += -lfftw3f -DSCTL_HAVE_FFTWF
# CXXFLAGS += -lfftw3l -DSCTL_HAVE_FFTWL
