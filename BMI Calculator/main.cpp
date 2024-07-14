#include <iostream>
#include <iomanip>
#include <limits>

double calculateBMI(double weight, double height, bool isMetric) {
    if (isMetric) {
        return weight / (height * height);
    } else {
        return 703 * weight / (height * height);
    }
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    double weight, height;
    char unit;
    bool isMetric;

    std::cout << "BMI Calculator\n";
    std::cout << "Enter 'M' for metric (kg/m) or 'I' for imperial (lbs/in): ";
    std::cin >> unit;

    if (unit == 'M' || unit == 'm') {
        isMetric = true;
        std::cout << "Enter weight in kilograms: ";
        std::cin >> weight;
        std::cout << "Enter height in meters: ";
        std::cin >> height;
    } else if (unit == 'I' || unit == 'i') {
        isMetric = false;
        std::cout << "Enter weight in pounds: ";
        std::cin >> weight;
        std::cout << "Enter height in inches: ";
        std::cin >> height;
    } else {
        std::cout << "Invalid unit selection. Exiting program.\n";
        return 1;
    }

    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter numeric values.\n";
        clearInputBuffer();
        return 1;
    }

    double bmi = calculateBMI(weight, height, isMetric);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Your BMI is: " << bmi << std::endl;

    std::cout << "BMI Categories:\n";
    std::cout << "Underweight = <18.5\n";
    std::cout << "Normal weight = 18.5-24.9\n";
    std::cout << "Overweight = 25-29.9\n";
    std::cout << "Obesity = BMI of 30 or greater\n";

    return 0;
}
