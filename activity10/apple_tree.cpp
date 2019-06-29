#include <iostream>

class Apple {
    friend class AppleTree;
    private:
        Apple() {}
};

class AppleTree {
    public:
        Apple createFruit() {
            Apple apple;
            std::cout << "apple created!" << std::endl;
            return apple;
        }
};

int main() {
    AppleTree tree;
    Apple apple = tree.createFruit();
}