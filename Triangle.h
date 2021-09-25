#pragma once
#include "Vector.h"

class Triangle {
private:
	float sign(Vector2 p1, Vector2 p2, Vector2 p3);
public:
    Vector self[3];
    Triangle(Vector a, Vector b, Vector c);

	bool Contains(Vector2 point);
    Vector GetNormal();
    Vector GetPointProjection(Vector point);
};