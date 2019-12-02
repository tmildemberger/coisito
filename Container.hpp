#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <cstddef>
#include <vector>

#include "Thing.hpp"

class Container {
public:
    Container(std::size_t size);
    virtual ~Container() = default;

    virtual bool lower(std::size_t ix1, std::size_t ix2) = 0;
    virtual void swap(std::size_t ix1, std::size_t ix2)  = 0;
    std::size_t getSize() const;

protected:
    std::size_t size_;
};

#endif // CONTAINER_HPP