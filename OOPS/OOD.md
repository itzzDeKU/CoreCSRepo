# Object Oriented Design

## Association

- In C++, an association is a relationship between two classes where one class “**uses-a**” relationship with the other class. In other words, an instance of one class **has** an **instance** of the other class as a member. This is a way of modeling real-world relationships between objects in an object-oriented programming language.
- For example, consider a class “Person” and a class “Address”. If a person “has an” address, we can say that there is an association between the two classes. We can implement this association in C++ as follows:

    ``` cpp
    #include <bits/stdc++.h>
    using namespace std;

    class Address {
    private:
        string location;
        int pincode;

    public:
        void setLocation(string location) {
            this->location = location;
        }

        void setPincode(int pincode) {
            this->pincode = pincode;
        }

        string getLocation() {
            return this->location;
        }

        int getPincode() {
            return this->pincode;
        }
    };

    class Student {
    private:
        string name;
        Address* address; // Pointer to Address (association)

    public:
        Student() : address(nullptr) {} // Initialize address pointer to null

        void setName(string name) {
            this->name = name;
        }

        string getName() {
            return this->name;
        }

        // Setter method for Address object (association)
        void setAddress(Address* addr) {
            address = addr;
        }

        void getAddress() {
            if (address) {
                cout << "Location is " << address->getLocation() << endl;
                cout << "Pincode is " << address->getPincode() << endl;
            } else {
                cout << "No address assigned" << endl;
            }
        }
    };

    int main() {
        Student student;
        student.setName("Aman");

        Address address; // Create an Address object
        address.setLocation("Hyderabad, Telangana");
        address.setPincode(500032);

        student.setAddress(&address); // Pass the address object to the student

        cout << "Name is " << student.getName() << endl;
        student.getAddress();

        return 0;
    }

    ```

- In this example, an instance of the “Person” class has an instance of the “Address” class as a member, representing the association between the two classes. The relationship between the two classes can also be represented using a UML (Unified Modeling Language) diagram, which is a graphical representation of the classes and their relationships.

---

## Aggregation

- In C++, aggregation is a special type of association between classes that represents a **weaker** relationship than a composition. In an aggregation relationship, one **class** is a **container** for objects of another class, but it is **not** **responsible** for the **creation** or **destruction** of those objects. This relationship is often referred to as a “**has-a**” relationship, because one class has objects of another class as members.
- An aggregation relationship is represented in C++ as an object of one class containing **pointers** to objects of another class. The contained objects are said to be part of the containing object, but they can exist **independently** of the containing object. If the containing object is destroyed, the contained objects are not automatically destroyed along with it.
- For example, consider a class `Department` and a class `Employee`. If a department "has many" employees, we can say that there is an aggregation relationship between the two classes. We can implement this aggregation relationship in C++ as follows:

    ``` cpp
    #include <bits/stdc++.h>
    using namespace std;

    class Address {
    private:
        string location;
        int pincode;

    public:
        void setLocation(string location) {
            this->location = location;
        }

        void setPincode(int pincode) {
            this->pincode = pincode;
        }

        string getLocation() {
            return this->location;
        }

        int getPincode() {
            return this->pincode;
        }
    };

    class Student {
    private:
        string name;
        Address* address; // Pointer to Address (aggregation)

    public:
        Student() : address(nullptr) {} // Initialize address pointer to null

        void setName(string name) {
            this->name = name;
        }

        string getName() {
            return this->name;
        }

        // Setter method for Address object (aggregation)
        void setAddress(Address* addr) {
            address = addr;
        }

        void getAddress() {
            if (address) {
                cout << "Location is " << address->getLocation() << endl;
                cout << "Pincode is " << address->getPincode() << endl;
            } else {
                cout << "No address assigned" << endl;
            }
        }
    };

    int main() {
        Student student;
        student.setName("Aman");

        Address address; // Create an Address object
        address.setLocation("Hyderabad, Telangana");
        address.setPincode(500032);

        student.setAddress(&address); // Pass the address object to the student

        cout << "Name is " << student.getName() << endl;
        student.getAddress();

        return 0;
    }

    ```

