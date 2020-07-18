#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_

#include "I_Account.h"


class Savings_Account: public I_Account {
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
protected:
    double int_rate;
public:
    Savings_Account(std::string name = def_name, double balance =def_balance, double int_rate = def_int_rate);    
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    virtual void print(std::ostream &os) const override;
};

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : I_Account{name, balance}, int_rate{int_rate} {
}

bool Savings_Account::withdraw(double amount) {
    return I_Account::withdraw(amount);
}

// Amount will be added with interest rate
bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    return I_Account::deposit(amount);
}

void Savings_Account::print(std::ostream &os) const {
    os << "Savings Account [Name: " << name << ", Balance: $" << balance  << ", Interest: " << int_rate << "%]";
}


#endif // _SAVINGS_ACCOUNT_H_