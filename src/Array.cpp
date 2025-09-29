#ifndef INCLUDE_ARRAY_CPP_
#define INCLUDE_ARRAY_CPP_

#include <iostream>
#include <SDL3/SDL.h>

#include "../include/rectangle/AllRectangles.hpp"
#include "../include/Array.hpp"

Array::Array(const RectangleType type, const int arr_size, const int window_width, const int window_height) :
		c_type(type), c_size(arr_size) {

	m_rects.resize(c_size);
	const int rect_width = window_width / c_size;
	for (int i = 0; i < c_size; i++) {
		const int rect_height = window_height / c_size * (i + 1);
		switch (type) {
			case RAINBOW:
				m_rects[i] = new RainbowRect(i* rect_width, window_height - rect_height, rect_width, rect_height);
				break;
			case INTERACTIVE:
				m_rects[i] = new InteractRect(i* rect_width, window_height - rect_height, rect_width, rect_height);
				break;
		}
		m_rects[i]->init_color(window_height);
	}
}

Array::~Array() {
	for (int i = 0; i < c_size; i++) {
		delete m_rects[i];
	}
}

// Shuffles the array
void Array::shuffle() {
	for (int i = 0; i < c_size; i++) {
		const int randIndex = std::rand() % (c_size - i) + i;
		swap(i, randIndex);
	}
}

// prints the array
void Array::printArray() const {
	for (int i = 0; i < c_size; i++) {
		std::cout << m_rects[i]->value() << " ";
	}
	std::cout << std::endl;
}

bool Array::isSorted() const {
	for (int i = 0; i < c_size - 1; i++) {
		if (m_rects[i]->value() > m_rects[i + 1]->value()) {
			return false;
		}
	}
	return true;
}

// Swaps Values in the array at index 'a' and 'b'
void Array::swap(int a, int b) {
	Rect* rectA = m_rects[a];
	Rect* rectB = m_rects[b];

	const float tmp_X = rectA->x;
	rectA->x = rectB->x;
	rectB->x = tmp_X;

	m_rects[a] = rectA;
	m_rects[b] = rectB;

	Rect *tmp = m_rects[a];
	m_rects[a] = m_rects[b];
	m_rects[b] = tmp;

}

int Array::value(const int index) const {
	if (index < 0 || index >= c_size) {
		return -1;
	}
	return m_rects[index]->value();
}
void Array::value(const int index, const int value) const {
	if (index < 0 || index >= c_size) {
		throw std::invalid_argument("index out of range");
	}
	return m_rects[index]->value(value);
}

int Array::size() const {
	return c_size;
}

Rect*& Array::operator[](const int index) {
	return m_rects[index];
}

#endif /* INCLUDE_ARRAY_CPP_ */
