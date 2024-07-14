#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits>

class Calculator {
private:
    double memory;

public:
    Calculator() : memory(0) {}

    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) {
        if (b == 0) {
            throw std::runtime_error("Division by zero!");
        }
        return a / b;
    }
    double power(double base, double exponent) { return std::pow(base, exponent); }
    double squareRoot(double a) {
        if (a < 0) {
            throw std::runtime_error("Cannot calculate square root of a negative number!");
        }
        return std::sqrt(a);
    }

    void setMemory(double value) { memory = value; }
    double getMemory() const { return memory; }
    void clearMemory() { memory = 0; }
};

void displayMenu() {
    std::cout << "\n==== Calculator Menu ====\n";
    std::cout << "1. Addition\n";
    std::cout << "2. Subtraction\n";
    std::cout << "3. Multiplication\n";
    std::cout << "4. Division\n";
    std::cout << "5. Power\n";
    std::cout << "6. Square Root\n";
    std::cout << "7. Memory Operations\n";
    std::cout << "8. Exit\n";
    std::cout << "========================\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Calculator calc;
    int choice;
    double a, b;

    std::cout << std::fixed << std::setprecision(2);

    while (true) {
        displayMenu();
        std::cin >> choice;

        if (choice == 8) {
            std::cout << "Thank you for using the calculator. Goodbye!\n";
            break;
        }

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << calc.add(a, b) << std::endl;
                    break;
                case 2:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << calc.subtract(a, b) << std::endl;
                    break;
                case 3:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << calc.multiply(a, b) << std::endl;
                    break;
                case 4:
                    std::cout << "Enter two numbers: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << calc.divide(a, b) << std::endl;
                    break;
                case 5:
                    std::cout << "Enter base and exponent: ";
                    std::cin >> a >> b;
                    std::cout << "Result: " << calc.power(a, b) << std::endl;
                    break;
                case 6:
                    std::cout << "Enter a number: ";
                    std::cin >> a;
                    std::cout << "Result: " << calc.squareRoot(a) << std::endl;
                    break;
                case 7:
                    int memoryChoice;
                    std::cout << "Memory Operations:\n";
                    std::cout << "1. Store in memory\n";
                    std::cout << "2. Recall from memory\n";
                    std::cout << "3. Clear memory\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> memoryChoice;
                    switch (memoryChoice) {
                        case 1:
                            std::cout << "Enter value to store: ";
                            std::cin >> a;
                            calc.setMemory(a);
                            std::cout << "Value stored in memory.\n";
                            break;
                        case 2:
                            std::cout << "Value in memory: " << calc.getMemory() << std::endl;
                            break;
                        case 3:
                            calc.clearMemory();
                            std::cout << "Memory cleared.\n";
                            break;
                        default:
                            std::cout << "Invalid memory operation choice.\n";
                    }
                    break;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}

