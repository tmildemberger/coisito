#include "BubbleSorter.hpp"

#include "Container.hpp"

#include <thread>
#include <chrono>

BubbleSorter::BubbleSorter(Container& container) : Sorter(container) {
}

void BubbleSorter::startSorting() {
    sorting = true;
    for (std::size_t i = 0; i < container_->getSize(); ++i) {
        for (std::size_t j = 1; j < container_->getSize() - i; ++j) {
            if (container_->lower(j, j - 1)) {
                container_->swap(j, j - 1);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));
    sorting = false;
}