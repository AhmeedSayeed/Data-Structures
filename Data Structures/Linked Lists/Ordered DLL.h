#ifndef DATA_STRUCTURES_ORDERED_DLL_H
#define DATA_STRUCTURES_ORDERED_DLL_H

#include <bits\stdc++.h>
using namespace std;

template <class T>
struct node{
    T info;
    node* nxt;
    node* prv;
};

template <class T>
class doublyLinkedList{
protected:
    node <T> *first;
    node <T> *last;
    int count;
public:
    doublyLinkedList()
    {
        first = NULL;
        last = NULL;
        count = 0;
    }

    const doublyLinkedList<T>& operator=(const doublyLinkedList<T> & otherList)
    {
        if(this != &otherList)
            copyList(otherList);
        return *this;
    }

    doublyLinkedList (const doublyLinkedList <T> & otherList)
    {
        first = NULL;
        copyList(otherList);
    }


    bool isEmptyList() const
    {
        return !count;
    }

    void destroy()
    {
        node <T> *temp;
        while(first != NULL)
        {
            temp = first;
            first = first->nxt;
            delete temp;
        }
        last = NULL;
        count = 0;
    }

    void initializeList()
    {
        destroy();
    }

    int length() const
    {
        return count;
    }

    void print() const
    {
        node <T> *current;
        current = first;
        while(current != NULL)
        {
            cout << current->info << ' ';
            current = current->nxt;
        }
    }

    void reversePrint() const
    {
        node <T> *current;
        current = last;
        while(current != NULL)
        {
            cout << current->info << ' ';
            current = current->prv;
        }
    }

    bool search(const T & item) const
    {
        node <T> *current;
        current = first;
        bool found = 0;
        while(current != NULL)
        {
            if(current->info >= item)
            {
                found = 1;
                break;
            }
            current = current->nxt;
        }
        if(found)
            found = (current->info == item);
        return found;
    }

    T front() const
    {
        assert(first != NULL);
        return first->info;
    }

    T back() const
    {
        assert(last != NULL);
        return last->info;
    }

    void insert(const T & item)
    {
        node <T> *trailCurrent , *current , *newnode;
        newnode = new node<T>;
        newnode->info = item;
        newnode->nxt = NULL;
        newnode->prv = NULL;
        if(first == NULL)
            first = last = newnode;
        else
        {
            current = first;
            while(current != NULL)
            {
                if(current->info >= item)
                    break;
                trailCurrent = current;
                current = current->nxt;
            }
            if(current == NULL)
            {
                last->nxt = newnode;
                newnode->prv = last;
                last = newnode;
            }
            else if(current == first)
            {
                first->prv = newnode;
                newnode->nxt = first;
                first = newnode;
            }
            else
            {
                newnode->nxt = current;
                current->prv = newnode;
                newnode->prv = trailCurrent;
                trailCurrent->nxt = newnode;
            }
        }
        count++;
    }

    void deleteNode(const T & item)
    {
        node <T> *trailCurrent , *current;
        if(first == NULL)
            cout << "Cannot delete from an empty list\n";
        else
        {
            current = first;
            while(current != NULL)
            {
                if(current->info >= item)
                    break;
                trailCurrent = current;
                current = current->nxt;
            }
            if(current != NULL && current->info == item)
            {
                if(current == first)
                {
                    first = first->nxt;
                    if(first != NULL)
                        first->prv = NULL;
                    else
                        last = NULL;
                }
                else
                {
                    trailCurrent->nxt = current->nxt;
                    if(current == last)
                        last = trailCurrent;
                    else
                        current->nxt->prv = trailCurrent;
                }
                delete current;
                count--;
            }
            else
                cout << "The item is to be deleted is not in the list\n";
        }
    }

    ~doublyLinkedList()
    {
        destroy();
    }

private:
    void copyList(const doublyLinkedList<T> & otherList)
    {
        destroy();
        if(otherList.first == NULL)
            return;
        count = otherList.count;
        node <T> *current , *newnode;
        current = otherList.first;
        first = new node<T>;
        first->info = current->info;
        first->nxt = NULL;
        first->prv = NULL;
        last = first;
        current = current->nxt;
        while(current != NULL)
        {
            newnode = new node<T>;
            newnode->info = current->info;
            newnode->nxt = NULL;
            newnode->prv = last;
            last->nxt = newnode;
            last = newnode;
            current = current->nxt;
        }
    }

};

#endif //DATA_STRUCTURES_ORDERED_DLL_H
