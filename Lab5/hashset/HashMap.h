//
// Created by jordan on 2021/3/8.
//

#ifndef HASHSET_HASHMAP_H
#define HASHSET_HASHMAP_H

template<class T>class HashMap {
public:
    T* &map[](int index);
    void add(T* mappin);
    bool include(T* mappin);
    void remove(T* mappin);
    void display();

private:
    int numbers;
    T** reparray;
    T* KMAP;
    T* p_ptr;
    void rehash(int size);
    int currentsize;




};


#endif //HASHSET_HASHMAP_H
