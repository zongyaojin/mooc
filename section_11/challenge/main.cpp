#include <iostream>
#include <vector>
#include <ctype.h>
#include <numeric>
#include <algorithm>
using namespace std;

void display_menu();
void get_input(char &c);
void display_vec(const vector<int> &v);
void add_number(vector<int> &v);
void display_mean(const vector<int> &v);
void display_smallest(const vector<int> &v);
void display_largest(const vector<int> &v);

int main() 
{
    char c {'\0'};
    vector<int> v;
    
    while (c!='q')
    {   
        display_menu();
        get_input(c);
        switch (c) {
            case 'p' :
                display_vec(v);
                break;
            case 'a':
                add_number(v);
                break;
            case 'm':
                display_mean(v);
                break;
            case 's':
                display_smallest(v);
                break;
            case 'l':
                display_largest(v);
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

void display_menu() {
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
}

void get_input(char &c) {
    cout << "\nEnter your choise: ";
    cin >> c;
    c = tolower(c);
}

void display_vec(const vector<int> &v) {
    if (v.size()==0) {
        cout << "[] - the list is empty" << endl;
    } else {
        cout << "[ ";
        for (auto i:v) {
            cout << i << " ";
        }
        cout << "]" << endl;
    }
}

void add_number(vector<int> &v) {
    cout << "\nEnter an integer to add to the list: ";
    int temp {0};
    cin >> temp;
    v.push_back(temp);
    cout << temp << " added." << endl;
}

void display_mean(const vector<int> &v) {
    if (v.size()==0) {
        cout << "[] - the list is empty, does not compute." << endl;
    } else {
        cout << "The mean is: " << accumulate(v.begin(), v.end(), 0.0) / v.size() << endl;
    }
}

void display_smallest(const vector<int> &v) {
    if (v.size()==0) {
        cout << "[] - the list is empty, does not compute." << endl;
    } else {
        cout << "The smallest number is: " << *min_element(v.begin(), v.end()) << endl;
    }
}

void display_largest(const vector<int> &v) {
    if (v.size()==0) {
        cout << "[] - the list is empty, does not compute." << endl;
    } else {
        cout << "The largest number is: " << *max_element(v.begin(), v.end()) << endl;
    }
}