#include "Container.hpp"

Container::Container(std::size_t size) : size_(size) {
}

std::size_t Container::getSize() const {
    return size_;
}