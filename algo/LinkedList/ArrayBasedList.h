//
// Created by Дима Шестаков on 04.04.2021.
//


#pragma once
#include"LinkedList.h"

#define defaultSize 10

template<typename E>
class Alist: public List<E>{
private:
    size_t capacity; //максимальное количество элементов в списке
    size_t size; //текущеее количество элементов в списке
    size_t curr; //Позиция в списке текущего элемента
    E* arr; //массив в котором хранятся элементы
public:
    Alist(size_t size = defaultSize){
        capacity = size;
        this->size = curr = 0;
        arr = new E[size];
    }

    ~Alist(){
        delete [] arr;
    }

    void clear(){
        delete [] arr;
        size = curr = 0;
        arr = new E[capacity];
    }

    void insert(const E& it){
        Assert(size < capacity, "List capacity exceeded");
        for(size_t i = size; i > curr; i--){
            arr[i] = arr[i-1];
        }
        arr[curr] = it;
        size++;
    }

    void append(const E& it){
        Assert(size < capacity, "List capacity exceeded");
        arr[size++] = it;
    }

    E remove(){
        Assert((curr >= 0) && (curr < size), "No element");
        auto it = arr[curr];
        for(size_t i = curr; i < size - 1; i++){
            arr[i] = arr[i+1];
        }
        size--;
        return it;
    }

    void moveToStart(){curr = 0;}
    void moveToEnd(){curr = size;}
    void prev(){if(curr != 0) curr--;}
    void next(){if(curr < size) curr++;}

    size_t length() const{
        return size;
    }

    size_t curPos() const{
        return curr;
    }

    void moveToPos(size_t pos){
        Assert((pos >= 0) && (pos <= size), "No Pos out of range");
        curr = pos;
    }

    const E& getVal() const{
        Assert((curr >= 0) && (curr < size), "No current element");
        return arr[curr];
    }

};