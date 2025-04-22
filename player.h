#ifndef PLAYER_H
#define PLAYER_H

#include <iostream> 
#include "character.h"

using namespace std; 
class Player
{
    private:
        std::string _name;
        Character _character;
        int _advisor;
        string _advisorName;
        int _pathType; // 1 = pride land    2 = cub training
        int _position = 0;
        int _previousPosition;
        bool _extraTurn;
        int _age;
        int _strength;
        int _stamina;
        int _wisdom;
        int _pridePoints;
        string _characterName;
        bool _finished = false;

    public:

        Player(std::string _name);
        Player();
        // Player(std::string _name, Character _character, Advisor _advisor, int _pathType, bool _ int _character, int _strength, int _stamina, int _wisdom, int _pridePoints);
        

        // getters

        string getName();
        Character getCharacter();
        // Advisor getAdvisor();
        int getPathType();
        int getAdvisor();
        int getPosition();
        int getPreviousPosition();
        bool getExtraTurn();
        int getAge();
        int getStrength();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        string getAdvisorName();
        bool getFinished();
        // int getPathType();

        // setters

        void setName(string name);
        void setAge(int age);
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom);
        void setPridePoints(int pridePoints);
        void setCharName(string charName);
        void setPathType(int p);
        void setAdvisor(int a);
        void setAdvisorName(string a);
        void setCharacter(Character c);
        void setPosition(int p);



        

        // methods

        void printPlayerStats();
        void cubTraining();
        void prideLand();
        void move(int spaces);
        void updateStats(); // update stats based on certain things
        void chooseAdvisor(); // allows for picking an advisor
        void traitToPoints();
        void finished();



};

#endif