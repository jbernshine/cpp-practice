#include <iostream>
using namespace std;

namespace LamborghiniCar {
    void output() {
        cout << "Congraduations! You deserve the Lamborghini." << endl;
    }
}

namespace PorscheCar {
    void output() {
        cout << "Congraduations! You deserve the Porsche." << endl;
    }
}

int main() {
    int magicNumber; 
    cout << "Select a magic number (1 or 2) to win your dream car: ";
    cin >> magicNumber;

    if (magicNumber == 1) {
        LamborghiniCar::output();
    }
    else if (magicNumber == 2) {
        PorscheCar::output();
    }
    else {
        cout << "Please type the correct magic number." << endl;
    }

    return 0;
}