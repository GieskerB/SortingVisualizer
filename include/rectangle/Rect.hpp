#ifndef INCLUDE_RECTANGLE_HPP_
#define INCLUDE_RECTANGLE_HPP_

#include <SDL3/SDL.h>

enum RectangleType {
	INTERACTIVE, RAINBOW
};

class Rect {

	SDL_Rect m_rect;

protected:

	uint8_t m_red, m_green, m_blue;

	constexpr Rect(const int x, const int y, const int w, const int h,
					 const uint8_t r, const uint8_t g, const uint8_t b) : m_rect(x, y, w, h),
																		  m_red(r), m_green(g), m_blue(b) {
	}
	constexpr Rect(const int x, const int y, const int w, const int h) : m_rect(x, y, w, h),
	m_red(69), m_green(69), m_blue(69) {
	}

public:

	virtual ~Rect();

	[[nodiscard]] SDL_Rect& rect() ;
	void rect(const SDL_Rect &);

	[[nodiscard]] int& value();
	void value(int);

	uint8_t& red();
	void red(uint8_t);
	uint8_t& green();
	void green(uint8_t);
	uint8_t& blue();
	void blue(uint8_t);

	virtual void resetState() = 0;

};

#endif /* INCLUDE_RECTANGLE_HPP_ */
