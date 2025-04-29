#ifndef DATA_STRUCTURES_UNORDERED_SLL_H
#define DATA_STRUCTURES_UNORDERED_SLL_H

#include <bits\stdc++.h>
#include "SLL.h"
using namespace std;


template <class T>
class unorderedLinkedList : public linkedList<T>{
public:
    bool search(const T & item) const // O(n)
    {
        node <T> *current;
        current = this->first;
        while(current != NULL)
        {
            if(current->info == item)
                return true;
            current = current->link;
        }
        return false;
    }

    void insertFirst(const T & item) // O(1)
    {
        node <T> *newnode;
        newnode = new node<T>;
        newnode->info = item;
        newnode->link = this->first;
        if(this->first == NULL)
            this->last = newnode;
        this->first = newnode;
        this->count++;
    }

    void insertLast(const T & item) // O(1)
    {
        node <T> *newnode;
        newnode = new node<T>;
        newnode->info = item;
        newnode->link = NULL;
        if(this->first == NULL)
            this->first = newnode;
        else
            this->last->link = newnode;
        this->last = newnode;
        this->count++;
    }

    void deleteNode(const T & item) // O(n)
    {
        node <T> *current;
        node <T> *trailCurrent;
        if(this->first == NULL)
            cout << "Cannot delete from empty list\n";
        else
        {
            if(this->first->info == item)
            {
                trailCurrent = this->first;
                this->first = this->first->link;
                if(this->first == NULL)
                    this->last = NULL;
                delete trailCurrent;
                this->count--;
            }
            else
            {
                bool found = 0;
                trailCurrent = this->first;
                current = this->first->link;
                while(current != NULL)
                {
                    if (current->info == item)
                    {
                        found = 1;
                        break;
                    }
                    trailCurrent = current;
                    current = current->link;
                }
                if(found)
                {
                    trailCurrent->link = current->link;
                    if(this->last == current)
                        this->last = trailCurrent;
                    delete current;
                    this->count--;
                }
                else
                    cout << "The item is to be deleted is not in the list\n";
            }
        }
    }

    void deleteFirst() // O(1)
    {
        if(this->first == NULL)
            cout << "Cannot delete from an empty list\n";
        else
        {
            node <T> *current;
            current = this->first;
            this->first = this->first->link;
            if(this->first == NULL)
                this->last = NULL;
            delete current;
        }
    }
};

#endif //DATA_STRUCTURES_UNORDERED_SLL_H
