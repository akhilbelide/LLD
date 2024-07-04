#include<iostream>
using namespace std;

class WeightInPounds{
    public:
    virtual double getWeight()=0;
};

class WeightInPoundsBaby : public WeightInPounds{
    public:
    double getWeight(){
        return 20.0;
    }
};

class WeightInKgs{
    public:
    virtual double getWeight()=0;
};

class Adapter : public WeightInKgs{
    public:
    WeightInPounds *wtInLbs;

    Adapter(WeightInPounds *_wt){
        wtInLbs = _wt;
    }

    double getWeight(){
        return wtInLbs->getWeight() * 0.45;
    }

};

int main(){
    // client only knows about weightInKgs
    WeightInKgs *kgs = new Adapter(new WeightInPoundsBaby());
    cout<<kgs->getWeight();

    return 0;
}