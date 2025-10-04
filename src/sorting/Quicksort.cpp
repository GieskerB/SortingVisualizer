#include "../../include/sorting/Quicksort.hpp"

#include <iostream>

#define PIVOT_PICKED 0
#define PIVOT_VALUE 1
#define LEFT_POINTER 2
#define RIGHT_POINTER 3
#define PIVOT_RETURNED 4

Quicksort::Quicksort(Array *array) : Sort(array), nodes{{false, 0, 0, 0, false}} {
}

void Quicksort::quicksort(const int begin, const int end, const int limit,
                          StackMemory<std::tuple<bool, int, int, int, bool>, 2> *node) {
	if (begin >= end || end > array->size()) return;

	if (node->children[0] == nullptr) {
		node->children[0] = new StackMemory<std::tuple<bool, int, int, int, bool>, 2>{{false, 0, 0, 0, false}};
		node->children[1] = new StackMemory<std::tuple<bool, int, int, int, bool>, 2>{{false, 0, 0, 0, false}};
	}

	// pick a pivot element and swap it with the last element in this range
	if (!std::get<PIVOT_PICKED>(node->data)) {
		std::get<PIVOT_PICKED>(node->data) = true;
		const int pivot_index = /*end;//*/(begin + end) / 2;
		std::get<PIVOT_VALUE>(node->data) = array->value(pivot_index);
		std::get<LEFT_POINTER>(node->data) = begin;
		std::get<RIGHT_POINTER>(node->data) = end;
		array->swap(pivot_index, end);
		++swaps;
		if (swaps >= limit) {
			throw swaps;
		}
	}

	// Perform the partitioning
	while (std::get<LEFT_POINTER>(node->data) < std::get<RIGHT_POINTER>(node->data)) {
		// Search for the next element greater and left from the pivot
		while (array->value(std::get<LEFT_POINTER>(node->data)) <= std::get<PIVOT_VALUE>(node->data) and std::get<
			       LEFT_POINTER>(node->data) <
		       std::get<RIGHT_POINTER>(node->data)) {
			std::get<LEFT_POINTER>(node->data)++;
		}
		// Search for the next element smaller and right from the pivot
		while (array->value(std::get<RIGHT_POINTER>(node->data)) >= std::get<PIVOT_VALUE>(node->data) and std::get<
			       LEFT_POINTER>(node->data) <
		       std::get<RIGHT_POINTER>(node->data)) {
			std::get<RIGHT_POINTER>(node->data)--;
		}
		// Swap them
		if (std::get<LEFT_POINTER>(node->data) != std::get<RIGHT_POINTER>(node->data)) {
			array->swap(std::get<LEFT_POINTER>(node->data), std::get<RIGHT_POINTER>(node->data));
			++swaps;
			if (swaps >= limit) {
				throw swaps;
			}
		}
	}
	if (!std::get<PIVOT_RETURNED>(node->data)) {
		std::get<PIVOT_RETURNED>(node->data) = true;
		array->swap(std::get<LEFT_POINTER>(node->data), end);
		++swaps;
		if (swaps >= limit) {
			throw swaps;
		}
	}

	// Recursive call
	if (!node->children[0]->visited) quicksort(begin, std::get<LEFT_POINTER>(node->data) - 1, limit, node->children[0]);
	if (!node->children[1]->visited) quicksort(std::get<LEFT_POINTER>(node->data) + 1, end, limit, node->children[1]);

	node->visited = true;
}

void Quicksort::sort(int limit) {
	if (array->is_sorted()) return;
	swaps = 0;
	try {
		quicksort(0, array->size() - 1, limit, &nodes);
	} catch (int swaps) {
		return;
	}
}

void Quicksort::reset() {
	for (int i = 0; i < 2; ++i) {
		delete nodes.children[i];
		nodes.children[i] = nullptr;
		nodes.data = {false,0,0,0,false};
	}
}
