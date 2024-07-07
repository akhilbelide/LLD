#include<iostream>
using namespace std;

class Vehicle{
    public:
    int capacity;
    int mileage;
    Vehicle(int _capacity, int _mileage){
        capacity = _capacity;
        mileage = _mileage;
    }
     int getCapacity(){
        return capacity;
    }
     int getMileage(){
        return mileage;
    }

    virtual void details(){

    }
};

class CarXUV : public Vehicle{
    public:
    CarXUV(int _capacity, int _mileage) : Vehicle(_capacity, _mileage){
    }
    void details(){
        cout<<"This is an XUV with capacity - "<<capacity<<" ,mileage: "<<mileage<<endl;
    }
};

class CarSUV : public Vehicle{
    public:
    CarSUV(int _capacity, int _mileage) : Vehicle(_capacity, _mileage){
    }
    void details(){
        cout<<"This is an SUV with capacity - "<<capacity<<" ,mileage: "<<mileage<<endl;
    }
};

class Bike : public Vehicle{
    public:
    Bike(int _capacity, int _mileage) : Vehicle(_capacity, _mileage){
    }
    void details(){
        cout<<"This is a bike with capacity - "<<capacity<<" ,mileage: "<<mileage<<endl;
    }
};

class NullObj : public Vehicle{
    public:
    NullObj(int _capacity, int _mileage) : Vehicle(_capacity, _mileage){
    }
    void details(){
        cout<<"no obj"<<endl;
    }
};


class VehicleFactory{
    public:
    static Vehicle* getVehicle(string type, int _capacity, int _mileage){
        if(type=="XUV")
            return new CarXUV(_capacity, _mileage);
        else if(type == "SUV")
            return new CarSUV(_capacity, _mileage);
        else if(type == "Bike")
            return new Bike(_capacity, _mileage);
        //else return nullptr;
        else return new NullObj(0, 0); // with default behavior, nullptr is replaced by Null Object
    }
};


int main(){
    // this will return null ptr exception or segmentation fault
    // if we dont check for the nullptr
    // if every time we do this then lots of sodhi
    // Vehicle *v = VehicleFactory::getVehicle("bike", 40, 2); 
    
    // if(v!=nullptr) 
    //     v->details();

    // as it does not return nullptr but returns a null obj with defaulkt behavior, we dont need to check for nullptr
    Vehicle *v = VehicleFactory::getVehicle("bike", 2, 40); 
    v->details();

    Vehicle *v2 = VehicleFactory::getVehicle("XUV", 7, 14); 
    v2->details();
    return 0;
}