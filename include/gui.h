#ifndef GUI_H
#define GUI_H

#include <imgui.h>
#include <../external/imgui/backends/imgui_impl_glfw.h>
#include <../external/imgui/backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

class GUI {
public:
    GUI(GLFWwindow* window);
    ~GUI();
    void beginFrame();
    void render();
private:
    GLFWwindow* window;
};

#endif
