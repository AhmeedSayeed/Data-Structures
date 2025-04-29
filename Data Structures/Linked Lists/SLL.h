#ifndef DATA_STRUCTURES_SLL_H
#define DATA_STRUCTURES_SLL_H

#include <bits\stdc++.h>
using namespace std;

template <class T>
struct node{
    T info;
    node* link;
};

template <class T>
class linkedListIterator{
private:
    node <T> *current;
public:
    linkedListIterator()
    {
        current = NULL;
    }
    linkedListIterator(node <T> *ptr)
    {
        current = ptr;
    }
    linkedListIterator<T> operator*()
    {
        return current->info;
    }
    linkedListIterator<T> operator++()
    {
        current = current->link;
        return *this;
    }
    bool operator==(const linkedListIterator<T> right) const
    {
        return (current == right.current);
    }
    bool operator!=(const linkedListIterator<T> right) const
    {
        return (current != right.current);
    }
};

template <class T>
class linkedList{
protected:
    node <T>* first;
    node <T>* last;
    int count;
public:
    linkedList() // O(1)
    {
        first = NULL;
        last = NULL;
        count = 0;
    }

    bool isEmptyList() const // O(1)
    {
        return !count;
    }

    void destroyList() // O(n)
    {
        node <T> *temp;
        while(first != NULL)
        {
            temp = first;
            first = first->link;
            delete temp;
        }
        last = NULL;
        count = 0;
    }

    int length() const // O(1)
    {
        return count;
    }

    T front() const // O(1)
    {
        assert(first != NULL);
        return first->info;
    }

    T back() const // O(1)
    {
        assert(last != NULL);
        return last->info;
    }

    linkedListIterator<T> begin() const // O(1)
    {
        return linkedListIterator<T>(first);
    }

    linkedListIterator<T> end() const // O(1)
    {
        return linkedListIterator<T>(NULL);
    }

    void initializeList() // O(n)
    {
        destroyList();
    }

    void print() const // O(n)
    {
        node <T> *current;
        current = first;
        while(current != NULL)
        {
            cout << current->info << ' ';
            current = current->link;
        }
        delete current;
    }

    ~linkedList() // O(n)
    {
        destroyList();
    }

    linkedList(const linkedList<T> & otherList) // O(n)
    {
        first = NULL;
        copyList(otherList);
    }

    const linkedList<T>& operator= (const linkedList<T> & otherList) // O(n)
    {
        if(this != &otherList)
            copyList(otherList);
        return *this;
    }

private:
    void copyList(const linkedList<T> & otherList) // O(n)
    {
        this->count = otherList.count;
        if(first != NULL)
            destroyList();
        if(otherList.first != NULL)
        {
            node <T> *current;
            node <T> *newnode;
            current = otherList.first;
            first = new node<T>();
            first->info = current->info;
            first->link = NULL;
            last = first;
            current = current->link;
            while(current != NULL)
            {
                newnode = new node<T>;
                newnode->info = current->info;
                newnode->link = NULL;
                last->link = newnode;
                last = newnode;
                current = current->link;
            }
        }
    }
};

#endif //DATA_STRUCTURES_SLL_H
