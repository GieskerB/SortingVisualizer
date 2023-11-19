#include "../../include/sorting/Heapsort.hpp"

Heapsort::Heapsort(Array *array, Renderer *renderer) :
		Sort(array, renderer) {
	this->heapSize = this->array->SIZE;
}

Uint16 Heapsort::leftChildIndex(Uint16 parenIndex) {
	return 2 * parenIndex + 1;
}

Uint16 Heapsort::rightChildIndex(Uint16 parenIndex) {
	return 2 * parenIndex + 2;
}

Uint16 Heapsort::heapify(const Uint16 index, Uint16 currentSteps,
		const int maxSteps) {
	if (this->leftChildIndex(index) < this->heapSize) { // hasLeft
		currentSteps = this->heapify(2 * index + 1, currentSteps, maxSteps);
	}
	if (this->rightChildIndex(index) < this->heapSize) { // hasRight
		currentSteps = this->heapify(2 * index + 2, currentSteps, maxSteps);
	}

	currentSteps = this->siftDown(index, currentSteps, maxSteps);
	return currentSteps;
}

Uint16 Heapsort::siftDown(const Uint16 index, Uint16 currentSteps,
		const int maxSteps) {
	// Break condition: "Node" is a leaf
	if (this->leftChildIndex(index) >= this->heapSize) { // If has Right must have Left
		return currentSteps;
	}

	const Uint16 lci = this->leftChildIndex(index);
	const Uint16 rci = this->rightChildIndex(index);

	if (rci < this->heapSize) {
		// Has left and right child
		if (this->array->compareBigger(lci, rci)) {
			// Left Child bigger then right
			if (this->array->compareBigger(lci, index)) {
				// left child bigger then parent
				currentSteps = this->renderer->renderSwap(lci,index, currentSteps, maxSteps);
			}
		} else {
			// Right Child bigger then left
			if (this->array->compareBigger(rci, index)) {
				// right child bigger then parent
				currentSteps = this->renderer->renderSwap(rci,index, currentSteps, maxSteps);
			}
		}
		// Recursive call for left and right child
		currentSteps = this->siftDown(lci, currentSteps, maxSteps);
		currentSteps = this->siftDown(rci, currentSteps, maxSteps);
	} else {
		// Only has a left Child
		if (this->array->compareBigger(lci, index)) {
			// left child bigger then parent
			currentSteps = this->renderer->renderSwap(lci,index, currentSteps, maxSteps);
		}
		// Recursive call only for left child
		currentSteps = this->siftDown(lci, currentSteps, maxSteps);
	}
	return currentSteps;
}

void Heapsort::sort(int stepCount) {
	this->renderer->renderArray();
	int currentSteps = this->heapify(0, 0, stepCount);

	while (this->heapSize > 0) {
		this->array->swap(0, this->heapSize - 1);
		this->heapSize--;
		currentSteps = this->siftDown(0, currentSteps, stepCount);
		if (stepCount > 0 && currentSteps >= stepCount) {
			currentSteps = 0;
			this->renderer->renderArray();
		}
	}
}

