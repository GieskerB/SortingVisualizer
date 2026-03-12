#include "../../include/sorting/Bubblesort.hpp"

Bubblesort::Bubblesort(Array *array) : Sort(array), glob_i(0), glob_j(0) {}

void Bubblesort::sort(const int limit) {

    if (array->is_sorted()) return;

    swaps = 0;
    for (int i = glob_i; i < array->size(); ++i) {
        for (int j = glob_j; j < array->size() - 1; ++j) {
            if (array->value(j) > array->value(j + 1)) {
                array->swap(j, j + 1);
                ++swaps;
                if (swaps >= limit) {
                    glob_i = i;
                    glob_j = j;
                    return;
                }
            }
        }
        glob_j = 0;
    }
}

void Bubblesort::reset() {
    glob_i = glob_j = 0;
}

