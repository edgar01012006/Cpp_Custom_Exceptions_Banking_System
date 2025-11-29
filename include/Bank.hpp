#ifndef BANK_HPP
#define BANK_HPP

#include <vector>
#include <string>
#include "BankAccount.hpp"
#include "BankExcpetions.hpp"
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"

class Bank {
    public:
        Bank() = default;
        ~Bank();
        void withdraw(const std::string& cardNumber, double amount);
        void deposit(const std::string& cardNumber, double amount);
        void createCheckingsAccount(const std::string& name);
        void createSavingsAccount(const std::string& name);
        void transfer(const std::string& cardNumber1, const std::string& cardNumber2, double amount);
        void display() const;

        void menu();
        
    private:
        BankAccount* findCardNumber(const std::string& cardNumber);

        std::vector<BankAccount*> m_bankAccounts;
};

#endif