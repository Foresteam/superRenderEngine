#pragma once
#include "RenderObject.h"

class RORect : public RenderObject {
public:
	RORect(Vector2, Vector2, Quaternion = Quaternion());
};