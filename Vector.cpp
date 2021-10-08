#include "Vector.h"
#include <math.h>

Vector::Vector(double x, double y, double z) {
	this->x = x;
	this->y = y;
    this->z = z;
}
Vector::Vector() : Vector::Vector(MAXCOLS / 2, MAXROWS / 2, 0) {}
Vector Vector::WrapScreen() {
	if (x < 0)
		x += MAXCOLS;
	if (y < 0)
		y += MAXROWS;
	if (x >= MAXCOLS)
		x -= MAXCOLS;
	if (y >= MAXROWS)
		y -= MAXROWS;
	return *this;
}
Vector Vector::Random() {
	return Vector(distrx(gen), distry(gen), 0);
}
Vector Vector::Cross(const Vector& v2) {
    Vector out = Vector();
    out.x = y * v2.z - z * v2.y;
    out.y = z * v2.x - x * v2.z;
    out.z = x * v2.y - y * v2.x;
    return out;
}
double Vector::Dot(const Vector& v2) {
    double prod = 0;
    prod += x * v2.x;
    prod += y * v2.y;
    prod += z * v2.z;
    return prod;
}
double Vector::GetDistance(const Vector& v2) {
	return sqrt(pow(x - v2.x, 2) + pow(y - v2.y, 2) + pow(z - v2.z, 2));
}
double Vector::GetLength() {
    return GetDistance(Vector(0, 0, 0));
}
Vector Vector::Normalized() {
    return *this / GetLength();
}
Vector Vector::Angle() {
    Vector out = Vector();
    out.x = atan2(y, x);
	out.y = atan2(x, z);
	return out;
}
std::random_device Vector::rd;
std::mt19937 Vector::gen = std::mt19937(rd());
std::uniform_int_distribution<> Vector::distrx = std::uniform_int_distribution<>(0, MAXCOLS);
std::uniform_int_distribution<> Vector::distry = std::uniform_int_distribution<>(0, MAXROWS);

Vector2::Vector2(double x, double y) : Vector::Vector(x, y, 0) {}
Vector2::Vector2(const Vector& vec) : Vector2::Vector2(vec.x, vec.y) {}
Vector2::Vector2() : Vector2::Vector2(MAXCOLS / 2, MAXROWS / 2) {}

Angle::Angle(double x, double y) : Vector2(x, y) {
    Normalize180();
}
Angle::Angle(Vector vec) : Angle(vec.x, vec.y) {}
Angle::Angle() : Angle(0, 0) {}
void Angle::Normalize180() {
    while (x > M_PI)
        x -= M_PI * 2;
	while (x < -M_PI)
		x += M_PI * 2;
	while (y > M_PI)
		y -= M_PI * 2;
	while (y < -M_PI)
		y += M_PI * 2;
	while (z > M_PI)
		z -= M_PI * 2;
	while (z < -M_PI)
		z += M_PI * 2;
}