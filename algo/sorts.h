//
// Created by Дима Шестаков on 16.01.2021.
//

#ifndef C___SORTS_H
#define C___SORTS_H

#endif //C___SORTS_H

#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int>& arr)
{
    int n = 1;
    while(n != 0)
    {
        n = 0;
        for(size_t j = 0 ; j < arr.size()-1; ++j)
        {
            if(arr[j] > arr[j+1])
            {
                n++;
                swap(arr[j], arr[j+1]);
            }
        }
    }
}


void choice_sort(vector<int>& arr)
{
    for(size_t i =0; i < arr.size()-1; ++i)
    {
        for(size_t j = i+1; j < arr.size(); ++j)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

size_t partition(vector<int>& arr, size_t l, size_t h)
{
    size_t p = h;
    size_t firsthigh = l;
    for(size_t i =0; i < h; ++i)
    {
        if(arr[i] < arr[p]){
            swap(arr[i], arr[firsthigh]);
            firsthigh++;
        }
    }
    swap(arr[p], arr[firsthigh]);
    return firsthigh;
}

void quicksort(vector<int>& arr, size_t l, size_t h)
{
    if(h-1 > 0) {
        size_t p = partition(arr, l, h);
        quicksort(arr, l, p);
        quicksort(arr, p+1, h);
    }
}

