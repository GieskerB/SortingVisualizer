#include "../../include/sorting/Mergesort.hpp"

#include "../../include/rectangle/InteractiveRectangle.hpp"

Uint8 Mergesort::divide(Uint16 start, Uint16 end, Uint8 currentSteps,
		int maxSteps) {
	if (start >= end) {
		return currentSteps;
	}

	const Uint16 middle = (start + end) / 2 + start;

	currentSteps = this->divide(start, middle, currentSteps, maxSteps);
	currentSteps = this->divide(middle, end, currentSteps, maxSteps);

	currentSteps = this->conquer(start, middle, end, currentSteps, maxSteps);

	return currentSteps;
}

Uint8 Mergesort::conquer(Uint16 start, Uint16 middle, Uint16 end,
		Uint8 currentSteps, int maxSteps) {

	const Uint16 ARR1SIZE = middle - start;
	const Uint16 ARR2SIZE = end - middle;

	BaseRectangle *arr1[ARR1SIZE], *arr2[ARR2SIZE];

	for (int i = start; i < middle; i++) {
		arr1[i - start] = this->array->get(i);
	}

	for (int i = middle; i < end; i++) {
		arr2[i - middle] = this->array->get(i);
	}

	Uint16 leftPointer = start, rightPointer = middle, totalPointer = start;

	while (leftPointer < middle && rightPointer < end) {
		if (this->array->TYPE == RectangleType::INTERACTIVE) {
			((InteractiveRectangle*) arr1[leftPointer])->setCompared();
			((InteractiveRectangle*) arr2[rightPointer])->setCompared();
		}
		if (arr1[leftPointer]->getValue() > arr2[rightPointer]->getValue()) {
			if (this->array->TYPE == RectangleType::INTERACTIVE) {
				((InteractiveRectangle*) arr2[rightPointer])->setSwapped();
			}
			this->array->set(arr2[rightPointer++], totalPointer++);

		} else {
			if (this->array->TYPE == RectangleType::INTERACTIVE) {
				((InteractiveRectangle*) arr1[leftPointer])->setSwapped();
			}
			this->array->set(arr1[leftPointer++], totalPointer++);
		}

	}

	while (leftPointer < middle) {
		if (this->array->TYPE == RectangleType::INTERACTIVE) {
			((InteractiveRectangle*) arr1[leftPointer])->setSwapped();
		}
		this->array->set(arr1[leftPointer++], totalPointer++);
	}

	while (rightPointer < end) {
		if (this->array->TYPE == RectangleType::INTERACTIVE) {
			((InteractiveRectangle*) arr2[rightPointer])->setSwapped();
		}
		this->array->set(arr2[rightPointer++], totalPointer++);
	}

	this->renderer->renderArray();

	return currentSteps;
}

Mergesort::Mergesort(Array *array, Renderer *renderer) :
		Sort(array, renderer) {
}

void Mergesort::sort(int stepCount) {
	this->divide(0, this->array->SIZE, 0, stepCount);
}

