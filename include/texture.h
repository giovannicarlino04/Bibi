#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>

class Texture {
public:
    Texture(const char* path);
    GLuint ID;
private:
    void loadTexture(const char* path);
};

#endif
