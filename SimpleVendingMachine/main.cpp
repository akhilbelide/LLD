#include<iostream>
#include "vendingMachine.h"
#include "state.h"
using namespace std;


int main(){
    VendingMachine *machine = new VendingMachine();
    State *curr_state;

    curr_state = machine->state;
    curr_state->choose_product(machine);
    curr_state->click_insert_coins_button(machine);

    curr_state = machine->state;
    curr_state->insert_coins(machine);
    curr_state->insert_coins(machine);
    curr_state->choose_product(machine);
    curr_state->click_select_product_button(machine);

    curr_state = machine->state;
    curr_state->click_select_product_button(machine);
    curr_state->dispatch_product(machine);
    curr_state->choose_product(machine);

    curr_state = machine->state;
    curr_state->dispatch_product(machine);

    
    return 0;
}