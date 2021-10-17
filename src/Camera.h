//
// Created by Rasmus Fey on 15/10/2021.
//

#ifndef UNTITLED_CAMERA_H
#define UNTITLED_CAMERA_H
#include "glm/glm.hpp"

using glm::mat4; using glm::vec3;

class Camera {
public:
    mat4 getLookAtMatrix();

    vec3 getPosition() const;
    vec3 getRotation() const;

    void setPosition(vec3 newPos);
    void setRotation(vec3 newRotation);

private:
    vec3 position;
    float roll;
    float pitch;
    float yaw;
};


#endif //UNTITLED_CAMERA_H
