#include "input.h"
#include <GLFW/glfw3.h>
#include <iostream>

void InputManager::initialize() {
    // Any input initialization logic (if necessary)
}

void InputManager::processInput() {
    // Process input (for now, just a placeholder)
    if (glfwGetKey(glfwGetCurrentContext(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(glfwGetCurrentContext(), true);
    }
}
