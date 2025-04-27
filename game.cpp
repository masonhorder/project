// MASON HORDER AND HADDEN SPENCER

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

// FILE SET UP

// this method reads the files for riddles, events and characters
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


        int age = std::stoi(ageStr);
        int strength = std::stoi(strStr);
        int stamina = std::stoi(staStr);
        int wisdom = std::stoi(wisStr);
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



// PLAYER SET UP - Hadden

// sets up player with certain values
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
        // if(!cin.fail()){
        if((playerCountInput > 1 && playerCountInput < 6)){
            validPlayerCount = true;
        }
        // }
    }
    
    _playerCount = playerCountInput;

    int selectedBoardSize;
    cout << "\nHow big would you like the playing board to be? (30 - 80)" << endl; 
    
    bool validBoardSize = false;
    //CUSTOMIZATION - Allow for different board size - made a ratio in board.cpp that made green tiles ratio to length
    while(!validBoardSize){ 
        cout << "Type in a value from 30 to 80: ";
        cin >> selectedBoardSize;

        cout << endl;
        if((selectedBoardSize >= 30 && selectedBoardSize <= 80)){
            validBoardSize = true;
        }
    }
    
    _boardSize = selectedBoardSize;

    cout << "\n Awesome! Your board will be " << _boardSize << " tiles long!" << endl;

    
    // This loop sets name

    for(int i = 0; i < _playerCount; i++){
        string n;
        cout << "\n\n\nHello Player " << (i+1) << "!\nWhats your name?" << endl;
        cin >> n;

        players[i] = Player(n);
    }


    
    for(int i = 0; i < _playerCount; i++){

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

    
        // path selection

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

}






// SET UP BOARD

void Game::setUpBoard(){
    board = Board(_playerCount, _boardSize);
    
    int pMap[5][2];


    for(int i = 0; i < _playerCount; i++){
        pMap[i][1] = 0; // sets position to 0,
        pMap[i][0] = players[i].getPathType();
    }

    board.setPlayerMap(pMap);

}


// Check if game over

bool Game::isGameOver(){
    int playersDone = 0;
    for(int i = 0; i < _playerCount; i++){ // for each player, add if they are done
        if(players[i].getFinished()) playersDone++;
    }

    if(playersDone == _playerCount) return true; // if playersDone == total players, everyone is done
    return false;

}



// GAME PLAY

// this function includes the main game play

