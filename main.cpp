#include <iostream>

#include "./User/User.h"
#include "./RSA/RSA.h"
#include "./Auth/Register.h"
#include "./Auth/Login.h"

int main () {
    std::cout << "Welcome to BemRom application!" << std::endl;

    std::unique_ptr<User> user = std::make_unique<User>();

    while (true) {
        try {
            std::cout << "Please type your option(0 - exit the app | 1 - register | 2 - login " << std::endl;
            std::cout << "3 - Account information | 4 - Find flight by origin and destination | 5 - Book flight" << std::endl;
            std::cout << "6 - Top up your balance | 7 - See what flights you reserved since you joined us):" << std::endl;
            if (user->getIsOperator()) {
                std::cout << "Your operator rights: " << std::endl;
                std::cout << "8 - Add new flight | 9 - Delete flight | 10 - Change flight information" << std::endl;
            }

            int option;
            std::cin >> option;

            if (option == 0) break;
            else if (option == 1) {
                if (user->getIsLoggedIn()) {
                    throw "You are already logged in!";
                }
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
                if (user->getIsLoggedIn()) {
                    throw "You are already logged in!";
                }
                std::cout << "Welcome to our login page:" << std::endl;
                std::cout << "Please type in the following information: " << std::endl;

                std::cout << "Name: " << std::endl;
                std::string name;
                std::cin >> name;

                std::cout << "Password: " << std::endl;
                std::string password;
                std::cin >> password;

                Login* loginInstance = new Login();
                user = loginInstance->tryLoginUser(name, password);

                delete loginInstance;
            }
            else if (option == 3) {
                if (user->getIsLoggedIn()) {
                    user->showAccountInformation();
                }
                else throw "You are not logged in!";
            }
            else if (option == 6) {
                std::cout << "Type in the amount of money you want to put in your wallet: ";
                int amount;
                std::cin >> amount;
                user->topUpBalance(amount);
            }
            else {
                std::cout << "Invalid option!" << std::endl;
            }
        }
        catch (const char* msg) {
            std::cout << msg << std::endl;
        }
    }

    return 0;
}