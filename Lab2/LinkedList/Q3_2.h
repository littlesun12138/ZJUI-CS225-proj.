//
// Created by jordan on 2021/1/24.
//
#include "dlist.h"

#ifndef LINKEDLIST_Q3_2_H
#define LINKEDLIST_Q3_2_H

template<class T>
class Q3_2 : public DList<T>{

public:
    void pushback(T x);
    void pushfront(T x);
    void popback();
    void popfront();


};


#endif //LINKEDLIST_Q3_2_H
