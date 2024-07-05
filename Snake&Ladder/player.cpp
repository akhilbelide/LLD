#include "player.h"
using namespace std;

void Player::setName(string _name){
    this->name = _name;
};

string Player::getName(){
    return this->name;
};

void Player::setPosition(int pos){
    curr_position=pos;
}

int Player::getPosition(){
    return this->curr_position;
}