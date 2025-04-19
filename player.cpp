#include <iostream>
// #include "character.h"
#include "player.h"

using namespace std;


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

int Player::getAdvisor(){
    return _advisor;
}

int Player::getPosition(){
    return _position;
}

Character Player::getCharacter(){
    return _character;
}






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


void Player::cubTraining(){
    _strength += 500;
    _stamina += 500;
    _wisdom += 500;
    _pridePoints = _pridePoints - 5000;
}

void Player::prideLand(){
    _strength += 200;
    _stamina += 200;
    _wisdom += 200;
    _pridePoints += 5000;
}

void Player::printPlayerStats(){
    cout << "\nPlayer stats for " << _name << ": ";
    // cout << "\n\nAdvisor: " << (_advisor==0 ? _advisorName : "None");
    // cout << "\n\nPath Type: " << (_pathType == 1 ? "Pride Lands" : "Cub Training");
    // cout << "\n\nAge: " << _age;
    cout << "\n\nStrength: " << _strength;
    cout << "\n\nStamina: " << _stamina;
    cout << "\n\nWisdom: " << _wisdom;
    cout << "\n\nPride Points: " << _pridePoints;
    cout << "\n\nCharacter Name: " << _characterName;
    cout << "\n------------\n";


}


