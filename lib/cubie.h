#pragma once
#include "lib/data.h"
#include "lib/utils.h"
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include <vector>
#include <array>

class Cubie {
private:
    int animationStep;
    std::unordered_map<Notation, bool> animation;
    Vector3 position;
    Vector3 expectedPosition;
    Vector3 size;
    CubieType type;
    std::array<Color, 6> colors;
    std::array<Vector3, 8> vertices;
public:
    Cubie(Vector3 , CubieType);
    std::array<Color, 6> initColors();
    std::array<Vector3, 8> initVertices();
    std::unordered_map<Notation, bool> initAnimation();
    void update();
    void draw();
    void updatePosition(Vector3);
    void updateExpectedPosition(Vector3);
    void rotate(int, Vector3);
    void updateVertices(std::array<Vector3, 8>);
    void updateVertice(int, Vector3);
    void updateRotation(float, Vector3);
    void updateAnimation(Notation, bool);
    bool isInAnimation();

    Vector3 getPosition();
    std::array<Vector3, 8> getVertices();
    Vector3 getExpectedPosition();

    Vector3 calcExpectedPosition(int, Vector3);
};

