#include "RORect.h"

RORect::RORect(Vector2 p, Vector2 size, Quaternion rotation) : RenderObject(rotation) {
    // size = Vector2(size.x, size.y / 2);
    Vector p2 = p + size;
    Vector cb = p + Vector2(0, size.y);
    Vector ct = p + Vector2(size.x, 0);
    triangles.push_back(Triangle(p, ct, cb));
    triangles.push_back(Triangle(ct, cb, p2));
    CalcCenter();
}