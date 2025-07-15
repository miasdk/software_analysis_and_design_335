CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET = library_catalog
SOURCES = main.cpp AVLTree.cpp HashTable.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile source files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Test compilation
test: $(TARGET)
	@echo "Compilation successful! Run './$(TARGET)' to start the program."

.PHONY: all clean run test 