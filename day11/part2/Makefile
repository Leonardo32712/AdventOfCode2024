# Directories
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

# Files
EXECUTABLE = $(BUILD_DIR)/advent
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SOURCES))

# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -I$(INCLUDE_DIR)

# Build Rules
all: $(EXECUTABLE)

# Link all object files into the final executable
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Compile each .cc file into a .o file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Ensure the build directory exists
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

# Run the executable with the input file
run: $(EXECUTABLE)
	@$(EXECUTABLE) input.txt
