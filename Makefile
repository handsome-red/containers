# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -fprofile-arcs -ftest-coverage
LDFLAGS := -lgtest -lgtest_main -lpthread -fprofile-arcs

# Project structure
SRC_DIR := .
OBJ_DIR := obj
TEST_DIR := tests

# Source files
SRCS := $(wildcard $(SRC_DIR)/s21_*.h) $(wildcard $(SRC_DIR)/s21_*.tpp)
LIB := s21_containers.a

# Test files
TEST_SRCS := $(TEST_DIR)/test.cpp
TEST_OBJ := $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRCS))
TEST_EXEC := test_container

# Coverage settings
COVERAGE_DIR := coverage

.PHONY: all clean test gcov_report rebuild

all: $(LIB)

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TEST_EXEC): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: $(TEST_EXEC)
	./$(TEST_EXEC)
	mkdir -p $(COVERAGE_DIR)
	lcov --capture --directory . --output-file $(COVERAGE_DIR)/coverage.info \
		--include "*/s21_*" \
		--exclude "*/tests/*" \
		--exclude "/usr/*"
	genhtml $(COVERAGE_DIR)/coverage.info --output-directory $(COVERAGE_DIR)/report \
		--demangle-cpp --title "s21_containers coverage"
	@echo "Coverage report: file://$(CURDIR)/$(COVERAGE_DIR)/report/index.html"
	rm -f *.gcda *.gcno
	open coverage/report/index.html

rebuild: clean all

clean:
	rm -rf $(OBJ_DIR) $(LIB) $(TEST_EXEC) $(COVERAGE_DIR) *.gcda *.gcno