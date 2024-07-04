#include<iostream>
#include<set>
#include<vector>
#include "piece.h"
using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board{
    private:
    int size;

    public:
    vector<vector<Piece> > board;
    
    Board();
    Board(int size);
    int getSize();
    set<pair<int, int> > getEmptyCells();
    void setPiece(int x, int y, Piece p);
    bool checkWinner();
    void printBoard();

};


#endif