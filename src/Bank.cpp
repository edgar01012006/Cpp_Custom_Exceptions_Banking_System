#include "../include/Bank.hpp"

BankAccount* Bank::findCardNumber(const std::string& cardNumber) {
    try {
        for (BankAccount* const bankAccount: m_bankAccounts) {
            if (bankAccount->getCardNumber() == cardNumber) {
                return bankAccount;
            }
        }
        throw AccountNotFound("Account not found");
    } catch(const BankExceptions& ex) {
        std::cout << ex.what() << std::endl;
    }
    return nullptr;
}

Bank::~Bank() {
    for (int i = 0; i < m_bankAccounts.size(); ++i) {
        delete m_bankAccounts[i];
    }
}

void Bank::withdraw(const std::string& cardNumber, double amount) {
    BankAccount* bankAccount = findCardNumber(cardNumber);
    if (bankAccount != nullptr) {
        bankAccount->withdraw(amount);
    }
}

void Bank::deposit(const std::string& cardNumber, double amount) {
    BankAccount* bankAccount = findCardNumber(cardNumber);
    if (bankAccount != nullptr) {
        bankAccount->deposit(amount);
    }
}

void Bank::createCheckingsAccount(const std::string& name) {
    m_bankAccounts.push_back(new CheckingAccount(name));
}

void Bank::createSavingsAccount(const std::string& name) {
    m_bankAccounts.push_back(new SavingsAccount(name));
}

void Bank::transfer(const std::string& cardNumber1, const std::string& cardNumber2, double amount) {
    BankAccount* const bankAccount1 = findCardNumber(cardNumber1);
    if (bankAccount1 != nullptr) {
        BankAccount* const bankAccount2 = findCardNumber(cardNumber2);
        if (bankAccount2 != nullptr) {
            if (bankAccount1->withdraw(amount) == true) {
                bankAccount2->deposit(amount);
            }
        }
    }
}

void Bank::display() const {
    for (BankAccount* const bankAccount: m_bankAccounts) {
        bankAccount->display();
        std::cout << "\n";
    }
}

void Bank::menu() {
    int input = 1;
    std::string name; // 1, 2
    std::string cardNumber1; // 3, 4, 5
    std::string cardNumber2; // 5
    double amount; // 3, 4, 5

    while (input != 0) {
        std::cout << "\n0: Exit\n" 
                  << "1: create Checking account\n"
                  << "2: create Savings account\n"
                  << "3: withdraw\n"
                  << "4: deposit\n"
                  << "5: transfer\n"
                  << "6: display all accounts\n\n";
        
        std::cout << "Your input: "; 
        std::cin >> input;
        std::cout << "\n";
        switch(input) {
            case 0:
                return;
            case 1:
                std::cout << "Enter the name\n";
                std::cin >> name;
                createCheckingsAccount(name);
                break;
            case 2:
                std::cout << "Enter the name\n";
                std::cin >> name;
                createSavingsAccount(name);
                break;
            case 3:
                std::cout << "Enter the card number\n";
                std::cin >> cardNumber1;
                std::cout << "Enter the amount\n";         
                std::cin >> amount;
                withdraw(cardNumber1, amount);
                break;
            case 4:
                std::cout << "Enter the card number\n";
                std::cin >> cardNumber1;
                std::cout << "Enter the amount\n"; 
                std::cin >> amount;
                deposit(cardNumber1, amount);
                break;
            case 5:
                std::cout << "Enter the card number you will transfer from\n";
                std::cin >> cardNumber1;
                std::cout << "Enter the card number you will transfer to\n";
                std::cin >> cardNumber2;
                std::cout << "Enter the amount you would like to transfer\n";
                std::cin >> amount;
                transfer(cardNumber1, cardNumber2, amount);
                break;
            case 6:
                display();
                break;
            default:
                break;
        }
    }
}