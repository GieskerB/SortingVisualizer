#ifndef INCLUDE_ARRAY_HPP_
#define INCLUDE_ARRAY_HPP_

#include "rectangle/BaseRectangle.hpp"

class Array {

//	friend class Sort;
//	friend class Renderer;

private:

	BaseRectangle **array;

	void fillArray(Uint16 wWidth, Uint16 wHeight);

//protected:

public:

	const RectangleType TYPE;
	const Uint16 SIZE;

	Array(RectangleType type, Uint16 size, Uint16 wWidth, Uint16 wHeight);
	~Array();

	void shuffle();
	void printArray();

	bool isSorted();

	bool compareBigger(Uint16 a, Uint16 b);
	bool compareSmaller(Uint16 a, Uint16 b);

	bool compareBiggerToValue(Uint16 index, Uint16 value);
	bool compareSmallerToValue(Uint16 index, Uint16 value);

	void swap(Uint16 a, Uint16 b);

	Uint16 getValue(Uint16 index);

	BaseRectangle* get(Uint16 index);
	void set(BaseRectangle *rect, Uint16 index);

};

#endif /* INCLUDE_ARRAY_HPP_ */
