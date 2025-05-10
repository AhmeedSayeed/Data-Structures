#ifndef DATA_STRUCTURES_VECTOR_H
#define DATA_STRUCTURES_VECTOR_H

#include <bits\stdc++.h>
using namespace std;

template <class T>
class Vector {
private:
    int sz;
    int capacity;
    T *data;

public:
    Vector() : sz(0) , capacity(1)
    {
        data = new T[capacity];
    }

    Vector(int n) : sz(n) , capacity(n)
    {
        data = new T[capacity];
    }

    bool empty() { return !sz; }

    int size() { return sz; }

    void push_back(T val)
    {
        if(sz == capacity)
        {
            capacity <<= 1;
            T *newData = new T[capacity];
            for (int i = 0; i < sz; ++i)
                newData[i] = data[i];
            delete [] data;
            data = newData;
        }
        data[sz++] = val;
    }

    void pop_back()
    {
        if(empty())
            throw out_of_range("Vector is empty");
        sz--;
    }

    T& operator[](int index)
    {
        return data[index];
    }

    T& front()
    {
        if(empty())
            throw out_of_range("Vector is empty");
        return data[0];
    }

    T& back()
    {
        if(empty())
            throw out_of_range("Vector is empty");
        return data[sz-1];
    }
    
    ~Vector()
    {
        delete [] data;
    }
};

#endif //DATA_STRUCTURES_VECTOR_H
