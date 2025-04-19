#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "character.h"
#include "event.h"
#include "riddle.h"
#include <vector>

class Game {
private:
    // Player player1;
    // Player player2;

    Player players[5];

    int _playerCount = 0;

    Board board;

    int turnCounter;

    std::vector<Character> allCharacters;
    // std::vector<Advisor> allAdvisors;
    // std::vector<RandomEvent> randomEvents;
    // std::vector<Riddle> riddles;

public:
    Game();


    void readFiles(); 

    void playerSetup(); // assign the players names, characters and paths

    void mainMenu();


    void processTile();
    void handleRandomEvent();
    void handleChallenge();
    void playTurn(Player p);
    bool isGameOver();
    void endGame();
};

#endif