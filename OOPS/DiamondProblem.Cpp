#include <iostream>
using namespace std;

// Base class
class Base {
public:
    void fun() { cout << "Base" << endl; }
};

// Parent class 1
class Parent1 : public Base {
public:
};

// Parent class 1 (virtual inheritance)
// class Parent1 : virtual public Base {
// public:
// };

// Parent class 2
class Parent2 : public Base {
public:
};

// Parent class 2 (virtual inheritance)
// class Parent2 : virtual public Base {
// public:
// };

// Child class inheriting from both Parent1 and Parent2
class Child : public Parent1, public Parent2 {
};

int main()
{
    Child* obj = new Child();
    // Ambiguity of which path to access grandparent function
    // obj->fun(); 
    
    // Two Ways to Fix: 
    // Fix ambiguity using scope resolution
    obj->Parent1::fun(); // Calls fun() via Parent1's path
    obj->Parent2::fun(); // Calls fun() via Parent2's path
    
    // Using Virtual Inheritance
    // How it work?
    // obj->fun();

    delete obj;
    return 0;
}

