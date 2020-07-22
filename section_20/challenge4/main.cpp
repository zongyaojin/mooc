#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctype.h>
#include <algorithm>

bool is_palindrome(const std::string& s);

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };

    std::cout << std::boolalpha;
    
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    std::cout << "---------------" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}


bool is_palindrome(const std::string& s) 
{
    std::stack<char> stk;
    std::queue<char> que;
    for (const char c:s) {
        if (std::isalpha(c)) {
            stk.push(std::tolower(c));
            que.push(std::tolower(c));
        }
    }
    
    while (stk.size() > 1) {
        if (stk.top() != que.front())
            return false;
        stk.pop();
        que.pop();
    }
    
    return true;
}