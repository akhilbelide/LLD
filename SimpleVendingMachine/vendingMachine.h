#include<iostream>
#include "state.h"
using namespace std;

#ifndef VENDING_H
#define VENDING_H


class VendingMachine{
    public:

    State *state;

    VendingMachine();
    void changeState(State *new_state);
};

#endif