#ifndef BUBBLE_SORTER_HPP
#define BUBBLE_SORTER_HPP

#include "Sorter.hpp"

class BubbleSorter : public Sorter {
public:
    BubbleSorter(Container& container);
    void startSorting();

private:
};

#endif // BUBBLE_SORTER_HPP