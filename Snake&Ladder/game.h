#include "board.h"
#include "dice.h"
#include "player.h"
#include<queue>
#include<vector>
using namespace std;

class Game{
    public:
    queue<Player*> players;
    vector<Dice*> dices;
    Board *b;

    Game();
    void initailize_game();
    void start_game();

};
