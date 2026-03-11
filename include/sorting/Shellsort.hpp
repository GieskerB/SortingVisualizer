#ifndef SORTINGVISUALIZER_SHELLSORT_HPP
#define SORTINGVISUALIZER_SHELLSORT_HPP

#include "Sort.hpp"

class Shellsort : public Sort {

    bool done_reverse;
    int glob_i, glob_j, glob_gab;

public:

    Shellsort(Array *array);
    void sort(int) override;
    void reset() override;
};


#endif //SORTINGVISUALIZER_SHELLSORT_HPP