//
// Created by jordan on 2021/1/25.
//
#include "dlistsort.h"

#ifndef LAB3_DEQUE_H
#define LAB3_DEQUE_H

template <class T>
class deque : public DList<T>{
public:
    deque(int k);
    deque();
    ~deque();
    merge();
    mergesort();

private:
    T* merge_list;
    node<T>* first;
    node<T>* last;
    int length;
};


#endif //LAB3_DEQUE_H
