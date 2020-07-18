#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_

#include "Savings_Account.h"


class Trust_Account : public Savings_Account {
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double bonus_threshold = 5000.0;
    static constexpr int max_withdrawals = 3;
    static constexpr double max_withdraw_percent = 0.2;
protected:
    int num_withdrawals;
public:
    Trust_Account(std::string name = def_name,  double balance = def_balance, double int_rate = def_int_rate);
    
    // Only allowed maximum of 3 withdrawals, each can be up to a maximum of 20% of the account's value
    virtual bool withdraw(double) override;
    // Deposits of $5000.00 or more will receive $50 bonus
    virtual bool deposit(double) override;
    virtual void print(std::ostream &os) const override;
};

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account{name, balance, int_rate}, num_withdrawals{0}  {
        
}

// Deposit additional $50 bonus when amount >= $5000, with the interest rate inherited from Savings_Account
bool Trust_Account::deposit(double amount) {
    if (amount >= bonus_threshold)
        amount += bonus_amount;
    return Savings_Account::deposit(amount);
}

// Only allowed 3 withdrawals, each can be up to a maximum of 20% of the account's value
bool Trust_Account::withdraw(double amount) {
    if (num_withdrawals >= max_withdrawals || (amount > balance * max_withdraw_percent))
        return false;
    else {
        ++num_withdrawals;
        return Savings_Account::withdraw(amount);
    }
}

void Trust_Account::print(std::ostream &os) const {
    os << "Trusted Account [Name: " << name << ", Balance: $" << balance  << ", Interest: " << int_rate << "%, withdrawls: " << num_withdrawals << "]";
}


#endif // _TRUST_ACCOUNT_H_
