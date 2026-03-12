#include "../../include/sorting/Stoogesort.hpp"

#include <cmath>

Stoogesort::Stoogesort(Array *array) : Sort(array) {}

void Stoogesort::split(const int begin, const int end, const int limit, StackMemory<void, 3> *node) {
    if (begin >= end) {
        node->visited = true;
        return;
    }

    if (const int delta = end - begin; delta == 1) {
        if (array->value(begin) > array->value(end)) {
            array->swap(begin, end);
            ++swaps;
            if (swaps >= limit) {
                node->visited = true;
                throw swaps;
                // Store current state.
                // Da a "super" return -> throw?
            }
        }
    } else {
        const int third = std::ceil(delta / 3.0);

        if (node->children[0] == nullptr) {
            node->children[0] = new StackMemory<void, 3>;
            node->children[1] = new StackMemory<void, 3>;
            node->children[2] = new StackMemory<void, 3>;
        }

        if (!node->children[0]->visited)
            split(begin, end - third, limit, node->children[0]);
        if (!node->children[1]->visited)
            split(begin + third, end, limit, node->children[1]);
        if (!node->children[2]->visited)
            split(begin, end - third, limit, node->children[2]);
    }
    node->visited = true;
}

void Stoogesort::sort(const int limit) {
    if (array->is_sorted()) return;
    swaps = 0;
    try {
        split(0, array->size() - 1, limit, &nodes);
    } catch (int) {
    }
}

void Stoogesort::reset() {
    for (int i = 0; i < 3; ++i) {
        delete nodes.children[i];
        nodes.children[i] = nullptr;
    }
}

