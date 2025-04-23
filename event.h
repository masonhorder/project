// MASON HORDER AND HADDEN SPENCER


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
    Event(std::string desc, int ptype, int advisorFilter, int delta);

    // getters
    std::string  getDescription();
    int getPathType();
    int getAdvisorFilter();
    int getPrideDelta();

};

#endif