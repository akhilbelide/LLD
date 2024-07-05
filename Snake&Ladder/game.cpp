#include "game.h"
using namespace std;

Game::Game(){
    initailize_game();
}

void Game::initailize_game(){
    //set up the Players
    Player *p1 = new Player();
    p1->setName("Akhil");
    p1->setPosition(-1);

    Player *p2 = new Player();
    p2->setName("Dhoni");
    p2->setPosition(-1);

    //board set up
    //in its constructor
    b=new Board(5);

    //Dice
    Dice *d = new Dice(1,6);
    Dice *d2 = new Dice(1,8);
    dices.push_back(d);
    dices.push_back(d2);

    //placing Snakes & Ladders
    b->placeJumps(3,5);

}

void Game::start_game(){
    bool hasWinner = false;

    while(!hasWinner){
        Player *curr_player = players.front();
        players.pop();

        int counter=0;
        for(Dice* dice : dices){
            counter+=dice->rollDice();
        }

        int new_position = curr_player->getPosition() + counter;
        Cell *new_cell = b->getCell(new_position);

        if(new_cell->jump!=nullptr){
            new_position = new_cell->jump->end;
        }

        curr_player->setPosition(new_position);
        players.push(curr_player);

        if(new_position >= b->size*b->size)
            hasWinner = true;
    }
}