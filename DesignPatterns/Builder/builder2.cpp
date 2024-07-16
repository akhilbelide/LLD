#include<iostream>
using namespace std;

class Phone{
    public:
    int mandatory;
    int RAM;
    int storage;
    string brand;
    bool hasCamera;


    Phone(){

    }
    
    Phone(Phone *p){
        this->mandatory=p->mandatory;
        this->RAM = p->RAM;
        this->storage = p->storage;
        this->brand = p->brand;
        this->hasCamera = p->hasCamera;
    }


    void print(){
        cout<<"Phone has "<<mandatory<<" manditory value, "<<RAM<<" GB RAM, "<<storage<<" GB Storage Space, "<<brand<<" - Brand, "<<hasCamera<<" camera, "<<endl;
    }

};


class PhoneBuilder{
    public:
    Phone *p;

    PhoneBuilder(int _mandatory){
        p = new Phone();
        this->p->mandatory = _mandatory;
    }

    PhoneBuilder* setRAM(int _RAM){
        this->p->RAM=_RAM;
        return this;
    }

    PhoneBuilder* setStorage(int _store){
        this->p->storage = _store;
        return this;
    }

    PhoneBuilder* setBrand(string _brand){
        this->p->brand=_brand;
        return this;
    }

    PhoneBuilder* setCamera(bool _cam){
        this->p->hasCamera = _cam;
        return this;
    }

    Phone* build(){
        return this->p;
    }

};


int main(){
    PhoneBuilder *pb = new PhoneBuilder(1);
    Phone *p1 = pb->setRAM(3)->setBrand("Apple")->build();

    PhoneBuilder *pb2 = new PhoneBuilder(2);
    Phone *p2 = pb2->setRAM(3)->setBrand("Apple")->setCamera(true)->setStorage(256)->build();
    p1->print();
    p2->print();
    return 0;
}