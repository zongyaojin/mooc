#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{
    ifstream in_file {"../responses.txt"};
    
    if (!in_file.is_open()) {
        cerr << "Cannot open file.\n" << endl;
        return 1;
    }
    
    cout << setw(10) << left << "Student" << setw(10) << right << "Score" << endl;
    cout << setw(20) << setfill('-') << "" << endl;
    cout << setfill(' ');
    
    string key, answer, student;
    int score{0}, count{0};
    double total{0};
    
    getline(in_file, key);
    while (!in_file.eof()) {
        getline(in_file, student);
        getline(in_file, answer);
        
        score = 0;
        for (size_t i=0; i<key.size(); ++i) {
            if (key.at(i) == answer.at(i))
                ++score;
        }
        
        cout << setw(10) << left << student << setw(10) << right << score << endl;
        ++count;
        total += score;
    }
    
    cout << setw(20) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << setw(10) << left << "Average" << setw(10) << right << total/count << endl;
    cout << endl;
    
    in_file.close();
	return 0;
}
