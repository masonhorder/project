#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream> 
#include "player.h"



using namespace std; 
class Character
{
    private:
        std::string _name;
        int _age;
        int _strength;
        int _stamina;
        int _wisdom;
        int _pridePoints;
        bool _isChosen;

    public:

        Character();
        Character(std::string _name, int _age, int _strength, int _stamina, int _wisdom, int _pridePoints);
        

        string getName();
        int getAge();
        int getStrenght();
        int getStamina();
        int getWisdom();
        int getPridePoints();

        void setName(string name);
        void setAge(int age);
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom);
        void setPridePoints(bool pridePoints);

        // void printStats();


};

#endif