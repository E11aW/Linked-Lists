#include "Child.h"
using namespace std;

Child::Child()
{

}
Child::Child(string first_name, string last_name, int age)
{
    first_name_ = first_name;
    last_name_ = last_name;
    age_ = age;
}
string Child::first_name() const
{
    return first_name_;
}
string Child::last_name() const
{
    return last_name_;
}
int Child::age() const
{
    return age_;
}
ostream& operator <<(ostream& stream, Child& c)
{
    stream << c.first_name_;
    stream << c.last_name_;
    stream << c.age_;
    return stream;
}
istream& operator >>(istream& stream, Child& c)
{
    stream >> c.first_name_;
    stream >> c.last_name_;
    stream >> c.age_;
    return stream;
}
bool Child::operator==(Child& other) const
{
    if(first_name_ == other.first_name_ && last_name_ == other.last_name_ && age_ == other.age_) return true;
    else return false;
}
bool Child::operator!=(Child& other) const
{
    if(*this == other) return false;
    else return true;
}
bool Child::operator<(Child& other) const
{
    if(last_name_ < other.last_name_) return true;
    if(last_name_ == other.last_name_ && first_name_ < other.first_name_) return true;
    if(last_name_ == other.last_name_ && first_name_ == other.first_name_ && age_ < other.age_) return true;
    return false;
}
bool Child::operator>(Child& other) const
{
    if(*this < other) return false;
    else return false;
}