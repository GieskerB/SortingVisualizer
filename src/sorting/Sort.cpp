#ifndef INCLUDE_SORTER_CPP_
#define INCLUDE_SORTER_CPP_

#include "../../include/sorting/Sort.hpp"

Sort::Sort(Array *array, Renderer *renderer) {
	this->array = array;
	this->renderer = renderer;
}

Sort::~Sort() {
	// Nothing to delete here... Only pointers to data outside of this construct
}

void Sort::sortFully() {
	this->sort(-1);
	this->renderer->renderArray();
	SDL_Delay(16);
}

void Sort::sortStepByStep() {
	this->sort(1);
	this->renderer->renderArray();
	SDL_Delay(16);
}

void Sort::sortMultipleSteps(int numSteps) {
	this->sort(numSteps);
	this->renderer->renderArray();
	SDL_Delay(16);
}

#endif /* INCLUDE_SORTER_CPP_ */
