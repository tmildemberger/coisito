#include "Desnome.hpp"

#include "Managers/EventManager.hpp"
#include "Managers/GraphicsManager.hpp"
#include "StateManager.hpp"

#include "Sorters/BubbleSorter.hpp"
#include "Sorters/SelectionSorter.hpp"

#include <thread>
#include <iostream>
#include <sstream>

Desnome::Desnome(
    StateManager& manager, GraphicsManager& graphics, EventManager& events)
    : VisibleState(manager, graphics, events), container(10, graphics_),
      current_sorter(0) {
    sorters.push_back(new BubbleSorter(container));
    sorters.push_back(new SelectionSorter(container));
}

Desnome::~Desnome() {
    for (auto& s : sorters) {
        delete s;
    }
    sorters.clear();
}

void Desnome::exec() {
    std::thread sort(&Sorter::startSorting, sorters[current_sorter]);
    while (!sorters[current_sorter]->isSorting()) ;
    while (sorters[current_sorter]->isSorting()) {
        events_.processEvents();
        graphics_.clear(240, 240, 240);
        std::stringstream ss;
        ss << container.getComparisons();
        vec2f viewsize = graphics_.getViewSize();
        graphics_.drawTextCentered(ss.str(), vec2f(viewsize.x / 2, viewsize . y / 4), 40);
        container.draw();
        graphics_.display();
    }
    sort.join();
    manager_.popState();
}

void Desnome::selectAlgorithm(Algorithm alg) {
    current_sorter = static_cast<std::size_t>(alg);
}