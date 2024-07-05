#include "cell.h"
#include<vector>
using namespace std;

class Board{
    public:
    int size;
    vector<vector<Cell*>> cells;

    Board(int _size);
    Cell* getCell(int pos);
    void placeJumps(int snakes, int ladders);
};
