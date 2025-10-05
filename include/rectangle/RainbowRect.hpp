#ifndef INCLUDE_RAINBOWRECTANGLE_HPP_
#define INCLUDE_RAINBOWRECTANGLE_HPP_

#include "Rect.hpp"

struct RainbowRect: Rect {

	constexpr RainbowRect(const float x, const float y, const float w,const float h) :
		Rect(x, y, w, h) {
	}

	void resetState() override;
	void init_color(float) override;
	Rect* copy() override;
};

#endif /* INCLUDE_RAINBOWRECTANGLE_HPP_ */
