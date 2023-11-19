#ifndef INCLUDE_RAINBOWRECTANGLE_HPP_
#define INCLUDE_RAINBOWRECTANGLE_HPP_

#include "BaseRectangle.hpp"
class RainbowRectangle: public BaseRectangle {

private:

	Uint8 initRed(Uint16 value, Uint16 maxValue) const;
	Uint8 initGreen(Uint16 value, Uint16 maxValue) const;
	Uint8 initBlue(Uint16 value, Uint16 maxValue) const;

public:

	RainbowRectangle(Uint16 wWidth, Uint16 wHeight, Uint16 value,
			Uint16 maxValue);

	Uint8 getRed()  override;

	Uint8 getGreen()  override;

	Uint8 getBlue()  override;

	Uint8 getAlpha()  override;

	void resetState() override;
};

#endif /* INCLUDE_RAINBOWRECTANGLE_HPP_ */
