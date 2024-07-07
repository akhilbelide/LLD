#include "vendingMachine.h"

VendingMachine::VendingMachine(){
    state = new IdleState();
}

void VendingMachine::changeState(State *new_state){
    state = new_state;
}