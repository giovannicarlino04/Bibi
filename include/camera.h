#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
    glm::mat4 GetViewMatrix() const;

private:
    glm::vec3 Position, Front, Up, Right, WorldUp;
    float Yaw, Pitch;
    void updateCameraVectors();
};

#endif
