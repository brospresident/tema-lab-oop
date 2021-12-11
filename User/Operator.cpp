#include "./Operator.h"

Operator::Operator(std::string name, std::string password, std::string email, int balance, bool isOperator, bool isLoggedIn) : User(name, password, email, balance, isOperator, isLoggedIn) {
    std::cout << ">> You are logged in as an operator." << std::endl;
}

