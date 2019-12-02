#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include <stack>

class State;

class StateManager {
public:
    void popState();
    void pushState(State* state);
protected:
    std::stack<State*> states;
};

#endif // STATE_MANAGER_HPP