#ifndef COISITO_HPP
#define COISITO_HPP

#include "StateManager.hpp"
#include "Managers/GraphicsManager.hpp"
#include "Managers/EventManager.hpp"
#include "Menu.hpp"
#include "Desnome.hpp"

class Coisito : public StateManager {
public:
    Coisito();
    Desnome& getDesnome();

private:
    void run();
    GraphicsManager graphics;
    EventManager events;

    Menu inicial;
    Desnome principal;
};

// enum class GameState {
//   MAIN_MENU,
//   PAUSE_MENU,
//   TEMPLE_LEVEL,
//   CAVERN_LEVEL,
//   EXTRA_LEVEL,
//   END_GAME,
//   EXIT,
//   LEADERBOARD
// };

// Managers::GraphicsManager graphics_man;
// Managers::EventManager events_man;

// Menus::MainMenu menu;
// Menus::PauseMenu pause;
// Menus::LeaderBoardMenu leaderboard;

// Entities::Mobs::TheUndying player1;
// Entities::Mobs::ThePenitent player2;

// Levels::TempleLevel temple;
// Levels::CavernLevel cavern;
// Concurrent::ExtraLevel extra;

// GameState current;
// GameState unpause;

// void play();

// void goToLevel(Levels::Level* level);

// void mainMenu();
// void pauseMenu();
// void leaderBoard();

// void templeLevel();
// void cavernLevel();
// void extraLevel();

#endif // COISITO_HPP