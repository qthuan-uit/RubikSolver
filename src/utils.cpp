#include "lib/utils.h"

float roundTo(float val, int n) {
    float multiplier = std::pow(10.f, n);
    return std::round(val * multiplier) / multiplier;
}

Vector3 transformRotation(Vector3 v, float t, Vector3 p, bool relativeToPivot) {
    if (relativeToPivot) v = Vector3Subtract(v, p);
    Vector3 newV;
    
    if (p.x) newV = Vector3{
        v.x,
        v.y*cosf(t) - v.z*sinf(t),
        v.y*sinf(t) + v.z*cosf(t)
    };
    if (p.y) newV = Vector3{
        v.x*cosf(t) + v.z*sinf(t),
        v.y,
        -v.x*sinf(t) + v.z*cosf(t)
    };
    if (p.z) newV = Vector3{
        v.x*cosf(t) - v.y*sinf(t),
        v.x*sinf(t) + v.y*cosf(t),
        v.z
    };
    if (relativeToPivot) newV = Vector3Add(newV, p);

    return newV;
};