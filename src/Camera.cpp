//
// Created by Rasmus Fey on 15/10/2021.
//

#include "Camera.h"
#include "glm/gtc/matrix_transform.hpp"

using glm::mat4; using glm::vec3;

mat4 Camera::getLookAtMatrix() {
    vec3 upVector = glm::vec3(sin(roll), cos(roll), 0.0f);
    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    //return glm::lookAt(position, position + glm::normalize(direction), glm::vec3(0.0f,1.0f,0.0f));
    return glm::lookAt(position,glm::vec3(0.0f, 0.0f, 0.0f),upVector);
}

vec3 Camera::getPosition() const {
    return position;
}

void Camera::setPosition(vec3 newPos) {
    position = newPos;
}


/**
 * @return The camera's rotation on three rotational axis, yaw, pitch, and roll
 */
vec3 Camera::getRotation() const {
    return {yaw, pitch, roll};
}

/**
 * @param newRotation The camera's new rotation on three rotational axis, yaw pitch, and roll
 */
void Camera::setRotation(vec3 newRotation) {
    yaw = newRotation.x;
    pitch = newRotation.y;
    roll = newRotation.z;
}
