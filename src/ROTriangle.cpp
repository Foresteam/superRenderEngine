#include "ROTriangle.h"

ROTriangle::ROTriangle(Vector2 a, Vector2 b, Vector2 c, Quaternion rotation) : RenderObject(rotation) {
	triangles.push_back(RenderTriangle(a, b, c));
	CalcCenter();
}