//
// Created by Дима Шестаков on 03.02.2021.
//

#ifndef ALGO_HEAP_H
#define ALGO_HEAP_H


#include<iostream>


class Heap
{
private:
    static const int SIZE = 100;
protected:
    int* h;
    int heap_size;
public:
    Heap() : heap_size(0)
    {
        h = new int[SIZE];
    }

    Heap(int* heap, int hs) : heap_size(hs)
    {
        h = heap;
    }

    void buildHeap();
    void out();
    void outHeap();
    int getmax();
    void add(int);
    void heapify(int);
    friend int* HeapSort(int*, int);
    int* ret()
    {
        return h;
    }
    ~Heap()
    {
        delete h;
    }
};

void Heap::heapify(int i) {
    int left = 2*i;
    int right = 2*i+1;
    if(left < heap_size)
    {
        if(h[i] < h[left])
        {
            std::swap(h[i], h[left]);
            heapify(left);
        }
    }
    if(right < heap_size)
    {
        if(h[right] > h[i])
        {
            std::swap(h[right], h[i]);
            heapify(right);
        }
    }
}

void Heap::add(int n)
{
    int i = heap_size;
    int parent = (i-1)/2;
    h[i] = n;
    while(parent >= 0 && i > 0)
    {
        if(h[i] > h[parent])
        {
            std::swap(h[i], h[parent]);
        }
        i = parent;
        parent = (i-1)/2;
    }
    heap_size++;
}

void Heap::out()
{
    for(int i =0; i < heap_size; ++i)
    {
        std::cout << h[i] << " ";
    }
    std::cout << std::endl;
}

void Heap::outHeap() {
    int i =0;
    int k = 1;
    while(i < heap_size)
    {
        while((i < k) && (i < heap_size))
        {
            std::cout << h[i] << " ";
            ++i;
        }
        std::cout << std::endl;
        k = 2*k+1;
    }
}

int Heap::getmax()
{
    int x = h[0];
    h[0] = h[heap_size-1];
    heap_size--;
    heapify(0);
    return x;
}

void Heap::buildHeap() {
    for(int i = (heap_size-1)/2; i >= 0; --i)
    {
        heapify(i);
    }
}

int* HeapSort(int* a, int sz)
{
    Heap h(a, sz);
    h.buildHeap();
    for(int i = h.heap_size-1; i > 0; --i)
    {
        std::swap(h.h[i], h.h[0]);
        h.heap_size--;
        h.heapify(0);
    }
    return h.ret();
}
#endif //ALGO_HEAP_H
