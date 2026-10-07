#include "lib/cubie.h"

Cubie::Cubie(Vector3 position, CubieType type) {
    this->position = position;
    this->type = type;
    this->size = {0.8f, 0.8f, 0.8f};
    this->colors = this->getColors();
};
void Cubie::update() {

};
void Cubie::draw() {
    for (int index = 0; index < 6; index++) {
        const auto& indexes = cubieVertIndex[index];
        Vector3 v1, v2, v3, v4;
        v1 = {
            this->position.x + indexes[0][0] * this->size.x/2,
            this->position.y + indexes[0][1] * this->size.y/2,
            this->position.z + indexes[0][2] * this->size.z/2
        };
        v2 = {
            this->position.x + indexes[1][0] * this->size.x/2,
            this->position.y + indexes[1][1] * this->size.y/2,
            this->position.z + indexes[1][2] * this->size.z/2
        };
        v3 = {
            this->position.x + indexes[2][0] * this->size.x/2,
            this->position.y + indexes[2][1] * this->size.y/2,
            this->position.z + indexes[2][2] * this->size.z/2
        };
        v4 = {
            this->position.x + indexes[3][0] * this->size.x/2,
            this->position.y + indexes[3][1] * this->size.y/2,
            this->position.z + indexes[3][2] * this->size.z/2
        };
        DrawTriangle3D(v1, v2, v3, this->colors[index]);
        DrawTriangle3D(v1, v3, v4, this->colors[index]);
    }
}

std::array<Color, 6> Cubie::getColors() {
    return {
        position.x == 1 ?  RED : BLACK,
        position.x == -1 ? ORANGE : BLACK,
        position.y == 1 ?  BLUE : BLACK,
        position.y == -1 ? GREEN : BLACK,
        position.z == 1 ?  WHITE : BLACK,
        position.z == -1 ? YELLOW : BLACK
    };
};