//
// Created by bjarne on 3/11/26.
//

#include "../../include/sorting/Cyclesort.hpp"

Cyclesort::Cyclesort(Array* array): Sort (array), glob_cycle(-1){

}

void Cyclesort::sort(const int limit) {
    if (array->is_sorted()) return;

    if (glob_cycle == -1) glob_cycle = 0;
    swaps = 0;
    int cycle_index = glob_cycle;
    while (!array->is_sorted()) {
        int smaller = 0;
        Rect* curr = (*array)[cycle_index];
        for (int i = cycle_index + 1; i < array->size(); i++) {
            if (array->value(i) < curr->value()) {
                ++smaller;
            }
        }
        if (smaller == 0) {
            // Correct position;
            ++cycle_index;
        } else {
            array->swap(cycle_index, cycle_index + smaller);
            swaps++;
            if (swaps > limit) {
                glob_cycle = cycle_index;
                return;
            }
        }
    }
}

void Cyclesort::reset(){
    glob_cycle = -1;
}
