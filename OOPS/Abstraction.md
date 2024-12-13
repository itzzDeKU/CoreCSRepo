# OOPS

## Abstraction

### Brief

- Abstraction in Object-Oriented Programming (OOP) is the process of hiding implementation details and exposing only the essential features of an object or system to the outside world. It allows users to interact with objects through their interfaces, without worrying about the underlying complexities.
- In short, Hiding irrelevant data.
- Implemented using virtual functions and interfaces.

### Key Features of Abstraction

1. Hides Implementation Details:

    - The focus is on what an object does rather than how it does it.
    - This is achieved using abstract classes or interfaces in programming.

2. Provides Simplicity:

    - Users interact with the object using well-defined methods, without needing to understand the internal workings.

3. Achieved Using:

    - **Abstract Classes**: Classes containing one or more pure virtual functions (functions declared with = 0 in C++).
    - **Interfaces**: Define a contract that derived classes must follow.

### Data Binding

- Data binding is a process of binding the application UI and business logic. Any Change made in business logice will reflect directly to the application UI.

### Extra

#### Virtual Function

- A virtual function (also known as virtual methods) is a member function that is declared within a base class and is re-defined (overridden) by a derived class. When you refer to a derived class object using a pointer or a reference to the base class, you can call a virtual function for that object and execute the derived class’s version of the method.

- Virtual functions ensure that the correct function is called for an object, regardless of the type of reference (or pointer) used for the function call.
- They are mainly used to achieve Runtime polymorphism.
- Functions are declared with a virtual keyword in a base class.
- The resolving of a function call is done at runtime.

##### Rules for Virtual Functions

The rules for the virtual functions in C++ are as follows:

1. Virtual functions cannot be static.
2. A virtual function can be a friend function of another class.
3. Virtual functions should be accessed using a pointer or reference of base class type to achieve runtime polymorphism.
4. The prototype of virtual functions should be the same in the base as well as the derived class.
5. They are always defined in the base class and overridden in a derived class. It is not mandatory for the derived class to override (or re-define the virtual function), in that case, the base class version of the function is used.
6. A class may have a virtual destructor but it cannot have a virtual constructor.
