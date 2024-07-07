#include<iostream>
using namespace std;

// Receiver
class AirConditioner{
    private:
    bool state;
    int temp;

    public:
    AirConditioner(int def_temp){
        temp = def_temp;
    }

    int get_temp(){
        return temp;
    }

    bool get_state(){
        return state;
    }

    void set_temp(int _temp){
        temp = _temp;
    }

    void turn_on(){
        state=true;
    }

    void turn_off(){
        state = false;
    }
};

// Commands
class Command{
    public: 
    virtual void execute()=0;
};

class ACTurnOnCommand : public Command{
    public:
    AirConditioner *ac;
    ACTurnOnCommand(AirConditioner *_ac){
        ac = _ac;
    }
    void execute(){
        ac->turn_on();
    }
};


class ACTurnOffCommand : public Command{
    public:
    AirConditioner *ac;
    ACTurnOffCommand(AirConditioner *_ac){
        ac = _ac;
    }
    void execute(){
        ac->turn_off();
    }
};

class ACTempIncrCommand : public Command{
    public:
    AirConditioner *ac;
    ACTempIncrCommand(AirConditioner *_ac){
        ac = _ac;
    }
    void execute(){
        ac->set_temp(ac->get_temp()+1);
    }
};

class ACTempDecrCommand : public Command{
    public:
    AirConditioner *ac;
    ACTempDecrCommand(AirConditioner *_ac){
        ac = _ac;
    }
    void execute(){
        ac->set_temp(ac->get_temp()-1);
    }
};

// Remote
class Remote{
    public:
    Command *cmd;
    Remote(Command *_cmd){
        cmd = _cmd;
    }

    void pressButton(){
        cmd->execute();
    }
};

void display(int num){
    cout<<num<<endl;
}

int main(){
    // client ahs to know about all the details - NO ABSTRACTION here
    // suppose what if turning on AC prpcess has many steps/operations - client has to do that one by one
    // AirConditioner *ac = new AirConditioner();
    // ac->turn_on();
    // cout<<ac->getState()<<endl;
    // ac->set_temp(25);
    // cout<<ac->get_temp()<<endl;

    AirConditioner *ac = new AirConditioner(25);

    Remote *on_button = new Remote(new ACTurnOnCommand(ac));
    Remote *off_button = new Remote(new ACTurnOffCommand(ac));
    Remote *incr_temp = new Remote(new ACTempIncrCommand(ac));
    Remote *decr_temp = new Remote(new ACTempDecrCommand(ac));

    on_button->pressButton();
    display(ac->get_state());

    off_button->pressButton();
    display(ac->get_state());

    display(ac->get_temp());
    incr_temp->pressButton();
    incr_temp->pressButton();
    display(ac->get_temp());

    decr_temp->pressButton();
    display(ac->get_temp());
    return 0;
}

