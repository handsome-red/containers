# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -I.
LDFLAGS := -lgtest -lgtest_main -lpthread

# Project structure
SRC_DIR := .
LIST_DIR := ./list
TEST_DIR := ./tests

# Test files
TEST_SRC := $(TEST_DIR)/test.cpp
TEST_EXEC := test_containers

# Coverage settings
COVERAGE_DIR := coverage

.PHONY: all test clean gcov_report

all: test

$(TEST_EXEC): $(TEST_SRC) $(wildcard $(LIST_DIR)/*.h) $(wildcard $(LIST_DIR)/*.tpp)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: CXXFLAGS += -fprofile-arcs -ftest-coverage
gcov_report: LDFLAGS += -fprofile-arcs
gcov_report: test
	mkdir -p $(COVERAGE_DIR)
	lcov --capture --directory . --output-file $(COVERAGE_DIR)/coverage.info \
		--exclude "*/tests/*" \
		--exclude "/usr/*"
	genhtml $(COVERAGE_DIR)/coverage.info --output-directory $(COVERAGE_DIR)/report
	@echo "Coverage report available at: file://$(CURDIR)/$(COVERAGE_DIR)/report/index.html"
	open $(COVERAGE_DIR)/report/index.html

clean:
	rm -rf $(TEST_EXEC) $(COVERAGE_DIR) *.gcda *.gcno