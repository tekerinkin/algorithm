//
// Created by Дима Шестаков on 04.04.2021.
//

#pragma once
#include<iostream>



template<typename E>
class List{
public:

    void  operator = (const List&) = delete;

    List(const List&) = delete;

    List() = default;
    virtual ~List() = default;

    //Удаляет все элементы  списка
    virtual void clear() = 0;

    //Вставляет элемент в определенное место в списке
    virtual void insert(const E& item) = 0;

    //Вставлет элемент в конец списка
    virtual void append(const E& item) = 0;

    //Удаляет и возвращает текущий элемент
    virtual E remove() = 0;

    //Устанавливает указатель на начло списка
    virtual void moveToStart() = 0;

    //Устанавливает указатель на конец списка
    virtual void moveToEnd() = 0;

    //Сдвигает указатель на один влево.
    // Ничего не происходит если указатель уже на начале
    virtual void prev() = 0;

    //Сдвигает указатель на один вправо.
    //Ничего не происходит если уже указатель на конце
    virtual void next() = 0;

    //Возвращает длину списка
    virtual size_t length() const  = 0;

    //Возвращает текущую позицию
    virtual size_t curPos() const = 0;

    //Сдвигает указатель в новую позицию
    virtual void moveToPos(size_t pos) = 0;

    //Возвращает текущий элемент
    virtual const E& getVal() const = 0;
};

void Assert(bool a, const char* c){
    if(!a)
        throw std::runtime_error(c);
}