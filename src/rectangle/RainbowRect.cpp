#ifndef INCLUDE_RAINBOWRECTANGLE_CPP_
#define INCLUDE_RAINBOWRECTANGLE_CPP_

#include <iostream>

#include "../../include/rectangle/RainbowRect.hpp"

constexpr int map_range(const int input, const int input_start, const int input_end, const int output_start, const int output_end) {
	return static_cast<int>(static_cast<float>(output_start)
		+ static_cast<float>(output_end - output_start)
		/ static_cast<float>(input_end - input_start)
		* static_cast<float>(input - input_start));
}

uint8_t RainbowRect::initRed(int value, int maxValue) const {
	const int hue = map_range(value, 0, maxValue, 0, 360);
	const float sixth = hue / 60.0;
	const int sixthInt = sixth;

	const float decimal = sixth - sixthInt;
	const float inversDecimal = 1 - decimal;

	uint8_t redValue;

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

uint8_t RainbowRect::initGreen(int value, int maxValue) const {
	const int hue = map_range(value, 0, maxValue, 0, 360);
	const float sixth = hue / 60.0;
	const int sixthInt = sixth;

	const float decimal = sixth - sixthInt;
	const float inversDecimal = 1 - decimal;

	uint8_t greenValue;

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

uint8_t RainbowRect::initBlue(int value, int maxValue) const {
	const int hue = map_range(value, 0, maxValue, 0, 360);
	const float sixth = hue / 60.0;
	const int sixthInt = sixth;

	const float decimal = sixth - sixthInt;
	const float inversDecimal = 1 - decimal;

	uint8_t blueValue;

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

void RainbowRect::resetState() {
}

#endif /* INCLUDE_RAINBOWRECTANGLE_CPP_ */

