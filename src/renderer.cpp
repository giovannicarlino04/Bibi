#include "renderer.h"
#include <iostream>

bool Renderer::initialize() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }

    // Create the window and OpenGL context
    window = glfwCreateWindow(800, 600, "Game Engine", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create window\n";
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window);
    
    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW\n";
        return false;
    }

    // OpenGL setup
    glViewport(0, 0, 800, 600);
    glEnable(GL_DEPTH_TEST);

    return true;
}

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::present() {
    // Future: Add rendering calls for game objects
}

void Renderer::shutdown() {
    glfwDestroyWindow(window);
}

GLFWwindow* Renderer::getWindow() const {
    return window;
}
