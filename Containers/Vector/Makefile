# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Target executable
TARGET = vector

# Source files
SRC = main.cpp 

# Object files
OBJ = $(SRC:.cpp=.o)

# Include directory
INCLUDE_DIR = -Iinclude -Ivector

# Rule to compile the program
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $(TARGET) $(OBJ)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJ)

# Phony targets
.PHONY: clean
