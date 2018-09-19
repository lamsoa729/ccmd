include ./MakefileInc.mk # Extra include files if necessary

CXX = mpicxx# Compiler to use
EXE = ccmd.X# Executable function 
SRC_DIR = src# Source file
OBJ_DIR = obj# Object file directory
UNAME_S:=$(shell uname -s) 

print-%: ; @echo $*=$($*) # print function if necessary

SHELL = /bin/bash # What shell to use

SFTPATH:=/usr/local# Where all libraries located on computer are stored

TRNG = $(SFTPATH)/include/trng# Tina's random number generator library
PVFMM = $(SFTPATH)/include/pvfmm# PVFMM library, particle classes and stuff
YAML = lib/yaml-cpp# Yaml-cpp library located in internal library

SRC = $(wildcard $(SRC_DIR)/*.cpp)# Get all cpp source files
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)# List object files from source files

CPPFLAGS += -Iinclude -I$(TRNG)/include -I$(YAML)/include# Preprocessor flags, such as .hpp file.
CFLAGS += -Wall -Wl,-rpath,$(YAML)/osxlib/# Compiler flags,
LDFLAGS += -Llib -L$(SFTPATH)/lib -L$(YAML)/osxlib/# Linker flags,
LDLIBS += -lm -ltrng4 -lyaml-cpp# Third party libraries to link against, see lib

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -MP -MMD -c $< -o $@
#LIBRARIES = $(Trilinos_LIBRARIES) $(Trilinos_TPL_LIBRARIES) $(USERLIBS)

.PHONY: all clean test love-not-war

all: $(EXE)

clean:
	$(RM) $(OBJ)

test:
	echo "Tests not implemented yet"

love-not-war:
	echo "Peace and harmony be upon you"


