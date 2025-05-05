#ifndef DATA_STRUCTURES_HEAP_H
#define DATA_STRUCTURES_HEAP_H

#include <bits\stdc++.h>
#include "../Vector/Vector.h"
using namespace std;

template <class T, class Compare = less<T>>
class Heap {
protected:
    Vector <T> heap;
    Compare comp;
    int left(int i) { return 2*i + 1; }
    int right(int i) { return 2*i + 2; }
    int parent(int i) { return (i-1) / 2; }
    bool compare(T a, T b) { return comp(a,b); }

    void buildHeap() // O(nlog(n))
    {
        for (int i = heap.size()/2 - 1; i >= 0; --i)
            heapify(heap, i, heap.size());
    }

    void heapify(Vector <T> & heap, int i, int n) // O(log(n))
    {
        int l = left(i);
        int r = right(i);
        int max = i;
        if(l < n && compare(heap[max],heap[l]))
            max = l;
        if(r < n && compare(heap[max],heap[r]))
            max = r;
        if(max != i)
        {
            swap(heap[i], heap[max]);
            heapify(heap, max, n);
        }
    }

public:
    Heap() {}

    Heap(vector <T> v) // O(nlog(n))
    {
        for (int i = 0; i < v.size(); ++i)
            heap.push_back(v[i]);
        buildHeap();
    }

    bool isEmpty() { return heap.empty(); } // O(1)

    void display() // O(n)
    {
        cout << "[ ";
        for (int i = 0; i < heap.size(); ++i)
            cout << heap[i] << ' ';
        cout << "]\n";
    }

    T getTop() { return heap[0]; }

    void deleteTop() // O(log(n))
    {
        swap(heap.front(), heap.back());
        heap.pop_back();
        heapify(heap, 0, heap.size());
    }

    void insert(T val) // O(log(n))
    {
        int i = heap.size();
        heap.push_back(val);
        while(i > 0 && compare(heap[parent(i)], heap[i]))
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    T extractTop() // O(log(n))
    {
        T top = getTop();
        deleteTop();
        return top;
    }

    void changeKey(int i, T key) // O(log(n))
    {
        if(!compare(heap[i], key) && heap[i] != key)
            throw invalid_argument("New key is violate heap Property");
        heap[i] = key;
        while(i > 0 && compare(heap[parent(i)], heap[i]))
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }

    vector <T> heapSort() // O(nlog(n))
    {
        Vector <T> v;
        for (int i = 0; i < heap.size(); ++i)
            v.push_back(heap[i]);
        for (int i = v.size()-1; i > 0; --i)
        {
            swap(v[i], v[0]);
            heapify(v, 0, i);
        }
        vector <T> v1;
        for (int i = 0; i < heap.size(); ++i)
            v1.push_back(heap[i]);
        return v1;
    }
};

#endif //DATA_STRUCTURES_HEAP_H
