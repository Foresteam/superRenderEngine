#pragma once
#include "RenderObject.h"

class ROTriangle : public RenderObject {
public:
	ROTriangle(Vector2, Vector2, Vector2, Quaternion = Quaternion());
};