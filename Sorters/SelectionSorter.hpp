#ifndef SELECTION_SORTER_HPP
#define SELECTION_SORTER_HPP

#include "Sorter.hpp"

class SelectionSorter : public Sorter {
public:
    SelectionSorter(Container& container);
    void startSorting();

private:
};

#endif // SELECTION_SORTER_HPP