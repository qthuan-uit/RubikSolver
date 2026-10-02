#include "lib/utils.h"
#define PI 3.14159f

template <typename T>
void log(T content) {
    std::cout << content <<'\n';
}

float toRad(float deg) {
    return (deg/180.f) * PI;
};

float toDeg(float rad) {
    return (rad/PI) * 180.f;
};

float sinDeg(float deg) {
    return sin(toRad(deg));
};

float cosDeg(float deg) {
    return cos(toRad(deg));
};

float tanDeg(float deg) {
    return tan(toRad(deg));
};