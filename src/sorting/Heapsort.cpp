#include "../../include/sorting/Heapsort.hpp"

// TODO: StackMemory::visited currently unused

Heapsort::Heapsort(Array *array) : Sort(array), full_sift(true), heap_size(array->size()) {}

int Heapsort::left_child(const int parent) { return 2 * parent + 1; }

int Heapsort::right_child(const int parent) { return 2 * parent + 2; }

bool Heapsort::has_left(const int index) const { return left_child(index) < heap_size; }

bool Heapsort::has_right(const int index) const { return right_child(index) < heap_size; }

void Heapsort::heapify(const int index, const int limit, StackMemory<3> *node) {
	if (node->children[0] == nullptr) {
		node->children[0] = new StackMemory<3>;
		node->children[1] = new StackMemory<3>;
		node->children[2] = new StackMemory<3>;
	}
	if (has_left(index) and !node->children[0]->visited) heapify(left_child(index), limit, node->children[0]);
	if (has_right(index) and !node->children[1]->visited) heapify(right_child(index), limit, node->children[1]);

	if (!node->children[0]->visited) sift_down(index, limit, node->children[2]);
	node->visited = false;
}

void Heapsort::sift_down(const int index, const int limit, StackMemory<3> *node) {
	// Break condition: "Node" is a leaf
	if (left_child(index) >= heap_size) return;

	if (node->children[0] == nullptr) {
		node->children[0] = new StackMemory<3>;
		node->children[1] = new StackMemory<3>;
		node->children[2] = new StackMemory<3>;
	}

	const int lci = left_child(index);
	const int rci = right_child(index);

	if (rci < heap_size) {
		// Has left and right child
		if (array->value(lci) > array->value(rci)) {
			// Left Child bigger then right
			if (array->value(lci) > array->value(index)) {
				// left child bigger then parent
				array->swap(lci, index);
				++swaps;
				if (swaps >= limit) {
					throw swaps;
				}
			}
		} else {
			// Right Child bigger then left
			if (array->value(rci) > array->value(index)) {
				// right child bigger then parent
				array->swap(rci, index);
				++swaps;
				if (swaps >= limit) {
					throw swaps;
				}
			}
		}
		// Recursive call for left and right child
		if (!node->children[0]->visited) sift_down(lci, limit, node->children[0]);
		if (!node->children[1]->visited) sift_down(rci, limit, node->children[1]);
	} else {
		// Only has a left Child
		if (array->value(lci) > array->value(index)) {
			// left child bigger then parent
			array->swap(lci, index);
			++swaps;
			if (swaps >= limit) {
				throw swaps;
			}
		}
		// Recursive call only for left child
		if (!node->children[2]->visited) sift_down(lci, limit, node->children[2]);
	}
	node->visited = false;
}

void Heapsort::sort(int limit) {
	if (array->is_sorted()) return;
	swaps = 0;

	try {
		if (!heapify_nodes.visited) heapify(0, limit, &heapify_nodes);
	} catch (int swaps) {
		return;
	}

	while (heap_size > 0) {
		if (full_sift) {
			full_sift = false;
			array->swap(0, heap_size - 1);
			heap_size--;
			++swaps;
			if (swaps >= limit) {
				return;
			}
		}
		try {
			sift_down(0, limit, &sift_down_nodes);
		} catch (int swaps) {
			return;
		}
		full_sift = true;
	}
}

void Heapsort::reset() {
	heap_size = array->size();
	full_sift = true;
	for (int i = 0; i < 2; ++i) {
		delete heapify_nodes.children[i];
		delete sift_down_nodes.children[i];
		heapify_nodes.children[i] = nullptr;
		sift_down_nodes.children[i] = nullptr;
	}
}


