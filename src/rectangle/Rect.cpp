#ifndef INCLUDE_RECTANGLE_CPP_
#define INCLUDE_RECTANGLE_CPP_

#include "../../include/rectangle/Rect.hpp"

Rect::~Rect() = default;

SDL_Rect &Rect::rect() {
	return m_rect;
}

void Rect::rect(const SDL_Rect &rect) {
	m_rect = rect;
}

int& Rect::value() {
	return m_rect.h;
}

void Rect::value(int value) {
	m_rect.h = value;
}

uint8_t &Rect::red() {
	return m_red;
}

void Rect::red(uint8_t red) {
	m_red = red;
}

uint8_t &Rect::green() {
	return m_green;
}

void Rect::green(uint8_t green) {
	m_green = green;
}

uint8_t &Rect::blue() {
	return m_blue;
}

void Rect::blue(uint8_t blue) {
	m_blue = blue;
}

#endif /* INCLUDE_RECTANGLE_CPP_ */
