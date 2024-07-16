#include<iostream>
#include<time.h>
#include <cstdlib>
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

enum SplitType{
    EQUAL,
    UNEQUAL,
    PERCENT
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

    // Derived1 *d = nullptr;
    // if(d==nullptr)
    //     cout<<"Value is null"<<endl;
    // else cout<<"some value"<<endl;

    // cout<<d<<endl;

    // Strategy *s = new Strategy(new Derived2());
    // s->display();

    // int max=6;
    // int min=1;
    // srand(time(0));

    // for(int i=0;i<10;i++){
        
    //     int num = min + (rand()%(max-min+1));
    //     cout<<num<<endl;
    // }

    SplitType t = UNEQUAL;
    cout<<t<<endl;

    for(int i=0;i<26;i++){
        cout<<i<<" - ";
        cout<<ceil((float)i/9.0)<<endl;
    }
    
    return 0;
}