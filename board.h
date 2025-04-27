// MASON HORDER AND HADDEN SPENCER


#ifndef BOARD_H
#define BOARD_H
#include "tile.h"

class Board
{
private:
    int  _board_size;
    Tile _tiles[2][80];
    static const int _MAX_PLAYERS = 5;
    int _player_count;
    int _playerMap[_MAX_PLAYERS][2]; // spot 1 is path type, spot 2 is position
    void displayTile(int track, int pos, bool displayPlayerOnTile[5]);
    void initializeTiles(int player_index);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count, int _board_size);
    void displayTrack(int track);
    void initializeBoard();
    void displayBoard();
    bool movePlayer(int player_index, int moveSpaces);
    int getPlayerPosition(int player_index) const;
    void setPlayerMap(int p[5][2]); 
    char processTile(int t, int p);
    void setBoardSize(int b);
    int getBoardSize();
};

#endif