#ifndef LIST_342_H_
#define LIST_342_H_
#include <iostream>
#include <fstream>
using namespace std;

template<class T>
struct Node
{
    T* data;
    Node* next = nullptr;
};

template<class T> class List342;
template<class T> ostream& operator <<(ostream& stream, List342<T>& list);

template<class T>
class List342
{
public:
    //Constructors and Deconstructors
    List342();
    List342(const List342& source);
    ~List342();

    //Actions
    bool BuildList(string file_name);
    bool Insert( T* obj);
    bool Remove(T target, T& result);
    bool Peek(T target, T& result) const;
    int Size() const;
    void DeleteList();
    bool Merge(List342& list1);

    //Operator Overloads
    List342 operator+(List342& rhs) const;
    List342& operator+=(List342& other);
    bool operator==(List342& other) const;
    bool operator!=(List342& other) const;
    friend ostream& operator << <T>(ostream& stream, List342<T>& list);
    List342<T>& operator=(const List342& source);
private:
    Node<T>* head_;
};
#include "List342.cpp"
#endif