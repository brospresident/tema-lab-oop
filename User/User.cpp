#include "./User.h"

User::User(int id, std::string name, std::string password, std::string email, int balance) {
    this->id = id;
    this->name = name;
    this->password = password;
    this->email = email;
    this->balance = balance;
}

User::User(int id, std::string name, std::string password, std::string email, int balance, std::vector<Flight> reservedFlights) {
    this->id = id;
    this->name = name;
    this->password = password;
    this->email = email;
    this->balance = balance;
    this->reservedFlights = reservedFlights;
}

int User::getId() {
    return this->id;
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

std::vector<Flight> User::getReservedFlights() {
    return this->reservedFlights;
}

void User::setId(int id) {
    this->id = id;
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

void User::setReservedFlights(std::vector<Flight> reservedFlights) {
    this->reservedFlights = reservedFlights;
}

void User::addReservedFlight(Flight flight) {
    this->reservedFlights.push_back(flight);
}

void User::removeReservedFlight(Flight flight) {
    for (int i = 0; i < this->reservedFlights.size(); i++) {
        if (this->reservedFlights[i] == flight) {
            this->reservedFlights.erase(this->reservedFlights.begin() + i);
        }
    }
}

