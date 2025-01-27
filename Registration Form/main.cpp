#include <iostream>
#include <string>
#include <limits>

class RegistrationForm {
private:
    std::string firstName;
    std::string lastName;
    std::string email;
    int age;
    std::string password;

public:
    void fillForm() {
        std::cout << "=== Registration Form ===" << std::endl;
        
        getFirstName();
        getLastName();
        getEmail();
        getAge();
        getPassword();
        
        std::cout << "Registration complete!" << std::endl;
    }

private:
    void getFirstName() {
        std::cout << "Enter first name (or 'J' for John): ";
        std::cin >> firstName;
        if (firstName == "J") firstName = "John";
    }

    void getLastName() {
        std::cout << "Enter last name (or 'D' for Doe): ";
        std::cin >> lastName;
        if (lastName == "D") lastName = "Doe";
    }

    void getEmail() {
        std::cout << "Enter email (or 'D' for default@example.com): ";
        std::cin >> email;
        if (email == "D") email = "default@example.com";
    }

    void getAge() {
        std::cout << "Enter age (or '0' for 18): ";
        std::cin >> age;
        if (age == 0) age = 18;
        while (std::cin.fail() || age < 0 || age > 120) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid age (0-120): ";
            std::cin >> age;
            if (age == 0) age = 18;
        }
    }

    void getPassword() {
        std::cout << "Enter password (or 'D' for default password): ";
        std::cin >> password;
        if (password == "D") password = "defaultPassword123";
    }
};

int main() {
    RegistrationForm form;
    form.fillForm();
    return 0;
}

