#ifndef INCLUDE_RECTANGLE_HPP_
#define INCLUDE_RECTANGLE_HPP_

#include <SDL3/SDL.h>

enum RectangleType {
	INTERACTIVE, RAINBOW
};

struct Rect : SDL_FRect {

	uint8_t r, g, b;

	constexpr Rect(const float x, const float y, const float w, const float h,
					 const uint8_t r, const uint8_t g, const uint8_t b) : SDL_FRect(x, y, w, h),
																		  r(r), g(g), b(b) {
	}
	constexpr Rect(const float x, const float y, const float w, const float h) : SDL_FRect(x, y, w, h),
	r(69), g(69), b(69) {
	}


	virtual ~Rect();

	[[nodiscard]] float& value();
	void value(float);

	virtual void resetState() = 0;

};

#endif /* INCLUDE_RECTANGLE_HPP_ */
