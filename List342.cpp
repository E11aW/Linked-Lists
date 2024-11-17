#ifndef LIST_342_CPP_
#define LIST_342_CPP_
#include "List342.h"
using namespace std;

template<class T>
List342<T>::List342() : head_(nullptr)
{

}
template<class T>
List342<T>::List342(const List342& source) : head_(nullptr)
{
    *this = source;
}
template<class T>
List342<T>::~List342()
{
    DeleteList();
}
template<class T>
bool List342<T>::BuildList(string file_name)
{
    //Get Input and Sort it
    ifstream input_file;
    input_file.open(file_name);
    if(input_file.eof()) return false;
    while(!input_file.eof())
    {
        T temp_object;
        input_file >> temp_object;
        Insert(&temp_object);
    }
    input_file.close();
    return true;
}
template<class T>
bool List342<T>::Insert(T* obj)
{
    T current_obj = *obj;
    //Ensures inserting unique object
    T result;
    if(Peek(current_obj, result)) return false;
    //Empty list
    Node<T>* insert_node = new Node<T>(); // must add the value itself not reference
    insert_node->data = new T(current_obj);
    if(head_ == nullptr)
    {
        head_ = insert_node;
        return true;
    }
    //First object
    if(current_obj < *head_->data)
    {
        insert_node->next = head_;
        head_ = insert_node;
        return true;
    }
    //Anywhere else in the list
    Node<T>* current_node = head_;
    while(current_node->next != nullptr && *current_node->next->data < current_obj)
    {
        current_node = current_node->next;
    }
    insert_node->next = current_node->next;
    current_node->next = insert_node;
    return true;
}
template<class T>
bool List342<T>::Remove(T target, T& result)
{
    if(head_ == nullptr || target < *head_->data) return false;
    //Checks if first data is target
    if(*head_->data == target)
    {
        result = *head_->data;
        Node<T>* delete_node = head_;
        if(head_->next == nullptr) head_ = nullptr;
        else head_ = head_->next;
        delete delete_node->data;
        delete delete_node;
        return true;
    }
    Node<T>* current_node = head_;
    //Checks all other datas in list
    while(current_node->next != nullptr)
    {
        if(*current_node->next->data == target)
        {
            result = *current_node->next->data;
            Node<T>* delete_node = current_node->next;
            current_node->next = current_node->next->next;
            delete delete_node->data;
            delete delete_node;
            return true;
        } 
        current_node = current_node->next;
    }
    return false;
}
template<class T>
bool List342<T>::Peek(T target, T& result) const 
{
    if(head_ == nullptr) return false;
    if(*head_->data == target)
    {
        result = *head_->data;
        return true;
    } 
    Node<T>* current_node = head_;
    while(current_node->next != nullptr)
    {
        current_node = current_node->next;
        if(*current_node->data == target) 
        {
            result = *current_node->data;
            return true;
        }
    }
    return false;
}
template<class T>
int List342<T>::Size() const
{
    if(head_ == nullptr) return 0;
    Node<T>* current_node = head_;
    int size = 1;
    while(current_node->next != nullptr)
    {
        current_node = current_node->next;
        size++;
    }
    return size;
}
template<class T>
void List342<T>::DeleteList()
{
    while(head_ != nullptr) // needs to also delete objects in the list
    {
        Node<T>* current_node = head_;
        head_ = head_->next;
        delete current_node->data;
        delete current_node;
    }
}
template<class T>
bool List342<T>::Merge(List342& list1)
{
    //Checks front of lists
    if(*this == list1) return false;
    if(head_ == nullptr || list1.head_ == nullptr) return false;
    Node<T>* current_node = head_;
    Node<T>* other_current_node = list1.head_;
    T result;
    //Traverses both sorted lists to merge them together
    while(current_node->next != nullptr && other_current_node != nullptr)
    {
        if(!Peek(*other_current_node->data, result))
        {
            if(*other_current_node->data < *current_node->next->data)
            {
                Node<T>* insert_node = new Node<T>();
                T insert_data = *other_current_node->data;
                insert_node->data = new T(insert_data);
                if(*other_current_node->data < *current_node->data)
                {
                    //Adds smaller values to front of list
                    insert_node->next = current_node;
                    head_ = insert_node;
                    current_node = head_;
                }
                else
                {
                    insert_node->next = current_node->next;
                    current_node->next = insert_node;
                }
                other_current_node = other_current_node->next;
            }
            else current_node = current_node->next;
        }
        else other_current_node = other_current_node->next;
    }
    //Adds extra values from extra list
    while(other_current_node != nullptr) 
    {
        T insert_data = *other_current_node->data;
        current_node->next = new Node<T>();
        current_node->next->data = new T(insert_data);
        current_node = current_node->next;
        other_current_node = other_current_node->next;
    
    }
    list1.DeleteList();
    return true;
}
//Operator Overloads
template<class T>
List342<T> List342<T>::operator+(List342& rhs) const //make more efficient i guess
{
    List342<T> new_list = *this;
    new_list += rhs;
    return new_list;
}
template<class T>
//This uses pretty much the same code as merge, it just preserves the second list
List342<T>& List342<T>::operator+=(List342& other)
{
    List342<T> temp_list = other;
    Merge(temp_list);
    return *this;
}
template<class T>
bool List342<T>::operator==(List342& other) const
{
    if(Size() != other.Size()) return false;
    if(*head_->data != *other.head_->data) return false;
    Node<T>* current_node = head_;
    Node<T>* other_current_node = other.head_;
    while(current_node->next != nullptr)
    {
        current_node = current_node->next;
        other_current_node = other_current_node->next;
        if(*current_node->data != *other_current_node->data) return false;
    }
    return true;
}
template<class T>
bool List342<T>::operator!=(List342& other) const
{
    if(*this == other) return false;
    else return true;
}
template<class T>
ostream& operator <<(ostream& stream, List342<T>& list)
{
    if(list.head_ == nullptr) return stream;
    Node<T>* current_node = list.head_;
    stream << *current_node->data;
    while(current_node->next != nullptr)
    {
        current_node = current_node->next;
        stream << *current_node->data;
    }
    return stream;
}
template<class T>
List342<T>& List342<T>::operator=(const List342<T>& source)
{
    Node<T>* source_node; 
    Node<T>* destination_node;

    //Check if assigning to self
    if(this == &source) return *this;
    //Check if list is empty
    if(source.head_ == nullptr) return *this;

    //Empty desitnation stack of elements
    DeleteList();
    //Copy over first node from source
    destination_node = new Node<T>();
    T insert_data = *source.head_->data;
    destination_node->data = new T(insert_data);
    head_ = destination_node;
    source_node = source.head_->next;
    //Loop and copy over all other nodes
    while(source_node != nullptr)
    {
        destination_node->next = new Node<T>();
        destination_node = destination_node->next;
        T new_insert_data = *source_node->data;
        destination_node->data = new T(new_insert_data);
        source_node = source_node->next;
    }
    return *this;
}
#endif