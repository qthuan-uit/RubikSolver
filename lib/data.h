#pragma once
#include <cstdint>
#include <raylib.h>
#include <cmath>
#include <map>
#include <vector>
#include <array>
#include <unordered_map>
#include <string>
#include <numbers>

constexpr float TO_RAD = 3.14159265358979323846f / 180;

namespace Data {
    constexpr uint16_t WIDTH = 1200;
    constexpr uint16_t HEIGHT = 900;
    constexpr uint16_t FPS = 60;
    constexpr uint16_t ANIMATION_FRAME = 10;
    constexpr Color BGCOLOR = {200, 200, 200, 255};
};

enum class CubieType {
    CORNER,
    CENTER,
    SIDE
};

enum class Notation {
    F, F_PRIME,
    B, B_PRIME,
    L, L_PRIME,
    R, R_PRIME,
    U, U_PRIME,
    D, D_PRIME
};

const std::unordered_map<Notation, std::array<int, 7>> notationRotMap = {
    // Dir - Pivot - Face
    {Notation::U, {-1, 0, 0, 1, 0, 0, 1}},
    {Notation::D, {1, 0, 0, -1, 0, 0, -1}},
    {Notation::F, {-1, 1, 0, 0, 1, 0, 0}},
    {Notation::B, {1, -1, 0, 0, -1, 0, 0}},
    {Notation::L, {1, 0, -1, 0, 0, -1, 0}},
    {Notation::R, {-1, 0, 1, 0, 0, 1, 0}},
    
    {Notation::U_PRIME, {1, 0, 0, 1, 0, 0, 1}},
    {Notation::D_PRIME, {-1, 0, 0, -1, 0, 0, -1}},
    {Notation::F_PRIME, {1, 1, 0, 0, 1, 0, 0}},
    {Notation::B_PRIME, {-1, -1, 0, 0, -1, 0, 0}},
    {Notation::L_PRIME, {-1, 0, -1, 0, 0, -1, 0}},
    {Notation::R_PRIME, {1, 0, 1, 0, 0, 1, 0}},
};

const std::array<Notation, 12> notations = {
    Notation::F,
    Notation::B,
    Notation::R,
    Notation::L,
    Notation::U,
    Notation::D,
    Notation::F_PRIME,
    Notation::B_PRIME,
    Notation::R_PRIME,
    Notation::L_PRIME,
    Notation::U_PRIME,
    Notation::D_PRIME
};

const std::unordered_map<Notation, std::string> notationMessageTranslation = {
    {Notation::F, "Front"},
    {Notation::B, "Back"},
    {Notation::R, "Right"},
    {Notation::L, "Left"},
    {Notation::U, "Up"},
    {Notation::D, "Down"},

    {Notation::F_PRIME, "Front Prime"},
    {Notation::B_PRIME, "Back Prime"},
    {Notation::R_PRIME, "Right Prime"},
    {Notation::L_PRIME, "Left Prime"},
    {Notation::U_PRIME, "Up Prime"},
    {Notation::D_PRIME, "Down Prime"},
};

const std::unordered_map<int, Notation> notationKeyTranslation = {
    {70, Notation::F},
    {66, Notation::B},
    {82, Notation::R},
    {76, Notation::L},
    {85, Notation::U},
    {68, Notation::D},

    {170, Notation::F_PRIME},
    {166, Notation::B_PRIME},
    {182, Notation::R_PRIME},
    {176, Notation::L_PRIME},
    {185, Notation::U_PRIME},
    {168, Notation::D_PRIME}
};

const std::vector<KeyboardKey> notationKeys = {
    KEY_L, KEY_R, KEY_U, KEY_D, KEY_F, KEY_B
};

const std::array<std::array<int, 4>, 6> faceIndices = {{
    {0, 1, 2, 3},
    {4, 5, 6, 7},
    {1, 4, 7, 2},
    {5, 0, 3, 6},
    {3, 2, 7, 6},
    {1, 0, 5, 4}
}};