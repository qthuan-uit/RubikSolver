#pragma once
#include "lib/data.h"
#include <raylib.h>

class CameraWorld {
private:
    float theta;
    float phi;
    float orgDist;
    float rotateSpeed = 2.f;
    float zoomSpeed = 1.f;
    Vector3 position;
    Camera3D camera;
public:
    CameraWorld(float theta, float phi, float orgDist, Vector3 position);
    void update();
    void rotate(float, float);
    void zoom(float);
    Camera3D getCamera();
};