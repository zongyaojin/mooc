#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_

#include <vector>
#include "I_Account.h"

void display(const std::vector<I_Account*> accounts);
void deposit(std::vector<I_Account*> &accounts, double amount);
void withdraw(std::vector<I_Account*> &accounts, double amount);

void display(const std::vector<I_Account*> accounts) {
    std::cout << "\n=== Accounts ===========================================" << std::endl;
    for (const auto acc:accounts) 
        std::cout << *acc << std::endl;
}

void deposit(std::vector<I_Account*> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc:accounts)  {
        if (acc->deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;
    }
}

void withdraw(std::vector<I_Account*> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto &acc:accounts)  {
        if (acc->withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc << std::endl;
    } 
}


#endif