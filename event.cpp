#include <iostream>
#include "player.h"
#include "event.h"

Event::Event(string d, int p, int a, int c){
    _description = d;
    _pathType = p;
    _advisorFilter = a;
    _prideDelta = c;
}

// Event::