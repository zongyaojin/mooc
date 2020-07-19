#ifndef _ILLEGAL_BALANCE_EXCEPTION_H__
#define _ILLEGAL_BALANCE_EXCEPTION_H__

#include <exception>

class IllegalBalanceException: public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept {
        return "\n \033[1;31m IllegalBalanceException: \n\t You can not create an account with negative balance. \033[0m \n";
    }
};

#endif // _ILLEGAL_BALANCE_EXCEPTION_H__
