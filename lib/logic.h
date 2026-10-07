#pragma once
#include <raylib.h>
#include <rlgl.h>
#include "lib/camera.h"
#include "lib/cubie.h"
#include <iostream>
#include <vector>
#include <raymath.h>

void update(CameraWorld*, std::vector<Cubie*>);

void handleKey(CameraWorld*, std::vector<Cubie*>);

void render(CameraWorld*, std::vector<Cubie*>);