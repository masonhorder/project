#include <iostream>
#include "character.h"
#include "player.h"

using namespace std;

Character::Character(std::string name, int age, int strength, int stamina, int wisdom, int pridePoints){

    

    _name = name;
    _age = age;
    _strength = strength;
    _stamina = stamina;
    _wisdom = wisdom;
    _pridePoints = pridePoints;




}

Character::Character() {
    _name = "";
    _age = 0;
    _strength = 0;
    _stamina = 0;
    _wisdom = 0;
    _pridePoints = 0;
}


string Character::getName(){
    return _name;
}

int Character::getAge(){
    return _age;
}

int Character::getStrenght(){
    return _strength;
}

int Character::getStamina(){
    return _stamina;
}

int Character::getWisdom(){
    return _wisdom;
}

int Character::getPridePoints(){
    return _pridePoints;
}

void setName(string name);
void setAge(int age);
void setStrength(int strength);
void setStamina(int stamina);
void setWisdom(int wisdom);
void setPridePoints(bool pridePoints);

// void Character::printStats(){
//     cout << "Player Stats for " << _name << ": " << endl;
//     cout << "Age: " << _age;
//     cout << "Strength: " << _age;
//     cout << "Stamina: " << _age;
//     cout << "Age: " << _age;
//     cout << "Age: " << _age;
//     cout << "Chosen: " << _isChosen;
// }

