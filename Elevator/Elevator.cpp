#include<iostream>
#include<vector>
#include<queue>
using namespace std;

enum Direction{
    UP,
    DOWN,
    IDLE
};

enum Status{
    IDLE,
    MOVING
};

class Display{
    int floor_number;
    Direction dir;

};

class Door{
    public:
    Door(){}
    void openDoor(){

    }
    void closeDoor(){

    }
};

class Building{
    public:
    vector<Floor*> floors;

    void addFloor(Floor *f){
        this->floors.push_back(f);
    }

    vector<Floor*> getFloors(){
        return this->floors;
    }

};

class Floor{
    public:
    int floor_number;
    ExternalButton *button;
    Display *display;
};

class ExternalButton{
    public:
    ExternalButtonDispatcher *dispatcher;

    void pressButton(int curr_floor, Direction dir){
        dispatcher->submitRequest(curr_floor, dir);
    }
};


class ExternalButtonDispatcher{
    public:
    vector<ElevatorController*> all_controllers;
    AssignStrategy *startegy;

    ExternalButtonDispatcher(AssignStrategy *_strategy){
        this->startegy = _strategy;
    }

    void submitRequest(int floor, Direction dir){
        startegy->process(all_controllers, floor, dir);
    }
};

class AssignStrategy{
    public:
    virtual void process(vector<ElevatorController*> all_controllers, int floor, Direction dir)=0;
};

class OddEvenStartegy : public AssignStrategy{
    public:
    void process(vector<ElevatorController*> all_controllers, int floor, Direction dir){
        for(ElevatorController *controller : all_controllers){
            int elevatorID = controller->elevator_obj->id;
            if(elevatorID%2==1 && floor%2==1)
                controller->SubmitNewRequest(floor, dir);
            else if(elevatorID%2==0 && floor%2==0)
                controller->SubmitNewRequest(floor, dir);
        }
    }
};

//any new strategies can be implemented by extending the base class
//this is an example of Strategy Design Pattern
class FixedFloorStartegy : public AssignStrategy{
    public:
    void process(vector<ElevatorController*> all_controllers, int floor, Direction dir){
        //some other strategy
    }
};

class InternalButton{
    public:
    int floor_number;
    InternalButtonDispatcher *dispatcher;

    InternalButton(){

    }

    InternalButton(int num){
        floor_number = num;
    }

    void pressButton(int elevatorID, int dest_floor_number){
        dispatcher->SubmitRequest(elevatorID, dest_floor_number);
    }
};


class InternalButtonDispatcher{
    public:
    vector<ElevatorController*> all_controllers;

    void SubmitRequest(int elevatorID, int dest_floor_number){
        for(ElevatorController *controller : all_controllers){
            if(controller->elevator_obj->id == elevatorID){
                controller->SubmitNewRequest(dest_floor_number, dest_floor_number>controller->elevator_obj->curr_floor? UP: DOWN);
            }
        }
    }
};

class ElevatorController{
    public:
    ElevatorCar *elevator_obj;
    priority_queue<int, vector<int>, greater<int> > UpMinPQ;
    priority_queue<int> DownMaxPQ;
    queue<int> pending;

    void SubmitNewRequest(int floor_number, Direction dir){
        if(dir==UP)
            UpMinPQ.push(floor_number); // simplified logic
        else DownMaxPQ.push(floor_number);
    }

    void Action(){

    }
};


class ElevatorCar{
    public:
    int id;
    int curr_floor;
    Door *door;
    Status status;
    Direction dir;
    vector<InternalButton*> *internal_buttons;

    ElevatorCar(int _id, Door *_door, Status _status, Direction _dir, vector<InternalButton*> *_internal_buttons){
        id=_id;
        curr_floor=0;
        door=_door;
        status=_status;
        dir=_dir;
        internal_buttons=_internal_buttons;
    }

    void move(int floor, Direction dir){

    }
};

int main(){
    Building *building = new Building();

    return 0;
}