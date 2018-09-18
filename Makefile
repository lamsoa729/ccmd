include ./MakefileInc.mk

SRCDIR = src
OBJDIR = obj
BINDIR = bin
SRCEXT = cpp
LIBDIR = lib
INCDIR = include

#COMPILE_FLAGS = -std=c++11
#RCOMPILE_FLAGS = -D NDEBUG -O2 -march=native -g
#DCOMPILE_FLAGS = -D DEBUG -O0 -g
#LINK_FLAGS =
#RLINK_FLAGS =
#DLINK_FLAGS =


#ifeq ($(THREADING),iomp)
#        COMPILE_FLAGS += -openmp -parallel-source-info=2
#        LINK_FLAGS += -openmp -parallel-source-info=2
#else 
#        COMPILE_FLAGS += -fopenmp
#        LINK_FLAGS += -fopenmp
#endif

#ifeq ($(NOGRAPH),true)
#        COMPILE_FLAGS += -D NOGRAPH
#        LINK_FLAGS += -D NOGRAPH
#endif

UNAME_S:=$(shell uname -s)
#ifeq ($(LOC),ARL)
#        CC = gcc-8
#        CXX = g++-8
#        GSLINCS = `pkg-config --cflags gsl`
#        GSLLIBS = `pkg-config --libs gsl`
#        FFTWINCS = `pkg-config --cflags fftw3`
#        GLFW3INCS = -I/opt/X11/include -I/usr/X11R6/include
#        GLFW3LIBS = -L/opt/X11/lib -L/usr/local/Cellar/glfw/3.2.1/lib -lglfw -framework OpenGL -lglew
#        YAMLINCS = -I./Lib/yaml-cpp/include
#        YAMLLIBS = -Wl,-rpath,./Lib/yaml-cpp/osxlib -L./Lib/yaml-cpp/osxlib/ -lyaml-cpp
#        PNGLIBS = `/usr/local/bin/libpng-config --ldflags`
#        INCLUDES = $(GLFW3INCS) $(YAMLINCS) $(GSLINCS) $(FFTWINCS)
#        LIBS = $(PNGLIBS) $(GLFW3LIBS) $(YAMLLIBS) $(GSLLIBS)
#else ifeq ($(LOC),CJE)
#        CC = gcc-7
#        CXX = g++-7
#        GSLINCS = `pkg-config --cflags gsl`
#        GSLLIBS = `pkg-config --libs gsl`
#        FFTWINCS = `pkg-config --cflags fftw3`
#        GLFW3INCS = -I/opt/X11/include -I/usr/X11R6/include
#        GLFW3LIBS = -L/opt/X11/lib -L/usr/local/Cellar/glfw/3.2.1/lib -lglfw3 -framework OpenGL -lglew
#        YAMLINCS = -I./Lib/yaml-cpp/include
#        YAMLLIBS = -Wl,-rpath,./Lib/yaml-cpp/osxlib -L./Lib/yaml-cpp/osxlib/ -lyaml-cpp
#        PNGLIBS = `/usr/local/bin/libpng-config --ldflags`
#        INCLUDES = $(GLFW3INCS) $(YAMLINCS) $(GSLINCS) $(FFTWINCS)
#        LIBS = $(PNGLIBS) $(GLFW3LIBS) $(YAMLLIBS) $(GSLLIBS)
#else ifeq ($(UNAME_S),Darwin)
#        CC = gcc-7
#        CXX = g++-7
#        GSLINCS = `pkg-config --cflags gsl`
#        GSLLIBS = `pkg-config --libs gsl`
#        FFTWINCS = `pkg-config --cflags fftw3`
#        GLFW3INCS = -I/opt/X11/include -I/usr/X11R6/include
#        GLFW3LIBS = -L/opt/X11/lib -L/usr/local/Cellar/glfw/3.2.1/lib -lglfw -framework OpenGL -lglew
#        YAMLINCS = -I./Lib/yaml-cpp/include
#        YAMLLIBS = -Wl,-rpath,./Lib/yaml-cpp/osxlib -L./Lib/yaml-cpp/osxlib/ -lyaml-cpp
#        PNGLIBS = `/usr/local/bin/libpng-config --ldflags`
#        INCLUDES = $(GLFW3INCS) $(YAMLINCS) $(GSLINCS) $(FFTWINCS)
#else ifeq ($(LOC),Janus)
#        GSLINCS = `pkg-config --cflags gsl`
#        GSLLIBS = `pkg-config --libs gsl`
#        GLFW3INCS =
#        GLFW3LIBS =
#        FFTWINCS = `pkg-config --cflags fftw3`
#        YAMLINCS = -I./januslib/yaml-cpp/include
#        YAMLLIBS = -Wl,-rpath,./januslib/yaml-cpp/static -L./januslib/yaml-cpp/static -lyaml-cpp
#        PNGLIBS = `/usr/bin/libpng-config --ldflags`
#        INCLUDES = $(GLFW3INCS) $(YAMLINCS) $(GSLINCS) $(FFTWINCS)
#        LIBS = $(GLFW3LIBS) $(YAMLLIBS) $(GSLLIBS) $(PNGLIBS)
#else ifeq ($(LOC),Summit)
#        GSLINCS = `pkg-config --cflags gsl`
#        GSLLIBS = `pkg-config --libs gsl`
#        GLFW3INCS =
#        GLFW3LIBS =
#        FFTWINCS = `pkg-config --cflags fftw3`
#        YAMLINCS = -I./Lib/yaml-cpp/include
#        YAMLLIBS = -Wl,-rpath,./Lib/yaml-cpp/summitlib -L./Lib/yaml-cpp/summitlib/ -lyaml-cpp
#        PNGLIBS = `/usr/bin/libpng-config --ldflags`
#        INCLUDES = $(GLFW3INCS) $(YAMLINCS) $(GSLINCS) $(FFTWINCS)
#        LIBS = $(GLFW3LIBS) $(YAMLLIBS) $(GSLLIBS) $(PNGLIBS)
#else ifeq ($(LOC),Pando)
#        GSLINCS = `pkg-config --cflags gsl`
#        GSLLIBS = `pkg-config --libs gsl`
#        GLFW3INCS =
#        GLFW3LIBS =
#        FFTWINCS = `pkg-config --cflags fftw3`
#        YAMLINCS = -I./pandolib/yaml-cpp/include
#        YAMLLIBS = -Wl,-rpath,./pandolib/yaml-cpp/static -L./pandolib/yaml-cpp/static -lyaml-cpp
#        PNGLIBS = `/usr/bin/libpng-config --ldflags`
#        INCLUDES = $(GLFW3INCS) $(YAMLINCS) $(GSLINCS) $(FFTWINCS)
#        LIBS = $(GLFW3LIBS) $(YAMLLIBS) $(GSLLIBS) $(PNGLIBS)
#else
#        GSLINCS = -I/usr/local/include
#        GSLLIBS = -L/usr/local/libs -lgsl -lgslcblas -lm
#        GLFW3INCS = -I/home/cedelmaier/common/glfw/include
#        GLFW3LIBS = -L/home/cedelmaier/common/glfw/build/src -lglfw3 -lGLEW -lGLU -lGL -lX11 -lXxf86vm -lpthread -ldl -lXrandr -lXi -lXcursor -lXinerama
#        #YAMLINCS = -I/home/cedelmaier/common/yaml-cpp/include
#        #YAMLLIBS = -Wl,-rpath,/home/cedelmaier/common/yaml-cpp/build -L/home/cedelmaier/common/yaml-cpp/build -lyaml-cpp
#        YAMLINCS = -I./rumorlib/yaml-cpp/include
#        YAMLLIBS = -Wl,-rpath,./rumorlib/yaml-cpp/static -L./rumorlib/yaml-cpp/static -lyaml-cpp
#        PNGLIBS = `/usr/bin/libpng-config --ldflags`
#        INCLUDES = $(GLFW3INCS) $(YAMLINCS) $(GSLINCS)
#        LIBS = $(GLFW3LIBS) $(YAMLLIBS) $(GSLLIBS) $(PNGLIBS)
#endif

