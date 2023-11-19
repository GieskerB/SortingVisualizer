#include "../../include/sorting/Selectionsort.hpp"

Selectionsort::Selectionsort(Array *array, Renderer *renderer) :
		Sort(array, renderer) {
}

void Selectionsort::sort(int stepCount) {
	Uint16 currentSteps = 0;

	for (int i = 0; i < this->array->SIZE - 1; i++) {
		Uint16 minValue = 65535;
		Uint16 minIndex;
		for (int j = i; j < this->array->SIZE; j++) {
			if (this->array->compareSmallerToValue(j, minValue)) {
				minValue = this->array->getValue(j);
				minIndex = j;
			}
		}
		currentSteps = this->renderer->renderSwap(i, minIndex, currentSteps,
				stepCount);
	}
}

