#pragma once
#include "RenderObject.h"

class RORect : public RenderObject {
public:
    RORect(Vector2, Vector2, Vector = Vector(0, 0, 0));
};