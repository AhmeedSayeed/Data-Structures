#ifndef DATA_STRUCTURES_BST_H
#define DATA_STRUCTURES_BST_H

#include <bits\stdc++.h>
using namespace std;

template <class T>
struct BSTNode{
    T key;
    BSTNode <T> *right;
    BSTNode <T> *left;

    BSTNode()
    {
        key = 0;
        left = NULL;
        right = NULL;
    }

    BSTNode(const T & val , BSTNode <T> *r = NULL , BSTNode <T> *l = NULL)
    {
        key = val;
        right = r;
        left = l;
    }
};

template <class T>
class BST{
protected:
    BSTNode <T> *root;
public:
    BST() // O(1)
    {
        root = NULL;
    }

    bool isEmpty() // O(1)
    {
        return root == NULL;
    }

    BSTNode <T>* getRoot() // O(1)
    {
        return root;
    }

    void clear() // O(log(n)) , O(n)
    {
        if(root == NULL)
            return;
        queue <BSTNode<T>*> q;
        q.push(root);

        while(!q.empty())
        {
            BSTNode<T> *current = q.front();
            q.pop();
            if(current->left != NULL)
                q.push(current->left);
            if(current->right != NULL)
                q.push(current->right);
            delete current;
        }
        root = NULL;
    }

    BSTNode<T>* search(const T val) // O(log(n)) , O(n)
    {
        if(root == NULL)
            return NULL;
        if(root->key == val)
            return root;
        BSTNode <T> *current = root;
        while(current != NULL)
        {
            if(current->key == val)
                return current;
            else if(current->key < val)
                current = current->right;
            else
                current = current->left;
        }
        return NULL;
    }

    void levelOrder() // O(log(n)) , O(n)
    {
        // BFS
        if(root == NULL)
        {
            cout << "Binary Search Tree is empty\n";
            return;
        }
        queue <BSTNode<T>*> q;
        q.push(root);

        while(!q.empty())
        {
            BSTNode<T> *current = q.front();
            q.pop();
            if(current->left != NULL)
                q.push(current->left);
            if(current->right != NULL)
                q.push(current->right);
            cout << current->key << ' ';
        }
    }

    void preOrder(BSTNode<T> *p) // O(log(n)) , O(n)
    {
        // DFS
        if(p == NULL)
            return;
        cout << p->key << ' ';
        preOrder(p->left);
        preOrder(p->right);
    }

    void inOrder(BSTNode<T> *p) // O(log(n)) , O(n)
    {
        // DFS
        if(p == NULL)
            return;
        inOrder(p->left);
        cout << p->key << ' ';
        inOrder(p->right);
    }

    void postOrder(BSTNode<T> *p) // O(log(n)) , O(n)
    {
        // DFS
        if(p == NULL)
            return;
        postOrder(p->left);
        postOrder(p->right);
        cout << p->key << ' ';
    }

    T getMax() // O(log(n)) , O(n)
    {
        if(isEmpty())
        {
            cout << "Binary Search Tree is empty\n";
            return -1;
        }
        BSTNode <T> *current = root;
        T item;
        while(current != NULL)
        {
            item = current->key;
            current = current->right;
        }
        return item;
    }

    T getMin() // O(log(n)) , O(n)
    {
        if(isEmpty())
        {
            cout << "Binary Search Tree is empty\n";
            return -1;
        }
        BSTNode <T> *current = root;
        T item;
        while(current != NULL)
        {
            item = current->key;
            current = current->left;
        }
        return item;
    }

    T successorForRoot() // O(log(n)) , O(n)
    {
        if(isEmpty())
        {
            cout << "Binary Search Tree is empty\n";
            return -1;
        }
        BSTNode <T> *current = root->right;
        if(current == NULL)
        {
            cout << "No Successor for root\n";
            return root->key;
        }
        T item;
        while(current != NULL)
        {
            item = current->key;
            current = current->left;
        }
        return item;
    }

    T predecessorForRoot() // O(log(n)) , O(n)
    {
        if(isEmpty())
        {
            cout << "Binary Search Tree is empty\n";
            return -1;
        }
        BSTNode <T> *current = root->left;
        if(current == NULL)
        {
            cout << "No Predecessor for root\n";
            return root->key;
        }
        T item;
        while(current != NULL)
        {
            item = current->key;
            current = current->right;
        }
        return item;
    }

    void insert(const T & val) // O(log(n)) , O(n)
    {
        BSTNode <T> *current = root , *prev;
        while(current != NULL)
        {
            prev = current;
            if(current->key < val)
                current = current->right;
            else
                current = current->left;
        }
        if(root == NULL)
            root = new BSTNode<T>(val);
        else if(prev->key < val)
            prev->right = new BSTNode<T>(val);
        else
            prev->left = new BSTNode<T>(val);
    }

    BSTNode<T>* searchParent(BSTNode<T>* node) // O(log(n)) , O(n)
    {
        if(node == NULL || root == NULL)
            return NULL;
        BSTNode <T> *current = root , *prev = NULL;
        while(current != NULL)
        {
            if(current == node)
                return prev;
            prev = current;
            if(current->key < node->key)
                current = current->right;
            else
                current = current->left;
        }
        if(current == NULL)
            return NULL;
        return prev;
    }

    void deleteNode(BSTNode<T>* node) // O(log(n)) , O(n)
    {
        if(node == NULL)
            return;
        BSTNode <T> *tmp = node , *prev = searchParent(node);
        if(node->left == NULL)
        {
            if(node == prev->left)
                prev->left = node->right;
            else
                prev->right = node->right;
        }
        else if(node->right == NULL)
        {
            if(node == prev->left)
                prev->left = node->left;
            else
                prev->right = node->left;
        }
        else
        {
            tmp = node->left;
            prev = node;
            while(tmp->right != NULL)
            {
                prev = tmp;
                tmp = tmp->right;
            }
            node->key = tmp->key;
            if(prev == node)
                prev->left = tmp->left;
            else
                prev->right = tmp->left;
        }
        delete tmp;
    }

    ~BST()
    {
        clear();
    }
};

#endif //DATA_STRUCTURES_BST_H
