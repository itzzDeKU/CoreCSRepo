# **OOPS**

## **Polymorphism**

- Polymorphism is the ability of a function, operator, or object to behave differently based on the context in which it is used.  
- In simpler terms, it allows the same interface to be used for different data types or implementations.  
- **Types of Polymorphism**:  
  - **Compile-time Polymorphism** (also called Static Polymorphism).  
  - **Runtime Polymorphism** (also called Dynamic Polymorphism).  

---

### **Compile-time Polymorphism**

- Achieved through **function overloading** and **operator overloading**.  
- The behavior is determined at **compile time**.  

#### **Function Overloading**

- Same function name with different parameter lists (type or number of parameters).  
- Allows multiple implementations of the same function name for different input types.  
- Example:  

  ```cpp
  class Calculator {
  public:
      int add(int a, int b) { return a + b; } // For integers
      double add(double a, double b) { return a + b; } // For doubles
  };

  int main() {
      Calculator calc;
      cout << calc.add(2, 3) << endl;       // Calls add(int, int)
      cout << calc.add(2.5, 3.5) << endl;   // Calls add(double, double)
  }
  ```

#### **Operator Overloading**

- Customizing the behavior of operators for user-defined types.  
- Example:  

  ```cpp
  class Complex {
  private:
      double real, imag;
  public:
      Complex(double r, double i) : real(r), imag(i) {}
      Complex operator+(const Complex& c) {
          return Complex(real + c.real, imag + c.imag);
      }
      void display() {
          cout << real << " + " << imag << "i" << endl;
      }
  };

  int main() {
      Complex c1(1.5, 2.5), c2(3.0, 4.0);
      Complex c3 = c1 + c2; // Operator overloading
      c3.display();
  }
  ```

---

### **Runtime Polymorphism**

- Achieved through **inheritance** and **virtual functions**.  
- The behavior is determined at **runtime**, depending on the actual type of the object.  
- Uses **pointers or references** to base class for dynamic behavior.  

#### **Virtual Functions**

- Functions declared in the base class with the `virtual` keyword.  
- Allows derived class implementations to override the base class method.  
- Example:  

  ```cpp
  class Shape {
  public:
      virtual int getArea() = 0; // Pure virtual function
      virtual ~Shape() {}; // Virtual destructor
  };

  class Rectangle : public Shape {
  private:
      int length, breadth;
  public:
      Rectangle(int l, int b) : length(l), breadth(b) {}
      int getArea() override { return length * breadth; }
  };

  class Circle : public Shape {
  private:
      int radius;
  public:
      Circle(int r) : radius(r) {}
      int getArea() override { return 3.14 * radius * radius; }
  };

  int main() {
      Shape* shape1 = new Rectangle(4, 5);
      Shape* shape2 = new Circle(3);
      cout << shape1->getArea() << endl; // Calls Rectangle's getArea()
      cout << shape2->getArea() << endl; // Calls Circle's getArea()
      delete shape1;
      delete shape2;
  }
  ```

---

### **Differences Between Compile-time and Runtime Polymorphism**

| **Aspect**              | **Compile-time Polymorphism**             | **Runtime Polymorphism**             |
|--------------------------|-------------------------------------------|---------------------------------------|
| **Resolution Time**      | Resolved at compile time.                | Resolved at runtime.                 |
| **Achieved Through**     | Function overloading, Operator overloading. | Virtual functions, Inheritance.      |
| **Flexibility**          | Limited to predefined overloads.         | Allows dynamic behavior.             |
| **Performance**          | Faster, as resolved at compile time.     | Slower, due to runtime overhead.     |
| **Keyword Required**     | No specific keyword required.            | Uses `virtual` keyword.              |
