#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
    ifstream in_file {"../romeoandjuliet.txt"};
    string word, buff;
    int num_found{0}, num_words{0};
    
    if (!in_file.is_open()) {
        cerr << "Cannot open file.\n" << endl;
        return 1;
    }
    
    cout << "Enter the substring to search for: ";
    cin >> word;
    
    while (in_file >> buff) {
        ++num_words;
        if (buff.find(word) != string::npos)
            ++num_found;
    }
    
    cout << num_words << " words were searched..." << endl;
    cout << "The substring " << word << " was found " << num_found << " times.\n" << endl;
    
    in_file.close();
	return 0;
}
