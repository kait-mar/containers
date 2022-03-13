#ifndef VECTOR_ITERATORS_HPP
#define VECTOR_ITERATORS_HPP

#include "../STL/utility.hpp"

namespace ft
{

    template<class T>
    class   vector_iterator
    {
    public:
        /*************** member type **************/
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef std::random_access_iterator_tag     iterator_category; 
        typedef ptrdiff_t                           difference_type; //sustruct two iterators result
        //typedef Distance                            distance_type;
        typedef T&                                  reference;

    private:
        pointer elem;
    public:
        /************* public function **********/
        vector_iterator()
        {
            elem = NULL;
        }
        vector_iterator(pointer p)
        {
            elem = p;
        }
        vector_iterator(const vector_iterator<T> &a)
        {
            elem = a.elem;
        }
        ~vector_iterator()
        {}
        vector_iterator<T> &operator=(const vector_iterator<T> &v)
        {
            elem = v.elem;
            return (*this);
        }
        bool operator!=(const vector_iterator<T> &v)
        {
            return (elem != v.elem);
        }
        bool operator==(const vector_iterator<T> &v)
        {
            return (elem == v.elem);
        }
        vector_iterator operator++()
        {
            elem++;
            return (*this);
        }
        vector_iterator operator--()
        {
            elem--;
            return (*this);
        }
        vector_iterator operator++(int) //get_sure of this , try to compile i++
        {
            vector_iterator res(*this);
            ++(*this);
            return (res);
        }
        vector_iterator operator--(int)
        {
            vector_iterator<T> res(*this);
            --(*this);
            return (res);
        }
        vector_iterator operator+(int a)
        {
            vector_iterator  res(*this);
            while (a--)
                ++res;
            return (res);
        }
        vector_iterator operator-(int a)
        {
            vector_iterator res(*this);
            while (a--)
                --res;
            return (res);
        }
        vector_iterator operator+=(int a)
        {
            while (a--)
                ++(*this);
            return (*this);
        }
        vector_iterator operator-=(int a)
        {
            while (a--)
                --(*this);
            return (*this);
        }
        value_type  &operator*()
        {
            return (*elem);
        }
        pointer operator->()
        {
            return (elem);
        }
        operator vector_iterator<const T> ()
        {
            return elem;
        }
    };

        

        /* vector reverse iterator */

    template<class T>
    class   vector_reverse_iterator
    {
    public:
        /*************** member type **************/
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef std::random_access_iterator_tag     iterator_category; 
        //typedef Distance                            difference_type;
        //typedef Distance                            distance_type;
        typedef T&                                  reference;
    private:
        pointer elem;
    public:
        /************* public function **********/
        vector_reverse_iterator()
        {
            elem = NULL;
        }
        vector_reverse_iterator(pointer p)
        {
            elem = p;
        }
        vector_reverse_iterator(const vector_reverse_iterator<T> &a)
        {
            elem = a.elem;
        }
        ~vector_reverse_iterator()
        {}
        vector_reverse_iterator<T> &operator=(const vector_reverse_iterator<T> &v)
        {
            elem = v.elem;
            return (*this);
        }
        bool operator!=(const vector_reverse_iterator<T> &v)
        {
            return (elem != v.elem);
        }
        bool operator==(const vector_reverse_iterator<T> &v)
        {
            return (elem == v.elem);
        }
        vector_reverse_iterator<T> &operator++()
        {
            elem--;
            return (*this);
        }
        vector_reverse_iterator &operator--()
        {
            elem++;
            return (*this);
        }
        vector_reverse_iterator &operator++(int) //get_sure of this , try to compile i++
        {
            vector_reverse_iterator<T> res(*this);
            ++(-this);
            return (res);
        }
        vector_reverse_iterator &operator--(int)
        {
            vector_reverse_iterator<T> res(*this);
            --(*this);
            return (res);
        }
        vector_reverse_iterator<T> &operator+(int a)
        {
            vector_reverse_iterator<T>  &res(*this);
            while (a--)
                --res;
            return (res);
        }
        vector_reverse_iterator<T> &operator-(int a)
        {
            vector_reverse_iterator<T>  &res(*this);
            while (a--)
                ++res;
            return (res);
        }
        vector_reverse_iterator<T> &operator+=(int a)
        {
            while (a--)
                ++(*this);
            return (*this);
        }
        vector_reverse_iterator<T> &operator-=(int a)
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
        operator vector_reverse_iterator<const T> ()
        {
            return elem;
        }
    };
};

    template<class T>
    ft::vector_iterator<T>  operator+(int a, ft::vector_iterator<T>& it)
    {
        return (it.operator+(a));
    }

#endif