#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

enum Channel{
    SMS, 
    Email
};

class Message{
    public:
    int id;
    string message;
    Message(){

    }
    Message(int _id, string _msg){
        id=_id;
        message = _msg;
    }
};

class SMSMessage : public Message{
    public:
    int phone_number;

    SMSMessage(){

    }

    SMSMessage(int _id, string _msg, int num):Message(_id, _msg){
        phone_number = num;
    }
};

class EmailMessage : public Message{
    public:
    string mailID;

    EmailMessage(){

    }

    EmailMessage(int _id, string _msg, string _mail):Message(_id, _msg){
        mailID = _mail;
    }
};

class NotifHandler{
    public:
    virtual void send(Message *msg)=0;
};

class SMSNotifHandler : public NotifHandler{
    void send(Message *msg){
        // some 3rd party logic to send
    }
};

class EmailNotifHandler : public NotifHandler{
    void send(Message *msg){
         // some 3rd party logic to send
    }
};

class NotifHandlerFactory{
    private:
    NotifHandlerFactory(){

    }
    static NotifHandlerFactory *factory;

    public:
    static NotifHandlerFactory* getInstance(){
        if(factory==nullptr){
            factory = new NotifHandlerFactory();
        }
        return factory;
    }
    
    NotifHandler* getHandler(Channel channel){
        if(channel == SMS){
            new SMSNotifHandler();
        }
        else if(channel == Email){
            new EmailNotifHandler();
        }
    }

};

class MessageService{
    public:
    NotifHandlerFactory *factory;
    NotifHandler *handler;

    MessageService(NotifHandlerFactory *_factory){
        factory = _factory;
    }

    vector<map<string, string> > parseJson(string msg){
        // some logic to convert that string into JSON 
        vector<map<string, string> > all_msgs;
        return all_msgs;
    }

    void sendNotif(string msgToSend){
        vector<map<string, string> > all_msgs;
        all_msgs = parseJson(msgToSend);
        Message *m;
        for(map<string, string> message : all_msgs){
            if(message["channel"]=="SMS"){
                handler = factory->getHandler(SMS);
                m = new SMSMessage(stoi(message["id"]), message["msg"], stoi(message["phone_number"]));
                handler->send(m);
            }
            else if(message["channel"]=="Email"){
                handler = factory->getHandler(Email);
                m = new EmailMessage(stoi(message["id"]), message["msg"], message["email"]); 
                handler->send(m);
            }
        }
    }
};

int main(){
   
    string msg = "[{\"id\": \"1\", \"channel\": \"email\", \"message\": \"hello how is it going?\", \"email\": \"test@test.com\"},{\"id\": \"2\", \"channel\": \"sms\", \"message\": \"whats gwan bruh?\", \"mobileNumber\": \"9793448789\"}]";
    
    NotifHandlerFactory *factory = NotifHandlerFactory::getInstance();
    
    MessageService *service = new MessageService(factory);
    service-> sendNotif(msg);
};
