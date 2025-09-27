#ifndef INCLUDE_ARRAY_CPP_
#define INCLUDE_ARRAY_CPP_

#include <iostream>
#include <SDL3/SDL.h>

#include "../include/rectangle/AllRectangles.hpp"
#include "../include/Array.hpp"

void Array::fillArray(int wWidth, int wHeight) {
	array = new Rect*[this->SIZE];
	for (int i = 0; i < this->SIZE; i++) {
		switch (this->TYPE) {
		case INTERACTIVE:
			array[i] = new InteractRect(wWidth, wHeight, i, this->SIZE);
			break;
		case RAINBOW:
			array[i] = new RainbowRect(wWidth, wHeight, i, this->SIZE);
			break;
		default:
			array[i] = nullptr;
		}

	}
}

Array::Array(RectangleType type, int size, int wWidth, int wHeight) :
		TYPE(type), SIZE(size) {

	this->fillArray(wWidth, wHeight);

}

Array::~Array() {
	for (int i = 0; i < this->SIZE; i++) {
		delete this->array[i];
	}
	delete this->array;
}

// Shuffles the array
void Array::shuffle() {
	for (int i = 0; i < this->SIZE; i++) {
		int randIndex = std::rand() % (this->SIZE - i) + i;
		swap(i, randIndex);
	}
}

// prints the array
void Array::printArray() {
	for (int i = 0; i < this->SIZE; i++) {
		std::cout << array[i]->value() << " ";
	}
	std::cout << std::endl;
}

bool Array::isSorted() {
	for (int i = 0; i < this->SIZE - 1; i++) {
		if (this->array[i]->value() > this->array[i + 1]->value()) {
			return false;
		}
	}
	return true;
}

// Swaps Values in the array at index 'a' and 'b'
void Array::swap(int a, int b) {
	SDL_Rect rectA = array[a]->rect();
	SDL_Rect rectB = array[b]->rect();

	int tmp_X = rectA.x;
	rectA.x = rectB.x;
	rectB.x = tmp_X;

	array[a]->rect(rectA);
	array[b]->rect(rectB);

	Rect *tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;

	if (this->TYPE == RectangleType::INTERACTIVE) {
		((InteractRect*) array[a])->setSwapped();
		((InteractRect*) array[b])->setSwapped();
	}

}

int Array::getValue(int index) {
	if (index < 0 || index >= SIZE) {
		return -1;
	}
	return this->array[index]->value();
}

int& Array::operator[](int index) {
	return this->array[index]->value();
}

Rect* Array::get(int index) {
	if (index < 0 || index >= SIZE) {
		return nullptr;
	}
	return this->array[index];
}

void Array::set(Rect *rect, int index) {
	this->array[index] = rect;
	this->array[index]->value(index);
}

#endif /* INCLUDE_ARRAY_CPP_ */
