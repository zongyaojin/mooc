#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() 
{
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string test, encrypted, decrypted;
    cout << "Enter your secret message: ";
    getline(cin, test);
    decrypted = encrypted = test;

    cout << "\nEncrypting message..." << endl;
    
    transform(test.begin(), test.end(), encrypted.begin(),
              [&alphabet, &key](char c) {
                  if (alphabet.find(c) != string::npos) {
                      return key.at(alphabet.find(c));
                  } else {
                      return c;
                  }
              });
              
    cout << "\nEncrypted message: " << encrypted << endl;
    cout << "\nDecrypting message..." << endl;

    transform(encrypted.begin(), encrypted.end(), decrypted.begin(),
              [&alphabet, &key](char c) {
                  if (key.find(c) != string::npos) {
                      return alphabet.at(key.find(c));
                  } else {
                      return c;
                  }
              });
              
    cout << "\nDecrypted message: " << decrypted << endl << endl;
    
	return 0;
}
