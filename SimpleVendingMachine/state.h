#include<iostream> 
#include<exception>
using namespace std;

#ifndef STATE_H
#define STATE_H

class VendingMachine;

class State{
    public:

    virtual void click_insert_coins_button(VendingMachine *machine) =0; 
    virtual void insert_coins(VendingMachine *machine)=0;
    virtual void click_select_product_button(VendingMachine *machine) =0; 
    virtual void choose_product(VendingMachine *machine)=0;
    virtual void dispatch_product(VendingMachine *machine) =0; 
    virtual void cancel(VendingMachine *machine)=0;
};


class IdleState : public State{
    public:

    IdleState();
    void click_insert_coins_button(VendingMachine *machine);
    void insert_coins(VendingMachine *machine);
    void click_select_product_button(VendingMachine *machine);
    void choose_product(VendingMachine *machine);
    void dispatch_product(VendingMachine *machine);
    void cancel(VendingMachine *machine);
};

class HasMoneyState : public State{
    public:

    HasMoneyState();
    void click_insert_coins_button(VendingMachine *machine);
    void insert_coins(VendingMachine *machine);
    void click_select_product_button(VendingMachine *machine);
    void choose_product(VendingMachine *machine);
    void dispatch_product(VendingMachine *machine);
    void cancel(VendingMachine *machine);
};  


class SelectProdState : public State{
    public:

    SelectProdState();
    void click_insert_coins_button(VendingMachine *machine);
    void insert_coins(VendingMachine *machine);
    void click_select_product_button(VendingMachine *machine);
    void choose_product(VendingMachine *machine);
    void dispatch_product(VendingMachine *machine);
    void cancel(VendingMachine *machine);
};  


class DispatchState : public State{
    public:

    DispatchState();
    void click_insert_coins_button(VendingMachine *machine);
    void insert_coins(VendingMachine *machine);
    void click_select_product_button(VendingMachine *machine);
    void choose_product(VendingMachine *machine);
    void dispatch_product(VendingMachine *machine);
    void cancel(VendingMachine *machine);
}; 


#endif