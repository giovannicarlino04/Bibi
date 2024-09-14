#ifndef CORE_H
#define CORE_H

#include "renderer.h"
#include "input.h"

class Engine {
public:
    bool initialize();
    void run();
    void shutdown();

private:
    Renderer renderer;
    InputManager inputManager;
    bool isRunning;
    void update(float deltaTime);
    void render();
};

#endif
