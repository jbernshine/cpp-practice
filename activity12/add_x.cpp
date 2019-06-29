#include <iostream>

class AddX {
    public: 
        AddX(int x) : x(x) {}
        int operator() (int y) { return x + y; }
    private:
        int x;
};

int main() {
    AddX add_five(5);
    std::cout << add_five(4) << std::endl;
}