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
        

        string getName();
        int getAge();
        int getStrenght();
        int getStamina();
        int getWisdom();
        int getPridePoints();
        bool getChosen();

        void setName(string name);
        void setAge(int age);
        void setStrength(int strength);
        void setStamina(int stamina);
        void setWisdom(int wisdom);
        void setPridePoints(bool pridePoints);


        void choseChar();

        void printStats();


};

#endif