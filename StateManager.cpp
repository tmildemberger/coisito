#include "StateManager.hpp"

void StateManager::popState() {
    states.pop();
}

void StateManager::pushState(State* state) {
    states.push(state);
}