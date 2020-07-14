#include <iostream>
#include <vector>
#include <ctype.h>
#include <numeric>
#include <algorithm>
using namespace std;

int main() 
{
    char c {'\0'};
    vector<int> v;
    
    while (c!='q') 
    {
        cout << "\nP - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
    
        cout << "\nEnter your choise: ";
        cin >> c;
        
        switch (tolower(c)) {
            case 'p' :
                if (v.size()==0) {
                    cout << "[] - the list is empty" << endl;
                } else {
                    cout << "[ ";
                    for (auto i:v) {
                        cout << i << " ";
                    }
                    cout << "]" << endl;
                }
                break;
            case 'a':
                {
                    cout << "\nEnter an integer to add to the list: ";
                    int temp {0};
                    cin >> temp;
                    v.push_back(temp);
                    cout << temp << " added." << endl;
                    break;
                }
            case 'm':
                if (v.size()==0) {
                    cout << "[] - the list is empty, does not compute." << endl;
                } else {
                    cout << "The mean is: " << accumulate(v.begin(), v.end(), 0.0) / v.size() << endl;
                }
                break;
            case 's':
                if (v.size()==0) {
                    cout << "[] - the list is empty, does not compute." << endl;
                } else {
                    cout << "The smallest number is: " << *min_element(v.begin(), v.end()) << endl;
                }
                break;
            case 'l':
                if (v.size()==0) {
                    cout << "[] - the list is empty, does not compute." << endl;
                } else {
                    cout << "The largest number is: " << *max_element(v.begin(), v.end()) << endl;
                }
                break;
            case 'q':
                cout << "\nGoodbye!" << endl;
                return 0;
            default:
                cout << "\nUnknown selection, please try again." << endl;
        }
    }
    
	return 0;
}
