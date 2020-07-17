#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, num_withdrawn{0} {
}

bool Trust_Account::withdraw(double amount) {
    if (num_withdrawn>=3 || amount>0.2*balance) {
        return false;
    } else
        ++num_withdrawn;
        return Savings_Account::deposit(amount);
}

bool Trust_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    if (amount >= 5000)
        amount += 50;
    return Savings_Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%" << ", withdrawn: " << account.num_withdrawn << "]";
    return os;
}