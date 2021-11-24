#pragma once
#include "RenderTriangle.h"
#include <list>
#include <random>

class RenderObject {
protected:
    Quaternion rotation;
    Vector center;
    std::list<RenderTriangle> triangles;
    RenderObject(Quaternion rotation);
    void CalcCenter();
public:
    virtual ~RenderObject() = default;
	std::list<RenderTriangle> GetTriangles() {
		return triangles;
	}
	Quaternion GetRotation();
    void Rotate(Quaternion rotation);

    void Paint(Pixel pixel);
};