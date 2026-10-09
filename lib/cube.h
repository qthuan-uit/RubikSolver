#pragma once
#include <array>
#include <iostream>
#include <raylib.h>
#include "lib/cubie.h"
#include "lib/data.h"

class Cube {
private:
    std::vector<Cubie*> cubies;
public:
    Cube(std::vector<Cubie*>);
    void handleNotation(Notation);
    void update();
    void draw();
    Cubie* at(Vector3);
    std::array<Cubie*, 9> getFace(Vector3);
};