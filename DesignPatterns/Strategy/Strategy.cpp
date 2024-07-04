#include<iostream>
using namespace std;

class Payment{
    public:
    virtual void pay(int amount)=0;
};

class CreditCardPayment : public Payment{
    public:
    void pay(int amount) {
        cout<<"Paid "<<amount<<" using Credit Card"<<endl;
    }
};

class PaypalPayment : public Payment{
    public:
    void pay(int amount) override {
        cout<<"Paid "<<amount<<" using Paypal"<<endl;
    }
};

class CryptoPayment : public Payment{
    public:
    void pay(int amount) override {
        cout<<"Paid "<<amount<<" using Crypto"<<endl;
    }
};

class Cart{
    public:
    Payment *strategy;

    void setPayment(Payment *_startegy){
        this->strategy = _startegy;
    }

    void payment(int amt){
        strategy->pay(amt);
    }
};

int main(){
    Cart *c = new Cart();
    c->setPayment(new CreditCardPayment());
    c->payment(200);

    c->setPayment(new PaypalPayment());
    c->payment(120);

    c->setPayment(new CryptoPayment());
    c->payment(5000);

    return 0;
}