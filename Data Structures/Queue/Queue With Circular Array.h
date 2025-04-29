#ifndef DATA_STRUCTURES_QUEUE_WITH_CIRCULAR_ARRAY_H
#define DATA_STRUCTURES_QUEUE_WITH_CIRCULAR_ARRAY_H

#include <bits\stdc++.h>
using namespace std;


template <class T , unsigned int size = 100>
class Queue{
private:
    int first;
    int last;
    int count;
    int arr[size];
public:
    Queue() : first(0) , last(size-1) , count(0) {} // O(1)

    bool isEmpty() // O(1)
    {
        return !count;
    }

    bool isFull() // O(1)
    {
        return count == size;
    }

    void clear() // O(1)
    {
        count = 0;
        first = 0;
        last = size-1;
    }

    T First() // O(1)
    {
        assert(!isEmpty());
        return arr[first];
    }

    void enqueue(const T & item) // O(1)
    {
        if(isFull())
        {
            cout << "Queue is full cannot enqueue\n";
            return;
        }
        last = (last + 1) % size;
        arr[last] = item;
        count++;
    }

    T dequeue() // O(1)
    {
        if(isEmpty())
        {
            cout << "Queue is empty cannot dequeue\n";
            return -1;
        }
        T item = arr[first];
        first = (first + 1) % size;
        count--;
        return item;
    }

    void print() // O(n)
    {
        if(isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "[ ";
        for (int i = first; i != last; i = (i+1) % size)
            cout << arr[i] << ' ';
        cout << arr[last] << ' ';
        cout << "]\n";
    }
};

#endif //DATA_STRUCTURES_QUEUE_WITH_CIRCULAR_ARRAY_H
