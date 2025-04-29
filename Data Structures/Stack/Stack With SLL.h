#ifndef DATA_STRUCTURES_STACK_WITH_SLL_H
#define DATA_STRUCTURES_STACK_WITH_SLL_H

#include <bits\stdc++.h>
#include "../Linked Lists/Unordered SLL.h"
using namespace std;


template <class T>
class Stack{
private:
    unorderedLinkedList <T> list;
public:

    bool isEmpty() const // O(1)
    {
        return list.isEmptyList();
    }

    void clear() // O(n)
    {
        list.destroyList();
    }

    void print() const // O(n)
    {
        if(isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "[ ";
        list.print();
        cout << "]\n";
    }

    T Top() const // O(1)
    {
        if(isEmpty())
        {
            cout << "Stack is empty in top\n";
            return -1;
        }
        return list.front();
    }

    void push(const T & item) // O(1)
    {
        list.insertFirst(item);
    }

    T pop() // O(1)
    {
        if(isEmpty())
        {
            cout << "Stack is empty in pop\n";
            return -1;
        }
        T item = list.front();
        list.deleteFirst();
        return item;
    }

    ~Stack()
    {
        clear();
    }
};

#endif //DATA_STRUCTURES_STACK_WITH_SLL_H
