#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_

#include <iostream>
#include <string>
#include "I_Account.h"


class Checking_Account: public I_Account {
private:
    static constexpr const char *def_name = "Unnamed Checking Account";
    static constexpr double def_balance = 0.0;
    static constexpr double per_check_fee = 1.5;
public:
    Checking_Account(std::string name = def_name, double balance = def_balance);    
    virtual bool withdraw(double) override;
    virtual bool deposit(double) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Checking_Account() = default;
};

Checking_Account::Checking_Account(std::string name, double balance)
    : I_Account{name, balance} {
}

bool Checking_Account::withdraw(double amount) {
    amount += per_check_fee;
    return I_Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return I_Account::deposit(amount);
}

void Checking_Account::print(std::ostream &os) const {
    os << "Checking Account [Name: " << name << ", Balance: $" << balance << ", Fee: $" << per_check_fee << "]";
}


#endif // _CHECKING_ACCOUNT_H_ 
