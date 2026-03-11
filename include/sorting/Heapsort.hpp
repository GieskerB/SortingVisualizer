#ifndef INCLUDE_SORTING_HEAPSORT_HPP_
#define INCLUDE_SORTING_HEAPSORT_HPP_

#include "Sort.hpp"
#include "../StackMemory.hpp"

class Heapsort: public Sort {

	StackMemory<void,3> heapify_nodes, sift_down_nodes;

	bool full_sift;

	int heap_size;

	static inline int left_child(int);
	static inline int right_child(int);
	inline bool has_left(int) const;
	inline bool has_right(int) const;

	void heapify(int, int, StackMemory<void,3>*);
	void sift_down(int, int, StackMemory<void,3>*);

public:

	Heapsort(Array *array);
	void sort(int) override;
	void reset() override;


};

#endif /* INCLUDE_SORTING_HEAPSORT_HPP_ */
