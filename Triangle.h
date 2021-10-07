#pragma once
#include "Vector.h"

class Triangle {
private:
	float sign(Vector2 p1, Vector2 p2, Vector2 p3);
    class Vertex {
    private:
        Angle angle;
        double magnitude;
    public:
        Vertex(Angle ang, double mag) {
            angle = ang;
            magnitude = mag;
        }
        Vertex() : Vertex(Angle(), 0) {}
        static Vertex FromPoint(Vector point, Vector* base);
        
        Vector ToPoint(Vector* base);
        void Rotate(Vector angle) {
            this->angle += angle;
        }
    };
	Vertex verteces[3];
    Vector* base;
    Vector GetPoint(int n);
public:
    Vector _points[3];
	Triangle(Vector a, Vector b, Vector c);
    void CalcVerteces(Vector* base);

    Vector* GetPoints();
    void Rotate(Vector ang);

	bool Contains(Vector2 point);
    Vector GetNormal();
    Vector GetPointProjection(Vector point);
};