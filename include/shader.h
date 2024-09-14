// shader.h
#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>

class Shader {
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    void use() const;
    GLuint getID() const { return ID; }

private:
    GLuint ID;
    void checkCompileErrors(GLuint shader, std::string type);
};

#endif
