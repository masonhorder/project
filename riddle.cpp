// MASON HORDER AND HADDEN SPENCER


#include <iostream>
#include "player.h"
#include "riddle.h"


// CONSTRUCTOR

// constructor
Riddle::Riddle(string q, string a){
    _answer = a;
    _question = q;
}

// GETTERS
string Riddle::getQuestion(){
    return _question;
}

string Riddle::getAnswer(){
    return _answer;
}
