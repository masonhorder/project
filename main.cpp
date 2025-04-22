// #include "board.h"
#include "game.h"
// #include "game.cpp"
#include "character.h"
// #include "character.cpp"
#include "player.h"
// #include "player.cpp"
#include "board.h"
// #include "board.cpp"
#include "event.h"
// #include "event.cpp"
#include "riddle.h"
// #include "riddle.cpp"

#include <iostream>

using namespace std;




int main(){

    // Board board = Board(2);

    // board.displayBoard();

    Game game;

    game.readFiles(); // done for character input
    game.playerSetup(); // player set up
    game.setUpBoard();  // create a random game board


    //loop unitl game end



    while(!game.isGameOver()){  // TODO change this to actual condition eventually
        game.playTurn();
    }
    



    game.endGame();

    

    return 0;
}