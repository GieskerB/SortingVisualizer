
#ifndef INCLUDE_SORTING_STOOGESORT_HPP_
#define INCLUDE_SORTING_STOOGESORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include <array>

template <int N>
struct RecusiveTree {
	std::array<RecusiveTree*, N> children{nullptr};
	bool visited{false};
	~RecusiveTree() {
		for (int i = 0; i < N; ++i) delete children[i];
	}

};

class Stoogesort: public Sort {

	RecusiveTree<3> nodes;

	void split(int, int, int,RecusiveTree<3>*);

public:

	Stoogesort(Array *array);
	void sort(int) override;
	void reset() override;

};

#endif /* INCLUDE_SORTING_STOOGESORT_HPP_ */
