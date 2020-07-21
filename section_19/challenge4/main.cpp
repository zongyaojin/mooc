#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() 
{
    ifstream in_file {"../romeoandjuliet.txt"};
    ofstream out_file {"../romeoandjuliet_out.txt"};
    
    if (!in_file) {
        cerr << "Error opening input file.\n" << endl;
        return 1;
    }
    
    if (!out_file) {
        cerr << "Error opening output file.\n" << endl;
        return 1;
    }
    
    int line {1};
    string buff;
    
    while (getline(in_file, buff))
        out_file << setw(10) << left << line++ << buff << endl;            
    
    in_file.close();
    out_file.close();
    cout << "Task completed.\n" << endl;
	return 0;
}
