#include "VisibleContainer.hpp"

#include "Managers/GraphicsManager.hpp"
#include "vec2.hpp"

#include <iterator>
#include <utility>
#include <thread>
#include <chrono>

VisibleContainer::VisibleContainer(std::size_t size, GraphicsManager& graphics)
    : Container(size), graphics_(graphics), comparisons(0), swaps(0) {
    vec2f viewsize = graphics_.getViewSize();
    for (std::size_t i = 0; i < size_; ++i) {
        things.emplace_back((i * 435 + 159) % 256, graphics_,
            vec2f(viewsize.x * (i + 1) / (size_ + 1), viewsize.y / 2));
    }
}

bool VisibleContainer::lower(std::size_t ix1, std::size_t ix2) {
    ++comparisons;
    things[ix1].setColor(120, 80, 40);
    things[ix2].setColor(120, 80, 40);
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    things[ix1].setColor(40, 80, 120);
    things[ix2].setColor(40, 80, 120);
    return things[ix1].getVal() < things[ix2].getVal();
}

void VisibleContainer::swap(std::size_t ix1, std::size_t ix2) {
    ++swaps;
    things[ix1].setColor(40, 120, 80);
    things[ix2].setColor(40, 120, 80);
    std::this_thread::sleep_for(std::chrono::milliseconds(700));
    things[ix1].setColor(40, 80, 120);
    things[ix2].setColor(40, 80, 120);

    VisibleThing temp = things[ix1];
    things[ix1]       = things[ix2];
    things[ix2]       = temp;

    vec2f viewsize = graphics_.getViewSize();
    for (std::size_t i = 0; i < size_; ++i) {
        things[i].setCenter(vec2f(viewsize.x * (i + 1) / (size_ + 1), viewsize.y / 2));
    }
}

void VisibleContainer::draw() {
    for (auto& t : things) {
        t.draw();
    }
}

int VisibleContainer::getComparisons() const {
    return comparisons;
}

int VisibleContainer::getSwaps() const {
    return swaps;
}
