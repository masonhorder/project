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
void Player::setPridePoints(bool pridePoints){
    _pridePoints = pridePoints;
}
void Player::setCharName(string charName){
    _charName = charName;
}

void Player::setPathType(int p){
    _pathType = p;
}

void Player::setAdvisor(int a){
    _advisor = a;
}

// void Player::printStats(){

// }

