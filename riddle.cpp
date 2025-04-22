#include <iostream>
#include "player.h"
#include "riddle.h"

Riddle::Riddle(string q, string a){
    _answer = a;
    _question = q;
}


string Riddle::getQuestion(){
    return _question;
}

string Riddle::getAnswer(){
    return _answer;
}
// Event::