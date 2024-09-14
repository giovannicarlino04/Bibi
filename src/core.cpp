#include "core.h"
#include <GLFW/glfw3.h>

bool Engine::initialize() {
    // Initialize subsystems (GLFW, GLEW, etc.)
    if (!renderer.initialize()) {
        return false;
    }

    inputManager.initialize();
    isRunning = true;
    return true;
}

void Engine::run() {
    float lastTime = glfwGetTime();
    while (isRunning) {
        float currentTime = glfwGetTime();
        float deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Handle input
        inputManager.processInput();

        // Update game logic
        update(deltaTime);

        // Render the scene
        render();

        // Swap buffers and poll events
        glfwSwapBuffers(renderer.getWindow());
        glfwPollEvents();

        if (glfwWindowShouldClose(renderer.getWindow())) {
            isRunning = false;
        }
    }
}

void Engine::update(float deltaTime) {
    // Game logic updates (e.g., movement, physics)
}

void Engine::render() {
    renderer.clear();
    // Render game objects
    renderer.present();
}

void Engine::shutdown() {
    renderer.shutdown();
    glfwTerminate();
}
