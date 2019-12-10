#include "Menu.hpp"

#include "Coisito.hpp"
#include "Desnome.hpp"
#include "Managers/EventManager.hpp"
#include "Managers/GraphicsManager.hpp"
#include "StateManager.hpp"
#include "vec2.hpp"

#include <iostream>

Menu::Menu(Coisito& coisito, GraphicsManager& graphics, EventManager& events)
    : VisibleState(coisito, graphics, events), coisito_(coisito),
      keep_going(true), key_event_id(0), mouse_event_id(0) {
    graphics_.loadAsset("image.jpg");
    vec2f viewsize = graphics_.getViewSize();
    buttons.emplace_back(graphics_, vec2f(viewsize.x / 2, viewsize.y * 1 / 4), "Bubble Sort", 0);
    buttons.emplace_back(graphics_, vec2f(viewsize.x / 2, viewsize.y * 2 / 4), "Selection Sort", 1);
    buttons.emplace_back(graphics_, vec2f(viewsize.x / 2, viewsize.y * 3 / 4), "Exit", 2);
}

void Menu::exec() {
    // vec2f viewsize = graphics_.getViewSize();
    // graphics_.centerCamera(viewsize * .5);
    keep_going = true;

    key_event_id   = events_.addKeyboardListener([this](EventManager::Event e) {
        if (e.getType() == EventManager::EventType::KeyPressed
            && e.getKey() == EventManager::Key::Escape) {
            keep_going = false;
        }
    });
    mouse_event_id = events_.addMouseListener([this](EventManager::Event e) {
        if (e.getType() == EventManager::EventType::MouseButtonPressed) {
            vec2f pos = graphics_.getMousePosInView();
            for (auto& b : buttons) {
                if (b.isInside(pos)) {
                    if (b.getId() == 0) {
                        coisito_.getDesnome().selectAlgorithm(
                            Desnome::Algorithm::BUBBLE_SORT);
                        manager_.pushState(&(coisito_.getDesnome()));
                        keep_going = false;
                    } else if (b.getId() == 1) {
                        coisito_.getDesnome().selectAlgorithm(
                            Desnome::Algorithm::SELECTION_SORT);
                        manager_.pushState(&(coisito_.getDesnome()));
                        keep_going = false;
                    } else {
                        keep_going = false;
                        manager_.popState();
                    }
                }
            }
        } else if (e.getType()
            == EventManager::EventType::MouseButtonReleased) {
            //   vec2f pos = graphics_.getMousePosInView();
        }
    });

    while (keep_going) {
        events_.processEvents();
        graphics_.clear(20, 20, 20);
        graphics_.drawAsset("image.jpg", { -100, -100 });
        // vec2f viewsize = graphics_.getViewSize();
        // graphics_.drawRect(viewsize / 2 - vec2f(50, 50), {250, 50}, 100, 100,
        // 100, 150); graphics_.drawTextCentered("bom dia", viewsize / 2, 40);
        for (auto& b : buttons) {
            b.draw();
        }
        graphics_.display();
    }

    removeListeners();
}

// Menu::Menu()
//     : graphics(nullptr)
//     , keep_going(true)
//     , key_event_id(0)
//     , mouse_event_id(0)
//     , return_val(0) {
// }

Menu::~Menu() {
    removeListeners();
}

// void Menu::init(Managers::GraphicsManager& g, Managers::EventManager& e) {
//     graphics = &g;
//     events   = &e;
// }

void Menu::removeListeners() {
    if (key_event_id != 0) {
        events_.removeKeyboardListener(key_event_id);
        key_event_id = 0;
    }
    if (mouse_event_id != 0) {
        events_.removeMouseListener(mouse_event_id);
        mouse_event_id = 0;
    }
}

// const int MainMenu::exec() {
//     Utils::VectorF viewsize = graphics->getViewSize();
//     graphics->centerCamera(viewsize * .5);
//     keep_going = true;
//     return_val = 0;

//     key_event_id
//         = events->addKeyboardListener([this](Managers::EventManager::Event e)
//         {
//               if (e.getType() ==
//               Managers::EventManager::EventType::KeyPressed
//                   && e.getKey() == Managers::EventManager::Key::Escape) {
//                   keep_going = false;
//               }
//           });
//     mouse_event_id
//         = events->addMouseListener([this](Managers::EventManager::Event e) {
//               if (e.getType()
//                   == Managers::EventManager::EventType::MouseButtonPressed) {
//                   Utils::VectorF pos = graphics->getMousePosInView();
//                   for (auto& b : buttons) {
//                       if (b->isInside(pos)) {
//                           if (b->getId() != 5) {
//                               return_val = b->getId();
//                               keep_going = false;
//                           }
//                       }
//                   }
//               } else if (e.getType()
//                   == Managers::EventManager::EventType::MouseButtonReleased)
//                   { Utils::VectorF pos = graphics->getMousePosInView(); for
//                   (auto& b : buttons) {
//                       if (b->isInside(pos)) {
//                           if (b->getId() == 5) {
//                               twoPlayers = !twoPlayers;
//                           }
//                       }
//                   }
//               }
//           });

//     while (keep_going) {
//         events->processEvents();
//         graphics->clear(20, 20, 20);
//         for (auto& b : buttons)
//             b->draw();
//         Utils::VectorF viewsize = graphics->getViewSize();

//         graphics->drawTextCentered(((twoPlayers) ? "2" : "1"),
//             Utils::VectorF(viewsize.x * (1 + 0.3) / 2, viewsize.y / 9
//             * 4.85), 21);
//         graphics->display();
//     }

//     removeListeners();

//     return return_val;
// }