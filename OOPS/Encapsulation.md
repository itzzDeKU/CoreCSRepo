# OOPS

## Encapsulation

### Definition

- Encapsulation is the process of combining data (attributes) and functions (methods) into a single unit, called a class.
- It restricts direct access to some of the object's components, ensuring controlled interaction through methods.

### Key Features

1. Data Hiding:

    - Internal state (attributes) of an object is hidden from the outside world.
    - Data can only be accessed or modified through public methods (getters and setters).

2. Controlled Access:

    - Only specific, well-defined methods are exposed to the outside world to interact with the object's data.

3. Advantages:

    - Protects data from unintended modifications.
    - Increases security by preventing unauthorized access.
    - Makes code more modular, maintainable, and easier to debug.

4. Implementation in C++:

    - Use the private access specifier to make attributes inaccessible from outside the class.
    - Use public getter and setter methods to allow controlled access.
