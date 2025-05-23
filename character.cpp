// MASON HORDER AND HADDEN SPENCER



#include <iostream>
#include "character.h"
#include "player.h"

using namespace std;


// "common" character object constructor which passes through all the values
Character::Character(std::string name, int age, int strength, int stamina, int wisdom, int pridePoints){
    _name = name;
    _age = age;
    _strength = strength;
    _stamina = stamina;
    _wisdom = wisdom;
    _pridePoints = pridePoints;
}

// default constructor
Character::Character() {
    _name = "";
    _age = 0;
    _strength = 0;
    _stamina = 0;
    _wisdom = 0;
    _pridePoints = 0;
}

// GETTERS:
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

bool Character::getChosen(){
    return _isChosen;
}




// SETTERS:

void Character::setName(string name){
    _name = name;
}
void Character::setAge(int age){
    _age = age;
}
void Character::setStrength(int strength){
    _strength = strength;
}
void Character::setStamina(int stamina){
    _stamina = stamina;
}
void Character::setWisdom(int wisdom){
    _wisdom = wisdom;
}
void Character::setPridePoints(bool pridePoints){
    _pridePoints = pridePoints;
}
void Character::choseChar(){
    // sets the character to picked

    _isChosen = true;
}



// print the characters stats/traits
void Character::printStats(){
    cout << "Character Stats for " << _name << ": " << endl;
    cout << "Age: " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pridePoints << endl;
    cout << "Chosen: " << (_isChosen ? "Yes" : "No") << endl << endl;
}

