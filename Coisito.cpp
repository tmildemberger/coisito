#include "Coisito.hpp"

Coisito::Coisito()
    : events(graphics), inicial(*this, graphics, events),
      principal(*this, graphics, events) {
    run();
}

Desnome& Coisito::getDesnome() {
    return principal;
}

void Coisito::run() {
    pushState(&inicial);
    while (!states.empty()) {
        // lembrar de tirar outros includes de lugares onde não usam mais
        states.top()->exec();
        // run exec on current state
    }
}

// DescentIntoMadness::DescentIntoMadness() :
//   graphics_man(), events_man(), menu(), pause(), leaderboard(), player1(),
//   player2(), temple(), cavern(), current(GameState::MAIN_MENU),
//   unpause{GameState::END_GAME} {

//   events_man.setGraphicsManager(graphics_man);

//   menu.init(graphics_man, events_man);
//   pause.init(graphics_man, events_man);
//   leaderboard.init(graphics_man, events_man);

//   temple.init(graphics_man, events_man);
//   cavern.init(graphics_man, events_man);
//   extra.init(graphics_man, events_man);

//   player1.initializeGeneric(&temple); // só para usar o graphics manager e
//   eventos player2.initializeGeneric(&temple); player1.setLevel(nullptr);
//   player2.setLevel(nullptr);

//   play();
// }

// DescentIntoMadness::~DescentIntoMadness() {

// }

// void DescentIntoMadness::play() {
//   bool playing = true;
//   while (playing) {
//     switch (current) {
//       case GameState::MAIN_MENU:
//         mainMenu();
//         break;
//       case GameState::PAUSE_MENU:
//         pauseMenu();
//         break;
//       case GameState::TEMPLE_LEVEL:
//         templeLevel();
//         break;
//       case GameState::CAVERN_LEVEL:
//         cavernLevel();
//         break;
//       case GameState::LEADERBOARD:
//         leaderBoard();
//         break;
//       case GameState::EXTRA_LEVEL:
//         extraLevel();
//         break;
//       case GameState::END_GAME:
//         leaderboard.addNewHighScore(player1.getDeathCounter());
//         current = GameState::LEADERBOARD;
//         break;
//       case GameState::EXIT:
//       default:
//         playing = false;
//         break;
//     }
//   }

// }

// void DescentIntoMadness::mainMenu() {
//   int decisao = menu.exec();
//   if (decisao == 0) {
//     current = GameState::EXIT;
//   } else if (decisao == 1) {
//     unpause = current = GameState::TEMPLE_LEVEL;
//     goToLevel(&temple);
//     temple.playFromStart();

//   } else if (decisao == 2) {
//     unpause = current = GameState::TEMPLE_LEVEL;
//     goToLevel(&temple);
//     temple.loadLastSaved();

//   } else if (decisao == 3) {
//     unpause = current = GameState::CAVERN_LEVEL;
//     goToLevel(&cavern);
//     cavern.playFromStart();

//   } else if (decisao == 4) {
//     unpause = current = GameState::CAVERN_LEVEL;
//     goToLevel(&cavern);
//     cavern.loadLastSaved();

//   } else if (decisao == 6) {
//     current = GameState::LEADERBOARD;
//   } else if (decisao == 7) {
//     unpause = current = GameState::EXTRA_LEVEL;
//     goToLevel(&extra);
//     extra.playFromStart();

//   }
// }

// void DescentIntoMadness::pauseMenu() {
//   int decisao = pause.exec();
//   if (decisao == 0) {
//     current = unpause;
//   } else if (decisao == 1) {
//     if (unpause == GameState::TEMPLE_LEVEL) {
//       temple.saveState();
//     } else {
//       cavern.saveState();
//     }
//     current = unpause;
//   } else if (decisao == 2) {
//     current = GameState::MAIN_MENU;
//   }
// }

// void DescentIntoMadness::leaderBoard() {
//   int decisao = leaderboard.exec();
//   if (decisao == 0) {
//     current = GameState::MAIN_MENU;
//   }
// }

// void DescentIntoMadness::templeLevel() {
//   int dec = temple.exec();
//   if (dec == 0) current = GameState::PAUSE_MENU;
//   else if (dec == 1) {
//     unpause = current = GameState::CAVERN_LEVEL;
//     goToLevel(&cavern);
//     cavern.playFromStart();
//   }
// }

// void DescentIntoMadness::cavernLevel() {
//   int dec = cavern.exec();
//   if (dec == 0) current = GameState::PAUSE_MENU;
//   else if (dec == 1) {
//     unpause = current = GameState::END_GAME;
//   }
// }

// void DescentIntoMadness::extraLevel() {
//   int dec = extra.exec();
//   if (dec == 0) current = GameState::PAUSE_MENU;
//   else if (dec == 1) {
//     unpause = current = GameState::MAIN_MENU;
//   }
// }

// void DescentIntoMadness::goToLevel(Levels::Level* level) {
//   player1.setLevel(level);
//   player2.setLevel(menu.useTwoPlayers() ? level : nullptr);

//   level->setPlayers(&player1, menu.useTwoPlayers() ? &player2 : nullptr);
// }