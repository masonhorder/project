#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include "character.h"
#include "advisor.h"

using namespace std; 
class Player
{
    private:
        std::string _name;
        Character _character;
        // Advisor _advisor;
        int _pathType;
        bool _hasAdvisor;
        int _position;
        int _previousPosition;
        bool _extraTurn;
        int _age;
        int _strength;
        int _stamina;
        int _wisdom;
        int _pridePoints;

    public:

        Player(std::string _name);
        Player();
        // Player(std::string _name, Character _character, Advisor _advisor, int _pathType, bool _ int _character, int _strength, int _stamina, int _wisdom, int _pridePoints);
        

        // getters

        string getName();
        Character getCharacter();
        // Advisor getAdvisor();
        int getPathType();
        bool getHasAdvisor();
        int getPosition();
        int getPreviousPosition();
        bool getExtraTurn();
        int getAge();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();

        // setters

        void setName(std::string name);
        void getCharacter(Character character);
        // void getAdvisor(Advisor advisor);
        void getPathType(int pathType);
        void getHasAdvisor(bool hasAdvisor);
        void getPosition(int position);
        void getPreviousPosition(int previousPosition);
        void getExtraTurn(bool extraTurn);
        void getAge(int age);
        void getStrength(int strength);
        void getStamina(int stamina);
        void getWisdom(int wisdom);
        void getPridePoints(int pridePoints);

        

        // methods

        void move(int spaces);
        void updateStats(); // update stats based on certain things
        void chooseAdvisor(); // allows for picking an advisor
        void traitToPoints();


};

#endif