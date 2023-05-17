#include <iostream>

 class Base {
public:
    virtual void display() {
        std::cout << "Base display()" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() {
        std::cout << "Derived display()" << std::endl;
    }
};

int main() {
    Derived derivedObj;
    derivedObj.display(); // In ra "Derived display()"

    Base* basePtr = &derivedObj;
    basePtr->display(); // In ra "Base display()"

    return 0;
}
