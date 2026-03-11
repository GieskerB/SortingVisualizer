#ifndef INCLUDE_SORTING_RADIXSORT_HPP_
#define INCLUDE_SORTING_RADIXSORT_HPP_

#include <array>
#include <queue>

#include "Sort.hpp"

// TODO add different bases

// enum Base {
// 	BINARY = 2, OCTAL = 8, DECIMAL = 10, HEXADECIMAL = 16
// };

class Radixsort: public Sort {

	std::array<std::queue<Rect*>,10> buckets;

	void sort_in_buckets();

	int number_index, glob_bucket_index, glob_array_index;
	bool numbers_in_buckets;

public:

	Radixsort(Array *array);

	void sort(int) override;
	void reset() override;
};

#endif /* INCLUDE_SORTING_RADIXSORT_HPP_ */
