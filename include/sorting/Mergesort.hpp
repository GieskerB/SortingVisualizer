#ifndef INCLUDE_SORTING_MERGESORT_HPP_
#define INCLUDE_SORTING_MERGESORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Mergesort: public Sort {

	void divide(int, int, int);
	void conquer(int, int, int, int);

public:

	Mergesort(Array*);
	void sort(int) override;
	void reset() override;

};

#endif /* INCLUDE_SORTING_MERGESORT_HPP_ */
