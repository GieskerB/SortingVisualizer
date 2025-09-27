#ifndef INCLUDE_ARRAY_HPP_
#define INCLUDE_ARRAY_HPP_

#include <sys/types.h>

#include "rectangle/Rect.hpp"

class Array {

	Rect **array;

	void fillArray(int wWidth, int wHeight);

public:

	const RectangleType TYPE;
	const int SIZE;

	Array(RectangleType type, int size, int wWidth, int wHeight);
	~Array();

	void shuffle();
	void printArray();
	bool isSorted();

	void swap(int a, int b);

	int getValue(int index);

	int& operator[](int);
	
	Rect* get(int index);
	void set(Rect *rect, int index);

};

#endif /* INCLUDE_ARRAY_HPP_ */
