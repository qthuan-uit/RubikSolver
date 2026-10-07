#pragma once
#include <cstdint>
#include <raylib.h>
#include <cmath>
#include <map>
#include <vector>

namespace Data {
    constexpr uint16_t WIDTH = 1200;
    constexpr uint16_t HEIGHT = 900;
    constexpr uint16_t FPS = 60;
    constexpr Color BGCOLOR = {255, 255, 255, 255};
};

enum class CubieType {
    CORNER,
    CENTER,
    SIDE
};

const std::vector<std::vector<std::vector<int>>> cubieVertIndex = {
    {
        { 1, -1, -1}, { 1,  1, -1}, { 1,  1,  1}, { 1, -1,  1}
    },
    {
        {-1,  1, -1}, {-1, -1, -1}, {-1, -1,  1}, {-1,  1,  1}
    },
    {
        { 1,  1, -1}, {-1,  1, -1}, {-1,  1,  1}, { 1,  1,  1}
    },
    {
        {-1, -1, -1}, { 1, -1, -1}, { 1, -1,  1}, {-1, -1,  1}
    },
    {
        { 1, -1,  1}, { 1,  1,  1}, {-1,  1,  1}, {-1, -1,  1}
    },
    {
        { 1,  1, -1}, { 1, -1, -1}, {-1, -1, -1}, {-1,  1, -1}
    }
};