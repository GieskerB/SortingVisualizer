#ifndef INCLUDE_ARRAY_CPP_
#define INCLUDE_ARRAY_CPP_

#include "../include/Array.hpp"

#include <iostream>
#include "../include/rectangle/AllRectangles.hpp"

// Fills the array with numbers from 1 up-to size
void Array::fillArray(Uint16 wWidth, Uint16 wHeight) {
	array = new BaseRectangle*[this->SIZE];
	for (Uint16 i = 0; i < this->SIZE; i++) {
		switch (this->TYPE) {
		case INTERACTIVE:
			array[i] = new InteractiveRectangle(wWidth, wHeight, i, this->SIZE);
			break;
		case RAINBOW:
			array[i] = new RainbowRectangle(wWidth, wHeight, i, this->SIZE);
			break;
		default:
			array[i] = nullptr;
		}

	}
}

Array::Array(RectangleType type, Uint16 size, Uint16 wWidth, Uint16 wHeight) :
		TYPE(type), SIZE(size) {

	this->fillArray(wWidth, wHeight);

}

Array::~Array() {
	for (Uint16 i = 0; i < this->SIZE; i++) {
		delete this->array[i];
	}
	delete this->array;
}

// Shuffles the array
void Array::shuffle() {
	for (Uint16 i = 0; i < this->SIZE; i++) {
		int randIndex = std::rand() % (this->SIZE - i) + i;
		swap(i, randIndex);
	}
}

// prints the array
void Array::printArray() {
	for (Uint16 i = 0; i < this->SIZE; i++) {
		std::cout << array[i]->getValue() << " ";
	}
	std::cout << std::endl;
}

bool Array::isSorted() {
	for (Uint16 i = 0; i < this->SIZE - 1; i++) {
		if (this->array[i]->getValue() > this->array[i + 1]->getValue()) {
			return false;
		}
	}
	return true;
}

bool Array::compareBigger(Uint16 a, Uint16 b) {
	Uint16 aValue = this->array[a]->getValue();
	Uint16 bValue = this->array[b]->getValue();

	if (this->TYPE == RectangleType::INTERACTIVE) {
		((InteractiveRectangle*) array[a])->setCompared();
		((InteractiveRectangle*) array[b])->setCompared();
	}

	return aValue > bValue;

}

bool Array::compareSmaller(Uint16 a, Uint16 b) {
	Uint16 aValue = this->array[a]->getValue();
	Uint16 bValue = this->array[b]->getValue();

	if (this->TYPE == RectangleType::INTERACTIVE) {
		((InteractiveRectangle*) array[a])->setCompared();
		((InteractiveRectangle*) array[b])->setCompared();
	}

	return aValue < bValue;
}

bool Array::compareBiggerToValue(Uint16 index, Uint16 value) {
	Uint16 indexValue = this->array[index]->getValue();
	if (this->TYPE == RectangleType::INTERACTIVE) {
		((InteractiveRectangle*) array[index])->setCompared();
	}
	return indexValue > value;
}

bool Array::compareSmallerToValue(Uint16 index, Uint16 value) {
	Uint16 indexValue = this->array[index]->getValue();
	if (this->TYPE == RectangleType::INTERACTIVE) {
		((InteractiveRectangle*) array[index])->setCompared();
	}
	return indexValue < value;
}

// Swaps Values in the array at index 'a' and 'b'
void Array::swap(Uint16 a, Uint16 b) {
	SDL_Rect rectA = array[a]->getRect();
	SDL_Rect rectB = array[b]->getRect();

	int tmp_X = rectA.x;
	rectA.x = rectB.x;
	rectB.x = tmp_X;

	array[a]->setRect(rectA);
	array[b]->setRect(rectB);

	BaseRectangle *tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;

	if (this->TYPE == RectangleType::INTERACTIVE) {
		((InteractiveRectangle*) array[a])->setSwapped();
		((InteractiveRectangle*) array[b])->setSwapped();
	}

}

Uint16 Array::getValue(Uint16 index) {
	if (index < 0 || index >= SIZE) {
		return -1;
	}
	return this->array[index]->getValue();
}

BaseRectangle* Array::get(Uint16 index) {
	if (index < 0 || index >= SIZE) {
		return nullptr;
	}
	return this->array[index];
}

void Array::set(BaseRectangle *rect, Uint16 index) {
	this->array[index] = rect;
	this->array[index]->updateRect(index);
}

#endif /* INCLUDE_ARRAY_CPP_ */
