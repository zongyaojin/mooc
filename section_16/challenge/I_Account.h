#ifndef _I_ACCOUNT_H_
#define _I_ACCOUNT_H_
#include <iostream>
#include <string>
#include "I_Printable.h"

class I_Account: public I_Printable {
protected:
    std::string name;
    double balance;
public:
    I_Account(std::string name, double balance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(std::ostream &os) const = 0;
};

I_Account::I_Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool I_Account::deposit(double amount) {
    if (amount <= 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool I_Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

#endif