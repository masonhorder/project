#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream> 




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
        
        // GETTERS
        string getName();
        int getAge();
        int getStrenght();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        bool getChosen();

        // SETTERS
        void setName(string name);
        void setAge(int age);
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom);
        void setPridePoints(bool pridePoints);

        // METHODS
        void choseChar();
        void printStats();


};

#endif