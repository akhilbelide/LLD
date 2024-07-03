#include<iostream>
using namespace std;

class Singleton{
    private:
    static Singleton *obj;
    Singleton(){
        cout<<"Inside constructor"<<endl;
    }

    public:
    static Singleton* getObj(){
        if(obj == nullptr){
            cout<<"Created!"<<endl;
            obj = new Singleton();
            return obj;
        }
        else return obj;
    }
};

class Normal{
    public:
    Normal(){
        cout<<"Inside Constructor of Normal"<<endl;
    }
};


Singleton *Singleton::obj = nullptr;

int main(){
    //Singleton *obj = new Singelton();
    Singleton *obj1 = Singleton::getObj();
    Singleton *obj2 = Singleton::getObj();
    if(obj1==obj2)
        cout<<"Equal!"<<endl;
    else cout<<"Objects are not equal!"<<endl;

    Normal *ob1 = new Normal();
    Normal *ob2 = new Normal();
    if(ob1==ob2)
        cout<<"Equal!"<<endl;
    else cout<<"Objects are not equal!"<<endl;
    return 0;
}