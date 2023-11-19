#ifndef INCLUDE_INTERACTIVERECTANGLE_HPP_
#define INCLUDE_INTERACTIVERECTANGLE_HPP_

#include <SDL_rect.h>

#include "BaseRectangle.hpp"

class InteractiveRectangle: public BaseRectangle {

private:


	static const Uint32 DEFAULT_COLOR = (255 << 24) | (255 << 16) | (255 << 8) | 255;
	static const Uint32 COMPARED_COLOR = (0 << 24) | (255 << 16) | (0 << 8) | 255;
	static const Uint32 SWAPPED_COLOR = (255 << 24) | (0 << 16) | (0 << 8) | 255;

	bool compared, swapped;

	void resetChecked();
	void resetSwapped();


public:

	InteractiveRectangle(Uint16 wWidth, Uint16 wHeight, Uint16 value,
			Uint16 maxValue);

	void setCompared();
	void setSwapped();

	Uint8 getRed()  override;

	Uint8 getGreen()  override;

	Uint8 getBlue()  override;

	Uint8 getAlpha()  override;

	void resetState() override;
};

#endif /* INCLUDE_INTERACTIVERECTANGLE_HPP_ */
