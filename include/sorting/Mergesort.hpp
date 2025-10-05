#ifndef INCLUDE_SORTING_MERGESORT_HPP_
#define INCLUDE_SORTING_MERGESORT_HPP_

#include <tuple>
#include <memory>

#include "Sort.hpp"
#include "../Array.hpp"
#include "../StackMemory.hpp"

using StackMemMS = StackMemory<std::tuple<bool,std::vector<std::shared_ptr<Rect*>>, std::vector<std::shared_ptr<Rect*>>,int,int,int>,3>;

class Mergesort: public Sort {

	StackMemMS nodes;

	void divide(int, int, int,StackMemMS*);
	void conquer(int, int, int, int,StackMemMS*);

public:

	Mergesort(Array*);
	void sort(int) override;
	void reset() override;

};

#endif /* INCLUDE_SORTING_MERGESORT_HPP_ */
