#ifndef RIDDLE_H
#define RIDDLE_H

#include <iostream>
#include "player.h"



class Riddle {
    private:
    std::string _question;
    std::string _answer;   

    public:
    // CONSTRUCTOR
    Riddle(std::string q, std::string ans);

    // GETTERS
    string getQuestion();
    string getAnswer();

};

#endif