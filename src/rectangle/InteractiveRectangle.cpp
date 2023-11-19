#include "../../include/rectangle/InteractiveRectangle.hpp"

#include <iostream>

InteractiveRectangle::InteractiveRectangle(Uint16 wWidth, Uint16 wHeight,
		Uint16 value, Uint16 maxValue) :
		BaseRectangle(wWidth, wHeight, value, maxValue, 255, 255, 255, 255) {

	this->compared = false;
	this->swapped = false;
}

void InteractiveRectangle::resetChecked() {
	if (this->compared) {
		this->compared = false;
	}
}

void InteractiveRectangle::resetSwapped() {
	if (this->swapped) {
		this->swapped = false;
	}
}

void InteractiveRectangle::setCompared() {
	if (!this->swapped) {
		this->red = (COMPARED_COLOR & 255 << 24) >> 24;
		this->green = (COMPARED_COLOR & 255 << 16) >> 16;
		this->blue = (COMPARED_COLOR & 255 << 8) >> 8;
		this->alpha = COMPARED_COLOR & 255;
	}
	this->compared = true;
}

void InteractiveRectangle::setSwapped() {
	this->red = (SWAPPED_COLOR & 255 << 24) >> 24;
	this->green = (SWAPPED_COLOR & 255 << 16) >> 16;
	this->blue = (SWAPPED_COLOR & 255 << 8) >> 8;
	this->alpha = SWAPPED_COLOR & 255;
	this->swapped = true;
}

Uint8 InteractiveRectangle::getRed() {

	return this->red;
}

Uint8 InteractiveRectangle::getGreen() {
	return this->green;
}

Uint8 InteractiveRectangle::getBlue() {
	return this->blue;
}

Uint8 InteractiveRectangle::getAlpha() {
	return this->alpha;
}

void InteractiveRectangle::resetState() {

	if (this->swapped || this->compared) {
		this->red = (DEFAULT_COLOR & 255 << 24) >> 24;
		this->green = (DEFAULT_COLOR & 255 << 16) >> 16;
		this->blue = (DEFAULT_COLOR & 255 << 8) >> 8;
		this->alpha = DEFAULT_COLOR & 255;
	}
	this->resetChecked();
	this->resetSwapped();
}
