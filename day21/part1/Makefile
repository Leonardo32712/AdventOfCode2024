# Directories
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include

# Files
EXECUTABLE = $(BUILD_DIR)/advent
SOURCES = $(wildcard $(SRC_DIR)/*.cc)
OBJECTS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(SOURCES))
DEPENDS = $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.d, $(SOURCES))

# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++14 -g -Wall -I$(INCLUDE_DIR)

# Build Rules
all: $(EXECUTABLE)
	@echo "🚀 Building the executable: $(EXECUTABLE)..."

# Link all object files into the final executable
$(EXECUTABLE): $(OBJECTS)
	@echo "🔗 Linking object files to create the executable!"
	@$(CXX) $(OBJECTS) -o $@

# Compile each .cc file into a .o file and generate dependencies
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	@echo "⚙️ Compiling: $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

# Ensure the build directory exists
$(BUILD_DIR):
	@echo "📂 Creating build directory..."
	@mkdir -p $(BUILD_DIR)

# Clean up build artifacts
clean:
	@echo "🧹 Cleaning up build files..."
	@rm -rf $(BUILD_DIR)

# Run the executable with the input file
run: $(EXECUTABLE)
	@echo -e "🎮 Running the executable with input.txt...\n"
	@$(EXECUTABLE) input.txt

# Include generated dependency files
-include $(DEPENDS)
