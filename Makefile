CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wextra -pedantic
CPPFLAGS = -Itools/ -Iinclude/

BUILD_DIR = build
SRC_DIR = src
TEST_DIR = tests

CATCH2_SRC = tools/catch2/catch_amalgamated.cpp
CATCH2_OBJ = build/catch2.o

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

TEST_FILES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_FILES))
TEST_EXE = bin/tests.out

all: test

test: $(TEST_EXE)
	$(TEST_EXE)

$(TEST_EXE): $(CATCH2_OBJ) $(OBJ_FILES) $(TEST_OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(CATCH2_OBJ): $(CATCH2_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(CATCH2_OBJ) $(OBJ_FILES) $(TEST_OBJ_FILES)
