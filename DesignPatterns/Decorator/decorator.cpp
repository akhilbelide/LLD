#include<iostream>
using namespace std;

class BasePizza{
    public:
    virtual int cost()=0;
};

class VegDelight :public BasePizza{
    public:
    int cost(){
        return 100;
    }
};

class Margherita :public BasePizza{
    public:
    int cost(){
        return 120;
    }
};

class Toppings : public BasePizza{

};

class ExtraCheese : public Toppings{
    private:
    BasePizza *pizza;

    public:
    ExtraCheese(BasePizza *_pizza){
        pizza = _pizza;
    }

    int cost(){
        return this->pizza->cost() + 15;
    }
};

class Mushroom : public Toppings{
    private:
    BasePizza *pizza;

    public:
    Mushroom(BasePizza *_pizza){
        pizza = _pizza;
    }

    int cost(){
        return this->pizza->cost() + 20;
    }
};

class Jalapenos : public Toppings{
    private:
    BasePizza *pizza;

    public:
    Jalapenos(BasePizza *_pizza){
        pizza = _pizza;
    }

    int cost(){
        return this->pizza->cost() + 10;
    }
};



int main(){
    BasePizza *p1 = new Margherita();
    cout<<p1->cost()<<endl;

    BasePizza *p2 = new Jalapenos(new ExtraCheese(new VegDelight()));
    cout<<p2->cost()<<endl;
    return 0;
}