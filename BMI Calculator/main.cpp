#include <iostream>

float calculateBMI(float weight, float height) {
    // Calculate BMI using weight in kilograms and height in meters
    float bmi = weight / (height * height);
    return bmi;
}

int main() {
    std::cout << "Welcome to the BMI Calculator!" << std::endl;

    // Input weight in kilograms
    float weight;
    std::cout << "Enter your weight in kilograms: ";
    std::cin >> weight;

    // Input height in meters
    float height;
    std::cout << "Enter your height in meters: ";
    std::cin >> height;

    // Calculate BMI
    float bmi = calculateBMI(weight, height);
    std::cout << "Your BMI is: " << bmi << std::endl;

    return 0;
}
