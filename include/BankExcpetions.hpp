#ifndef BANKEXCEPTIONS_HPP
#define BANKEXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class BankExceptions : public std::runtime_error {
    public:
        BankExceptions(const std::string& message) : std::runtime_error(message) {}
};

class AccountNotFound : public BankExceptions {
    public:
        AccountNotFound(const std::string& message) : BankExceptions(message) {}
};

class InsufficientFund : public BankExceptions {
    public:
        InsufficientFund(const std::string& message) : BankExceptions(message) {}
};

class NegativeAmount : public BankExceptions {
    public:
        NegativeAmount(const std::string& message) : BankExceptions(message) {}
};

#endif