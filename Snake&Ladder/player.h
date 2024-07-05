#include<iostream>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H

class Player{
    private:
    string name;
    int curr_position;

    public:
    void setName(string _name);
    string getName();
    void setPosition(int _pos);
    int getPosition();
};

#endif