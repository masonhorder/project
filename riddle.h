#ifndef RIDDLE_H
#define RIDDLE_H

#include <iostream>
#include "player.h"



class Riddle {
    private:
    std::string _question;
    std::string _answer;   

    public:
    // ctor
    Riddle(std::string q, std::string ans);

    // getters
    string getQuestion();
    string getAnswer();

};

#endif