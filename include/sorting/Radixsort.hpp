#ifndef INCLUDE_SORTING_RADIXSORT_HPP_
#define INCLUDE_SORTING_RADIXSORT_HPP_

#include <queue>

#include "Sort.hpp"

#include "../Array.hpp"
#include "../Renderer.hpp"

enum Base {
	BINARY = 2, OCTAL = 8, DECIMAL = 10, HEXADECIMAL = 1
};

class Radixsort: public Sort {
private:

	static const char DIGITS[];
	static const Uint8 BUFFER_SIZE;

	const Base BASE;

	const Uint8 largestNumberLength;

	std::queue<BaseRectangle*> *buckets;


	Uint8 digitToNumber(char digit);
	Uint8 numberLengthBaseX(Uint16 numberDec);
	char& toBaseXConverter(Uint16 numberDec);

protected:
	void sort(int stepCount) override;

public:

	Radixsort(Array *array, Renderer *renderer, Base base = DECIMAL);
	~Radixsort();
};

#endif /* INCLUDE_SORTING_RADIXSORT_HPP_ */
