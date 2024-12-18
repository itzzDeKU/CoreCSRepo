#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
    // Why required -- Upcasting
    // void virtual setDimension(int len) = 0; // Mandatory, Pure Virtual 
    void virtual setDimension(int len){}; // Mandatory, Pure Virtual 
    void virtual setDimension2(int len, int brd){}; // Optional , Not Pure Virtual
    int virtual getArea() = 0;
    virtual ~Shape() {};
};

class Square : public Shape
{
private:
    int len;

public:
    int getArea() override
    {
        return len * len;
    }
    void setDimension(int len) override
    {
        this->len = len;
    }
};
class Rectangle : public Shape
{
private:
    int len, brd;

public:
    int getArea() override
    {
        return len * brd;
    }
    void setDimension2(int len, int brd) override
    {
        this->len = len;
        this->brd = brd;
    }
};

class Circle : public Shape
{
private:
    int radius;

public:
    int getArea() override
    {
        return 3.14 * radius * radius;
    }
    void setDimension(int len) override
    {
        this->radius = len;
    }
};

int main()
{
    Shape *circle = new Circle();
    Shape *square = new Square();
    Shape *rect = new Rectangle();
    // Setting dimensions
    circle->setDimension(4);
    square->setDimension(4);
    rect->setDimension2(4, 5);
    // finding area
    cout << circle->getArea() << endl;
    cout << square->getArea() << endl;
    cout << rect->getArea() << endl;

    delete square;
    delete circle;
    return 0;
}

// Possible Way for Strict Abstraction:
// Dynamic cast 
// Parameterized Virtual Functions