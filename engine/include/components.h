#ifndef COMPONENTS_H
#define COMPONENTS_H

#include "entity.h"
#include <glm/glm.hpp>  // For glm::vec3

// TransformComponent stores position and possibly other transformation data
class TransformComponent : public Component {
public:
    TransformComponent(const glm::vec3& position) : position(position) {}

    glm::vec3 position;
};

// RenderComponent stores color or rendering-related data
class RenderComponent : public Component {
public:
    RenderComponent(const glm::vec3& color) : color(color) {}

    glm::vec3 color;
};

#endif
