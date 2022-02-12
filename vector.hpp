#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

template <class T, class alloc = std::allocator<T> >
class vector
{
private:
    T   *array;
    int _capacity;
    int _size;
public:
    /***************** member type *****************/
    typedef T        value_type;
    typedef alloc     allocator_type;
    typedef T&        reference;
    typedef const T&  const_reference;
    typedef T*                  pointer;
    typedef const T*             const_pointer;
    typedef typename std::random_access_iterator_tag iterator; // add const
    //create your own class iterator with all functions and operators (its type is random access)
    typedef typename std::reverse_iterator  reverse_iterator; //add const
    typedef ptrdiff_t          difference_type;
    typedef size_t       size_type;
    /****************** member functions **********/
    //add the other types of constructors
    vector()
    {
        this->_size = 0;
        this->_capacity = 1;
        this->array = get_allocator().allocate(this->_capacity);
    }
    ~vector()
    {
        get_allocator().dealocate(array, this->_capacity);
        this->_size = 0;
    }
    vector<T>    &operator=(const vector<T> &v )
    {
        if (v._size >= this->_capacity)
        {
            get_allocator().deallocate(array, this->_capacity);
            this->_capacity = v._size * 2;
            get_allocator().allocate(this->_capacity);
        }
        for(int i = 0; i < v._size; i++)
        {
            this->array[i] = v.array[i];
        }
        this->_size = v._size;
        return (*this);
    }
    /****************  allocator  ****************/
    alloc   get_allocator() const
    {
        return(alloc());
    }
    /*************** iterators ******************/
    iterator    begin()
    {
        iterator    x(this->array);
        return (x);
    }
    //add the const iterators
    iterator    end()
    {
        iterator    x(array + _size);
        return (x);
    }
    reverse_iterator    rbegin()
    {
        reverse_iterator    x(array + _size - 1);
        return (x);
    }
    reverse_iterator    rend()
    {
        reverse_iterator    x(array - 1);
        return (x);
    }
    /*******************  capacity  ***************/
    int size() //can be size_t
    {
        return (_size);
    }
    //size_t  max_size()
    int capacity()
    {
        return (_capacity);
    }
    //void    resize()
    bool    empty()
    {
        if (this->_size == 0)
            return (true);
        return (false);
    }

    /**************** modifiers  *****************/
    //use destroy and construct
    //u can add other private func
    void    push_back(T &val)
    {
        if (this->_size == this->_capacity)
        {
            
            this->_capacity *= 2;
            T   *b = get_allocator().allocate(this->_capacity);
            for(int i = 0; i < this->_size; i++)
                b[i] = this->array[i];
            b[this->size] = val;
            get_allocator().deallocate(array, this->_size);
            this->array = b;
        }
        else
            this->array[this->_size] = val;
        this->_size++;
    }
    void    pop_back()
    {
        this->_size--;
    }
    //insert
    //erase
    //swap
    void    clear()
    {
        this->_size = 0;
    }
    /*************** element access ***************/
    typename alloc::reference    operator[](int o)
    {
        return (this->array[o]);
    }
    typename alloc::const_reference    operator[](int o) const
    {
        return (this->array[o]);
    }
    typename alloc::reference    at(int o)
    {
        if (o >= this->_size)
            throw(std::out_of_range(""));
        else
            return (this->array[o]);
    }
    typename alloc::const_reference    at(int o) const
    {
        if (o >= this->_size)
            throw(std::out_of_range(""));
        else
            return (this->array[o]);
    }
    typename alloc::reference    front()
    {
        return(this->array[0]);
    }
    typename alloc::const_reference    front() const
    {
        return(this->array[0]);
    }
    typename alloc::reference    back()
    {
        return(this->array[this->_size - 1]);
    }
    typename alloc::const_reference    back() const
    {
        return(this->array[this->_size - 1]);
    }
};


#endif