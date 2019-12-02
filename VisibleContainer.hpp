#ifndef VISIBLE_CONTAINER_HPP
#define VISIBLE_CONTAINER_HPP

#include "Container.hpp"
#include "VisibleThing.hpp"

class GraphicsManager;

class VisibleContainer : public Container {
public:
    VisibleContainer(std::size_t size, GraphicsManager& graphics);

    bool lower(std::size_t ix1, std::size_t ix2) override;
    void swap(std::size_t ix1, std::size_t ix2) override;

    void draw();
    int getComparisons() const;
    int getSwaps() const;
private:
    GraphicsManager& graphics_;
    std::vector<VisibleThing> things;

    int comparisons;
    int swaps;
};

#endif // VISIBLE_CONTAINER_HPP