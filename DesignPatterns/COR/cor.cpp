#include<iostream>
using namespace std;

class Logger{
    public:
    static const int info = 1;
    static const int debug = 2;
    static const int error = 3;

    Logger *next;

    Logger(Logger *_next){
        next = _next;
    }

    virtual void log(int logLevel, string message){
        next->log(logLevel, message);
    }
};

class InfoLogger : public Logger{
    public: 

    InfoLogger(Logger *n) : Logger(n){

    }

    void log(int logLevel, string message){
        if(logLevel == Logger::info){
            cout<<"In Info Logger - "<<message<<endl;
        }
        else{
            Logger::log(logLevel, message);
        }
    }
};

class ErrorLogger : public Logger{
    public: 

    ErrorLogger(Logger *n) : Logger(n){

    }

    void log(int logLevel, string message){
        if(logLevel == Logger::error){
            cout<<"In Error Logger - "<<message<<endl;
        }
        else{
            Logger::log(logLevel, message);
        }
    }
};

class DebugLogger : public Logger{
    public: 

    DebugLogger(Logger *n) : Logger(n){

    }

    void log(int logLevel, string message){
        if(logLevel == Logger::debug){
            cout<<"In Debug Logger - "<<message<<endl;
        }
        else{
            next->log(logLevel, message);
        }
    }
};

class NullObjLogger : public Logger{
    public: 

    NullObjLogger(Logger *n) : Logger(n){

    }

    void log(int logLevel, string message){
        cout<<"Unsupported!"<<endl;
    }
};

int main(){
    Logger *l1 = new InfoLogger(new DebugLogger( new ErrorLogger(new NullObjLogger(nullptr))));
    l1->log(1, "msg");
    l1->log(2, "msg");
    l1->log(3, "msg");
    l1->log(4, "msg");
    return 0;
}