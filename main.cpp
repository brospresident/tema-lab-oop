#include <iostream>

#include "./Auth/Register.h"
#include "./User/User.h"

int main () {
    std::cout << "Welcome to BemRom application!" << std::endl;

    User* user = new User();

    while (true) {
        try {
            std::cout << "Please type your option(0 - exit the app | 1 - register | 2 - login " << std::endl;
            std::cout << "3 - Account information | 4 - Find flight by origin and destination | 5 - Book flight" << std::endl;
            std::cout << "6 - Top up your balance | 7 - See what flights you reserved since you joined us):" << std::endl;
            int option;
            std::cin >> option;

            if (option == 0) break;
            else if (option == 1) {
                std::cout << "Welcome to our register page:" << std::endl;
                std::cout << "Please type in the following information: " << std::endl;
                
                std::cout << "Name: " << std::endl;
                std::string name;
                std::cin >> name;

                std::cout << "Password: " << std::endl;
                std::string password;
                std::cin >> password;

                std::cout << "Confirm password: " << std::endl;
                std::string confirmPassword;
                std::cin >> confirmPassword;

                std::cout << "Email: " << std::endl;
                std::string email;
                std::cin >> email;

                Register* registerInstance = new Register();

                user = registerInstance->tryRegisterUser(name, password, confirmPassword, email);

                delete registerInstance;
            } 
            else if (option == 2) {
                std::cout << "Welcome to our login page:" << std::endl;
                std::cout << "Please type in the following information: " << std::endl;
            }
            else if (option == 3) {
                if (user->getIsLoggedIn()) {
                    std::cout << "Name: " << user->getName() << std::endl;
                }
                else throw "You are not logged in!";
            } 
            else {
                std::cout << "Invalid option!" << std::endl;
            }
        }
        catch (const char* msg) {
            std::cout << msg << std::endl;
        }
    }

    delete user;
    return 0;
}