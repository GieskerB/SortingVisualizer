#include "../../include/sorting/Stoogesort.hpp"

#include <cmath>

Stoogesort::Stoogesort(Array *array, Renderer *renderer) :
		Sort(array, renderer) {
}

int Stoogesort::split(Uint16 begin, Uint16 end, Uint8 currentSteps,
		const int stepMax) {
	if (begin >= end) {
		return currentSteps;
	}
	currentSteps++;
	if (end - begin == 1) {
		if (this->array->compareBigger(begin, end)) {
			currentSteps = this->renderer->renderSwap(begin, end, currentSteps, stepMax);
//			this->array->swap(begin, end);
		}
	} else {
		int delta = end - begin + 1;
		int oneThirds = (int) std::floor(1.0 * delta / 3.0);
		int twoThirds = (int) std::ceil(2.0 * delta / 3.0);

		currentSteps = this->split(begin, begin - 1 + twoThirds, currentSteps,
				stepMax);
		currentSteps = this->split(begin + oneThirds, end, currentSteps,
				stepMax);
		currentSteps = this->split(begin, begin - 1 + twoThirds, currentSteps,
				stepMax);
	}
//	this->renderer->renderArray();
	return currentSteps;
}

void Stoogesort::sort(int stepCount) {
	this->split(0, this->array->SIZE - 1, 0, stepCount);
}

