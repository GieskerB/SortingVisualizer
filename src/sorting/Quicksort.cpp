#include "../../include/sorting/Quicksort.hpp"

#include <iostream>

#define PIVOT_PICKED 0
#define PIVOT_RETURNED 1
#define PIVOT_VALUE 2
#define LEFT_POINTER 3
#define RIGHT_POINTER 4

Quicksort::Quicksort(Array *array) : Sort(array) {
}

static int pivot_move = 0;

void Quicksort::quicksort(const int begin, const int end, const int limit, StackValueMemory<2, 5> *node) {
	if (begin >= end || end > array->size()) return;

	if (node->children[0] == nullptr) {
		node->children[0] = new StackValueMemory<2, 5>;
		node->children[1] = new StackValueMemory<2, 5>;
	}

	// pick a pivot element and swap it with the last element in this range
	if (node->values[PIVOT_PICKED] == 0) {
		node->values[PIVOT_PICKED] = 1;
		pivot_move++;
		const int pivot_index = /*end;//*/(begin + end) / 2;
		node->values[PIVOT_VALUE] = array->value(pivot_index);
		node->values[LEFT_POINTER] = begin;
		node->values[RIGHT_POINTER] = end;
		array->swap(pivot_index, end);
		++swaps;
		if (swaps >= limit) {
			throw swaps;
		}
	}

	// Perform the partitioning
	while (node->values[LEFT_POINTER] < node->values[RIGHT_POINTER]) {
		// Search for the next element greater and left from the pivot
		while (array->value(node->values[LEFT_POINTER]) <= node->values[PIVOT_VALUE] and node->values[LEFT_POINTER] <
		       node->values[RIGHT_POINTER]) {
			node->values[LEFT_POINTER]++;
		}
		// Search for the next element smaller and right from the pivot
		while (array->value(node->values[RIGHT_POINTER]) >= node->values[PIVOT_VALUE] and node->values[LEFT_POINTER] <
		       node->values[RIGHT_POINTER]) {
			node->values[RIGHT_POINTER]--;
		}
		// Swap them
		if (node->values[LEFT_POINTER] != node->values[RIGHT_POINTER]) {
			array->swap(node->values[LEFT_POINTER], node->values[RIGHT_POINTER]);
			++swaps;
			if (swaps >= limit) {
				throw swaps;
			}
		}
	}
	if (node->values[PIVOT_RETURNED] == 0) {
		node->values[PIVOT_RETURNED] = 1;
		array->swap(node->values[LEFT_POINTER], end);
		pivot_move--;
		++swaps;
		if (swaps >= limit) {
			throw swaps;
		}
	}

	// Recursive call
	if (!node->children[0]->visited) quicksort(begin, node->values[LEFT_POINTER] - 1, limit, node->children[0]);
	if (!node->children[1]->visited) quicksort(node->values[LEFT_POINTER] + 1, end, limit, node->children[1]);

	node->visited = true;
}

void Quicksort::sort(int limit) {
	if (array->is_sorted()) return;
	swaps = 0;
	try {
		quicksort(0, array->size() - 1, limit, &nodes);
	} catch (int swaps) {
		std::cout << pivot_move << std::endl;
		return;
	}
}

void Quicksort::reset() {
	for (int i = 0; i < 2; ++i) {
		delete nodes.children[i];
		nodes.children[i] = nullptr;
	}
}
