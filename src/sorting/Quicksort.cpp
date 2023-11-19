#include "../../include/sorting/Quicksort.hpp"

#include <iostream>

Quicksort::Quicksort(Array *array, Renderer *renderer, PivotType pivotType) :
		Sort(array, renderer), PIVOT_TYPE(pivotType) {

}

Uint16 Quicksort::getPivotIndex(Uint16 begin, Uint16 end) {
	switch (this->PIVOT_TYPE) {
	case FIRST:
		return begin;
	case MIDDEL:
		return (begin + end) / 2;
	case LAST:
		return end;
	case RANDOM:
		return (std::rand() % (end - begin)) + begin;
	default:
		return -1;
	}
}

Uint16 Quicksort::quicksort(Uint16 begin, Uint16 end, Uint16 currentSteps,
		const int maxSteps) {
	if (begin >= end || end > this->array->SIZE) {
		return currentSteps;
	}
	// pick a pivot element and swap it with the last element in this range
	const Uint16 pivotIndex = this->getPivotIndex(begin, end);
	const Uint16 pivotValue = this->array->getValue(pivotIndex);
	currentSteps = this->renderer->renderSwap(pivotIndex, end, currentSteps,
			maxSteps);

	// Perform the partitioning
	Uint16 leftPointer = begin;
	Uint16 rightPointer = end;
	while (leftPointer < rightPointer) {
		// Search for the next element greater and left from the pivot
		while (!(this->array->compareBiggerToValue(leftPointer, pivotValue))
				&& leftPointer < rightPointer) {
			leftPointer++;
		}
		// Search for the next element smaller and right from the pivot
		while (!(this->array->compareSmallerToValue(rightPointer, pivotValue))
				&& leftPointer < rightPointer) {
			rightPointer--;
		}
		// Swap them
		currentSteps = this->renderer->renderSwap(leftPointer, rightPointer,
				currentSteps, maxSteps);
	}
	currentSteps = this->renderer->renderSwap(leftPointer, end, currentSteps,
			maxSteps);

	// Recursive call
	currentSteps = this->quicksort(begin, leftPointer - 1, currentSteps,
			maxSteps);
	currentSteps = this->quicksort(leftPointer + 1, end, currentSteps,
			maxSteps);

	return currentSteps;
}

void Quicksort::sort(int stepCount) {
	this->quicksort(0, this->array->SIZE - 1, 0, stepCount);
}
