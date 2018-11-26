include ./MakefileInc.mk # Extra include files if necessary

CXX = mpicxx# Compiler to use
EXE = ccmd_main# Executable function 
TEST = test-main# Executable test function
SRC_EXT = cpp
SRC_DIR = src# Source file
OBJ_DIR = obj# Object file directory
UNAME_S:=$(shell uname -s) 

print-%: ; @echo $*=$($*) # print function if necessary

SHELL = /bin/bash # What shell to use

SFTPATH:=/usr/local# Where all libraries located on computer are stored

TRNG = $(SFTPATH)/include/trng# Tina's random number generator library
PVFMM = $(SFTPATH)/include/pvfmm# PVFMM library, particle classes and stuff
YAML = lib/yaml-cpp# Yaml-cpp library located in internal library

## Main objects must be kept separate from other object files if you want your project to compile
# Main source files
EXE_SRC = $(SRC_DIR)/$(EXE).$(SRC_EXT)
TEST_SRC = $(SRC_DIR)/$(TEST).$(SRC_EXT)
MAIN_SRCS = $(EXE_SRC)\
	    $(TEST_SRC)
# Main objects
EXE_OBJ = $(EXE_SRC:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
TEST_OBJ = $(TEST_SRC:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/%.o)
MAIN_OBJS = $(EXE_OBJ)\
	    $(TEST_OBJ)

SRC = $(filter-out $(MAIN_SRCS), $(wildcard $(SRC_DIR)/*.$(SRC_EXT))) # Get all cpp source files except main sources
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)# List object files from source files

# Flags and linking
CPPFLAGS += -I$(YAML)/include -Iinclude -I$(TRNG)/include# Preprocessor flags, such as .hpp file.
CFLAGS += -Wall -Wl,-rpath,$(YAML)/mpicxx/# Compiler flags,
LDFLAGS += -Llib -L$(YAML)/mpicxx/ -L$(SFTPATH)/lib# Linker flags, Make sure special libraries come first
LDLIBS += -lm -ltrng4 -lyaml-cpp# Third party libraries to link against, see lib

#LIBRARIES = $(Trilinos_LIBRARIES) $(Trilinos_TPL_LIBRARIES) $(USERLIBS)

# Rule for source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(SRC_EXT)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -MP -MMD -c $< -o $@ $(LDLIBS)

# Rule for making executable objects
$(EXE).X: $(OBJ) $(EXE_OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(TEST).X: $(OBJ) $(TEST_OBJ)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

.PHONY: all clean test love-not-war

all: $(EXE).X

test: $(TEST).X
	$(TEST).X

clean:
	$(RM) $(OBJ)
	$(RM) $(MAIN_OBJS)
	rm -f *.X


love-not-war:
	echo "Peace and harmony be upon you"


