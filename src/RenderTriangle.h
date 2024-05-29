#pragma once
#include <foresteamnd/Triangle>

struct Pixel {
	char self;
	int colorPair;
	Pixel(char self = ' ', int colorPair = 0) {
		this->self = self;
		this->colorPair = colorPair;
	}
};

class RenderTriangle : public Triangle {
public:
	Pixel pixel;
	RenderTriangle(Vector a, Vector b, Vector c) : Triangle(a, b, c) {}
};