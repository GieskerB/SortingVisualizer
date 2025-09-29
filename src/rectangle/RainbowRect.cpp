#ifndef INCLUDE_RAINBOWRECTANGLE_CPP_
#define INCLUDE_RAINBOWRECTANGLE_CPP_

#include "../../include/rectangle/RainbowRect.hpp"

#include <iostream>
#include <ostream>
#include <stdexcept>

void RainbowRect::init_color(const float max_val) {
	const float hue = h / max_val * 360;
	const float sixth = hue / 60.0f;
	const int sixth_int = static_cast<int>(sixth);

	const float decimal = sixth - static_cast<float>(sixth_int);
	const float decimal_inv = 1 - decimal;

	switch (sixth_int) {
		case 0:
		case 6:
			r = 255;
			g = static_cast<uint8_t>(decimal * 255);
			b = 0;
			break;
		case 1:
			r = static_cast<uint8_t>(decimal_inv * 255);
			g = 255;
			b = 0;
			break;
		case 2:
			r = 0;
			g = 255;
			b = static_cast<uint8_t>(decimal * 255);
			break;
		case 3:
			r = 0;
			g = static_cast<uint8_t>(decimal_inv * 255);
			b = 255;
			break;
		case 4:
			r = static_cast<uint8_t>(decimal * 255);
			g = 0;
			b = 255;
			break;
		case 5:
			r = 255;
			g = 0;
			b = static_cast<uint8_t>(decimal_inv * 255);
			break;
		default:
			throw std::runtime_error("RainbowRect::init_color: Invalid color");
	}
}

void RainbowRect::resetState() {
}

#endif /* INCLUDE_RAINBOWRECTANGLE_CPP_ */