print-%: ; @echo $*=$($*)

SHELL = /bin/bash
SYSLIB =	
SIZE =	size

.SUFFIXES:

#ifneq ($(LIBS),)
#        COMPILE_FLAGS += $(shell pkg-config --cflags $(LIBS))
#        LINK_FLAGS += $(shell pkg-config --libs $(LIBS))
#endif

# Special stuff for intel compiler
#CC=$(CXX)
#ifeq ($(CC),icpc)
#        COMPILE_FLAGS += -Wno-deprecated
#        #RCOMPILE_FLAGS += -openmp -DBOB_OMP
#else
#        COMPILE_FLAGS += -Wno-deprecated-declarations -Wno-deprecated
#        #RCOMPILE_FLAGS += -fopenmp -DBOB_OMP
#endif

# Combine compiler and linker flags
#ifeq ($(CFG),release)
#        export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(RCOMPILE_FLAGS)
#        export LDFLAGS := $(LDFLAGS) $(LINK_FLAGS) $(RLINK_FLAGS)
#else
#        export CXXFLAGS := $(CXXFLAGS) $(COMPILE_FLAGS) $(DCOMPILE_FLAGS)
#        export LDFLAGS := $(LDFLAGS) $(LINK_FLAGS) $(DLINK_FLAGS)
#endif

