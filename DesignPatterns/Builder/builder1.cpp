#include<iostream>
using namespace std;

class Phone{
    public:
    int mandatory;

    int RAM;
    int storage;
    string brand;
    bool hasCamera;

    string prop;

    Phone(int _manditory, int _RAM, int _store, string _brand, bool _cam, string _prop){
        mandatory=_manditory;
        RAM = _RAM;
        storage = _store;
        brand = _brand;
        hasCamera = _cam;
        prop = _prop;
    }


    void print(){
        cout<<"Phone has "<<mandatory<<" manditory value, "<<RAM<<" GB RAM, "<<storage<<" GB Storage Space, "<<brand<<" - Brand, "<<hasCamera<<" camera, "<<prop<<" - prop"<<endl;
    }

};


class PhoneBuilder{
    public:
    int mandatory;

    int RAM;
    int storage;
    string brand;
    bool hasCamera;

    string prop;

    PhoneBuilder(int _mandatory){
        mandatory = _mandatory;
    }

    PhoneBuilder* setRAM(int _RAM){
        RAM=_RAM;
        return this;
    }

    PhoneBuilder* setStorage(int _store){
        storage = _store;
        return this;
    }

    PhoneBuilder* setBrand(string _brand){
        brand=_brand;
        return this;
    }

    PhoneBuilder* setCamera(bool _cam){
        hasCamera = _cam;
        return this;
    }

    virtual PhoneBuilder* setProp(){
        return this;
    }

    Phone* build(){
        return new Phone(mandatory, RAM, storage, brand, hasCamera, prop);
    }

};

class NewPropPhoneBuilder : public PhoneBuilder{
    public:
    NewPropPhoneBuilder(int mandatory): PhoneBuilder(mandatory){
    }

    PhoneBuilder* setProp(){
        prop = "new";
        return this;
    }
};

class OldPropPhoneBuilder : public PhoneBuilder{
    public:
    OldPropPhoneBuilder(int mandatory): PhoneBuilder(mandatory){
    }
    PhoneBuilder* setProp(){
        prop = "old";
        return this;
    }
};



int main(){
    PhoneBuilder *pb = new NewPropPhoneBuilder(1);
    Phone *p1 = pb->setRAM(3)->setProp()->setBrand("Apple")->build();

    PhoneBuilder *pb2 = new OldPropPhoneBuilder(2);
    Phone *p2 = pb2->setRAM(3)->setBrand("Apple")->setCamera(true)->setStorage(256)->setProp()->build();
    p1->print();
    p2->print();
    return 0;
}