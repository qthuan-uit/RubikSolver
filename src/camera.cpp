#include "lib/camera.h"
#include "lib/utils.h"

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
        this->orgDist * sinDeg(theta) * sinDeg(phi),
        this->orgDist * sinDeg(theta) * cosDeg(phi),
        this->orgDist * cosDeg(theta)
    };

    this->camera.position = this->position;
}

void CameraWorld::rotate(float deltaPhi, float deltaTheta) {
    this->phi += deltaPhi;
    this->theta += deltaTheta;
}

void CameraWorld::zoom(float deltaDist) {
    this->orgDist += deltaDist;
}