#include "game.h"
#include "event.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


Game::Game(){

}

void startGame(){

}



void Game::readFiles() {

    // read character files

    std::ifstream char_in("project2_input_files/characters.txt");
    if (!char_in) {
        throw std::runtime_error("Cannot open data/characters.txt");
    }

    std::string char_line;
    // skip header
    if (!std::getline(char_in, char_line)) {
        throw std::runtime_error("characters.txt is empty");
    }

    while (std::getline(char_in, char_line)) {
        if (char_line.empty()) continue;

        std::stringstream ss(char_line);
        std::string name, ageStr, strStr, staStr, wisStr, ppStr;

        // split on '|'
        if (!std::getline(ss, name, '|') ||
            !std::getline(ss, ageStr, '|') ||
            !std::getline(ss, strStr, '|') ||
            !std::getline(ss, staStr, '|') ||
            !std::getline(ss, wisStr, '|') ||
            !std::getline(ss, ppStr)) {
            std::cerr << "Skipping bad line: " << char_line << "\n";
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









    // read event files

    std::ifstream event_in("project2_input_files/random_events.txt");
    if (!event_in) {
        throw std::runtime_error("Cannot open data/characters.txt");
    }

    std::string event_line;
    // skip header
    if (!std::getline(event_in, event_line)) {
        throw std::runtime_error("characters.txt is empty");
    }

    while (std::getline(event_in, event_line)) {
        if (event_line.empty()) continue;

        std::stringstream ss(event_line);
        std::string desc, pathTypeStr, advisorStr, prideDeltaStr;
        // int pathType, advisor, prideDelta;

        // split on '|'
        if (!std::getline(ss, desc, '|') ||
            !std::getline(ss, pathTypeStr, '|') ||
            !std::getline(ss, advisorStr, '|') ||
            !std::getline(ss, prideDeltaStr, '|')) {
            std::cerr << "Skipping bad line: " << event_line << "\n";
            continue;
        }


        int pathType = std::stoi(pathTypeStr);
        int advisor = std::stoi(advisorStr);
        int prideDelta = std::stoi(prideDeltaStr);


        allEvents.emplace_back(
            desc, pathType, advisor, prideDelta
        );
    }


    // read riddle files

    std::ifstream in("project2_input_files/riddles.txt");
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
        std::string question, answer;
        // int pathType, advisor, prideDelta;

        // split on '|'
        if (!std::getline(ss, question, '|') ||
            !std::getline(ss, answer, '|')) {
            std::cerr << "Skipping bad line: " << line << "\n";
            continue;
        }



        allRiddles.emplace_back(
            question, answer
        );
    }

    
}


void Game::playerSetup(){

    cout << "\n\nWelcome to the safari, we are going to put your survival skills to the test!\nYou need 2-5 players for this game, so find a couple friends. \n" << endl;




    // This code determines player count EXTRA CREDIT

    cout << "\nHow many players are you playing with? " << endl;



    bool validPlayerCount = false;
    int playerCountInput = 0;

    while (!validPlayerCount || cin.fail())
    {
        cout << "Type in (2,3,4 or 5): ";
        cin >> playerCountInput;
        

        cout << endl;
        // if(!cin.fail()){
        if((playerCountInput > 1 && playerCountInput < 6)){
            validPlayerCount = true;
        }
        // }
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

        // Player players[i] = players[i];

    

        // character selection

        cout << "Here are your lions to pick from: \n\n";

        for(int i = 0; i < 5; i++){
            allCharacters[i].printStats();
        }

        string selection;
        bool validSelection = false;
        int selectionIndex;
        cout << "\n\n" << players[i].getName() << " you are up, which character do you want? \n(Type in their name): ";
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
        players[i].setAge(allCharacters[selectionIndex].getAge());
        players[i].setStrength(allCharacters[selectionIndex].getStrenght());
        players[i].setStrength(allCharacters[selectionIndex].getStrenght());
        players[i].setStamina(allCharacters[selectionIndex].getStamina());
        players[i].setWisdom(allCharacters[selectionIndex].getWisdom());
        players[i].setPridePoints(allCharacters[selectionIndex].getPridePoints());
        players[i].setCharName(allCharacters[selectionIndex].getName());
        players[i].setCharacter(allCharacters[selectionIndex]);

    
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

        players[i].setPathType(path);

        // if in cub training pick an advisor
        if(path == 2){
            
            players[i].cubTraining();


            cout << "\n\nYou have picked to be in Cub Training, congratulations you get to pick an advisor! Advisors can protect you from certain random events. \nHere are your options: \n\n";

            int advisor = 0;
            string advisorName;
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

            players[i].setAdvisor(advisor);
            switch (advisor){
                case 1:
                    players[i].setAdvisorName("Rafiki");
                    break;
                case 2:
                    players[i].setAdvisorName("Nala");
                    break;
                case 3:
                    players[i].setAdvisorName("Sarabi");
                    break;
                case 4:
                    players[i].setAdvisorName("Zaru");
                    break;
                case 5:
                    players[i].setAdvisorName("Sarafina");
                    break;

            }

            

            
        
        }

        else{
            players[i].setAdvisor(0);
            players[i].setAdvisorName("");
            players[i].prideLand();
        }


    


    }

    // cout << "------" << player1.getName() << player1.getAge() << player1.getAdvisor() << player2.getName() << player2.getAge() << player2.getAdvisor();

}






// SET UP BOARD

void Game::setUpBoard(){
    board = Board(_playerCount);
    
    int pMap[5][2];

    // [
    //     [1,0],
    //     [2,0],
    //     [1,0]
    // ]

    for(int i = 0; i < _playerCount; i++){
        pMap[i][1] = 0; // sets position to 0,
        pMap[i][0] = players[i].getPathType();
    }

    board.setPlayerMap(pMap);

    // board.displayBoard();
}




bool Game::isGameOver(){
    int playersDone = 0;
    for(int i = 0; i < _playerCount; i++){
        if(players[i].getFinished()) playersDone++;
    }

    if(playersDone == _playerCount) return true;
    return false;

}


void Game::playTurn(){
    std::srand(std::time(0));
    for(int i = 0; i < _playerCount; i++){
        // main menu
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        if(!players[i].getFinished()){
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

            

            board.displayBoard();
            bool mainMenu = true;
            while(mainMenu){
                int mainMenuSelection;

                
                cout << "\n\n\n" << players[i].getName() << " it is your turn.";
                cout << "\n\nMAIN MENU - Select an option to continue:";
                cout << "\n\n1. Check Player Progress (1)";
                cout << "\n\n2. Review Character (2)";
                cout << "\n\n3. Check Position (3)";
                cout << "\n\n4. Review your Advisor (4)";
                cout << "\n\n5. Move Forward (5)";

                cout << "\n\n\nPlease chose one of the following options: ";
                cin >> mainMenuSelection;

                while(mainMenuSelection < 1 || mainMenuSelection > 5){
                    cout << "\nOops, type in 1, 2, 3, 4 or 5: ";
                    cin >> mainMenuSelection;
                }

                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                if(mainMenuSelection != 5){
                    switch (mainMenuSelection){

                        case 1: // main menu - check player progress
                            players[i].printPlayerStats();

                            // TODO: add ability to convert points

                            break;
                        
                        case 2: // main menu - review character 
                            players[i].getCharacter().printStats();
                            break;

                        case 3: // check position
                            cout << "You are on position: " << players[i].getPosition() << endl;
                            break;

                        case 4: // review advsior
                            cout << "Advisor Name: " << (players[i].getAdvisor() != 1 ? "You don't have an advisor, you selected to be in pride lands" : players[i].getAdvisorName()) << endl;

                            if(players[i].getAdvisor() != 0){
                                string changeAdvisor;
                                cout << "\nWould you like to change your advisor? (Y or N): ";
                                cin >> changeAdvisor;

                                while(changeAdvisor != "Y" && changeAdvisor != "N"){
                                    cout << "\nOops I didn't understand that, (Y or N): ";
                                    cin >> changeAdvisor;

                                }
                                if(changeAdvisor == "Y"){
                                    
                                    cout << "\n\nYou can update your advisor \nHere are your options: \n\n";

                                    int advisor = 0;
                                    string advisorName;
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

                                    players[i].setAdvisor(advisor);
                                    switch (advisor){
                                        case 1:
                                            players[i].setAdvisorName("Rafiki");
                                            break;
                                        case 2:
                                            players[i].setAdvisorName("Nala");
                                            break;
                                        case 3:
                                            players[i].setAdvisorName("Sarabi");
                                            break;
                                        case 4:
                                            players[i].setAdvisorName("Zaru");
                                            break;
                                        case 5:
                                            players[i].setAdvisorName("Sarafina");
                                            break;

                                    }
                                    

                                }
                                // else{

                                // }


                                
                            }
                            break;


                    }
                }
                else{
                    mainMenu = false;
                }
            }

            // move forward starts here

            bool anotherTurn = true;
            while(anotherTurn){
                anotherTurn = false;
                // spinner
                cout << "===============================\n\n";
                cout << players[i].getName() << ", we are going to roll a dice, this will indicate how many spaces you move." << endl;
                
                // roll dice
                std::uniform_int_distribution<int> distribution(1, 6);
                static std::mt19937 generator(std::time(0));
                int moveSpaces = distribution(generator);
                // int moveSpaces = 20;
                cout << "YOU ROLLED: " << moveSpaces << "\n\n";

                
                

                if(players[i].getPosition() + moveSpaces >= 51){ // if player reached the end
                    cout << "Congratulations " << players[i].getName() << "! You made it to the end, stand by till everyone else is done" << endl;
                    players[i].finished();
                    moveSpaces = 51 - players[i].getPosition();
                    players[i].setPosition(52);
                    board.movePlayer(i, moveSpaces);
                    // sleep_for(4000ms);
                }
                else{
                    
                    // handle players new tile


                    // moves
                    board.movePlayer(i, moveSpaces);
                    players[i].setPosition(board.getPlayerPosition(i));
                    board.displayBoard();

                    // processes tile

                    char tile = board.processTile(players[i].getPathType(), players[i].getPosition());

                    if(tile == 'G'){
                        int randomEventHappening = rand() % 100;
                        cout << "\n\nGrass Land!" << endl;
                        sleep_for(2000ms);
                        if(randomEventHappening < 50){
                            cout << "\nYou have been chosen for a random event" << endl;
                            int pickRandomEvent;
                            bool validEvent = false;
                            while(!validEvent){
                                pickRandomEvent = rand() % 50;
                                if((allEvents[pickRandomEvent].getPathType() == 2) || ((allEvents[pickRandomEvent].getPathType() == 0 ? 2 : 1) == players[i].getPathType()) ){
                                    validEvent = true;
                                }
                            }
                            
                            cout << "\n" << allEvents[pickRandomEvent].getDescription() << endl;
                            if((players[i].getAdvisor() == allEvents[pickRandomEvent].getAdvisorFilter()) && players[i].getAdvisor() != 0){
                                cout << "Lucky you, your advisor blocks you from this event!" << endl;

                            }
                            else{
                                players[i].setPridePoints(players[i].getPridePoints() + allEvents[pickRandomEvent].getPrideDelta());
                                cout << "Your Pride Points have updated, new value: " << to_string(players[i].getPridePoints()) << "(" << allEvents[pickRandomEvent].getPrideDelta() << ")" << endl;
                            }
                            

                        }
                        else{
                            cout << "\nNothing in the grass lands for you this time" << endl;
                        }

                        
                    }

                    else if(tile == 'B'){ // oasis tile
                        cout << "Oasis tile! You get another turn, and +200 stamina, wisdom and strenght" << endl;
                        
                        anotherTurn = true; // gives players an extra turn


                        //updates stats
                        players[i].setStamina(players[i].getStamina() + 200);
                        players[i].setStrength(players[i].getStrength() + 200);
                        players[i].setWisdom(players[i].getWisdom() + 200);
                    }

                    else if(tile == 'R'){ // graveyard tile
                        cout << "Graveyard! You have to go back 10 spaces, and lose 100 stamina, strength and wisdom" << endl;

                        players[i].setStamina(players[i].getStamina() - 100);
                        players[i].setStrength(players[i].getStrength() - 100);
                        players[i].setWisdom(players[i].getWisdom() - 100);

                        board.movePlayer(i, -10);
                        players[i].setPosition(board.getPlayerPosition(i));
                        
                        
                    }

                    else if(tile == 'N'){ // hyena tile
                        cout << "Hyena Tile, unfortunately you have been dragged back to you last position and lost 300 stamina points" << endl;

                        players[i].setStamina(players[i].getStamina() - 300);

                        board.movePlayer(i, -moveSpaces);
                        players[i].setPosition(board.getPlayerPosition(i));

                        

                    }

                    else if(tile == 'P'){ // counseling tile
                        cout << "Counseling Tile, pick an advisor and gain 300 stamina, strength and wisdom points" << endl;

                        players[i].setStamina(players[i].getStamina() + 300);
                        players[i].setStrength(players[i].getStrength() + 300);
                        players[i].setWisdom(players[i].getWisdom() + 300);

                        cout << "\n\nYou can update your advisor \nHere are your options: \n\n";

                        int advisor = 0;
                        string advisorName;
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

                        players[i].setAdvisor(advisor);
                        switch (advisor){
                            case 1:
                                players[i].setAdvisorName("Rafiki");
                                break;
                            case 2:
                                players[i].setAdvisorName("Nala");
                                break;
                            case 3:
                                players[i].setAdvisorName("Sarabi");
                                break;
                            case 4:
                                players[i].setAdvisorName("Zaru");
                                break;
                            case 5:
                                players[i].setAdvisorName("Sarafina");
                                break;

                        }
                    }

                    else if(tile == 'U'){
                        
                        int pickRandomEvent = rand() % 28;

                    }

                }
                    
                sleep_for(5ms);
                sleep_for(5000ms);

            }
        }
            
        
        else{
            cout << players[i].getName() << " you ended the game, next turn" << endl;
            sleep_for(2.5s);
        }
    }

}







int Game::getPlayerCount(){
    return _playerCount;
}