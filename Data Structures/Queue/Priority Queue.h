#ifndef DATA_STRUCTURES_PRIORITY_QUEUE_H
#define DATA_STRUCTURES_PRIORITY_QUEUE_H

#include <bits\stdc++.h>
#include "../Heap/Heap.h"
using namespace std;


template <class T, class Compare = less<T>>
class PriorityQueue {
private:
    Heap <T, Compare> heap;

public:
    bool isEmpty() { return heap.isEmpty(); } // O(1)

    void push(T val) // O(log(n))
    {
        heap.insert(val);
    }

    T pop() // O(log(n))
    {
        return heap.extractTop();
    }

    T top() // O(1)
    {
        return heap.getTop();
    }
};

#endif //DATA_STRUCTURES_PRIORITY_QUEUE_H
