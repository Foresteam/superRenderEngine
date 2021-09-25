#include "RenderObject.h"

RenderObject::RenderObject(Vector angle) {
    this->angle = angle;
}

Vector RenderObject::GetAngle() {
    return angle;
}

void RenderObject::CalcCenter() {
    int n = triangles.size() * 3;
    double sx = 0, sy = 0, sz = 0;

    for (auto& tri : triangles)
        for (unsigned char i = 0; i < 3; i++) {
            sx += tri.self[i].x;
            sy += tri.self[i].y;
            sz += tri.self[i].y;
        }

    center = Vector(sx / n, sy / n, sz / n);
}

void RenderObject::Rotate(Vector rangle) {
    angle += rangle;
}