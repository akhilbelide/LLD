#include<iostream>
#include<map>
#include<vector>
using namespace std;

enum SplitType{
    EQUAL,
    UNEQUAL,
    PERCENT
};

enum Category{
    GROCERY,
    SPORTS,
    HEALTH
};

class User;

class Balance{
    private:
    double owe;
    double getback;

    double get_owe(){
        return owe;
    }

    double get_getback(){
        return getback;
    }

    void set_owe(double amt){
        owe = amt;
    }

    void set_getback(double amt){
        getback = amt;
    }
};

class BalanceSheet{
    public:
    map<string, Balance> bal_sheet;
    double total;
    double total_owe;
    double total_getback;
};

class User{
    public:
    string name;
    BalanceSheet *bal_sheet;
};

class UserController{
    public:
    vector<User*> all_users;
    void addUser(){

    }
};

class Split{
    private:
    double amount;

    public:
    User *user;
    
    double get_amount(){
        return this->amount;
    }

    void set_amount(double amt){
        this->amount = amt;
    }
};

class Expense{
    public:
    int exp_id;
    double amount;
    string description;
    User *payer;
    SplitType type;
    vector<Split*> debtors; 

    Expense(int exp_id, double amount, string desc, User *payer, SplitType type, vector<Split*> debtors){
        this->exp_id = exp_id;
        this->amount = amount;
        this->description = desc;
        this->payer = payer;
        this->type = type;
        this->debtors = debtors;
    }
};

class ExpenseSplit{
    public:
    virtual void calculateSplits(double amount, vector<Split*> &debtors)=0;
};

class EqualSplits : public ExpenseSplit{
    public:
    void calculateSplits(double amount, vector<Split*> &debtors){
        double val = (double)amount/debtors.size();
        for(Split* debtor : debtors){
            debtor->set_amount(val);
        }
    }
};

class UnEqualSplits : public ExpenseSplit{
    public:
    void calculateSplits(double amount, vector<Split*> &debtors){
        // so, we need to have info on how amount is splitted 
    }
};

class PercentSplits : public ExpenseSplit{
    public:
    void calculateSplits(double amount, vector<Split*> &debtors){
        // so, we need to have info on what percentages it is split
    }
};

class SplitFactory{
    public:
    ExpenseSplit *split_type;
    
    static ExpenseSplit* getSplitType(SplitType type){
        switch(type){
            case EQUAL:
                return new EqualSplits(); break;
            case UNEQUAL:
                return new UnEqualSplits(); break;
            case PERCENT: 
                return new PercentSplits(); break;
            default: return nullptr; break;
        }
    }
};

class ExpenseController{
    public:
    Expense *expense;

    void addExpense(int exp_id, double amount, string desc, User *payer, SplitType type, vector<Split*> debtors){
        
        ExpenseSplit *expense_split_type = SplitFactory::getSplitType(type);
        if(expense_split_type!=nullptr)
            expense_split_type->calculateSplits(amount, debtors);
    }

    void updateExpense(){

    }
};


int main(){
    ExpenseController *exp_controller = new ExpenseController();
    UserController *user_controller = new UserController();

    return 0;
}