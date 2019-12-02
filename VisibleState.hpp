#ifndef VISIBLE_STATE_HPP
#define VISIBLE_STATE_HPP

#include "State.hpp"

class GraphicsManager;
class EventManager;

class VisibleState : public State {
public:
    VisibleState(StateManager& manager, GraphicsManager& graphics, EventManager& events);
    virtual ~VisibleState() = default;

protected:
    GraphicsManager& graphics_;
    EventManager& events_;
};

#endif // VISIBLE_STATE_HPP