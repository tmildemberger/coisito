#ifndef SORTER_HPP
#define SORTER_HPP

#include "../Container.hpp"

class Sorter {
public:
    Sorter(Container& container);
    virtual ~Sorter() = default;
    virtual void startSorting() = 0;
    bool isSorting() const;

protected:
    Container* container_;
    bool sorting;
};

#endif // SORTER_HPP