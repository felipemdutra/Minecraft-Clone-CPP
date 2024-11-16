# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -std=c++11 -Wall

# Linker flags for OpenGL, GLEW, and GLFW
LDFLAGS = -lGL -lGLEW -lglfw

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = builds
TARGET_DIR = $(BUILD_DIR)
TARGET = $(TARGET_DIR)/minecraft_clone

# Source files and object files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Default target
all: $(TARGET)

# Link the final executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGET_DIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/minecraft_clone

# Run the project
run: all
	./$(TARGET)

.PHONY: all clean run