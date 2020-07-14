#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    string input;
    cout << "Provide your input: ";
    getline(cin, input);

    for (size_t i=0; i<input.size(); i++) 
    {
        string forward = input.substr(0, i+1);
        string backward = string {forward.rbegin(), forward.rend()};
        cout << setw(input.size()+i);
        cout << forward + backward.erase(0,1) << endl;
    }

    return 0;

}