//
// Created by Дима Шестаков on 15.01.2021.
//

#ifndef C___AVL_H
#define C___AVL_H


#include<iostream>

using namespace std;


struct node //Create the class of tree's nodes, cause it is balanced, node should have height field
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


unsigned char height(node* p) // Return height of the node
{
    return p ? p->height : 0;
}

int balance_factor(node* p) // Return differ beetwen subtrees, the main indicator in AVL
{
    return height(p->right)-height(p->left);
}


void fixHeight(node* p) //Fix the height of node, obviously parent's should be max of his children's height plus 1
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr ? hl : hr)+1;
}


node* rotateright(node* root) // p        ====>       q
{                           //  /\                   / \
    node* p = root;        //  q  r                 a   p
    node* q = p->left;    //  / \                      / \
    p->left = q->right;  //  a   b                     b  r
    q->right = p;  
    fixHeight(p);
    fixHeight(q);
    return q;
}


node* rotateleft(node* root) // q        ====>         p
{                           // / \                    / \
    node* q = root;        // l   p                  q   b
    node* p = q->right;   //     / \                / \
    q->right = p->left;  //     a   b              l   a
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}


node* balance(node* root) // To balance AVL-tree we sould compose right rotation and left rotation to 
{                         // get Big right rotation and Big left rotation
    node* p = root;       // Left: if right child higher than left
    fixHeight(p);        //  Right: if left child heigher than right
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


node* insert(node* root, int k) //because avl is also search tree right > parent && left < parent
{                              // so if new key is bigger than root we go to right subtree
    node* p = root;           //  else go to left subtree
    if(!p) return new node(k);
    if(k > p->key)
        p->right = insert(p->right, k);
    else
        p->left = insert(p->left, k);
    return balance(p);
}


node* findMinNode(node* root) // if think it is obvious
{
    node* p = root;
    return p->left ? findMinNode(p->left) : p; 
}


node* removeMin(node* root) // look at findMinNode
{
    node* p = root;
    if(p->left == nullptr)
        return p->right;
    p->left = removeMin(p->left);
    return balance(p);
}


node* remove(node* root, int k) // locate determine node, remove it and update and balance its children
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

void inOrder(node* root) // just print AVL-tree;)
{
    node* p = root;
    if(!p)
        return;
    inOrder(p->left);
    cout << p->key << endl;
    inOrder(p->right);
}
#endif //C___AVL_H
