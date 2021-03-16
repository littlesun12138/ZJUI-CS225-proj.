//
// Created by jordan on 2021/1/25.
//
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "deque.h"
#include_next "dlistsort.h"
using std::cout;
using std::cin;

template<class T>
deque<T>::deque<class T>():DList<T>() {
    length = 20;
    cout<<"deque condtructor!"<<std::endl;
}

template<class T>
deque<T>::deque<class T>(int k) :DList<T>(),length(k){
    cout<<"deque constructor int!"<<std::endl;
}

template<class T>
deque<T>::~deque<T>() {
    cout<<"deque destructor!"<<std::endl;
}

