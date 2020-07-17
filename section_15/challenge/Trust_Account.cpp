#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, num_withdrawn{0} {
}

bool Trust_Account::withdraw(double amount) {
    if (balance-amount>=0 && num_withdrawn<3) {
        balance = balance-amount;
        ++num_withdrawn;
        return true;
    } else
        return false;
}

bool Trust_Account::deposit(double amount) {
    amount += amount * (int_rate/100);
    if (amount >= 5000)
        amount += 50;
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%" << ", withdrawn: " << account.num_withdrawn << "]";
    return os;
}