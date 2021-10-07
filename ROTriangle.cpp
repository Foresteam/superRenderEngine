#include "ROTriangle.h"

ROTriangle::ROTriangle(Vector2 a, Vector2 b, Vector2 c, Vector angle) : RenderObject(angle) {
    triangles.push_back(Triangle(a, b, c));
    CalcCenter();
}