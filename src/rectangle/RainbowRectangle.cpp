#ifndef INCLUDE_RAINBOWRECTANGLE_CPP_
#define INCLUDE_RAINBOWRECTANGLE_CPP_

#include <SDL_stdinc.h>
#include <cmath>
#include <iostream>

#include "../../include/rectangle/RainbowRectangle.hpp"

Uint8 RainbowRectangle::initRed(Uint16 value, Uint16 maxValue) const {
	const Uint16 hue = mapValue(value, 0, maxValue, 0, 360);
	const float sixth = hue / 60.0;
	const int sixthInt = sixth;

	const float decimal = sixth - sixthInt;
	const float inversDecimal = 1 - decimal;

	Uint8 redValue;

	switch (sixthInt) {
	case 0:
	case 5:
		redValue = 255;
		break;
	case 2:
	case 3:
		redValue = 0;
		break;
	case 4:
		redValue = decimal * 255;
		break;
	case 1:
		redValue = inversDecimal * 255;
		break;
	default:
		redValue = -1;
	}

	return redValue;
}

Uint8 RainbowRectangle::initGreen(Uint16 value, Uint16 maxValue) const {
	const Uint16 hue = mapValue(value, 0, maxValue, 0, 360);
	const float sixth = hue / 60.0;
	const int sixthInt = sixth;

	const float decimal = sixth - sixthInt;
	const float inversDecimal = 1 - decimal;

	Uint8 greenValue;

	switch (sixthInt) {
	case 1:
	case 2:
		greenValue = 255;
		break;
	case 4:
	case 5:
		greenValue = 0;
		break;
	case 0:
		greenValue = decimal * 255;
		break;
	case 3:
		greenValue = inversDecimal * 255;
		break;
	default:
		greenValue = -1;
	}

	return greenValue;
}

Uint8 RainbowRectangle::initBlue(Uint16 value, Uint16 maxValue) const {
	const Uint16 hue = mapValue(value, 0, maxValue, 0, 360);
	const float sixth = hue / 60.0;
	const int sixthInt = sixth;

	const float decimal = sixth - sixthInt;
	const float inversDecimal = 1 - decimal;

	Uint8 blueValue;

	switch (sixthInt) {
	case 3:
	case 4:
		blueValue = 255;
		break;
	case 0:
	case 1:
		blueValue = 0;
		break;
	case 2:
		blueValue = decimal * 255;
		break;
	case 5:
		blueValue = inversDecimal * 255;
		break;
	default:
		blueValue = -1;
	}
	std::cout << "--" << blueValue << "--";
	return blueValue;
}

RainbowRectangle::RainbowRectangle(Uint16 wWidth, Uint16 wHeight, Uint16 value,
		Uint16 maxValue) :
		BaseRectangle(wWidth, wHeight, value, maxValue,
				initRed(value, maxValue), initGreen(value, maxValue),
				initBlue(value, maxValue), 255) {
}

Uint8 RainbowRectangle::getRed() {
	return this->red;
}

Uint8 RainbowRectangle::getGreen() {
	return this->green;
}

Uint8 RainbowRectangle::getBlue() {
	return this->blue;
}

Uint8 RainbowRectangle::getAlpha() {
	return this->alpha;
}

void RainbowRectangle::resetState() {
}

#endif /* INCLUDE_RAINBOWRECTANGLE_CPP_ */

