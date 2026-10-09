#include <raylib.h>
#include <vector>
#include "lib/cubie.h"
#include "lib/data.h"
#include "lib/init.h"
#include "lib/logic.h"
#include "lib/camera.h"
#include "lib/cube.h"

CameraWorld* camera = new CameraWorld(45.f, 45.f, 10.f, {10, 10, 10});

std::vector<Cubie*> cubies = {
    new Cubie({0, 0, 1}, CubieType::CENTER),
    new Cubie({0, 0, -1}, CubieType::CENTER),
    new Cubie({0, 1, 0}, CubieType::CENTER),
    new Cubie({0, -1, 0}, CubieType::CENTER),
    new Cubie({1, 0, 0}, CubieType::CENTER),
    new Cubie({-1, 0, 0}, CubieType::CENTER),

    new Cubie({-1, 0, 1}, CubieType::SIDE),
    new Cubie({1, 0, 1}, CubieType::SIDE),
    new Cubie({0, -1, 1}, CubieType::SIDE),
    new Cubie({0, 1, 1}, CubieType::SIDE),

    new Cubie({-1, 0, -1}, CubieType::SIDE),
    new Cubie({1, 0, -1}, CubieType::SIDE),
    new Cubie({0, -1, -1}, CubieType::SIDE),
    new Cubie({0, 1, -1}, CubieType::SIDE),

    new Cubie({1, 1, 0}, CubieType::SIDE),
    new Cubie({-1, -1, 0}, CubieType::SIDE),
    new Cubie({1, -1, 0}, CubieType::SIDE),
    new Cubie({-1, 1, 0}, CubieType::SIDE),

    new Cubie({1, 1, 1}, CubieType::CORNER),
    new Cubie({-1, -1, 1}, CubieType::CORNER),
    new Cubie({1, -1, 1}, CubieType::CORNER),
    new Cubie({-1, 1, 1}, CubieType::CORNER),

    new Cubie({1, 1, -1}, CubieType::CORNER),
    new Cubie({-1, -1, -1}, CubieType::CORNER),
    new Cubie({1, -1, -1}, CubieType::CORNER),
    new Cubie({-1, 1, -1}, CubieType::CORNER),
};

Cube* cube = new Cube(cubies);

// {R/O , B/G , W/Y}


int main() 
{
    init();
    update(camera, cube); 
}