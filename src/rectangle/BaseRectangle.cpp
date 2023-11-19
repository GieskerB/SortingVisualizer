#ifndef INCLUDE_RECTANGLE_CPP_
#define INCLUDE_RECTANGLE_CPP_

#include "../../include/rectangle/BaseRectangle.hpp"

Uint16 BaseRectangle::mapValue(Uint16 value, Uint16 fromMin, Uint16 fromMax,
		Uint16 toMin, Uint16 toMax) {
	return toMin + (value - fromMin) * (toMax - toMin) / (fromMax - fromMin);
}

BaseRectangle::BaseRectangle(Uint16 wWidth, Uint16 wHeight, Uint16 value,
		Uint16 maxValue, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) :
		VALUE(value), MAX_VALUE(maxValue) {

	this->red = red;
	this->green = green;
	this->blue = blue;
	this->alpha = alpha;

	int x = mapValue(value, 0, maxValue, 0, wWidth);
	int w = wWidth / maxValue;
	int h = mapValue(value, 0, maxValue - 1, wHeight * 0.01, wHeight * 0.99);
	int y = wHeight - h;

	this->rect = { x, y, w, h };

}
BaseRectangle::~BaseRectangle() {
	// Nothing to do... No pointers
}

SDL_Rect BaseRectangle::getRect() {
	return this->rect;
}
void BaseRectangle::setRect(const SDL_Rect &rect) {
	this->rect = rect;
}

SDL_Rect* BaseRectangle::getRectPointer() {
	return (&this->rect);
}

void BaseRectangle::updateRect(Uint16 index) {
	this->rect.x = mapValue(index, 0, this->MAX_VALUE, 0,
			this->MAX_VALUE * this->rect.w);
}


Uint16 BaseRectangle::getValue() {
	return this->VALUE;
}

#endif /* INCLUDE_RECTANGLE_CPP_ */
