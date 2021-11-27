#include "./User.h"

User::User() {
    this->name = "";
    this->password = "";
    this->email = "";
    this->balance = 0;
    this->isLoggedIn = false;
    this->isOperator = false;
}


User::User(std::string name, std::string password, std::string email) {
    this->name = name;
    this->password = password;
    this->email = email;
    this->balance = 0;
    this->isLoggedIn = true;
    this->isOperator = false;
}

User::User(std::string name, std::string password, std::string email, int balance) {
    this->name = name;
    this->password = password;
    this->email = email;
    this->balance = balance;
}

User::User(std::string name, std::string password, std::string email, int balance, bool isOperator, bool isLoggedIn) {
    this->name = name;
    this->password = password;
    this->email = email;
    this->balance = balance;
    this->isOperator = isOperator;
    this->isLoggedIn = isLoggedIn;
}

std::string User::getName() {
    return this->name;
}

std::string User::getPassword() {
    return this->password;
}

std::string User::getEmail() {
    return this->email;
}

int User::getBalance() {
    return this->balance;
}

void User::setName(std::string name) {
    this->name = name;
}

void User::setPassword(std::string password) {
    this->password = password;
}

void User::setEmail(std::string email) {
    this->email = email;
}

void User::setBalance(int balance) {
    this->balance = balance;
}

// void User::removeReservedFlight(Flight flight) {
//     for (int i = 0; i < this->reservedFlights.size(); i++) {
//         if (this->reservedFlights[i] == flight) {
//             this->reservedFlights.erase(this->reservedFlights.begin() + i);
//         }
//     }
// }

bool User::getIsLoggedIn() {
    return this->isLoggedIn;
}

bool User::getIsOperator() {
    return this->isOperator;
}

void User::setOperator(bool isOperator) {
    this->isOperator = isOperator;
}

void User::setLoggedIn(bool isLoggedIn) {
    this->isLoggedIn = isLoggedIn;
}

void User::showAccountInformation() {
    std::cout << "Name: " << this->name << std::endl;
    std::cout << "Email: " << this->email << std::endl;
    std::cout << "Balance: " << this->balance << std::endl;
}


