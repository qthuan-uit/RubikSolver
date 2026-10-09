#include "lib/camera.h"
#include <raymath.h>

CameraWorld::CameraWorld(float phi, float theta, float orgDist, Vector3 position)
{
    this->phi = phi;
    this->theta = theta;
    this->orgDist = orgDist;
    this->position = position;

    Camera3D camera = {0};
    camera.position = {0, 0, 0};
    camera.target = {0, 0, 0};
    camera.up = {0, 0, 1};
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;

    this->camera = camera;
}

void CameraWorld::update() {
    this->position = {
        this->orgDist * sinf(theta*TO_RAD) * sinf(phi*TO_RAD),
        this->orgDist * sinf(theta*TO_RAD) * cosf(phi*TO_RAD),
        this->orgDist * cosf(theta*TO_RAD)
    };

    this->camera.position = this->position;
}

void CameraWorld::rotate(float deltaPhi, float deltaTheta) {
    this->phi += deltaPhi*this->rotateSpeed;
    this->theta += deltaTheta*this->rotateSpeed;
    this->theta = Clamp(this->theta, 0.01f, 180 - 0.01f);
}

void CameraWorld::zoom(float deltaDist) {
    this->orgDist += deltaDist*this->zoomSpeed;
    this->orgDist = Clamp(this->orgDist, 5.f, 60.f);
}

Camera3D CameraWorld::getCamera() {
    return this->camera;
}