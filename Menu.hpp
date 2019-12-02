#ifndef MENU_HPP
#define MENU_HPP

#include "Button.hpp"
#include "VisibleState.hpp"
#include <vector>

class Coisito;
class GraphicsManager;
class EventManager;

class Menu : public VisibleState {
public:
    Menu(Coisito& coisito, GraphicsManager& graphics, EventManager& events);
    void exec() override;
    ~Menu();

private:
    Coisito& coisito_;
    std::vector<Button> buttons;
    bool keep_going;
    int key_event_id;
    int mouse_event_id;

    void removeListeners();
    // int return_val;
};

#endif // MENU_HPP