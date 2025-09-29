#include "../../include/sorting/Bogosort.hpp"

Bogosort::Bogosort(Array *array) :
		Sort(array) {
}

void Bogosort::sort(const int limit) {
	for (int i = 0; i < limit; ++i) {
		if (array->is_sorted()) return;
		this->array->shuffle();
	}
}

