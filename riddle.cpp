#include <iostream>
#include "player.h"
#include "riddle.h"

Riddle::Riddle(string q, string a){
    _answer = a;
    _question = q;
}

// Event::