// it loops through and grants a turn to each player
void Game::playTurn(){
    std::srand(std::time(0));
    for(int i = 0; i < _playerCount; i++){
        // main menu
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        if(!players[i].getFinished()){ // check if the player is finished - if they are skip their turn
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

            

            board.displayBoard();
            bool mainMenu = true;
            while(mainMenu){ // loop through the main menu letting the player pick until they chose to move on
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


                string convertPoints;


                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                if(mainMenuSelection != 5){
                    switch (mainMenuSelection){

                        case 1: // main menu - check player progress and convert points
                            players[i].printPlayerStats();


                            
                            cout << "\nWould you like to convert your points right now? (Y or N): ";
                            cin >> convertPoints;

                            while(convertPoints != "Y" && convertPoints != "N"){
                                cout << "\nOops I didn't understand that, (Y or N): ";
                                cin >> convertPoints;

                            }
                            if(convertPoints == "Y"){
                                players[i].traitToPoints();

                                players[i].printPlayerStats();
                            }
                            

                            break;
                        
                        case 2: // main menu - review character 
                            players[i].getCharacter().printStats();
                            break;

                        case 3: // main menu - check position
                            cout << "You are on position: " << players[i].getPosition() << endl;
                            break;

                        case 4: // main menu - review advsior
                            cout << "Advisor Name: " << (players[i].getAdvisor() != 1 ? "You don't have an advisor, you selected to be in pride lands" : players[i].getAdvisorName()) << endl;

                            if(players[i].getAdvisor() != 0){ // check they have the ability to select advisor
                                string changeAdvisor;
                                cout << "\nWould you like to change your advisor? (Y or N): ";
                                cin >> changeAdvisor;

                                while(changeAdvisor != "Y" && changeAdvisor != "N"){
                                    cout << "\nOops I didn't understand that, (Y or N): ";
                                    cin >> changeAdvisor;

                                }

                                if(changeAdvisor == "Y"){ // change advisor if they want to
                                    
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



                                
                            }
                            break;


                    }
                }
                else{
                    mainMenu = false;
                }
            }

            // if player selected to roll and move here is the code (ie loop is broken)

            bool anotherTurn = true;
            while(anotherTurn){
                anotherTurn = false;
                
                
                // roll a dice
                cout << "===============================\n\n";
                cout << players[i].getName() << ", we are going to roll a dice, this will indicate how many spaces you move." << endl;
                
                std::uniform_int_distribution<int> distribution(1, 6);
                static std::mt19937 generator(std::time(0));
                int moveSpaces = distribution(generator);
                cout << "YOU ROLLED: " << moveSpaces << "\n\n";


                

                if(players[i].getPosition() + moveSpaces >=_boardSize-1){ // if player reached the end
                    cout << "Congratulations " << players[i].getName() << "! You made it to the end, stand by till everyone else is done" << endl;
                    players[i].finished();
                    moveSpaces = _boardSize-1 - players[i].getPosition();
                    players[i].setPosition(_boardSize);
                    board.movePlayer(i, moveSpaces);
                }
                else{
                    
                    // handle players new tile


                    // moves player to new spot
                    board.movePlayer(i, moveSpaces);
                    players[i].setPosition(board.getPlayerPosition(i));
                    board.displayBoard();



                    // processes tile



                    // EXTRA CREDIT, players battle for space on tile if they land on the same tile

                    int playerOnTile = -1;

                    for(int p = 0; p < _playerCount; p++){
                        if(players[p].getPosition() == players[i].getPosition() && p != i && players[p].getPathType() == players[i].getPathType()){
                            playerOnTile = p;
                        }
                    } 

                    if(playerOnTile != -1){
                        cout << "Uh oh! " << players[i].getName() <<  " and " << players[playerOnTile].getName() << " are sharing a tile... time to battle it out for who gets to stay" << endl;

                        cout << "\nWe will roll a dice for each of you, whoever rolls higher stays, the other will return to " << players[i].getName() << "'s previous position" << endl << endl;

                        sleep_for(3000ms);

                        std::uniform_int_distribution<int> distribution(1, 6);
                        static std::mt19937 generator(std::time(0));
                        int m1 = distribution(generator);
                        int m2 = distribution(generator);
                        
                        while(m2 == m1){
                            m2 = distribution(generator);
                        }

                        cout << "\n\n" << players[i].getName() << " Rolled: " << m1 << "\n\n";
                        cout << players[playerOnTile].getName() << " Rolled: " << m2 << "\n\n";

                        if(m2 > m1){
                            cout << players[i].getName() << " you must go back to your old space" << endl;
                            board.movePlayer(i, -moveSpaces);
                            players[i].setPosition(board.getPlayerPosition(i));

                        }
                        else{
                            cout << players[playerOnTile].getName() << " you must go back to " << players[i].getName() << "'s old space" << endl;
                            board.movePlayer(playerOnTile, -moveSpaces);
                            players[playerOnTile].setPosition(board.getPlayerPosition(i));
                        }

                    }


                    else{ // if two players arent on same tile, handle it as normal
                        char tile = board.processTile(players[i].getPathType(), players[i].getPosition());


                        // checks for the different tiles and has action based on what they land on
                        if(tile == 'G'){  // grass land tile

                            int randomEventHappening = rand() % 100;
                            cout << "\n\nGrass Land!" << endl;
                            sleep_for(2000ms);

                            if(randomEventHappening < 50){ // 50% chance a player gets a random event
                                cout << "\nYou have been chosen for a random event" << endl;
                                int pickRandomEvent;
                                bool validEvent = false;
                                while(!validEvent){ // makes sure that the event pertains to the correct path type
                                    pickRandomEvent = rand() % 50;
                                    if((allEvents[pickRandomEvent].getPathType() == 2) || ((allEvents[pickRandomEvent].getPathType() == 0 ? 2 : 1) == players[i].getPathType()) ){
                                        validEvent = true;
                                    }
                                }
                                
                                cout << "\n" << allEvents[pickRandomEvent].getDescription() << endl;

                                // checks if advisor blocks the event
                                if((players[i].getAdvisor() == allEvents[pickRandomEvent].getAdvisorFilter()) && players[i].getAdvisor() != 0){
                                    cout << "Lucky you, your advisor blocks you from this event!" << endl;

                                }
                                else{

                                    // EXTRA CREDIT: age effects events outcome
                                    double prideDeltaModifier = 1;
                                    int ageChangeHappening = rand() % 100;
                                    
                                    
                                    if(ageChangeHappening < 50){ // 50% chance age does effect event outcome
                                        int a = players[i].getAge();

                                        int randomAge = rand() % 20; // random age chosen

                                        if(a > randomAge){ // if player age is greater than random age, multiply pride delta times 2
                                            prideDeltaModifier = 2;
                                            cout << "Looks like your old age made a difference... you now have a pride point change of 2x: " << (allEvents[pickRandomEvent].getPrideDelta()*prideDeltaModifier) << " pride points" << endl;
                                        }
                                    }

                                    players[i].setPridePoints(players[i].getPridePoints() + (allEvents[pickRandomEvent].getPrideDelta()*prideDeltaModifier));
                                    cout << "Your Pride Points have updated, new value: " << to_string(players[i].getPridePoints()) << "(" << allEvents[pickRandomEvent].getPrideDelta() << ")" << endl;
                                }
                                

                            }


                            else{ // in the case that there is no event chosen
                                cout << "\nNothing in the grass lands for you this time" << endl;
                            }

                            
                        }


                        else if(tile == 'B'){ // oasis tile
                            cout << "Oasis tile! You get another turn, and +200 stamina, wisdom and strenght" << endl;
                            
                            anotherTurn = true; // gives players an extra turn, runs loop again


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
                            
                            // update stats
                            players[i].setStamina(players[i].getStamina() - 300);

                            board.movePlayer(i, -moveSpaces);
                            players[i].setPosition(board.getPlayerPosition(i));

                            

                        }

                        else if(tile == 'P'){ // counseling tile
                            cout << "Counseling Tile, pick an advisor and gain 300 stamina, strength and wisdom points" << endl;

                            // update stats
                            players[i].setStamina(players[i].getStamina() + 300);
                            players[i].setStrength(players[i].getStrength() + 300);
                            players[i].setWisdom(players[i].getWisdom() + 300);

                            cout << "\n\nYou can update your advisor \nHere are your options: \n\n";

                            // allow advisor selection
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

                        else if(tile == 'U'){ // challenge tile
                            
                            cout << "Challenge tile, Answer the riddle to gain 500 pride points" << endl;


                            // randomly picks a riddle
                            int pickRandomRiddle = rand() % 28;

                            string answer = allRiddles[pickRandomRiddle].getAnswer();
                            string input;
                            cout << "\nRiddle: " << allRiddles[pickRandomRiddle].getQuestion() << "(type in exact answer): ";
                            
                            cin >> input;


                            // makes answer actually correct by trimming the strings so only the chars are left
                            answer.erase(0, answer.find_first_not_of(" \t\r\n"));               
                            answer.erase(answer.find_last_not_of(" \t\r\n") + 1);               

                            input.erase(0, input.find_first_not_of(" \t\r\n"));                 
                            input.erase(input.find_last_not_of(" \t\r\n") + 1); 



                            if(answer == input){ // awards points if player is correct
                                cout << "\n\nCongrats you got it right! +500 pride points" << endl;
                                players[i].setPridePoints(players[i].getPridePoints() + 500);
                            }


                            else{
                                cout << "Wrong! Correct Answer: " << answer << endl;
                            }

                        }


                        // EXTRA CREDIT: tiles for each path type
                        else if(tile == 'W'){ // EXTRA CREDIT yellow tile which is pot of gold for pride lands
                            cout << "You landed on the best tile, pot of gold, enjoy +2000 pride points." << endl << endl;
                            players[i].setPridePoints(players[i].getPridePoints() + 2000);
                            cout << "Your pride points are now: " << players[i].getPridePoints() << endl;

                        }

                        

                        else if(tile == 'A'){ // EXTRA CREDIT black tile which removes points from every other player
                            cout << "You have turned to a wizard, take away 100 pride points from every other player." << endl << endl;
                            for(int s = 0; s < _playerCount; s++){
                                if(s != i){
                                    players[s].setPridePoints(players[s].getPridePoints()-100);
                                    players[i].setPridePoints(players[i].getPridePoints()+100);
                                }
                            }

                            cout << "Your pride points are now: " << players[i].getPridePoints() << endl;
                        }   
                    }

                }
                    
                sleep_for(5ms);
                sleep_for(5000ms);

            }
        }
            
        
        else{
            cout << players[i].getName() << " you made it to the end. Next turn" << endl;
            sleep_for(2s);
        }
    }

}


// method to end the game
void Game::endGame(){

    int playersranked[5]; // this stores the player numbers in a ranked order

    // convert points
    for(int i = 0; i < _playerCount; i++){
        players[i].traitToPoints();
    }

    int n = _playerCount;

    for(int i = 0; i < n; ++i) {
        playersranked[i] = i;
    }


    // SORT FUNCTION
    // sort players, create a ranked list based off pride poibnts
    for(int i = 0; i < n; ++i) {
        int bestPos = i;
        int bestIndex = playersranked[i];
        int bestScore = players[bestIndex].getPridePoints();

        for(int j = i + 1; j < n; ++j) {
            int idx = playersranked[j];
            int pts = players[idx].getPridePoints();
            if (pts > bestScore) {
                bestScore = pts;
                bestPos = j;
            }
        }

        if (bestPos != i) {
            int tmp = playersranked[i];
            playersranked[i] = playersranked[bestPos];
            playersranked[bestPos] = tmp;
        }
    }


    std::ofstream out("results.txt");  // stores results to a file


    // PRINT/STORE results
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    
    cout << "GAME OVER!!\n\n\n";
    out << "GAME OVER!!\n\n\n";

    cout << "Results: " << endl << endl;
    out << "Results: " << endl << endl;

    cout << "First Place: " << endl;
    out << "First Place: " << endl;

    sleep_for(1000ms);

    cout << players[playersranked[0]].getName() << " with " << players[playersranked[0]].getPridePoints() << " pride points\n\n";
    out << players[playersranked[0]].getName() << " with " << players[playersranked[0]].getPridePoints() << " pride points\n\n";

    cout << "Second Place: " << endl;
    out << "Second Place: " << endl;



    sleep_for(1000ms);

    cout << players[playersranked[1]].getName() << " with " << players[playersranked[1]].getPridePoints() << " pride points\n\n";
    out << players[playersranked[1]].getName() << " with " << players[playersranked[1]].getPridePoints() << " pride points\n\n";

    if(_playerCount > 2){
        cout << "Third Place: " << endl;
        out << "Third Place: " << endl;

        sleep_for(1000ms);

        cout << players[playersranked[2]].getName() << " with " << players[playersranked[2]].getPridePoints() << " pride points\n\n";
        out << players[playersranked[2]].getName() << " with " << players[playersranked[2]].getPridePoints() << " pride points\n\n";
        
        
        if(_playerCount > 3){
            cout << "Fourth Place: " << endl;
            out << "Fourth Place: " << endl;

            sleep_for(1000ms);

            cout << players[playersranked[3]].getName() << " with " << players[playersranked[3]].getPridePoints() << " pride points\n\n";
            out << players[playersranked[3]].getName() << " with " << players[playersranked[3]].getPridePoints() << " pride points\n\n";
            
            
            if(_playerCount > 4){
                cout << "Fifth Place: " << endl;
                out << "Fifth Place: " << endl;

                sleep_for(1000ms);

                cout << players[playersranked[4]].getName() << " with " << players[playersranked[4]].getPridePoints() << " pride points\n\n";
                out << players[playersranked[4]].getName() << " with " << players[playersranked[4]].getPridePoints() << " pride points\n\n";
            }
        }
    }

}


// returns player count
int Game::getPlayerCount(){
    return _playerCount;
}

int Game::getBoardSize(){
    return _boardSize;
}

void Game::setBoardSize(int b){
    _boardSize = b;
}