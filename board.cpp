#include "board.h"
#include <iostream>
#include <cstdlib> 
#include <ctime>   


#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m"
#define GREY "\033[48;2;128;128;128m"
#define RESET "\033[0m"

using namespace std;

Board::Board() {
    _player_count = _MAX_PLAYERS;
    for (int i = 0; i < _player_count; i++) {
        _playerMap[i][1] = 0;
    }
    initializeBoard();
}


Board::Board(int player_count)
{
    // if (player_count > _MAX_PLAYERS)
    //     _player_count = _MAX_PLAYERS;
    // else
    //     _player_count = player_count;

    // for (int i = 0; i < _player_count; i++) {
    //     _playerMap[i][1] = 0;
    // }

    _player_count = player_count;

    initializeBoard();
}

void Board::initializeBoard()
{
    for (int i = 0; i < 2; i++) {
        initializeTiles(i);
    }
}

void Board::initializeTiles(int player_index)
{
    std::srand(std::time(0));
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;

    for (int i = 0; i < total_tiles; i++)
    {
        if (i == 0) {
            temp.color = 'Y'; 
        }
        else if (i == total_tiles - 1) {
            temp.color = 'O'; 
        }
        else if (green_count < (player_index == 1 ? 30 : 20) && (rand() % (total_tiles - i) < (player_index == 1 ? 30 : 20) - green_count)) {
            temp.color = 'G'; 
            green_count++;
        }
        else {
            int specialType = rand() % 100;
            bool isFirstHalf = i < (total_tiles / 2);

            if (player_index == 0) { // Cub Training
                if (!isFirstHalf && specialType < 20) {
                    temp.color = 'R'; // Graveyard
                }
                else if (specialType < 40) {
                    temp.color = 'N'; // Hyena
                }
                else if (specialType < 55) {
                    temp.color = 'B'; // Advisor
                }
                else if (isFirstHalf && specialType < 80) {
                    temp.color = 'P'; // Oasis (25%)
                }
                else if (!isFirstHalf && specialType < 85) {
                    temp.color = 'P'; // Oasis (15%)
                }
                else {
                    temp.color = 'U'; // Challenge
                }
            }
            else { // Straight to the Pride Lands
                if (isFirstHalf) {
                    // if (specialType < 25) {
                    //     temp.color = 'R'; // Graveyard
                    // }
                    if (specialType < 50) {
                        temp.color = 'N'; // Hyena
                    }
                    else if (specialType < 70) {
                        temp.color = 'B'; // Advisor
                    }
                    else if (specialType < 75) {
                        temp.color = 'P'; // Oasis (5%)
                    }
                    else {
                        temp.color = 'U'; // Challenge
                    }
                }
                else {
                    if (specialType < 25) {
                        temp.color = 'R';
                    }
                    else if (specialType < 30) {
                        temp.color = 'N';
                    }
                    else if (specialType < 50) {
                        temp.color = 'B';
                    }
                    else if (specialType < 75) {
                        temp.color = 'P';
                    }
                    else {
                        temp.color = 'U';
                    }
                }
            }
        }

        _tiles[player_index][i] = temp;
    }
}

void Board::displayTile(int track, int pos, bool displayPlayerOnTile[5])
{
    string textToDisplay = "";
    string color = "";
    // bool player = isPlayerOnTile(player_index, pos);
    // for(int i = 0; i < 2; i++)
    if (_tiles[track][pos].color == 'R') color = RED;
    else if (_tiles[track][pos].color == 'G') color = GREEN;
    else if (_tiles[track][pos].color == 'B') color = BLUE;
    else if (_tiles[track][pos].color == 'U') color = PURPLE;
    else if (_tiles[track][pos].color == 'N') color = BROWN;
    else if (_tiles[track][pos].color == 'P') color = PINK;
    else if (_tiles[track][pos].color == 'O') color = ORANGE;
    else if (_tiles[track][pos].color == 'Y') color = GREY;

    for(int j = 0; j < _player_count; j++){
        if(displayPlayerOnTile[j]){
            textToDisplay = textToDisplay + "P" + to_string(j+1) + " ";
        }
    }

    
    cout << color << "|  " << textToDisplay << " |" << RESET;
    
}

void Board::displayTrack(int track)
{   

    for (int i = 0; i < _BOARD_SIZE; i++) { // for each spot on board
        
        
        bool displayPlayerOnTile[5];

        // [true, false, false, true]

        for(int j = 0; j < _player_count; j++){ // see which players are on a tile
            if(_playerMap[j][1] == i && _playerMap[j][0] == track+1){
                displayPlayerOnTile[j] = true;
            }
            else{
                displayPlayerOnTile[j] = false; 
            }
        }


        displayTile(track, i, displayPlayerOnTile);
    }

    cout << endl;
}

void Board::setPlayerMap(int p[5][2]){
    for(int i = 0; i < _player_count; i++){
        for(int j = 0; j < 2; j++){
            _playerMap[i][j] = p[i][j];
        }
    }
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++) { // for each track type
        if(i == 0) cout << "Pride Land Board: " << endl;
        if(i == 1) cout << "Cub Training Board: " << endl;
        displayTrack(i); // display the track
        if (i == 0) cout << endl;
    }
}

bool Board::movePlayer(int player_index, int moveSpaces)
{
    _playerMap[player_index][1] += moveSpaces;
    return _playerMap[player_index][1] == _BOARD_SIZE - 1;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index < _player_count)
        return _playerMap[player_index][1];
    return -1;
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    return _playerMap[player_index][1] == pos;
}

char Board::processTile(int track, int position){
    return _tiles[track-1][position].color;
}