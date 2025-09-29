#ifndef INCLUDE_ARRAY_HPP_
#define INCLUDE_ARRAY_HPP_

#include <vector>

#include "rectangle/Rect.hpp"

class Array {

	std::vector<Rect*> m_rects{};
	const RectangleType c_type;
	const int c_size;

public:


	Array(RectangleType, int, float, float);
	~Array();

	void shuffle();
	[[nodiscard]] bool isSorted() const;
	void swap(int,int);
	void print() const;

	void window_resize(float,float,float,float);

	[[nodiscard]] int value(int index) const;
	void value(int index, int value) const;

	[[nodiscard]] int size() const;

	Rect*& operator[](int);

};

#endif /* INCLUDE_ARRAY_HPP_ */