- In this example, an instance of the `Department` class contains pointers to objects of the `Employee` class, representing the aggregation relationship between the two classes. The contained objects `employees` can exist independently of the containing object `Department`, and if the `Department` object is destroyed, the `Employee` objects are not automatically destroyed along with it.
- Association && Aggregation can have **similar** implementation but differ mainly in *semantic* or how one object is related to another.

---

## Composition

- In C++, composition is a ***special*** type of ***association*** between classes that represents a ***stronger*** relationship than a regular association. In a composition relationship, one class is the **owner** of the other class and is responsible for its creation and destruction. This relationship is often referred to as a “**owns-a**” relationship, because one class has an instance of another class as a member.
- A composition relationship is represented in C++ as an object of one class being contained within another class. The contained object is said to be a part of the containing object, and it **cannot** exist independently of the containing object. If the containing object is destroyed, the contained object is automatically destroyed along with it.
- For example, consider a class `Student` and a class `Address`. If a studnents "*owns an*" address, we can say that there is a composition relationship between the two classes. We can implement this composition relationship in C++ as follows:

    ``` cpp
    #include <bits/stdc++.h>
    using namespace std;

    class Address {
    private:
        string location;
        int pincode;

    public:
        void setLocation(string location) {
            this->location = location;
        }

        void setPincode(int pincode) {
            this->pincode = pincode;
        }

        string getLocation() {
            return this->location;
        }

        int getPincode() {
            return this->pincode;
        }
    };

    class Student {
    private:
        string name;
        Address address; // Regular member object

    public:
        void setName(string name) {
            this->name = name;
        }

        string getName() {
            return this->name;
        }

        void setAddress(string location, int pincode) {
            address.setLocation(location);
            address.setPincode(pincode);
        }

        void getAddress() {
            cout << "Location is " << address.getLocation() << endl;
            cout << "Pincode is " << address.getPincode() << endl;
        }
    };

    int main() {
        Student student;
        student.setName("Aman");
        student.setAddress("Hyderabad, Telangana", 500032);
        cout << "Name is " << student.getName() << endl;
        student.getAddress();
        return 0;
    }
    ```

- In this example, an instance of the `Address` class is contained within an instance of the `Student` class, representing the composition relationship between the two classes. The contained object `address` cannot exist independently of the containing object `student`, and if the `student` object is destroyed, the `address` object is automatically destroyed along with it.
- The Student class owns the Address object and manages its lifecycle (dynamic allocation and deletion).

## **Aggregation vs Association vs Composition**

| **Aspect**               | **Association**                                         | **Aggregation**                                             | **Composition**                                             |
|--------------------------|---------------------------------------------------------|-------------------------------------------------------------|-------------------------------------------------------------|
| **Relationship Type**    | General "uses-a" relationship                           | Special "has-a" relationship                                | Strong "owns-a" relationship                               |
| **Ownership**            | No ownership                                           | Weak ownership                                              | Strong ownership                                            |
| **Lifecycle Dependency** | Independent lifecycle                                   | Independent lifecycle                                       | Dependent lifecycle                                         |
| **Object Dependency**    | Objects interact but do not depend on each other       | Contained objects can exist independently                   | Contained objects cannot exist without the container        |
| **Implementation**       | Uses objects directly, or pointers to other objects    | Uses pointers or references to other objects                | Uses member objects directly or dynamically allocated ones |
| **Example**              | `Teacher` teaches `Student`                            | `Department` contains `Employee`                           | `Car` contains `Engine`                                    |
| **Object Deletion**      | No automatic cleanup required                          | Contained objects must be cleaned up explicitly if pointers | Contained objects are cleaned up when the container is destroyed |
| **Flexibility**          | Most flexible as no lifecycle dependencies are imposed | Less flexible as the container has a weak reference to objects | Least flexible as the lifecycle is tightly bound to the container |
| **Common Use Cases**     | Modeling general relationships                         | Modeling part-whole relationships where parts are reusable  | Modeling part-whole relationships where parts are non-reusable |

---
