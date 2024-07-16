#include<iostream>
#include<vector>
using namespace std;

class Base{
    public:
    virtual int cost()=0;
};

class ThinCrust : public Base{
    public:
    int cost(){
        return 100;
    }
};

class HandMadeCrust : public Base{
    public:
    int cost(){
        return 120;
    }
};

class Size{
    public:
    virtual int cost()=0;
};

class Medium : public Size{
    public:
    int cost(){
        return 100;
    }
};

class Large : public Size{
    public:
    int cost(){
        return 200;
    }
};

class Cheese{
    public:
    virtual int cost()=0;
};

class Cheese1 : public Cheese{
    public:
    int cost(){
        return 25;
    }
};

class Cheese2 : public Cheese{
    public:
    int cost(){
        return 30;
    }
};


class Topping{
    public:
    virtual int cost()=0;
};

class Mushroom : public Topping{
    public:
    int cost(){
        return 15;
    }
};

class Jalapeno : public Topping{
    public:
    int cost(){
        return 20;
    }
};

class PizzaBuilder;

class Pizza{
    private:
    int totalCost;
    Pizza(){
        totalCost=0;
    }
    public:
    Base *base;
    Size *size;
    vector<Topping*> topping; //opional
    Cheese *cheese; //optional
    
    friend class PizzaBuilder;
    friend class Top;

    void addToCost(int _cost){
        totalCost +=_cost;
    }

    virtual int getTotal(){
        return totalCost;
    }
};

class PizzaBuilder{
    public:
    Pizza *pizza;
    PizzaBuilder(){
        pizza = new Pizza();
    }

    PizzaBuilder* setBase(Base *_base){
        pizza->base = _base;
        pizza->addToCost(pizza->base->cost());
        return this;
    }

    PizzaBuilder* setSize(Size *_size){
        pizza->size = _size;
        pizza->addToCost(pizza->size->cost());
        return this;
    }

    PizzaBuilder* setCheese(Cheese *_ch){
        pizza->cheese = _ch;
        pizza->addToCost(pizza->cheese->cost());
        return this;
    }

    PizzaBuilder* setTopping(Topping *_topping){
        pizza->topping.push_back( _topping);
        pizza->addToCost(_topping->cost());
        return this;
    }

    Pizza* build(){
        Pizza *res = pizza;
        pizza = new Pizza();
        return res;
    }

};

class Top : public Pizza{
    public:
    Top(){

    }
};

class Tomato : public Top{
    public:
    Pizza *p;
    Tomato(Pizza *_p){
        p=_p;
    }

    int getTotal(){
        return  p->getTotal() + 1000;
    }
};

class Onion : public Top{
    public:
    Pizza *p;
    Onion(Pizza *_p){
        p=_p;
    }

    int getTotal(){
        return p->getTotal() + 2000;
    }
};


int main(){
    PizzaBuilder *builder =  new PizzaBuilder();
    Pizza *p1 = builder ->setBase(new ThinCrust()) -> setSize(new Medium()) ->build();
    cout<<p1->getTotal()<<endl;

    Pizza *p2 = builder ->setBase(new ThinCrust()) -> setSize(new Large()) 
                        ->setTopping(new Jalapeno()) -> setTopping(new Mushroom()) ->build();
    cout<<p2->getTotal()<<endl;

    Pizza *p3 = new Tomato(builder ->setBase(new ThinCrust()) -> setSize(new Medium()) ->build());
    cout<<p3->getTotal()<<endl;

    Pizza *p4 = new Onion(new Tomato( builder ->setBase(new ThinCrust()) -> setSize(new Medium()) ->build() ));
    cout<<p4->getTotal()<<endl;


    //Pizza *p5 = new Onion(new Pizza()); // error - you have to build pizza, cannot get it directly. only after that you can add toppings to it
    // Pizza *p4 = new Pizza(); // error
    // cout<<p4->getTotal()<<endl;
    return 0;
}