#pragma once
#include "Triangle.h"
#include <list>
#include <random>

class RenderObject {
protected:
    std::list<Triangle> triangles;
    RenderObject(Vector);
    Vector angle;
    Vector center;
    void CalcCenter();
public:
    virtual ~RenderObject() = default;
    std::list<Triangle> GetTriangles() {
        return triangles;
    }
    Vector GetAngle();
    void Rotate(Vector);
};