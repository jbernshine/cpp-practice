#include <iostream>

void byreference_age_in_5_years(const int& age) {
    if (age >= 18) {
        std::cout << "Congraduations! You are eligible to vote for your nation." << std::endl;
    }
    else {
        int reqAge = 18;
        int yearsToGo = reqAge-age;

        std::cout << "No worries, just " << yearsToGo << " more years to go." << std::endl;
    }
}

int main() {
    int age;

    std::cout << "Please enter your age:";
    std::cin >> age;
    byreference_age_in_5_years(age);

    return 0;
}