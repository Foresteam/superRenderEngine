#include "Triangle.h"

Triangle::Triangle(Vector a, Vector b, Vector c) {
	_points[0] = a;
	_points[1] = b;
	_points[2] = c;
}
void Triangle::CalcVerteces(Vector* base) {
	this->base = base;
	verteces[0] = Vertex::FromPoint(_points[0], base);
	verteces[1] = Vertex::FromPoint(_points[1], base);
	verteces[2] = Vertex::FromPoint(_points[2], base);
	int a = 0;
}

Vector Triangle::GetPoint(int n) {
	return verteces[n].ToPoint(base);
}

float Triangle::sign(Vector2 p1, Vector2 p2, Vector2 p3) {
	return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool Triangle::Contains(Vector2 point) {
	double d1, d2, d3;
	bool has_neg, has_pos;

	d1 = sign(point, GetPoint(0), GetPoint(1));
	d2 = sign(point, GetPoint(1), GetPoint(2));
	d3 = sign(point, GetPoint(2), GetPoint(0));

	has_neg = d1 < 0 || d2 < 0 || d3 < 0;
	has_pos = d1 > 0 || d2 > 0 || d3 > 0;

	return !(has_neg && has_pos);
}
Vector Triangle::GetNormal() {
    return (GetPoint(1) - GetPoint(0)).Cross(GetPoint(2) - GetPoint(0)).Normalized();
}
Vector Triangle::GetPointProjection(Vector point) {
    Vector n = GetNormal();
    return point - n * (point - GetPoint(0)).Dot(n);
}

Vector* Triangle::GetPoints() {
	return new Vector[3] { GetPoint(0), GetPoint(1), GetPoint(2) };
}
void Triangle::Rotate(Angle ang) {
	for (int i = 0; i < 3; i++)
		verteces[i].Rotate(ang);
}

Triangle::Vertex Triangle::Vertex::FromPoint(Vector point, Vector* base) {
	Vector d = point - *base;
	auto a = d.Angle();
	return Vertex(d.Angle(), d.GetLength());
}
Vector Triangle::Vertex::ToPoint(Vector* base) {
	auto v = Vector(cos(angle.x), sin(angle.x), cos(angle.y));
	auto _ = v.GetLength();
	return *base + v * magnitude;
}