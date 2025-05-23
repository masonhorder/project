// MASON HORDER AND HADDEN SPENCER


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
    int _boardSize;

    Board board;

    int turnCounter;

    std::vector<Character> allCharacters;
    // std::vector<Advisor> allAdvisors;
    std::vector<Event> allEvents;
    std::vector<Riddle> allRiddles;

public:
    Game();



    // METHODS

    void readFiles(); 

    void playerSetup(); // assign the players names, characters and paths
    void setUpBoard();
    int getPlayerCount();
    void processTile();
    void handleRandomEvent();
    void handleChallenge();
    void playTurn();
    bool isGameOver();
    void endGame();
    void setBoardSize(int b);
    int getBoardSize();
    
};

#endif