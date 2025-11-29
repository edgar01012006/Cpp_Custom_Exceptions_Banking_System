#include "../include/CheckingAccount.hpp"

CheckingAccount::CheckingAccount(const std::string& name, double overdraftLimit)
    : BankAccount { name }, m_overdraftLimit { overdraftLimit } {} 

bool CheckingAccount::withdraw(double amount) {
    try {
        if (amount < 0) {
            throw NegativeAmount("Can't withdraw negative amount");
        }
        if (amount > m_balance) {
            double balanceOverdraft =  m_balance + (m_balance * (m_overdraftLimit / 100));
            if (amount > balanceOverdraft) {
                throw InsufficientFund("Can't withdraw; insufficient funds\n");
            }
            m_balance -= balanceOverdraft;
        }
        else {
            m_balance -= amount;
        }
    } catch(const BankExceptions& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
    return true;
}

bool CheckingAccount::deposit(double amount) {
    try {
        if (amount < 0) {
            throw NegativeAmount("Can't deposit negative amount");
        }
        m_balance += amount;
    } catch(const BankExceptions& ex) {
        std::cout << ex.what() << std::endl;
        return false;
    }
    return true;
}

void CheckingAccount::display() const {
    BankAccount::display();
    std::cout << "Overdraft limit: " << m_overdraftLimit << "%\n";
}