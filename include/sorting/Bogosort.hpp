#ifndef INCLUDE_SORTING_BOGOSORT_HPP_
#define INCLUDE_SORTING_BOGOSORT_HPP_

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

class Bogosort: public Sort {

protected:
	void sort(int stepCount) override;

public:

	Bogosort(Array *array, Renderer *renderer);

};

#endif /* INCLUDE_SORTING_BOGOSORT_HPP_ */
