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

    if (allCharacters.empty()) {
        throw std::runtime_error("No characters loaded");
    }
}


void Game::characterSelection(){
    for(int i = 0; i < 5; i++){
        std::cout << allCharacters[i].getName() << endl;
    }
}

void Game::choosePath(Player p){

}

void Game::mainMenu(Player p){

}

void Game::processTile(Player p, Tile t){

}

void Game::handleRandomEvent(Player p){

}

void Game::handleChallenge(Player p){

}

void Game::playTurn(Player p){

}

bool Game::isGameOver(){
    return true;
}

void Game::endGame(){

}
