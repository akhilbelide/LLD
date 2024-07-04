#include<iostream>
using namespace std;

class Base{
    public:
    Base(){

    }

    // virtual void func(){
    //     cout<<"In base class"<<endl;
    // }

    virtual void print()=0;
};

class Derived1 : public Base{
    public:

    Derived1(){

    }

    void func(){
        cout<<"In derived class"<<endl;
    }

    void print(){
        cout<<"from one"<<endl;
    }


};

class Derived2 : public Base{
    public:

    Derived2(){

    }

    void func(){
        cout<<"In derived class"<<endl;
    }

    void print(){
        cout<<"from two"<<endl;
    }
};

class Strategy{
    public:

    Base *b;

    Strategy(Base *_b){
        b=_b;
    }

    void display(){
        b->print();
    }
};

int main(){
    // Base *b = new Base();
    // Base b1;
    // b1.func();
    // Derived *d = new Derived();
    // Base *bd = new Derived();
    // b->func();
    // d->func();
    // bd->func();

    Strategy *s = new Strategy(new Derived2());
    s->display();
    return 0;
}