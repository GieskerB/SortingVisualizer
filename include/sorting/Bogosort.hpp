#ifndef INCLUDE_SORTING_BOGOSORT_HPP_
#define INCLUDE_SORTING_BOGOSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Bogosort: public Sort {

public:

	Bogosort(Array *array);
	void sort(int ) override;
	void reset() override;

};

#endif /* INCLUDE_SORTING_BOGOSORT_HPP_ */
