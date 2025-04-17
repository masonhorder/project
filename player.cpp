#include <iostream>
// #include "character.h"
#include "player.h"

using namespace std;

// Player::Player(std::string name, int age, int strength, int stamina, int wisdom, int pridePoints){

    

//     std::string _name;
//     Character _character;
//     // Advisor _advisor;
//     int _pathType;
//     bool _hasAdvisor;
//     int _position;
//     int _previousPosition;
//     bool _extraTurn;
//     int _age;
//     int _strength;
//     int _stamina;
//     int _wisdom;
//     int _pridePoints;




// }

Player::Player(){
    
}

Player::Player(std::string name){
    _name = name;
}


string Player::getName(){
    return _name;
}

int Player::getAge(){
    return _age;
}

int Player::getStrength(){
    return _strength;
}

int Player::getStamina(){
    return _stamina;
}

int Player::getWisdom(){
    return _wisdom;
}

int Player::getPridePoints(){
    return _pridePoints;
}

void setName(string name);
void setAge(int age);
void setStrength(int strength);
void setStamina(int stamina);
void setWisdom(int wisdom);
void setPridePoints(bool pridePoints);

// void Player::printStats(){

// }

