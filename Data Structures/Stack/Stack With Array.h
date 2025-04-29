#ifndef DATA_STRUCTURES_STACK_WITH_ARRAY_H
#define DATA_STRUCTURES_STACK_WITH_ARRAY_H

#include <bits\stdc++.h>
using namespace std;


template <class T , int size = 100>
class Stack{
private:
    int top;
    T arr[size];
public:
    Stack() : top(-1) {} // O(1)

    bool isEmpty() const // O(1)
    {
        return top == -1;
    }

    bool isFull() const // O(1)
    {
        return top == size;
    }

    void clear() // O(1)
    {
        top = -1;
    }

    T Top() const // O(1)
    {
        if(isEmpty())
        {
            cout << "Stack is empty in top\n";
            return -1;
        }
        return arr[top];
    }

    T pop() // O(1)
    {
        if(isEmpty())
        {
            cout << "Stack is empty in top\n";
            return -1;
        }
        return arr[top--];
    }

    void push(T item) // O(1)
    {
        if(isFull())
            cout << "Stack is full in push\n";
        else
            arr[++top] = item;
    }

    void print() const // O(n)
    {
        cout << "[ ";
        for (int i = top; ~i ; --i)
            cout << arr[i] << ' ';
        cout << "]\n";
    }
};

#endif //DATA_STRUCTURES_STACK_WITH_ARRAY_H
