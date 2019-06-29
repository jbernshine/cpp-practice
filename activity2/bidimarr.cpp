#include <iostream>

int main() {
    int foo[3][3];

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            foo[x][y] = x + y;
        }
    }

    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            std::cout << "foo[" << x << "][" << y << "]: " << foo[x][y] << std::endl;
        }
    }

    return 0;
}