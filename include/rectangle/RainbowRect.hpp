#ifndef INCLUDE_RAINBOWRECTANGLE_HPP_
#define INCLUDE_RAINBOWRECTANGLE_HPP_

#include "Rect.hpp"

class RainbowRect: public Rect {


	uint8_t initRed(int value, int maxValue) const;
	uint8_t initGreen(int value, int maxValue) const;
	uint8_t initBlue(int value, int maxValue) const;

public:

	constexpr RainbowRect(const int x, const int y, const int w,const int h) :
		Rect(x, y, w, h) {
	}

	void resetState() override;
};

#endif /* INCLUDE_RAINBOWRECTANGLE_HPP_ */
