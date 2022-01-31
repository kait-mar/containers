#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

template <class T>
class vector
{
private:
    T   *array;
    int capacity;
    int size;
public:
//class   iterator()
    vector();
    
    ~vector();

};

template<class T>
vector<T>::vector()
{
    this->size = 0;
    this->capacity = 1;
    this->array = new T[1];
}

template<class T>
vector<T>::~vector()
{
    delete [] T;
    this->size = 0;
}



#endif