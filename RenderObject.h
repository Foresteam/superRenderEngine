#pragma once
#include "Triangle.h"
#include <list>
#include <random>

class RenderObject {
protected:
    std::list<Triangle> triangles;
    RenderObject(Angle ang);
    Angle angle;
    Vector center;
    void CalcCenter();
public:
    virtual ~RenderObject() = default;
    std::list<Triangle> GetTriangles() {
        return triangles;
    }
    Angle GetAngle();
    void Rotate(Angle ang);
};