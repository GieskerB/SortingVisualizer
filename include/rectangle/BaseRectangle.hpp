#ifndef INCLUDE_RECTANGLE_HPP_
#define INCLUDE_RECTANGLE_HPP_

#include <SDL_rect.h>

enum RectangleType {
	INTERACTIVE, RAINBOW
};

class BaseRectangle {

private:

	const Uint16 VALUE;

	const Uint16 MAX_VALUE;

	SDL_Rect rect;

protected:


	Uint8 red, green, blue, alpha;

	static Uint16 mapValue(Uint16 value, Uint16 fromMin, Uint16 fromMax,
			Uint16 toMin, Uint16 toMax);

	BaseRectangle(Uint16 wWidth, Uint16 wHeight, Uint16 value, Uint16 maxValue,
			Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

public:

	virtual ~BaseRectangle();

	SDL_Rect getRect();
	void setRect(const SDL_Rect &rect);

	SDL_Rect* getRectPointer();

	void updateRect(Uint16 index);

	virtual Uint8 getRed() = 0;
	virtual Uint8 getGreen() = 0;
	virtual Uint8 getBlue() = 0;
	virtual Uint8 getAlpha() = 0;

	virtual void resetState() = 0;

	Uint16 getValue();

};

#endif /* INCLUDE_RECTANGLE_HPP_ */
