#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    bool initialize();
    void clear();
    void present();
    void shutdown();
    GLFWwindow* getWindow() const;

private:
    GLFWwindow* window;
};

#endif
