//
// Created by Дима Шестаков on 15.01.2021.
//

#ifndef C___AVL_H
#define C___AVL_H

#endif //C___AVL_H
#include<iostream>

using namespace std;


struct node
{
    int key;
    unsigned char height;
    node* right;
    node* left;
    node(int k)
    {
        key = k;
        height = 1;
        right = left = nullptr;
    }
};


unsigned char height(node* p)
{
    return p ? p->height : 0;
}

int balance_factor(node* p)
{
    return height(p->right)-height(p->left);
}


void fixHeight(node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr ? hl : hr)+1;
}


node* rotateright(node* root)
{
    node* p = root;
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}


node* rotateleft(node* root)
{
    node* q = root;
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}


node* balance(node* root)
{
    node* p = root;
    fixHeight(p);
    if(balance_factor(p) == 2)
    {
        if(balance_factor(p->right) < 0)
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if(balance_factor(p) == -2)
    {
        if(balance_factor(p->left) > 0)
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}


node* insert(node* root, int k)
{
    node* p = root;
    if(!p) return new node(k);
    if(k > p->key)
        p->right = insert(p->right, k);
    else
        p->left = insert(p->left, k);
    return balance(p);
}


node* findMinNode(node* root)
{
    node* p = root;
    return p->left ? findMinNode(p->left) : p;
}


node* removeMin(node* root)
{
    node* p = root;
    if(p->left == nullptr)
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}


node* remove(node* root, int k)
{
    node* p = root;
    if(!p)
        return nullptr;
    if(k < p->key)
        p->left = remove(p->left, k);
    else if(k > p->key)
        p->right = remove(p->right, k);
    else{
        node* q = p->left;
        node* r = p->right;
        delete p;
        if(!r)
            return q;
        node* min = findMinNode(r);
        min->left = q;
        min->right = removeMin(r);
        return balance(min);
    }
    return balance(p);
}

void inOrder(node* root)
{
    node* p = root;
    if(!p)
        return;
    inOrder(p->left);
    cout << p->key << endl;
    inOrder(p->right);
}