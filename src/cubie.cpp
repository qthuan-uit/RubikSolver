#include "lib/cubie.h"

Cubie::Cubie(Vector3 position, CubieType type) {
    this->position = position;
    this->expectedPosition = position;
    this->type = type;
    this->size = {0.8f, 0.8f, 0.8f};
    this->colors = this->initColors();
    this->vertices = this->initVertices();
    this->animationStep = 0;
    this->animation = this->initAnimation();
};
void Cubie::update() {
    for (const auto notation : notations) {
        if (this->animation[notation]) {
            if (this->animationStep < Data::ANIMATION_FRAME) {
                auto animRot = notationRotMap.at(notation);
                this->rotate(animRot[0], Vector3{animRot[1], animRot[2], animRot[3]});
                this->animationStep++;
            }
            else {
                this->position = this->expectedPosition;
                this->animation[notation] = 0;
                this->animationStep = 0;
            }
        }
    }
};

void Cubie::updateRotation(float theta, Vector3 pivot) {

}

void Cubie::updateAnimation(Notation notation, bool val) {
    this->animation[notation] = val;
};

void Cubie::updatePosition(Vector3 newPos) {
    this->position = newPos;
};

void Cubie::draw() {
    for (size_t i = 0; i < faceIndices.size(); i++) {
        const auto& indices = faceIndices[i];
        DrawTriangle3D(
            Vector3Add(this->vertices[indices[0]], this->position), 
            Vector3Add(this->vertices[indices[1]], this->position), 
            Vector3Add(this->vertices[indices[2]], this->position),
            this->colors[i]
        );
        DrawTriangle3D(
            Vector3Add(this->vertices[indices[0]], this->position), 
            Vector3Add(this->vertices[indices[2]], this->position), 
            Vector3Add(this->vertices[indices[3]], this->position),
            this->colors[i]
        );
    }
};

std::array<Color, 6> Cubie::initColors() {
    return {
        position.x == 1 ?  RED : BLACK,
        position.x == -1 ? ORANGE : BLACK,
        position.y == 1 ?  BLUE : BLACK,
        position.y == -1 ? GREEN : BLACK,
        position.z == 1 ?  WHITE : BLACK,
        position.z == -1 ? YELLOW : BLACK
    };
};

std::unordered_map<Notation, bool> Cubie::initAnimation() {
    return {
        {Notation::F, 0},
        {Notation::B, 0},
        {Notation::R, 0},
        {Notation::L, 0},
        {Notation::U, 0},
        {Notation::D, 0},

        {Notation::F_PRIME, 0},
        {Notation::B_PRIME, 0},
        {Notation::R_PRIME, 0},
        {Notation::L_PRIME, 0},
        {Notation::U_PRIME, 0},
        {Notation::D_PRIME, 0},
    };
}

std::array<Vector3, 8> Cubie::initVertices() {
    std::array<Vector3, 8> vertices = {
        Vector3{ 1, -1, -1},
        Vector3{ 1,  1, -1},
        Vector3{ 1,  1,  1},
        Vector3{ 1, -1,  1},
        Vector3{-1,  1, -1},
        Vector3{-1, -1, -1},
        Vector3{-1, -1,  1},
        Vector3{-1,  1,  1}
    };
    for (int i = 0; i < 8; i++) vertices[i] = {
        vertices[i].x * this->size.x/2.f,
        vertices[i].y * this->size.y/2.f,
        vertices[i].z * this->size.z/2.f
    };
    return vertices;
};

void Cubie::rotate(int dir, Vector3 pivot) {
    float theta = dir * TO_RAD * 1/Data::ANIMATION_FRAME * 90.f;
    Vector3 C = this->getPosition();
    Vector3 newC = transformRotation(C, theta, pivot, 1);
    this->updatePosition(newC);

    // Rotate Cubie
    for (int i = 0; i < 8; i++) {
        Vector3 P = this->vertices[i];
        Vector3 newP = transformRotation(P, theta, pivot, 0);
        this->updateVertice(i, newP);
    };
};

void Cubie::updateVertices(std::array<Vector3, 8> vertices) {
    this->vertices = vertices;
};

void Cubie::updateVertice(int index, Vector3 v) {
    this->vertices[index] = v;
};

std::array<Vector3, 8> Cubie::getVertices() {
    return this->vertices;
};

Vector3 Cubie::getPosition() {
    return this->position;
}

Vector3 Cubie::calcExpectedPosition(int dir, Vector3 pivot) {
    Vector3 C = this->getPosition();
    Vector3 E = transformRotation(C, 90.f * dir * TO_RAD, pivot, 1);
    E = Vector3 {
        std::round(E.x),
        std::round(E.y),
        std::round(E.z)
    };
    return E;
};

void Cubie::updateExpectedPosition(Vector3 pos) {
    this->expectedPosition = pos;
}

Vector3 Cubie::getExpectedPosition() {
    return this->expectedPosition;
}

bool Cubie::isInAnimation() {
    return (
        this->animation[Notation::L] || this->animation[Notation::L_PRIME] ||
        this->animation[Notation::R] || this->animation[Notation::R_PRIME] ||
        this->animation[Notation::F] || this->animation[Notation::F_PRIME] ||
        this->animation[Notation::B] || this->animation[Notation::B_PRIME] ||
        this->animation[Notation::U] || this->animation[Notation::U_PRIME] ||
        this->animation[Notation::D] || this->animation[Notation::D_PRIME]
    );
};