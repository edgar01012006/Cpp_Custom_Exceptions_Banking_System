# 🏦 Bank Account Management System — Interface-Based OOP Design

A C++ project demonstrating **object-oriented banking logic**, where accounts such as savings and checking are modeled using clean abstractions. Core operations—like deposits, withdrawals, transfers, and exception handling—are organized through well-structured classes to keep the system scalable and easy to extend.

This project showcases:

- Clear OOP separation of responsibilities  
- Polymorphism for handling different account types  
- Custom exception handling for invalid operations  
- Easy expandability for adding new account types  

---

## 📂 Project Structure

├── main.cpp  
├── include/  
│   ├── Bank.hpp  
│   ├── BankAccount.hpp  
│   ├── BankExcpetions.hpp  
│   ├── CheckingAccount.hpp  
│   └── SavingsAccount.hpp  
├── src/  
│   ├── Bank.cpp  
│   ├── BankAccount.cpp  
│   ├── CheckingAccount.cpp  
│   └── SavingsAccount.cpp  
└── README.md  

---

## ⚙️ Build & Run

```bash
# Compile using g++ (C++17)
g++ -std=c++17 -Iinclude src/Bank.cpp src/BankAccount.cpp src/CheckingAccount.cpp src/SavingsAccount.cpp main.cpp -o main

# Run on Linux
./main

# Run on Windows
./main.exe