#ifndef _INSUFFICIENT_FUNDS_EXCEPTION_H__
#define _INSUFFICIENT_FUNDS_EXCEPTION_H__

#include <exception>

class InsufficientFundsException: public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char* what() const noexcept {
        return "\n \033[1;31m InsufficientFundsException: \n\t You do not have enough balance to complete the withdrawl. \033[0m \n";
    }
};

#endif // _INSUFFICIENT_FUNDS_EXCEPTION_H__
