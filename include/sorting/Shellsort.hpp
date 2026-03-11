#ifndef SORTINGVISUALIZER_SHELLSORT_HPP
#define SORTINGVISUALIZER_SHELLSORT_HPP

#include "Sort.hpp"

class Shellsort : public Sort {

public:

    Shellsort(Array *array);
    void sort(int) override;
    void reset() override;
};


#endif //SORTINGVISUALIZER_SHELLSORT_HPP