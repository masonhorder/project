#include "game.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

using namespace std;


Game::Game(){

}

void startGame(){

}



void Game::readFiles() {
    std::ifstream in("project2_input_files/characters.txt");
    if (!in) {
        throw std::runtime_error("Cannot open data/characters.txt");
    }

    std::string line;
    // skip header
    if (!std::getline(in, line)) {
        throw std::runtime_error("characters.txt is empty");
    }

    while (std::getline(in, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string name, ageStr, strStr, staStr, wisStr, ppStr;

        // split on '|'
        if (!std::getline(ss, name, '|') ||
            !std::getline(ss, ageStr, '|') ||
            !std::getline(ss, strStr, '|') ||
            !std::getline(ss, staStr, '|') ||
            !std::getline(ss, wisStr, '|') ||
            !std::getline(ss, ppStr)) {
            std::cerr << "Skipping bad line: " << line << "\n";
            continue;
        }


        int age      = std::stoi(ageStr);
        int strength = std::stoi(strStr);
        int stamina  = std::stoi(staStr);
        int wisdom   = std::stoi(wisStr);
        int pridePts = std::stoi(ppStr);

        allCharacters.emplace_back(
            name, age, strength, stamina, wisdom, pridePts
        );
    }
}


void Game::playerSetup(){

    cout << "\n\nWelcome to the safari, we are going to put your survival skills to the test!\nYou need 2-5 players for this game, so find a couple friends. \n" << endl;




    // This code determines player count EXTRA CREDIT

    cout << "\nHow many players are you playing with? " << endl;



    bool validPlayerCount = false;
    int playerCountInput = 0;

    while (!validPlayerCount)
    {
        cout << "Type in (2,3,4 or 5): ";
        cin >> playerCountInput;
        cout << endl;

        if(playerCountInput > 1 && playerCountInput < 6){
            validPlayerCount = true;
        }
    }
    
    _playerCount = playerCountInput;

    

    // cout << "Here are your lions to pick from: \n\n";

    // for(int i = 0; i < 5; i++){
    //     allCharacters[i].printStats();
    // }


    // This loop sets name

    for(int i = 0; i < _playerCount; i++){
        string n;
        cout << "\nHello Player " << (i+1) << "!\nWhats your name?" << endl;
        cin >> n;

        players[i] = Player(n);
    }


    
    for(int i = 0; i < _playerCount; i++){

        Player playerUp = players[i];

    

        // character selection

        cout << "Here are your lions to pick from: \n\n";

        for(int i = 0; i < 5; i++){
            allCharacters[i].printStats();
        }

        string selection;
        bool validSelection = false;
        int selectionIndex;
        cout << "\n\n" << playerUp.getName() << " you are up, which character do you want? \n(Type in their name): ";
        cin >> selection;

        while (!validSelection)
        {
            for(int j = 0; j < 5; j++){
                if(selection == allCharacters[j].getName()){
                    if(!allCharacters[j].getChosen()){
                        validSelection = true;
                        selectionIndex = j;
                    }
                    else{
                        cout << allCharacters[j].getName() << " has already been chosen, sorry :(" << endl;
                    }
                }
            }
            if(!validSelection){
                cout << "Invalid selection, try again \n(Type in their name): ";
                cin >> selection;
            }


        }

        cout << "You picked " << allCharacters[selectionIndex].getName() << ", great choice!   \n\n";


        // set character to chosen
        allCharacters[selectionIndex].choseChar();


        // give player character stats
        playerUp.setAge(allCharacters[selectionIndex].getAge());
        playerUp.setStrength(allCharacters[selectionIndex].getStrenght());
        playerUp.setStrength(allCharacters[selectionIndex].getStrenght());
        playerUp.setStamina(allCharacters[selectionIndex].getStamina());
        playerUp.setWisdom(allCharacters[selectionIndex].getWisdom());
        playerUp.setPridePoints(allCharacters[selectionIndex].getPridePoints());
        playerUp.setCharName(allCharacters[selectionIndex].getName());

        
        // which path do you want

        int path = 0;
        bool validPathSelection = false;

        cout << "\n\nNow is the hard part... \nWhich path would you like to go on?" << endl;
        // cin >> path;
        while(!validPathSelection){
            
            cout << "\nOption 1: Straight to pride lands, where you gain 5000 pride points, however have no advisor" << endl;
            cout << "Option 2: Cub Training where you can chose an advisor and have a possibly more gentle experience" << endl;
            cout << "(Type in 1 or 2): ";
            cin >> path;
            if(path == 1 || path == 2){
                validPathSelection = true;
            }
            if(!validPathSelection){
                cout << "\n\nInvalid path selection, try again" << endl;
            }
        }

        playerUp.setPathType(path);

        // if in cub training pick an advisor
        if(path == 2){
            
            cout << "\n\nYou have picked to be in Cub Training, congratulations you get to pick an advisor! Advisors can protect you from certain random events. \nHere are your options: \n\n";

            int advisor = 0;
            bool validAdvisorSelection = false;

            while(!validAdvisorSelection){
                
                cout << "Option 1: Rafiki - Invisibility (the ability to become un-seen)" << endl;
                cout << "Option 2: Nala - Night Vision (the ability to see clearly in darkness)" << endl;
                cout << "Option 3: Sarabi - Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                cout << "Option 4: Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                cout << "Option 5: Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                cout << "(Type in the option/advisor you want): ";
                cin >> advisor;
                if(advisor == 1 || advisor == 2 || advisor == 3 || advisor == 4 || advisor == 5){
                    validAdvisorSelection = true;
                }
                if(!validAdvisorSelection){
                    cout << "\n\nInvalid Advisor selection, try again" << endl;
                }
            }

            playerUp.setAdvisor(advisor);

            
        
        }

        else{
            playerUp.setAdvisor(0);
        }


    


    }

    // cout << "------" << player1.getName() << player1.getAge() << player1.getAdvisor() << player2.getName() << player2.getAge() << player2.getAdvisor();

}

// void Game::choosePath(Player p){

// }

// void Game::mainMenu(Player p){

// }

// void Game::processTile(Player p, Tile t){

// }

// void Game::handleRandomEvent(Player p){

// }

// void Game::handleChallenge(Player p){

// }

// void Game::playTurn(Player p){

// }

// bool Game::isGameOver(){
//     return true;
// }

// void Game::endGame(){

// }
