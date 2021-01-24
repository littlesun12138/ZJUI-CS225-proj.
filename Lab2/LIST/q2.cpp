//
// Created by jordan on 2021/1/23.
//


#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "q2.h"
using std::cout;
using std::cin;

template <class T> Question2<T>::Question2(){}
template <class T> Question2<T>::~Question2(){}
template <class T> T Question2<T>::f(T x)
{
    // self- defined function f.
    return 2 * x;
}

template <class T>T Question2<T>::g(T x,T y)
{
    // self-defined function y.
    return x+y;
}

template <class T> T Question2<T>::src(AList<T>& l)
{
    T e = (T)0;

    if (!l.getlength()){
        return e;
    }
    if (1 == l.getlength()){
        return f(l.getitem(1));
    }
    // now we should cut the list to two part.

    Question2<T> sub1;
    Question2<T> sub2;
    int mid = (l.getlength())/2;

    // now we should divide the list to two part by the middle. 
    for (int i = 0; i < l.getlength(); i++){
        if ( i < mid) {
            sub1.append(l.getitem(i + 1));
        } else{
            sub2.append(l.getitem(i + 1));
        }
    }
    // now we can recursion
    T ret = g(src(sub1),src(sub2));
    return ret;
}
