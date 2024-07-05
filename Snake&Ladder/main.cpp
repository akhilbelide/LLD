#include "game.h"
using namespace std;

int main(){
    Game *game = new Game();
    game->initailize_game();
    game->start_game();
    return 1;
}