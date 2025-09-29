#ifndef INCLUDE_RECTANGLE_CPP_
#define INCLUDE_RECTANGLE_CPP_

#include "../../include/rectangle/Rect.hpp"

Rect::~Rect() = default;

float& Rect::value() {
	return h;
}

void Rect::value(const float value) {
	// TODO reset y
	h = value;
}

#endif /* INCLUDE_RECTANGLE_CPP_ */
