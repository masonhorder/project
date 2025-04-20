#ifndef BOARD_H
#define BOARD_H
#include "tile.h"

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 5;
    int _player_count;
    int _playerMap[5][2]; // spot 1 is path type, spot 2 is position
    // int _player_position[_MAX_PLAYERS];
    void displayTile(int track, int pos, bool displayPlayerOnTile[5]);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count);
    void displayTrack(int track);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index, int moveSpaces);
    int getPlayerPosition(int player_index) const;
    void setPlayerMap(int p[5][2]); 
};

#endif