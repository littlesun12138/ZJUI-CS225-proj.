//
// Created by jordan on 2021/1/24.
//
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Q3_2.h"
#include "alist.h"
using std::cout;
using std::cin;

// Now we should implement the helper function.

//constructors and destructors.
template<class T> Q3_2<T>::Q3_2(int size):
    begin(0),end(0),numitems(0)
{
    if (size < 0){ cout<<"invalid size!"<<std::endl; exit(1); }
    maxsize = size;
    if (size < 20){minsize = size; }
    else {minsize = 20;}
    reprarray = new T[maxsize];
}

template<class T>
Q3_2<T>::~Q3_2() { delete [] reprarray;}

// the function push_back can push a item T to the end of a function.

template<class T>
void Q3_2<T>::pushback(T x) {
    if ((end+1) == maxsize) {
        allocate(0);
    }
        if (numitems != 0) {end ++;}
        else{
            end++;
            begin++;
        }
        numitems++;
        reprarray[end] = x;
        cout<<"end is "<< end <<std::endl;
}

template<class T>
T Q3_2<T>::popback() {
    if (end < begin){ cout<<"empty list! "<<std::endl; exit(1);}
    if ((maxsize-end+1) == (maxsize*3)/4 && maxsize > minsize){ deallocate(0);}

    T ret = reprarray[end];
    end--;
    numitems--;

    return ret;
}

template<class T>
void Q3_2<T>::pushfront(T x) {
    if (begin<=0) { allocate(1);}
    if (numitems != 0) { begin--;}
    else {
        begin--;
        end--;
    }
    numitems++;
    reprarray[begin] = x;
    cout<<"begin is "<< begin<<std::endl;
}

template<class T>
T Q3_2<T>::popfront() {
    if (begin > end){ cout<<"empty list"<<std::endl; exit(1);}
    if (begin == (3*maxsize)/4 && maxsize > minsize){
        deallocate(1);
    }
    T ret = reprarray[begin];
    begin++;
    numitems--;
    return ret;
}

template<class T>
void Q3_2<T>::allocate(int x) {
    int newsize = 2 * maxsize;
    T *newarr = new T [newsize];
    if (x){
        for (int i = 0; i < numitems; i++) {
            newarr[maxsize + begin + i] = reprarray[begin + i];
        }
        begin += newsize/2;
        end += newsize/2;
    }
    else {
        for (int i = 0; i < numitems; i++) {
            newarr[begin + i] = reprarray[begin + i];
        }
    }
    delete [] reprarray;
    maxsize = newsize;
    reprarray = newarr;
    return;
}

template<class T>
void Q3_2<T>::deallocate(int x) {
    int newsize = maxsize/2;
    T* newarr = new T[newsize];
    if (x) {
        for (int i = 0; i < numitems; i++) {
            newarr[begin - newsize + i] = reprarray[begin + i];
        }
        begin -= newsize;
        end -= newsize;
    }else {
        for (int i = 0; i < numitems; i++) {
            newarr[begin + i] = reprarray[begin + i];
        }
    }
    delete [] reprarray;
    reprarray = newarr;

    maxsize = newsize;
    return;
}
template<class T> void Q3_2<T>::print()
{
     cout << "Display elements in the deque: " << std::endl;
     for (int i = begin ; i < begin+numitems ; i ++)
     {
         cout << reprarray[i] << " ";
     }
     cout << std::endl;
}
