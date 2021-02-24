//
// Created by Дима Шестаков on 07.01.2021.
//

#ifndef C___BST_H
#define C___BST_H

#endif //C___BST_H

#include<iostream>

using namespace std;

template<class T>
struct Node
{
  private:  
    Node* left;
    Node* right;
    T val;
  public:
    Node(Node* l, Node* r, T& x) : left(l), right(r), val(x)
    {}
    explicit Node(T& x) : val(x)
    {
        left = nullptr;
        right = nullptr;
    }

};

template<class T>
class BST
{
    Node<T>* root;
  public:
    explicit BST(T x)
    {
        root = new Node(x);
    }
    void add(T x , Node<T>* v);
    Node<T>* find(T x , Node<T>* v);
    T min();
    T max();

};

template<class T>
void BST<T>::add(T x , Node<T>* v)
{
    if(!root)
        v = new Node(x);
    if(x < root->val)
    {
        if(root->left)
            add(x,root->left);
        else
            root->left = new Node(x);
    }else{
        if(root->right)
            add(x,root->right);
        else
            root->right = new Node(x);
    }
}

template<class T>
Node<T>* BST<T>::find(T x,  Node<T>* v)
{
    if(root->val == x || root == nullptr)
        return root;
    if(x > root->val)
        return find(x, root>right);
    else
        return find(x, root->left);
}

template<class T>
T BST<T>::max() {
    Node<T>* ptr = root;
    while(ptr->r != nullptr && ptr->l != nullptr)
    {
        if(ptr->r == nullptr)
            ptr = ptr->l;
        else
            ptr = ptr->r;
    }
    return ptr->x;
}

template<class T>
T BST<T>::min()
{
    Node<T>* ptr = root;
    while(ptr->r != nullptr && ptr->l != nullptr)
    {
        if(ptr->l == nullptr)
            ptr = ptr->r;
        else
            ptr = ptr->l;
    }
    return ptr->x;
}

template<class T>
void inOrder(Node<T>* v) {
    if(!v)
        return;
    inOrder(v->left);
    cout << v->val << endl;
    inOrder(v->right);
}

template<class T>
Node<T>* findMinNode(Node<T>* root)
{
    Node<T>* tmp = root;
    while(tmp->left != nullptr)
        tmp = tmp->left;
    return tmp;
}

template<class T>
Node<T>* remove(Node<T>* tree, T k)
{
    if(tree == nullptr)
        return tree;
    if(tree->val < k)
        tree->right = remove(tree->right, k);
    if(tree->val > k)
        tree->left = remove(tree->left, k);
    if(tree->val == k)
    {
        if(tree->left == nullptr && tree->right == nullptr)
        {
            delete tree;
            tree = nullptr;
        }
        else if(tree->left == nullptr)
        {
            Node<T>* tmp = tree;
            tree = tree->right;
            delete tmp;
        }
        else if(tree->right == nullptr)
        {
            Node<T>* tmp = tree;
            tree = tree->left;
            delete tmp;
        } else{
            Node<T>* temp = findMinNode(tree->right);
            tree->val = temp->val;
            tree->right = remove(tree->right, temp->val);
        }
        
    }
    return tree;
}