# build information on all sources
ifeq ($(UNAME_S),Darwin)
	SOURCES = $(shell find $(SRCDIR) -name '*.$(SRCEXT)' | sort -k 1nr | cut -f2-)
else
	SOURCES = $(shell find $(SRCDIR) -name '*.$(SRCEXT)' -printf '%T@\t%p\n' \
			  										| sort -k 1nr | cut -f2-)
endif

# fallback case
rwildcard = $(foreach d, $(wildcard $1*), $(call rwildcard,$d/,$2) \
									$(filter $(subst *,%,$2), $d))
ifeq ($(SOURCES),)
	SOURCES := $(call rwildcard, $(SRCDIR), *.$(SRCEXT))
endif


CCMD_SRC = $(SRCDIR)/ccmd_main.cpp
MAIN_SOURCES = $(CCMD_SRC)
# Now we have to figure out which we are building of the program list, since that matters
# for things like not compiling more than one main
#NEWAGEBOB_SRC = $(SRCDIR)/newagebob.cpp
#SPINDLE_ANALYSIS_SRC = $(SRCDIR)/spindle_analysis.cpp
#DIFFUSION_ANALYSIS_FREE_SRC = $(SRCDIR)/diffusion_analysis_free.cpp
#XLINK_ANALYSIS_SRC = $(SRCDIR)/xlink_analysis.cpp

#MAIN_SOURCES = $(NEWAGEBOB_SRC)\
#               $(SPINDLE_ANALYSIS_SRC)\
#               $(DIFFUSION_ANALYSIS_FREE_SRC)\
#               $(XLINK_ANALYSIS_SRC)

# These are the common sources
SRCS = $(filter-out $(MAIN_SOURCES) $(EXCLUDE_SOURCES), $(SOURCES))

EXE := ccmd.X
OBJ = $(SRCS:$(SRCDIR)/%.$(SRCEXT)=$(OBJDIR)/%.o)
CCMD_OBJ = $(CCMD_OBJ:$(SRCDIR)/%.$(SRCEXT)=$(OBJDIR)/%.o)
#SPINDLE_ANALYSIS_OBJ= $(SPINDLE_ANALYSIS_SRC:$(SRCDIR)/%.$(SRCEXT)=$(OBJDIR)/%.o)
#DIFFUSION_ANALYSIS_FREE_OBJ= $(DIFFUSION_ANALYSIS_FREE_SRC:$(SRCDIR)/%.$(SRCEXT)=$(OBJDIR)/%.o)
#XLINK_ANALYSIS_OBJ = $(XLINK_ANALYSIS_SRC:$(SRCDIR)/%.$(SRCEXT)=$(OBJDIR)/%.o)

.PHONY: dirs
dirs:
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

.PHONY: clean
clean:
	rm -f -r $(OBJDIR)
	rm -f -r $(BINDIR)
	rm -f ccmd.X

.PHONY : test
test :
	echo "Hello testable world"

DEPS = $(OBJ:.o=.d)

# add dependencies
-include $(DEPS)

# source file rules
#$(EXE): $(OBJ)
#        $(LINK) $(OBJ)  -o $(EXE) $(LINKFLAGS) $(SYSLIB) $(LIBRARY_DIRS) $(LIBRARIES)
#        $(SIZE) $(EXE)

$(BINDIR)/ccmd.X: $(OBJ) $(CCMD_OBJ) 
	 $(CXX) $^ -o $@ $(LINKFLAGS) $(SYSLIB) $(LIBRARY_DIRS) $(LIBRARIES) $(SIZE) 

ccmd: dirs $(BINDIR)/ccmd.X;cp $(BINDIR)/ccmd.X ccmd.X


#spindle_analysis: dirs $(BINDIR)/spindle_analysis; cp $(BINDIR)/spindle_analysis spindle_analysis

#diffusion_analysis_free: dirs $(BINDIR)/diffusion_analysis_free; cp $(BINDIR)/diffusion_analysis_free diffusion_analysis_free

#xlink_analysis: dirs $(BINDIR)/xlink_analysis; cp $(BINDIR)/xlink_analysis xlink_analysis

#$(BINDIR)/newagebob: $(OBJECTS) $(NEWAGEBOB_OBJ)
#        $(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)

#$(BINDIR)/spindle_analysis: $(OBJECTS) $(SPINDLE_ANALYSIS_OBJ)
#        $(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)

#$(BINDIR)/diffusion_analysis_free: $(OBJECTS) $(DIFFUSION_ANALYSIS_FREE_OBJ)
#        $(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)

#$(BINDIR)/xlink_analysis: $(OBJECTS) $(XLINK_ANALYSIS_OBJ)
#        $(CXX) $^ -o $@ $(LDFLAGS) $(LIBS)


#$(OBJDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
#        $(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@
