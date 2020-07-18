#include <iostream>
#include <vector>
#include "I_Account.h"
#include "Account_Util.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std; 

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Savings 
    cout << "\n--------------- Savings tests ---------------" << endl;
    vector<I_Account*> sav_accounts;
    sav_accounts.push_back(new Savings_Account{});
    sav_accounts.push_back(new Savings_Account{"Superman"});
    sav_accounts.push_back(new Savings_Account{"Batman", 2000});
    sav_accounts.push_back(new Savings_Account{"Wonderwoman", 5000, 5.0});

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts,2000);
    // Delete all these memories allocated on the heap by the pointers to prevent memory leak
    for (auto p:sav_accounts)
        delete p;
    cout << endl;
   
    // Checking
    cout << "\n--------------- Checking tests ---------------" << endl;
    vector<I_Account*> check_accounts;
    check_accounts.push_back(new Checking_Account{});
    check_accounts.push_back(new Checking_Account{"Kirk"});
    check_accounts.push_back(new Checking_Account{"Spock", 2000});
    check_accounts.push_back(new Checking_Account{"Bones", 5000});

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);
    // Delete all these memories allocated on the heap by the pointers to prevent memory leak
    for (auto p:check_accounts)
        delete p;
    cout << endl;
    

    // Trust
    cout << "\n--------------- Trust tests ---------------" << endl;
    vector<I_Account*> trust_accounts;
    trust_accounts.push_back(new Trust_Account{});
    trust_accounts.push_back(new Trust_Account{"Athos", 10000, 5.0});
    trust_accounts.push_back(new Trust_Account{"Porthos", 20000, 4.0});
    trust_accounts.push_back(new Trust_Account{"Aramis", 30000});

    display(trust_accounts);
    deposit(trust_accounts, 1000);
    deposit(trust_accounts, 10000);
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    withdraw(trust_accounts, 3000);
    
    cout << "\n--------------- 5 withdrawls tests ---------------" << endl;
    
    // Withdraw 5 times from each trust account
    // All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
    for (int i=1; i<=5; i++)
        withdraw(trust_accounts, 1000);

    // Delete all these memories allocated on the heap by the pointers to prevent memory leak
    for (auto p:trust_accounts)
        delete p;
    cout << endl;
    
    cout << endl;
    
    return 0;
}

