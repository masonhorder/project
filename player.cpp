#include <iostream>
// #include "character.h"
#include "player.h"

using namespace std;


// default constructor
Player::Player(){

}


// constrcutor used
Player::Player(std::string name){
    _name = name;
}


// GETTERS

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

int Player::getAdvisor(){
    return _advisor;
}

string Player::getAdvisorName(){
    return _advisorName;
}

int Player::getPosition(){
    return _position;
}

Character Player::getCharacter(){
    return _character;
}

int Player::getPathType(){
    return _pathType;
}

bool Player::getFinished(){
    return _finished;

}





// SETTERS

void Player::setName(string name){
    _name = name;
}
void Player::setAge(int age){
    _age = age;
}
void Player::setStrength(int strength){
    _strength = strength;
}
void Player::setStamina(int stamina){
    _stamina = stamina;
}
void Player::setWisdom(int wisdom){
    _wisdom = wisdom;
}
void Player::setPridePoints(int p){
    _pridePoints = p;
}
void Player::setCharName(string charName){
    _characterName = charName;
}

void Player::setPathType(int p){
    _pathType = p;
}

void Player::setAdvisor(int a){
    _advisor = a;
}

void Player::setAdvisorName(string a){
    _advisorName = a;
}

void Player::setCharacter(Character c){
    _character = c;
}

void Player::setPosition(int p){
    _position = p;
}


// METHODS

// adjusts points if player select cub training 
void Player::cubTraining(){
    _strength += 500;
    _stamina += 500;
    _wisdom += 500;
    _pridePoints = _pridePoints - 5000;
}

// adjust points if player selects pride lands
void Player::prideLand(){
    _strength += 200;
    _stamina += 200;
    _wisdom += 200;
    _pridePoints += 5000;
}


// print out the players stats
void Player::printPlayerStats(){
    cout << "\nPlayer stats for " << _name << ": ";
    cout << "\n\nStrength: " << _strength;
    cout << "\n\nStamina: " << _stamina;
    cout << "\n\nWisdom: " << _wisdom;
    cout << "\n\nPride Points: " << _pridePoints;
    cout << "\n\nCharacter Name: " << _characterName;
    cout << "\n------------\n";


}


// when they finish the game, store it in player class
void Player::finished(){
    _finished = true;
}


// convert their trait points to pride points
void Player::traitToPoints(){

    //10x each point when converting
    _pridePoints += _stamina*10;
    _pridePoints += _wisdom*10;
    _pridePoints += _strength*10;

    _strength = 0;
    _wisdom = 0;
    _stamina = 0;

}

