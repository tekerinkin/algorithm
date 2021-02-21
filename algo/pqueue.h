//
// Created by Дима Шестаков on 04.02.2021.
//

#ifndef ALGO_PQUEUE_H
#define ALGO_PQUEUE_H

#endif //ALGO_PQUEUE_H
#include "heap.h"


using namespace std;

struct pqueue : private Heap
{
    int heapMax()
    {
        return h[0];
    }
    int extractMax()
    {
        if(heap_size < 1)
            throw std::out_of_range("Queue is empty!!");
        int max = h[0];
        h[0] = h[--heap_size];
        heap_size--;
        heapify(0);
        return max;
    }

};