#include "../../include/sorting/Selectionsort.hpp"

#include <limits>

Selectionsort::Selectionsort(Array *array) :
        Sort(array), glob_i(0), glob_j(0) {
}

void Selectionsort::sort(int limit) {

    if (array->is_sorted()) return;

    swaps = 0;
    for (int i = glob_i; i < array->size() - 1; ++i) {
        float min_val = std::numeric_limits<float>::max();
        int min_index = 0;
        glob_j = i;
        int j = glob_j;
        for (; j < array->size(); ++j) {
            if (array->value(j) < min_val) {
                min_val = array->value(j);
                min_index = j;
            }
        }
        array->swap(i, min_index);
        ++swaps;
        if (swaps >= limit) {
            glob_i = i + 1;
            glob_j = j;
            return;
        }
    }
}

void Selectionsort::reset() {
    glob_i = glob_j = 0;
}

