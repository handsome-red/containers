# Compiler settings
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror
LDFLAGS := -lgtest -lgtest_main -lpthread

# Project structure
SRC_DIR := .
OBJ_DIR := obj
TEST_DIR := tests

# Source files
SRCS := $(wildcard $(SRC_DIR)/s21_*.tpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
LIB := s21_containers.a

# Test files
TEST_SRC := $(TEST_DIR)/test.cpp
TEST_EXEC := test_container

# Coverage settings
GCOV_FLAGS := -fprofile-arcs -ftest-coverage
COVERAGE_DIR := coverage

.PHONY: all clean test gcov_report rebuild

all: $(LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIB): $(OBJS)
	ar rcs $@ $^

test: $(LIB)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_EXEC) $(LIB) $(LDFLAGS)
	./$(TEST_EXEC)

gcov_report: $(LIB)
	$(CXX) $(CXXFLAGS) $(GCOV_FLAGS) $(TEST_SRC) -o $(TEST_EXEC) $(SRCS) $(LDFLAGS)
	./$(TEST_EXEC)
	mkdir -p $(COVERAGE_DIR)
	lcov -t "$(TEST_EXEC)" -o $(COVERAGE_DIR)/$(TEST_EXEC).info -c -d .
	genhtml -o $(COVERAGE_DIR)/report $(COVERAGE_DIR)/$(TEST_EXEC).info
	rm -f *.gcda *.gcno

rebuild: clean all

clean:
	rm -rf $(OBJ_DIR) $(LIB) $(TEST_EXEC) $(COVERAGE_DIR) *.gcda *.gcno