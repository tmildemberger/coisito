#ifndef STATE_HPP
#define STATE_HPP

class StateManager;

class State {
public:
    State(StateManager& manager);
    virtual ~State() = default;

    virtual void exec() = 0;

protected:
    StateManager& manager_;
};

#endif // STATE_HPP