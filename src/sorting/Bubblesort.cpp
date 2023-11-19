#include "../../include/sorting/Bubblesort.hpp"

Bubblesort::Bubblesort(Array *array, Renderer *renderer) :
		Sort(array, renderer) {
}

void Bubblesort::sort(int stepCount) {
	Uint16 currentSteps = 0;
	Uint16 totalIterations = 0;
	while (!this->array->isSorted()) {
		for (int i = 0; i < this->array->SIZE - (totalIterations + 1); i++) {
			if (this->array->compareBigger(i, i + 1)) {
				currentSteps = this->renderer->renderSwap(i, i + 1,
						currentSteps, stepCount);
			}
		}
		totalIterations++;
	}
}

