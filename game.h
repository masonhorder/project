#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include "character.h"
#include "advisor.h"
#include "event.h"
#include "riddle.h"
#include <vector>

class Game {
private:
    Player player1;
    Player player2;
    Board board;
    int turnCounter;

    std::vector<Character> allCharacters;
    // std::vector<Advisor> allAdvisors;
    // std::vector<RandomEvent> randomEvents;
    // std::vector<Riddle> riddles;

public:
    Game();


    void startGame();
    void readFiles();
    void characterSelection();
    void choosePath(Player p);
    void mainMenu(Player p);
    void processTile(Player p, Tile t);
    void handleRandomEvent(Player p);
    void handleChallenge(Player p);
    void playTurn(Player p);
    bool isGameOver();
    void endGame();
};

#endif