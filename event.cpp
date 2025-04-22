#include <iostream>
#include "player.h"
#include "event.h"


// constructor
Event::Event(string d, int p, int a, int c){
    _description = d;
    _pathType = p;
    _advisorFilter = a;
    _prideDelta = c;
}

// GETTERS
std::string Event::getDescription(){
    return _description;
}
int Event::getPathType(){
    return _pathType;
}
int Event::getAdvisorFilter(){
    return _advisorFilter;
}
int Event::getPrideDelta(){
    return _prideDelta;
}