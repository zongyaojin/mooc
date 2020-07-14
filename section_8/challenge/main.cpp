#include <iostream>
#include <array>
using namespace std;

int main() 
{
    cout << "Enter an amount in cents: ";
    int amount {0};
    cin >> amount;
    
    cout << "\nYou can provide change for this change as follows:" << endl;
    
    const array<int, 5> worth{100, 25, 10, 5, 1};
    const array<string, 5> names{"Dollars: ", "Quarters: ", "Dimes: ", "Nickels: ", "Pennies: "};
    
    for (int i=0; i<5; i++) {
        if (amount >= worth.at(i)) {
            cout << names.at(i) << amount/worth.at(i) << endl;
            amount %= worth.at(i);
        }
    }
    
    cout << endl;
        
	return 0;
}

/* Preliminary code */

//int main() 
//{
//    cout << "Enter an amount in cents: ";
//    int amount {0};
//    cin >> amount;
//    
//    cout << "\nYou can provide change for this change as follows:" << endl;
//    
//    int dollars{0}, quarters{0}, dimes{0}, nickels{0}, pennies{0};
//    
//    if (amount >= 100) {
//        dollars = amount/100;
//        amount %= 100;
//    }
//    
//    if (amount >= 25) {
//        quarters = amount/25;
//        amount %= 25;
//    }
//    
//    if (amount >= 10) {
//        dimes = amount/10;
//        amount %= 10;
//    }
//    
//    if (amount >= 5) {
//        nickels = amount/5;
//        amount %= 5;
//    }
//    
//    pennies = amount;
//    
//    cout << "Dollars: " << dollars << endl;
//    cout << "Quarters: " << quarters << endl;
//    cout << "Dimes: " << dimes << endl;
//    cout << "Nickels: " << nickels << endl;
//    cout << "Pennies: " << pennies << endl << endl;
//        
//	return 0;
//}