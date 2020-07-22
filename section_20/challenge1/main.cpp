#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctype.h>
#include <algorithm>

bool is_palindrome(const std::string& s);
bool is_palindrome_2(const std::string& s);

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

    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    std::cout << "---------------" << std::endl;    
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome_2(s)  << s << std::endl;
    }
    std::cout << std::endl;
    
    return 0;
}


// Simple alpha-check and push-back to process the string and non-recursive to check palindrome
bool is_palindrome(const std::string& s) 
{
    std::deque<char> dq;
    for (const auto c:s) {
        if (std::isalpha(c))
            dq.push_back(std::tolower(c));
    }
    
    while (dq.size() > 1) {
        if (dq.front() != dq.back())
            return false;
        dq.pop_front();
        dq.pop_back();
    }
    
    return true;
}


// Using iterator to process the string and recursion to check palindrome
bool is_palindrome_2(const std::string& s) 
{
    std::string ss;
    std::copy_if(s.begin(), s.end(), std::back_inserter(ss),
        [](const auto &c) {
           return std::isalpha(c); 
        });
    std::transform(ss.begin(), ss.end(), ss.begin(), tolower);  
 
    std::deque<char> dq(ss.begin(), ss.end());
    if (dq.size() == 1 || dq.size() == 0)
        return true;
    if (dq.front() == dq.back()) {
        dq.pop_back();
        dq.pop_front();
        std::string buff(dq.begin(), dq.end());
        return is_palindrome(buff);
    } else {
        return false;
    }
}
