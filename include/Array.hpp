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

	void shuffle() const;
	[[nodiscard]] bool is_sorted() const;
	void swap(int,int) const;
	void swap(int,Rect*) const;
	void print() const;

	void window_resize(float,float,float,float) const;

	[[nodiscard]] float value(int index) const;
	void value(int index, float value) const;

	[[nodiscard]] int size() const;

	Rect*& operator[](int);

};

#endif /* INCLUDE_ARRAY_HPP_ */
