#pragma once
#include <random>

inline int MAXROWS, MAXCOLS;

class Vector {
private:
	static std::random_device rd;				   // obtain a random number from hardware
	static std::mt19937 gen;					   // seed the generator
	static std::uniform_int_distribution<> distrx; // define the range
	static std::uniform_int_distribution<> distry; // define the range
public:
	int x, y, z;
	Vector(int x, int y, int z);
	Vector();
	bool operator<(const Vector& v) const {
		if (std::min(std::min(x, y), z) < std::min(std::min(v.x, v.y), v.z))
			return true;
		else if (std::min(std::min(v.x, v.y), v.z) < std::min(std::min(x, y), z))
			return false;
		else
			return std::max(std::max(x, y), z) < std::max(std::max(v.x, v.y), v.z);
	}
	Vector operator+(const Vector& v2) {
		return Vector(x + v2.x, y + v2.y, z + v2.z);
	}
	Vector operator-(const Vector& v2) {
		return Vector(x - v2.x, y - v2.y, z - v2.z);
	}
    void operator-=(const Vector& v2) {
        *this = *this - v2;
    }
    void operator+=(const Vector& v2) {
        *this = *this + v2;
    }
	Vector operator*(const Vector& v2) {
		return Vector(x * v2.x, y * v2.y, z * v2.z);
	}
    Vector operator/(const double& n) {
        return Vector(x / n, y / n, z / n);
    }
    Vector operator*(const double& n) {
        return Vector(x * n, y * n, z * n);
    }
	bool operator==(const Vector& v2) {
		return x == v2.x && y == v2.y && z == v2.z;
	}
	Vector WrapScreen();
    Vector Cross(const Vector& v2);
    double Dot(const Vector& v2);
	double GetDistance(const Vector& v2);
    double GetLength();
    Vector Normalized();
	static Vector Random();
};

class Vector2 : public Vector {
public:
    Vector2(int x, int y);
    Vector2(Vector vec);
    Vector2();
};