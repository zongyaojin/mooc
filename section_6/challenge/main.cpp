#include <iostream>

using namespace std;

int main() 
{
    cout << "Hello, welcome to Carpet Cleaning Service!\n" << endl;
    
    cout << "How many small rooms would you like cleaned? ";
    int num_small {0}, num_large {0};
    cin >> num_small;
    
    cout << "How many large rooms would you like cleaned? ";
    cin >> num_large;
    
    cout << "\nEstimate for carpet cleaning service." << endl;
    cout << "Number of small rooms: " << num_small << endl;
    cout << "Number of large rooms: " << num_large << endl;
    
    const int cost_small {25}, cost_large {35};
    const double tax {0.06};
    
    cout << "Price per small room: $" << cost_small << endl;
    cout << "Price per large room: $" << cost_large << endl;
    
    double pre_tax {num_small*cost_small + num_large*cost_large};
    cout << "Cost: $" << pre_tax << endl;
    cout << "Tax: $"  << pre_tax*tax << endl;
    cout << "==========" << endl;
    cout << "Total estimate: $" << pre_tax*(1+tax) << endl;
    cout << "The estimate is valid for 30 days.\n" << endl;
	return 0;
}
