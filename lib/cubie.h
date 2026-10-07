#pragma once
#include "lib/data.h"
#include <raylib.h>
#include <vector>
#include <array>

class Cubie {
private:
    Vector3 position;
    Vector3 size;
    CubieType type;
    std::array<Color, 6> colors;
public:
    Cubie(Vector3 , CubieType);
    std::array<Color, 6> getColors();
    void update();
    void draw();
};

