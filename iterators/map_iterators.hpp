#ifndef MAP_ITERATORS
#define MAP_ITERATORS

#include "../STL/utility.hpp"

namespace ft
{
    template<class T>
    class   map_iterator
    {
    public:
        /*************** member type **************/
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef std::bidirectional_iterator_tag     iterator_category; 
        //typedef Distance                            difference_type;
        //typedef Distance                            distance_type;
        typedef T&                                  reference;


    private:
        pointer elem;
public:
        /************* public function **********/
        map_iterator()
        {
            elem = NULL;
        }
        map_iterator(pointer p)
        {
            elem = p;
        }
        map_iterator(const map_iterator<T> &a)
        {
            elem = a.elem;
        }
        ~map_iterator()
        {}
        map_iterator &operator=(const map_iterator<T> &v)
        {
            elem = v.elem;
            return (*this);
        }
        bool operator!=(const map_iterator &v)
        {
            return (elem != v.elem);
        }
        bool operator==(const map_iterator &v)
        {
            return (elem == v.elem);
        }
        map_iterator operator++()
        {
            elem++;
            return (*this);
        }
        map_iterator operator--()
        {
            elem--;
            return (*this);
        }
        map_iterator operator++(int) //get_sure of this , try to compile i++
        {
            map_iterator res(*this);
            ++(*this);
            return (res);
        }
        map_iterator operator--(int)
        {
            map_iterator res(*this);
            --(*this);
            return (res);
        }
        map_iterator operator+(int a)
        {
            map_iterator  res(*this);
            while (a--)
                ++res;
            return (res);
        }
        map_iterator operator-(int a)
        {
            map_iterator res(*this);
            while (a--)
                --res;
            return (res);
        }
        map_iterator operator+=(int a)
        {
            while (a--)
                ++(*this);
            return (*this);
        }
        map_iterator operator-=(int a)
        {
            while (a--)
                --(*this);
            return (*this);
        }
        value_type  operator*()
        {
            return (*elem);
        }
        pointer operator->()
        {
            return (elem);
        }

    };
};

#endif