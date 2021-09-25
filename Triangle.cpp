#include "Triangle.h"

Triangle::Triangle(Vector a, Vector b, Vector c) {
	self[0] = a;
	self[1] = b;
	self[2] = c;
}

float Triangle::sign(Vector2 p1, Vector2 p2, Vector2 p3) {
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool Triangle::Contains(Vector2 point) {
	float d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, self[0], self[1]);
	d2 = sign(point, self[1], self[2]);
	d3 = sign(point, self[2], self[0]);

	has_neg = d1 < 0 || d2 < 0 || d3 < 0;
	has_pos = d1 > 0 || d2 > 0 || d3 > 0;

	return !(has_neg && has_pos);
}
Vector Triangle::GetNormal() {
    return (self[1] - self[0]).Cross(self[2] - self[0]).Normalized();
}
Vector Triangle::GetPointProjection(Vector point) {
    Vector n = GetNormal();
    return point - n * (point - self[0]).Dot(n);
}