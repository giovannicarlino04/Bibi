#include "camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 front, float yaw, float pitch)
    : position(position), front(front), yaw(yaw), pitch(pitch) {
    updateCameraVectors();
}

void Camera::moveForward(float delta) {
    position += front * delta;
}

void Camera::moveBackward(float delta) {
    position -= front * delta;
}

void Camera::moveLeft(float delta) {
    position -= right * delta;
}
void Camera::moveRight(float delta) {
    position += right * delta;
}
void Camera::moveUp(float delta) {
    position += up * delta;
}
void Camera::moveDown(float delta) {
    position -= up * delta;
}
void Camera::rotate(float yawOffset, float pitchOffset) {
    yaw += yawOffset;
    pitch += pitchOffset;

    // Constrain pitch to avoid flipping
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;

    updateCameraVectors();
}

void Camera::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    this->front = glm::normalize(front);

    right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
    up = glm::normalize(glm::cross(right, front));
}

glm::mat4 Camera::GetViewMatrix() const {
    return glm::lookAt(position, position + front, up);
}
