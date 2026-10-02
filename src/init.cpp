#include "lib/init.h"
#include "lib/data.h"
#include "lib/camera.h"

void init() {
    InitWindow(Data::WIDTH, Data::HEIGHT, "My first RAYLIB program!");
    SetTargetFPS(Data::FPS);
    
}

void initWorld() {

}