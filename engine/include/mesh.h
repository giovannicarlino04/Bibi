#ifndef MESH_H
#define MESH_H

#include <vector>
#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Color;
};

class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices);
    void draw() const;

private:
    unsigned int VAO, VBO;
};

#endif
