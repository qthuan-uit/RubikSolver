#pragma once
#include <raylib.h>
#include "lib/camera.h"
#include <iostream>

void update(CameraWorld*);

void handleKey(CameraWorld*);

void render(CameraWorld*);