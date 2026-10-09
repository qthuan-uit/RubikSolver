#include "lib/cube.h"

Cube::Cube(std::vector<Cubie*> cubies) {
    this->cubies = cubies;
}

void Cube::draw() {
    for (const auto& cubie : this->cubies) {
        cubie->draw();
    }
}

void Cube::update() {
    for (const auto& cubie : this->cubies) {
        cubie->update();
    }
}

void Cube::handleNotation(Notation notation) {
    std::cout << notationMessageTranslation.at(notation) << std::endl;
    for (const auto& cubie : this->cubies) {
        if (cubie->isInAnimation()) return;
    }
    auto animRot = notationRotMap.at(notation);
    auto face = this->getFace(Vector3{animRot[4], animRot[5], animRot[6]});
    for (const auto& cubie : face) {
        auto expectedPos = cubie->calcExpectedPosition(animRot[0], Vector3{animRot[1], animRot[2], animRot[3]});
        cubie->updateExpectedPosition(expectedPos);
        cubie->updateAnimation(notation, 1);
    }
}

Cubie* Cube::at(Vector3 pos) {
    for (auto& cubie : this->cubies) {
        auto cubiePos = cubie->getPosition();
        if (cubiePos.x == pos.x && cubiePos.y == pos.y && cubiePos.z == pos.z) return cubie;
    }
    return nullptr;
};

std::array<Cubie*, 9> Cube::getFace(Vector3 pos) {
    std::array<Cubie*, 9> face;
    int index = 0;
    for (float i = -1; i <= 1; i++) {
        for (float j = -1; j <= 1; j++) {
            Vector3 cubiePos = pos.x ? Vector3{pos.x, i, j} : (pos.y ? Vector3{i, pos.y, j} : Vector3{i, j, pos.z});
            face[index] = this->at(cubiePos);
            index++;
        }
    }
    return face;
}