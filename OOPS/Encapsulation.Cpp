#include <bits/stdc++.h>
using namespace std;

class Person
{
private:
    int age;
    string gender;

public:
    int getAge()
    {
        return this->age;
    }

    string getGender()
    {
        return this->gender;
    }

    void setAge(int newAge)
    {
        this->age = newAge;
    }

    void setGender(string newGender)
    {
        this->gender = newGender;
    }
};

int main()
{
    Person *p = new Person();
    p->setAge(20);
    p->setGender("Male");
    cout << p->getAge() << endl;
    cout << p->getGender() << endl;
}