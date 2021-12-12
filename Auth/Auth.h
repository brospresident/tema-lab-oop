#ifndef AUTH
#define AUTH

#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>


/*
    A class that handles the authentication of the user.
*/
class AuthSingleton {
    protected:
        static AuthSingleton* instance;
    
    public:
        const int minPassLength = 8;
        static AuthSingleton* getInstance();
        /*
            Checks if the user exists in the database.
            @param username: The username of the user.
            @returns true if the user exists, false otherwise.
        */
        bool existsUser(std::string name);

        /*
            @param password the password provided for checking
            @returns true if the password meets the criteria, false otherwise
            The criteria is:
                - at least 8 characters
                - at least one uppercase letter
                - at least one lowercase letter
                - at least one number
                - at least one special character
        */
        bool validatePassword(std::string password);
        
        /*
            Checks if the email has the correct format
            @param email: The email of the user.
            @returns true if the email has the correct format, false otherwise.
        */
        bool validateEmail(std::string email);
};


#endif