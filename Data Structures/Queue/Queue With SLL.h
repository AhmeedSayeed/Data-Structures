#ifndef DATA_STRUCTURES_QUEUE_WITH_SLL_H
#define DATA_STRUCTURES_QUEUE_WITH_SLL_H

#include <bits\stdc++.h>
#include "../Linked Lists/Unordered SLL.h"
using namespace std;

template <class T>
class Queue{
private:
    unorderedLinkedList <T> list;
public:

    bool isEmpty() // O(1)
    {
        return list.isEmptyList();
    }

    void clear() // O(1)
    {
        list.destroyList();
    }

    T First() // O(1)
    {
        assert(!isEmpty());
        return list.front();
    }

    void enqueue(const T & item) // O(1)
    {
        list.insertLast(item);
    }

    T dequeue() // O(1)
    {
        if(isEmpty())
        {
            cout << "Queue is empty cannot dequeue\n";
            return -1;
        }
        T item = list.front();
        list.deleteFirst();
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
        list.print();
        cout << "]\n";
    }

    ~Queue()
    {
        clear();
    }
};

#endif //DATA_STRUCTURES_QUEUE_WITH_SLL_H
