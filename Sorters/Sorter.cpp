#include "Sorter.hpp"

Sorter::Sorter(Container& container) : container_(&container), sorting(false) {
}

bool Sorter::isSorting() const {
    return sorting;
}