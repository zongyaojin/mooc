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
    virtual ~I_Account() = default;
    // Always make the destructor virtual when a class is meant to be used polymorphically
    // Otherwise there could be resource leaks when you delete a derived class through a base class pointer
    // Coz the destructor could be statically-bound to the non-virtual base class destructor
    // Which is gonna slice the derived the class and possibly leak stuff
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

#endif // _I_ACCOUNT_H_