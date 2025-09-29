#ifndef INCLUDE_ARRAY_HPP_
#define INCLUDE_ARRAY_HPP_

#include <vector>

#include "rectangle/Rect.hpp"

class Array {

	std::vector<Rect*> m_rects{};
	const RectangleType c_type;
	const int c_size;

public:


	Array(RectangleType, int, int, int);
	~Array();

	void shuffle();
	void printArray() const;
	[[nodiscard]] bool isSorted() const;

	void swap(int a, int b);

	[[nodiscard]] int value(int index) const;
	void value(int index, int value) const;

	[[nodiscard]] int size() const;

	Rect*& operator[](int);

};

#endif /* INCLUDE_ARRAY_HPP_ */
