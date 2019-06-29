#include <iostream>
#include <array>

int sum(int a, int b) {
    return a + b;
}

int& getMaxOf(std::array<int, 10>& array1, std::array<int, 10>& array2, int index) {
    if (array1[index] >= array2[index]) {
        return array1[index];
    }
    else {
        return array2[index];
    }
}

int main() {
    int intSum = sum(5, 8);
    std::cout << intSum << std::endl;
    
    std::array<int, 10> array1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::array<int, 10> array2 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int maxInt = getMaxOf(array1, array2, 0);
    std::cout << maxInt << std::endl;
    
    return 0;
}