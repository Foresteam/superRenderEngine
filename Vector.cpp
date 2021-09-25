#include "Vector.h"

Vector::Vector(int x, int y, int z) {
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
double Vector::GetLength() {
    return sqrt(x*x + y*y + z*z);
}
Vector Vector::Normalized() {
    return *this / GetLength();
}
std::random_device Vector::rd;
std::mt19937 Vector::gen = std::mt19937(rd());
std::uniform_int_distribution<> Vector::distrx = std::uniform_int_distribution<>(0, MAXCOLS);
std::uniform_int_distribution<> Vector::distry = std::uniform_int_distribution<>(0, MAXROWS);

Vector2::Vector2(int x, int y) : Vector::Vector(x, y, 0) {}
Vector2::Vector2(Vector vec) : Vector2::Vector2(vec.x, vec.y) {}
Vector2::Vector2() : Vector2::Vector2(MAXCOLS / 2, MAXROWS / 2) {}