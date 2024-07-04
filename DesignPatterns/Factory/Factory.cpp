#include<iostream>
using namespace std;

class Shape{
    public:

    virtual int area(int side)=0;
};

class Square : public Shape{
    public:
    Square() : Shape(){

    }

    int area(int side){
        return side * side;
    }
};

class HalfSquare : public Shape{
    public:
    HalfSquare() : Shape(){

    }

    int area(int side){
        return (side*side)/2;
    }
};

class ShapeFactory{
    public:
    Shape* getShape(string str){
        if(str=="Sqaure")
            return new Square();
        else if(str=="HalfSquare")
            return new HalfSquare();
        else return nullptr;
    }
};

int main(){
    ShapeFactory *factory = new ShapeFactory();
    Shape *s1 = factory->getShape("Sqaure");
    Shape *s2 = factory->getShape("HalfSquare");

    cout<<s1->area(4)<<endl;
    cout<<s2->area(4)<<endl;
    return 0;
}