#include<iostream>
#include<vector>
using namespace std;

class Observer;

class Observable{
    public:
    virtual void add(Observer *obs)=0;
    virtual void remove(Observer *obs)=0;
    virtual void setData(int data)=0;
    virtual int getData()=0;
    virtual void notify()=0;
};


class Observer{
    public:
    virtual void update()=0;
};  

class IphoneObservable : public Observable{
    public:
    int count;
    vector<Observer*> subscribers;

    IphoneObservable(int initial_count){
        count = initial_count;
    }

    void add(Observer *obs){
        subscribers.push_back(obs);
    }
    
    void remove(Observer *obs){
        auto it = find(subscribers.begin(), subscribers.end(),obs);
 
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notify(){
        for(Observer *o : subscribers){
            o->update();
        }
    }

    void setData(int data){
        if(count==0){
            notify();
        }
        count += data;
    }
       
    
    int getData(){
        if(count>0)
            count--;
        return count;
    }
};

class AndroidphoneObservable : public Observable{
    public:
    int count;
    vector<Observer*> subscribers;

    AndroidphoneObservable(int initial_count){
        count = initial_count;
    }

    void add(Observer *obs){
        subscribers.push_back(obs);
    }
    
    void remove(Observer *obs){
        auto it = find(subscribers.begin(), subscribers.end(),obs);
 
        if (it != subscribers.end()) {
            subscribers.erase(it);
        }
    }

    void notify(){
        for(Observer *o : subscribers){
            o->update();
        }
    }

    void setData(int data){
        if(count==0){
            notify();
        }
        count += data;
    }
       
    
    int getData(){
        if(count>0)
            count--;
        return count;
    }
};

class EmailObserver : public Observer{
    public:
    string email;
    Observable *observable;
    EmailObserver(string _email, Observable *_observable){
        email = _email;
        this->observable = _observable;
    }

    void update(){
        cout<<"Mail sent to - "<<email<<endl;
    }
};

class SMSObserver : public Observer{
    public:
    string number;
    Observable *observable;
    SMSObserver(string _number, Observable *_observable){
        number = _number;
        this->observable = _observable;
    }

    void update(){
        cout<<"SMS sent to - "<<number<<endl;
    }
};


int main(){
    Observable *iphone = new IphoneObservable(0);
    Observable *android = new AndroidphoneObservable(2);
    Observer *obs1 = new EmailObserver("abc@gmail.com", iphone);
    Observer *obs2 = new EmailObserver("def@gmail.com", iphone);
    Observer *obs3 = new SMSObserver("3527099099", iphone);

   
    iphone->add(obs1);
    iphone->add(obs2);
    iphone->add(obs3);

    iphone->setData(10);

    android->getData();
    android->getData();
    android->getData();
    Observer *obs4 = new EmailObserver("abc@gmail.com", android);
    Observer *obs5 = new EmailObserver("def@gmail.com", android);
    android->add(obs4);
    android->add(obs5);

    android->setData(2);
    return 0;
}