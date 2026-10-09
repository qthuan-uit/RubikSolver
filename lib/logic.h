#pragma once
#include <raylib.h>
#include <rlgl.h>
#include "lib/camera.h"
#include "lib/cubie.h"
#include "lib/cube.h"
#include <iostream>
#include <vector>
#include <raymath.h>

void update(CameraWorld*, Cube*);

void handleKey(CameraWorld*, Cube*);

void render(CameraWorld*, Cube*);