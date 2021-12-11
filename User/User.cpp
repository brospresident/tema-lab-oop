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
    std::cout << "Balance: $" << this->balance << std::endl;
    if (this->isOperator) {
        std::cout << ">> You are logged in as an operator." << std::endl;
    }
}

void User::saveUserData() {
    UserWriter* fr = new UserWriter(this->getName(), "./Data/Users/", "txt");

    bool isOperator = this->isOperator;
    int balance = this->balance;
    
    std::vector<std::string> userData = {  this->name,
                                            this->password,
                                            this->email,
                                            std::to_string(balance),
                                            std::to_string(isOperator)
                                        };

    fr->write(userData);
}

void User::topUpBalance(int amount) {
    try {
        if (!this->isLoggedIn) {
            throw "You must be logged in!";
        }
        if (amount < 0) {
            throw "Amount must be higher than 0.";
        }
        this->balance += amount;
        std::cout << "Successfully deposited $" << amount << " to your account." << std::endl;
        this->saveUserData();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void User::bookFlight(FlightManager& fm, int flight) {
    try {
        if (!this->isLoggedIn) {
            throw "You must be logged in!";
        }
        if (this->balance < getFlightPrice(fm, flight)) {
            throw "You do not have enough money to book this flight.";
        }
        this->balance -= getFlightPrice(fm, flight);
        std::cout << "Successfully booked flight " << flight << "." << std::endl;
        this->bookedFlights.push_back(flight);
        this->saveUserData();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void User::cancelFlightBooking(FlightManager& fm, int flight) {
    try {
        if (!this->isLoggedIn) {
            throw "You must be logged in!";
        }

        if (this->bookedFlights.size() == 0) {
            throw "You have no booked flights.";
        }

        if (std::find(this->bookedFlights.begin(), this->bookedFlights.end(), flight) == this->bookedFlights.end()) {
            throw "You have not booked this flight.";
        }

        this->balance += getFlightPrice(fm, flight);
        std::cout << "Successfully canceled flight " << flight << "." << std::endl;
        this->bookedFlights.erase(std::remove(this->bookedFlights.begin(), this->bookedFlights.end(), flight), this->bookedFlights.end());
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }
}

void User::printAllReservations() {
    if (this->bookedFlights.size() == 0) {
        std::cout << "You have no booked flights." << std::endl;
    }
    else {
        std::cout << "Your booked flights:" << std::endl;
        for (int i = 0; i < this->bookedFlights.size(); i++) {
            std::cout << this->bookedFlights[i] << std::endl;
        }
    }
}


