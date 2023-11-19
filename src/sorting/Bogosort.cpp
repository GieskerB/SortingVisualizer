#include "../../include/sorting/Bogosort.hpp"

Bogosort::Bogosort(Array *array, Renderer *renderer) :
		Sort(array, renderer) {
}

void Bogosort::sort(int stepCount) {
	while (!this->array->isSorted()) {
		this->array->shuffle();
		this->renderer->renderArray();
	}
}

