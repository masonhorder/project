#include "game.h"
#include "character.h"
#include "player.h"
#include "board.h"
#include "event.h"
#include "riddle.h"

#include <iostream>

using namespace std;




int main(){
    Game game; // create game

    game.readFiles(); // load files
    game.playerSetup(); // player set up
    game.setUpBoard();  // create a random game board


    //loop unitl game end
    while(!game.isGameOver()){
        game.playTurn();
    }
    

    game.endGame(); // end game

    

    return 0;
}