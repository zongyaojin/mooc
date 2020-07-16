#include <iostream>
#include "Mystring.h"

using namespace std;

int main() 
{
    
    cout << boolalpha << endl;
    Mystring a {"frank"};
    Mystring b {"frank"};
    
    cout << (a==b) << endl;                 // true
    cout << (a!=b) << endl << endl;         // false
    
    b = "george";
    cout << (a==b) << endl;                 // false
    cout << (a!=b) << endl;                 // true
    cout << (a<b) << endl;                  // true
    cout << (a>b) << endl << endl;          // false
    
    Mystring s1 {"FRANK"};
    s1 = -s1;       
    cout << s1 << endl << endl;             // frank    

    s1 = s1 + "*****";
    cout << s1 << endl << endl;             // frank*****
    
    s1 += "-----";                          // frank*****-----
    cout << s1 << endl << endl;
    
    Mystring s2{"12345,"};
    s1 = s2 * 5;
    cout << s1 << endl << endl;             // 12345,12345,12345,12345,12345,
    
    Mystring s3{"abcdef,"};  
    s3 *= 10;
    cout << s3 << endl << endl;             // abcdef,abcdef,abcdef,abcdef,abcdef,abcdef,abcdef,abcdef,abcdef,abcdef,
    
    Mystring s = "Frank";
    ++s;
    cout << s << endl << endl;              // FRANK
    
    s = -s; 
    cout << s << endl << endl;              // frank
    
    Mystring result;
    result = ++s;                           
    cout << s << endl;                      // FRANK
    cout << result << endl << endl;         // FRANK
    
    s = "Frank";
    s++;
    cout << s << endl << endl;              // FRANK
    
    s = -s;
    cout << s << endl << endl;              // frank
    
    result = s++;
    cout << s << endl;                      // FRANK
    cout << result << endl << endl;         // frank
    
    return 0;
}
