#ifndef DATA_STRUCTURES_ORDERED_SLL_H
#define DATA_STRUCTURES_ORDERED_SLL_H

#include <bits\stdc++.h>
#include "SLL.h"
using namespace std;


template <class T>
class orderedLinkedList : public linkedList<T>{
public:
    bool search(const T & item) const // O(n)
    {
        node <T> *current;
        current = this->first;
        bool found = 0;
        while(current != NULL)
        {
            if(current->info >= item)
            {
                found = 1;
                break;
            }
            current = current->link;
        }
        if(found)
            found = (current->info == item);
        return found;
    }

    void insert(const T & item) // O(n)
    {
        node <T> *current , *trailCurrent;
        node <T> *newnode;
        newnode = new node<T>;
        newnode->info = item;
        newnode->link = NULL;
        current = this->first;
        while(current != NULL)
        {
            if(current->info >= item)
                break;
            trailCurrent = current;
            current = current->link;
        }
        if(this->first == NULL)
        {
            this->first = newnode;
            this->last = newnode;
        }
        else if(current == this->first)
        {
            newnode->link = this->first;
            this->first = newnode;
        }
        else
        {
            trailCurrent->link = newnode;
            newnode->link = current;
            if(current == NULL)
                this->last = newnode;
        }
        this->count++;
    }

    void deleteNode(const T & item) // O(n)
    {
        node <T> *trailCurrent , *current;
        if(this->first == NULL)
            cout << "Cannot delete from an empty list\n";
        else
        {
            current = this->first;
            while(current != NULL)
            {
                if(current->info >= item)
                    break;
                trailCurrent = current;
                current = current->link;
            }
            if(current != NULL && current->info == item)
            {
                if(current == this->first)
                {
                    this->first = this->first->link;
                    if(this->first == NULL)
                        this->last = NULL;
                }
                else
                {
                    trailCurrent->link = current->link;
                    if(current == this->last)
                        this->last = trailCurrent;
                }
                delete current;
                this->count--;
            }
            else
                cout << "The item is to be deleted is not in the list\n";
        }
    }
};

#endif //DATA_STRUCTURES_ORDERED_SLL_H
