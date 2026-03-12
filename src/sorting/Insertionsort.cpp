#include "../../include/sorting/Insertionsort.hpp"

Insertionsort::Insertionsort(Array *array) : Sort(array), done_reverse(true), glob_i(1), glob_j(1) {}

void Insertionsort::sort(const int limit) {

    if (array->is_sorted()) return;

    swaps = 0;
    for (int i = glob_i; i < array->size(); ++i) {
        if (done_reverse) {
            glob_j = i;
            done_reverse = false;
        }
        int j;
        for (j = glob_j; j > 0; --j) {
            if (array->value(j) < array->value(j - 1)) {
                array->swap(j, j - 1);
                ++swaps;
                if (swaps >= limit) {
                    glob_i = i;
                    glob_j = j;
                    return;
                }
            } else {
                done_reverse = true;
                // break;
            }
        }
        if (glob_j == 0) done_reverse = true;
    }
}

void Insertionsort::reset() {
    done_reverse = true;
    glob_i = glob_j = 1;
}
