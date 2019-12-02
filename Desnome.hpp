#ifndef DESNOME_HPP
#define DESNOME_HPP

#include <cstddef>

#include "VisibleContainer.hpp"
#include "VisibleState.hpp"

class GraphicsManager;
class EventManager;
class Sorter;

class Desnome : public VisibleState {
public:
    Desnome(
        StateManager& manager, GraphicsManager& graphics, EventManager& events);
    ~Desnome();
    void exec() override;

    enum class Algorithm {
        BUBBLE_SORT = 0,
        SELECTION_SORT,
        INSERTION_SORT,
    };

    void selectAlgorithm(Algorithm alg);

private:
    std::vector<Sorter*> sorters;
    VisibleContainer container;
    std::size_t current_sorter;
};

#endif // DESNOME_HPP