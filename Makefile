# Define variables for directories and files
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
IMGUI_SRC = external/imgui/imgui.cpp external/imgui/imgui_draw.cpp external/imgui/imgui_widgets.cpp external/imgui/imgui_tables.cpp
IMGUI_IMPL_SRC = external/imgui/backends/imgui_impl_glfw.cpp external/imgui/backends/imgui_impl_opengl3.cpp
IMGUI_OBJ = $(BUILD_DIR)/imgui.o $(BUILD_DIR)/imgui_draw.o $(BUILD_DIR)/imgui_widgets.o $(BUILD_DIR)/imgui_tables.o
IMGUI_IMPL_OBJ = $(BUILD_DIR)/imgui_impl_glfw.o $(BUILD_DIR)/imgui_impl_opengl3.o
IMGUI_LIB = $(BUILD_DIR)/libimgui.a
OBJ = $(BUILD_DIR)/Camera.o $(BUILD_DIR)/Shader.o $(BUILD_DIR)/Texture.o $(BUILD_DIR)/GUI.o $(BUILD_DIR)/main.o
EXE = $(BUILD_DIR)/output.exe

# Compiler and linker settings
CXX = g++
AR = ar
CXXFLAGS = -I$(INCLUDE_DIR) -I$(SRC_DIR) -Iexternal/imgui -Iexternal/imgui/backends
LDFLAGS = -L$(BUILD_DIR) -limgui -lglfw3 -lglew32 -lopengl32 -lgdi32 -lfmt

# Default target
all: $(EXE)

# Build ImGui object files
$(BUILD_DIR)/imgui.o: external/imgui/imgui.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/imgui_draw.o: external/imgui/imgui_draw.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/imgui_widgets.o: external/imgui/imgui_widgets.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/imgui_tables.o: external/imgui/imgui_tables.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/imgui_impl_glfw.o: external/imgui/backends/imgui_impl_glfw.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/imgui_impl_opengl3.o: external/imgui/backends/imgui_impl_opengl3.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Create ImGui static library
$(IMGUI_LIB): $(IMGUI_OBJ) $(IMGUI_IMPL_OBJ)
	$(AR) rcs $@ $(IMGUI_OBJ) $(IMGUI_IMPL_OBJ)

# Build the project
$(EXE): $(OBJ) $(IMGUI_LIB)
	$(CXX) -g $^ -o $@ $(LDFLAGS)

# Build the object files for the project
$(BUILD_DIR)/Camera.o: src/Camera.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/Shader.o: src/Shader.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/Texture.o: src/Texture.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/GUI.o: src/GUI.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(BUILD_DIR)/main.o: tests/test.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

# Create build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean up build directory
clean:
	rm -rf $(BUILD_DIR)/*.o $(BUILD_DIR)/*.a $(EXE)

# Phony targets
.PHONY: all clean
