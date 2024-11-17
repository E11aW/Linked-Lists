#ifndef CHILD_H_
#define CHILD_H_
#include <iostream>
#include <string>
using namespace std;

class Child
{
public:
    Child();
    Child(string first_name, string last_name, int age);
    string first_name() const;
    string last_name() const;
    int age() const;
    friend ostream& operator <<(ostream& stream, Child& c);
    friend istream& operator >>(istream& stream, Child& c);
    bool operator==(Child& other) const;
    bool operator!=(Child& other) const;
    bool operator<(Child& other) const;
    bool operator>(Child& other) const;
private:
    string first_name_;
    string last_name_;
    int age_;
};
#endif