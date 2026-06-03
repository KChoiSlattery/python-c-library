# Input configuration
# TEST_DIRS := tests
MAIN_SRC_FILE := src/main.c
LIB_DIRS := src/lib
INC_TOP_DIRS := src/lib #src/external_libraries/Unity/src /workspaces/tdd-test/src/external_libraries/CMSIS-DSP/Include /workspaces/tdd-test/src/external_libraries/cmsis_core/Core/Include

#LIB_ALSO_ADD := src/external_libraries/CMSIS-DSP/Source/BasicMathFunctions/arm_add_f64.c /workspaces/tdd-test/src/external_libraries/CMSIS-DSP/Source/BasicMathFunctions/arm_dot_prod_f64.c

# Output configuration
BUILD_DIR := build
# TEST_BUILD_DIR := build/tests

# This will recursively find all .c files in LIB_DIRS and its subfolders
LIBS := $(shell find $(LIB_DIRS) -name '*.c') $(LIB_ALSO_ADD)

# # Likewise for TEST_DIRS
# TESTS := $(shell find $(TEST_DIRS) -name '*.c') 

# Recursively find all subfolders of INC_DIRS
INC_DIRS := $(shell find $(INC_TOP_DIRS) -type d)
# Add a -I prefix to each folder in INC_DIRS.
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# Make the build directory if it does not exist and build using the flags we've generated above
main: $(MAIN_SRC_FILE) $(LIBS)
	mkdir -p $(BUILD_DIR)
	gcc -Wall -o $(BUILD_DIR)/main.out $(MAIN_SRC_FILE) $(LIBS) $(INC_FLAGS)

# # Use makefile functions to create names of test outputs
# TEST_OUTPUTS := $(notdir $(patsubst %.c,%.out,$(TESTS)))
# tests: $(TEST_OUTPUTS)

# # For each member of TEST_OUTPUTS, build from only the corresponding input
# $(TEST_OUTPUTS): $(TESTS)
# 	mkdir -p $(TEST_BUILD_DIR)
# 	gcc -Wall -o $(TEST_BUILD_DIR)/$@ $(filter %$(patsubst %.out,%.c,$@),$(TESTS)) $(LIBS) $(INC_FLAGS)
