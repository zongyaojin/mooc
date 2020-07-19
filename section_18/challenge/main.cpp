#include <iostream>
#include <memory>
#include "I_Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    
    try {
        vector<unique_ptr<I_Account>> accounts;
        accounts.emplace_back(new Savings_Account{"Batman", 2000.0});
        accounts.emplace_back(new Checking_Account{"Superman", 500});
        
        for (const auto &a:accounts) {
            cout << *a << endl;
            a->withdraw(500);
            cout << *a << endl;
        }
    } catch (const InsufficientFundsException &ex) {
        cerr << ex.what() << endl;
    }
    
    cout << "\n---------- End of Test 1 ----------\n" << endl;
    
    try {
        vector<unique_ptr<I_Account>> accounts;
        accounts.emplace_back(new Savings_Account{"Harry", 500.0});
        accounts.emplace_back(new Checking_Account{"Ron", -100});
        
        for (const auto &a:accounts) {
            cout << *a << endl;
            a->withdraw(500);
            cout << *a << endl;
        }
    } catch (const IllegalBalanceException &ex) {
        cerr << ex.what() << endl;
    }
    
    cout << "\n---------- End of Test 2 ----------\n" << endl;
    std::cout << "\nProgram completed successfully!\n" << std::endl;
    
    return 0;
}

