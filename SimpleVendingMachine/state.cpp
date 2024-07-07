#include "state.h"
#include "vendingMachine.h"

IdleState::IdleState(){
    cout<<"Machine currently in Idle State"<<endl;
}

void IdleState::click_insert_coins_button(VendingMachine *machine){
    cout<<"Inserting coins"<<endl;
    machine->changeState(new HasMoneyState());
}

void IdleState::insert_coins(VendingMachine *machine){
    cout<<"Click on Insert coins button first...."<<endl;
}

void IdleState::click_select_product_button(VendingMachine *machine){
    cout<<"Click on Insert coins button first...."<<endl;
}

void IdleState::choose_product(VendingMachine *machine){
    cout<<"Click on Insert coins button first...."<<endl;
}

void IdleState::dispatch_product(VendingMachine *machine){
    cout<<"Click on Insert coins button first...."<<endl;
}

void IdleState::cancel(VendingMachine *machine){
    cout<<"Click on Insert coins button first...."<<endl;
}

/// new class ------------------------------------------
HasMoneyState::HasMoneyState(){
    cout<<"Machine currently in HasMoney State"<<endl;
}

void HasMoneyState::click_insert_coins_button(VendingMachine *machine){
    cout<<"Already clicked.."<<endl;
}

void HasMoneyState::insert_coins(VendingMachine *machine){
    cout<<"Inserting coins"<<endl;
}

void HasMoneyState::click_select_product_button(VendingMachine *machine){
    cout<<"Clicked on Select product Button"<<endl;
    machine->changeState(new SelectProdState());
}

void HasMoneyState::choose_product(VendingMachine *machine){
    cout<<"Insert coins first & click on select product button"<<endl;
}

void HasMoneyState::dispatch_product(VendingMachine *machine){
    cout<<"Insert coins first & click on select product button"<<endl;
}

void HasMoneyState::cancel(VendingMachine *machine){
    cout<<"giving you refund...."<<endl;
    machine->changeState(new IdleState());
}


/// new class ------------------------------------------
SelectProdState::SelectProdState(){
    cout<<"Machine currently in SelectProd State"<<endl;
}

void SelectProdState::click_insert_coins_button(VendingMachine *machine){
    cout<<"Already clicked.."<<endl;
}

void SelectProdState::insert_coins(VendingMachine *machine){
    cout<<"Already inserted..."<<endl;
}

void SelectProdState::click_select_product_button(VendingMachine *machine){
    cout<<"Already clicked..."<<endl;
}

void SelectProdState::choose_product(VendingMachine *machine){
    cout<<"Selecting product"<<endl;
    machine->changeState(new DispatchState());
}

void SelectProdState::dispatch_product(VendingMachine *machine){
    cout<<"First select the product...."<<endl;
}

void SelectProdState::cancel(VendingMachine *machine){
    cout<<"giving you refund...."<<endl;
    machine->changeState(new IdleState());
}

/// new class ------------------------------------------
DispatchState::DispatchState(){
    cout<<"Machine currently in Dispatching State"<<endl;
}

void DispatchState::click_insert_coins_button(VendingMachine *machine){
    cout<<"Already clicked.."<<endl;
}

void DispatchState::insert_coins(VendingMachine *machine){
    cout<<"Already inserted..."<<endl;
}

void DispatchState::click_select_product_button(VendingMachine *machine){
    cout<<"Already clicked..."<<endl;
}

void DispatchState::choose_product(VendingMachine *machine){
    cout<<"Machine is busy dispatching.."<<endl;
}

void DispatchState::dispatch_product(VendingMachine *machine){
    cout<<"Dispatching/ed the selected product"<<endl;
    machine->changeState(new IdleState());
}

void DispatchState::cancel(VendingMachine *machine){
    cout<<"giving you refund...."<<endl;
    machine->changeState(new IdleState());
}
