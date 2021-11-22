#pragma once
#include <foresteamnd/Triangle.h>
#include <list>
#include <random>

class RenderObject {
protected:
    std::list<Triangle> triangles;
    RenderObject(Quaternion rotation);
    Quaternion rotation;
    Vector center;
    void CalcCenter();
public:
    virtual ~RenderObject() = default;
    std::list<Triangle> GetTriangles() {
        return triangles;
    }
    Quaternion GetRotation();
    void Rotate(Quaternion rotation);
};