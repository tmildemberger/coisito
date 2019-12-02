#include "SelectionSorter.hpp"

#include "Container.hpp"

#include <thread>
#include <chrono>

SelectionSorter::SelectionSorter(Container& container) : Sorter(container) {
}

void SelectionSorter::startSorting() {
    sorting = true;
    std::size_t lowest_ix;
    for (std::size_t i = 0; i < container_->getSize(); ++i) {
        lowest_ix = i;
        for (std::size_t j = i + 1; j < container_->getSize(); ++j) {
            if (container_->lower(j, lowest_ix)) {
                lowest_ix = j;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        container_->swap(i, lowest_ix);
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    sorting = false;
}