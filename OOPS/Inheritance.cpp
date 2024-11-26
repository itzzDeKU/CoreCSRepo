#include <bits/stdc++.h>
using namespace std;

// Hierarchical Inheritance: More than one base class from same class
class Animal
{
public:
    string name;

protected:
    void speak()
    {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal
{
public:
    // Will Inherit Public as public, protected as protected and private as private.
    void bark()
    {
        cout << name << " barks!" << endl; // Can access public member
        // speak();  // Can access protected member function inside derived class
    }
};

class Cat : protected Animal
{
public:
    // Will Inherit Public, Protected members as protected.
    void setName(string name)
    {
        this->name = name;
    }
    // Will Inherit Private as Private
    void meow()
    {
        cout << name << " meows!" << endl; // Can access protected member
        speak();                           // Can access protected member function
    }
    // protected: speak()
};

class Cow : private Animal
{
public:
    // Will Inherit Public, Protected members as private.
    void setName(string name)
    {
        this->name = name;
    }
    // protected: If protected, only accessible within derived class
    void moo()
    {
        cout << name << " Moos!" << endl; // Can access private member internally
        speak();                          // Can access private member function internally
    }
    // private: speak()
};

class Calf : private Cow
{
public:
    void cry()
    {
        moo(); // Can access `moo()` of Cow if not private
    }
};

// Multilevel Inheritance
// class Animal {
// public:
//     void eat() {
//         cout << "This animal eats food" << endl;
//     }
// };

// class Mammal : public Animal {
// public:
//     void giveBirth() {
//         cout << "Mammals give birth to live young" << endl;
//     }
// };

// class Human : public Mammal {
// public:
//     void think() {
//         cout << "Humans have the ability to think" << endl;
//     }
// };


// Hybrid Inheritance
// class Animal {
// public:
//     void eat() {
//         cout << "Animal eats food" << endl;
//     }
// };

// class Mammal : public Animal {
// public:
//     void breathe() {
//         cout << "Mammal breathes air" << endl;
//     }
// };

// class Bird : public Animal {
// public:
//     void fly() {
//         cout << "Birds can fly" << endl;
//     }
// };

// // Derived class combining Mammal and Bird
// class Bat : public Mammal, public Bird {
// public:
//     void hang() {
//         cout << "Bat hangs upside down" << endl;
//     }
// };

int main()
{
    Dog dog;
    dog.name = "Buddy"; // Can access public member of Animal
    dog.bark();         // Access inherited function
    // dog.speak();        // Access Speakk directly from outside if public, else inaccessible

    Cat cat;
    cat.setName("belaa");
    cat.meow();

    Cow cow;
    cow.setName("wendy");
    cow.moo(); // Accessible if only public

    Calf calf;
    calf.cry();

    // Human human;
    // human.eat();       // From Animal
    // human.giveBirth(); // From Mammal
    // human.think();     // From Human

    // Bat* bat = new Bat();
    // // bat->eat(); // ERROR: Ambiguity due to the diamond problem
    // bat->Mammal::eat(); // Explicitly calling eat from Mammal
    // bat->breathe();     // From Mammal
    // bat->fly();         // From Bird
    // bat->hang();        // From Bat

    return 0;
}
