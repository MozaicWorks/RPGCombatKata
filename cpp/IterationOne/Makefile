# Specify number of threads to use on compilation
MAKEFLAGS += -j8

OUT := out
BUILD := obj
REPORTS := reports

SRC_PATHS := $(shell find src -type d -printf 'src/%P:')
# Find all source files from the 'src' folder excluding main.cpp
SRCS := $(shell find src -name '*.cpp' -not -name 'main.cpp' -printf '%f ')

# CLI Production variables
CLI_SRCS := $(SRCS) main.cpp
EXE := $(OUT)/combat
BLD_PROD := $(BUILD)/prod
CLI_OBJS := $(CLI_SRCS:%.cpp=$(BLD_PROD)/%.o)

# Tests Production Variables
TEST_PATHS := $(shell find tests -type d -printf 'tests/%P:')
# Find all test files from the 'tests' folder, in the form test_*.cpp
TEST_SRCS := $(SRCS) $(shell find tests -name 'test_*.cpp' -printf '%f ')
TESTS := $(OUT)/combatTests
BLD_TEST := $(BUILD)/test
TEST_OBJS := $(TEST_SRCS:%.cpp=$(BLD_TEST)/%.o)
TEST_DEPS := $(TEST_OBJS:.o=.d)
COVERAGE := $(REPORTS)/coverage

# Search paths for source files
VPATH := $(SRC_PATHS)$(TEST_PATHS)

# Set compilation flags. Pass include paths, options to generate the dependency files
# and the compilation options
CXXFLAGS += -I"src/" -I"tests/" -I"tests/libs/"
CXXFLAGS += -MMD -MP
CXXFLAGS += -std=c++20 -fext-numeric-literals -Wall -W -pedantic

# These targets don't denote a file name
.PHONY: clean run runUnitTests runAcceptanceTests

# Default target runs the unit tests

runUnitTests: $(TESTS)
	$(TESTS) --no-intro=true --test-suite="unit"

# Link the test program
$(TESTS): $(TEST_OBJS) | $(OUT)
	@$(CXX) $(CXXFLAGS) -O0 --coverage $^ -o $@

# Build .o files for tests
$(BLD_TEST)/%.o: %.cpp | $(BLD_TEST)
	rm -f $(BLD_TEST)/*.gcda
	@$(CXX) $(CXXFLAGS) -O0 --coverage -o $@ -c $<

coverage: runUnitTests
	-gcov --all-blocks --branch-counts --function-summaries $(CLI_SRCS) --object-directory $(BLD_TEST) 

coverage-report: $(COVERAGE)

CURRENT_FOLDER := $(shell pwd)
INCLUDE := "$(CURRENT_FOLDER)/src/*"
EXCLUDE := "$(CURRENT_FOLDER)/src/libs/*"
COVERAGE_FULL_PATH := "$(CURRENT_FOLDER)/$(COVERAGE)"

$(COVERAGE): coverage
	@mkdir -p $(COVERAGE) 
	@lcov --capture --quiet --directory $(BLD_TEST) --include $(INCLUDE) --output-file "$(COVERAGE_FULL_PATH)/coverage.info"
	@genhtml $(COVERAGE)/coverage.info --output-directory $(COVERAGE)
	rm *.gcov

open-coverage-report: coverage-report 
	xdg-open $(COVERAGE)/index.html

$(BLD_TEST):
	@mkdir -p $@

# CLI Production build 
run: $(EXE)
	@$(EXE)

# Link 
$(EXE): $(CLI_OBJS) | $(OUT)
	@$(CXX) $(CXXFLAGS) $^ -o $@

# Build .o files
$(BLD_PROD)/%.o: %.cpp | $(BLD_PROD)
	@$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BLD_PROD):
	@mkdir -p $@

# Common Build targets
$(OUT):
	@mkdir -p $@

# Other targets
clean:
	$(RM) -r $(BUILD) $(OUT) $(REPORTS)

-include $(CLI_DEPS) $(TEST_DEPS)
