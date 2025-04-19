// #include "board.h"
#include "game.h"
#include "game.cpp"
#include "character.h"
#include "character.cpp"
#include "player.h"
#include "player.cpp"
#include "board.h"
#include "board.cpp"

#include <iostream>

using namespace std;




int main(){

    // Board board = Board(2);

    // board.displayBoard();

    Game game;

    game.readFiles(); // done for character input




    game.playerSetup();

    // game.endGame();

    // do you want to play again

    return 0;
}