#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include "player.h"



class Event {
private:
    std::string _description;
    int _pathType;
    int _advisorFilter;
    int _prideDelta;         

public:
    // ctor
    Event(std::string desc, int ptype, int advisorFilter, int delta);

    // getters
    const std::string&  getDescription() const;
    int getPathType()    const;
    int getAdvisorFilter() const;
    int getPrideDelta()  const;

    bool isApplicable(int playerPath, int playerAdvisor) const;

    void applyTo(Player& player) const;
};

#endif