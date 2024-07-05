#include "board.h"
#include "cell.h"
#include<vector>
#include<cstdlib>
#include<time.h>
using namespace std;

Board::Board(int _size){
    this->size = _size;
    cells.resize(size, vector<Cell*> (size));
}

Cell* Board::getCell(int pos){
    int row=pos/size;
    int col=pos%size;
    return cells[row][col];
}

void Board::placeJumps(int snakes, int ladders){
    srand(time(0));
    for(int i=0;i<snakes;i++){
        bool found = false;
        int snakeHead;
        int snakeTail;

        while(!found){
            snakeHead = rand()%((size*size) -1);
            snakeTail = rand()%((size*size) -1);
            if(snakeHead>snakeTail)
                found = true;

        }
        Jump *j = new Jump(snakeHead, snakeTail);
        Cell *cell = getCell(snakeHead);
        cell->jump = j;
    }

    for(int i=0;i<ladders;i++){
        bool found = false;
        int ladderStart;
        int ladderEnd;

        while(!found){
            ladderEnd = rand()%((size*size) -1);
            ladderStart = rand()%((size*size) -1);
            if(ladderEnd>ladderStart)
                found = true;

        }
        Jump *j = new Jump(ladderStart, ladderEnd);
        Cell *cell = getCell(ladderStart);
        cell->jump = j;
    }
}