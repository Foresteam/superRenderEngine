#pragma once
#include "Triangle.h"
#include <list>
#include <random>

class RenderObject {
protected:
    std::list<Triangle> triangles;
    RenderObject() = default;
public:
    virtual ~RenderObject() = default;
    std::list<Triangle> GetTriangles() {
        return triangles;
    }
};