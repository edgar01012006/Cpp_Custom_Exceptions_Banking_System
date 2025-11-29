#ifndef SAVINGSACCOUNT_HPP
#define SAVINGSACCOUNT_HPP

#include "BankAccount.hpp"
#include "BankExcpetions.hpp"

class SavingsAccount : public BankAccount {
    public:
        SavingsAccount(const std::string& name, double interestRate = 1.0);
        bool withdraw(double amount) override;
        bool deposit(double amount) override;
        void display() const override;

    private:
        double m_interestRate; // in %
};

#endif