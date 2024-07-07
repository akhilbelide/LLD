// It allows you to define the skeleton of an algorithm in a base class, 
// while allowing subclasses to customize specific steps of the algorithm without changing the overall structure.
#include<iostream>
using namespace std;

class Template{
    public:
    virtual void step1()=0;
    virtual void step2()=0;
    virtual void step3()=0;

    virtual void process() final {
        step1();
        step2();
        step3();
    }
};

class TemplateNew : public Template{
    public:

    void step1(){
        cout<<" Write email "<<endl;
    }
    void step2(){
        cout<<" Write Subject "<<endl;
    }
    void step3(){
        cout<<" Send mail "<<endl;
    }
};

class TemplateOld : public Template{
    public:

    void step1(){
        cout<<" Write Subject "<<endl;
    }
    void step2(){
        cout<<" Write Email "<<endl;
    }
    void step3(){
        cout<<" Send mail "<<endl;
    }

    // void process(){
    //     cout<<"lol"<<endl;
    // }
};

int main(){
    Template *latest = new TemplateNew();
    latest->process();

    Template *old = new TemplateOld();
    //TemplateOld *old = new TemplateOld();
    old->process();
    return 0;
}