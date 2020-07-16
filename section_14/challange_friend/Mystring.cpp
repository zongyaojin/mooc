#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// getters
int Mystring::get_length() const { return strlen(str); }
const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// -------------------------------------------------------------- //

Mystring operator-(const Mystring &rhs) {
    char temp[strlen(rhs.str)];
    for (size_t i{0}; i<strlen(rhs.str); ++i)
        temp[i] = tolower(rhs.str[i]);
    return Mystring{temp};
}

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !(lhs.str == rhs);
}

bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return !(lhs.str < rhs);
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator*(const Mystring &lhs, const int &rhs) {
    Mystring temp;
    if (rhs <= 0)
        return temp;
    for (int i{0}; i<rhs; ++i)
        temp = temp + lhs;
    return temp;
}

Mystring &operator*=(Mystring &lhs, const int &rhs) {
    lhs = lhs * rhs;
    return lhs;
}

Mystring &operator++(Mystring &rhs) {
    for (size_t i{0}; i<strlen(rhs.str); ++i)
        rhs.str[i] = toupper(rhs.str[i]);
    return rhs;
}

Mystring operator++(Mystring &rhs, int) {
    Mystring temp{rhs};
    operator++(temp);
    return temp;
}