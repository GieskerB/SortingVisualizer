#include "../../include/sorting/Shellsort.hpp"

Shellsort::Shellsort(Array *array) : Sort(array), done_reverse(true), glob_i(1), glob_j(1), glob_gab(-1) {}

void Shellsort::sort(int limit) {
    if (array->is_sorted()) return;

    swaps = 0;

    if (glob_gab == -1) glob_gab = array->size() / 2;

    for (int gab = glob_gab; gab > 0; gab /= 2) {
        if (glob_i < glob_gab) glob_i = glob_gab;
        for (int i = glob_i; i < array->size(); ++i) {
            if (done_reverse) {
                glob_j = i;
                done_reverse = false;
            }
            int j;
            for (j = glob_j; j > 0; j -= gab) {
                if (array->value(j) < array->value(j - gab)) {
                    array->swap(j, j - gab);
                    ++swaps;
                    if (swaps >= limit) {
                        glob_gab = gab;
                        glob_i = i;
                        glob_j = j - gab;
                        return;
                    }
                } else {
                    done_reverse = true;
                    // break;
                }
            }
            if (glob_j == 0) done_reverse = true;
        }
        glob_i = glob_j = 1;
    }
}

void Shellsort::reset() {
    done_reverse = true;
    glob_i = glob_j = 1;
}
