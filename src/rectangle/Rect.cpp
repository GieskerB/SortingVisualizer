#ifndef INCLUDE_RECTANGLE_CPP_
#define INCLUDE_RECTANGLE_CPP_

#include "../../include/rectangle/Rect.hpp"

Rect::~Rect() = default;

float& Rect::value() {
	return h;
}

void Rect::value(const float value) {
	const float delta = h - value;
	y -= delta;
	h = value;
}

void Rect::draw(SDL_Renderer *renderer) const {
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, this);
}


#endif /* INCLUDE_RECTANGLE_CPP_ */
