#include "VisibleState.hpp"

#include "Managers/EventManager.hpp"
#include "Managers/GraphicsManager.hpp"

VisibleState::VisibleState(
    StateManager& manager, GraphicsManager& graphics, EventManager& events)
    : State(manager), graphics_(graphics), events_(events) {
    // haha
}