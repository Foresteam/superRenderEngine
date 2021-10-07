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

    for (auto& tri : triangles) {
        for (unsigned char i = 0; i < 3; i++) {
            sx += tri._points[i].x;
            sy += tri._points[i].y;
            sz += tri._points[i].z;
        }
    }

    center = Vector(sx, sy, sz) / n;
    for (auto& tri : triangles)
        tri.CalcVerteces(&center);
}

void RenderObject::Rotate(Vector rangle) {
    angle += rangle;
}