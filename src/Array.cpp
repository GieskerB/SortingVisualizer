#ifndef INCLUDE_ARRAY_CPP_
#define INCLUDE_ARRAY_CPP_

#include <iostream>
#include <SDL3/SDL.h>

#include "../include/rectangle/AllRectangles.hpp"
#include "../include/Array.hpp"

constexpr float map_range(const float input, const float input_start, const float input_end, const float output_start, const float output_end) {
	return output_start
		+ (output_end - output_start)
		/ (input_end - input_start)
		* (input - input_start);
}

Array::Array(const RectangleType type, const int arr_size, const float window_width, const float window_height) :
		c_type(type), c_size(arr_size) {

	m_rects.resize(c_size);
	const float rect_width = window_width / c_size;
	for (int i = 0; i < c_size; i++) {
		const float rect_height = window_height / c_size * (i + 1);
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

void Array::swap(int i, int j ) {
	const auto temp_r = m_rects[i]->r;
	const auto temp_g = m_rects[i]->g;
	const auto temp_b = m_rects[i]->b;
	const auto temp_y = m_rects[i]->y;
	const auto temp_h = m_rects[i]->h;
	m_rects[i]->r = m_rects[j]->r;
	m_rects[i]->g = m_rects[j]->g;
	m_rects[i]->b = m_rects[j]->b;
	m_rects[i]->y = m_rects[j]->y;
	m_rects[i]->h = m_rects[j]->h;
	m_rects[j]->r = temp_r;
	m_rects[j]->g = temp_g;
	m_rects[j]->b = temp_b;
	m_rects[j]->y = temp_y;
	m_rects[j]->h = temp_h;
}

void Array::print() const {
	for (const auto& r : m_rects) {
		std::cout << r->h << " ";
	}
	std::cout << std::endl;
}



bool Array::is_sorted() const {
	for (int i = 0; i < c_size - 1; i++) {
		if (m_rects[i]->value() > m_rects[i + 1]->value()) {
			return false;
		}
	}
	return true;
}

void Array::window_resize(const float old_width, const float old_height, const float new_width, const float new_height) {
	for (auto& rect : m_rects) {
		rect->x = map_range(rect->x,0,old_width,0,new_width);
		rect->y = map_range(rect->y,0,old_height,0,new_height);
		rect->w = new_width / c_size;
		rect->h = map_range(rect->h,0,old_height,0,new_height);
	}
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
