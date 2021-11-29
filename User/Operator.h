#ifndef OPERATOR
#define OPERATOR

#include "./User.h"
#include <string>
#include <iostream>
#include <regex>

class Operator : public User {
    public:
        Operator(std::string name, std::string password, std::string email, int balance, bool isOperator, bool isLoggedIn);
};

#endif