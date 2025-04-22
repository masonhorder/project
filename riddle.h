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
    // const std::string  getDescription() const;
    // int getPathType()    const;
    // int getAdvisorFilter() const;
    // int getPrideDelta()  const;

};

#endif