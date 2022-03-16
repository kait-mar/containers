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
        vector_iterator &operator++()
        {
            elem++;
            return (*this);
        }
        vector_iterator &operator--()
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
        vector_iterator operator+(difference_type a) const
        {
            vector_iterator  res(*this);
            while (a--)
                ++res;
            return (res);
        }
        vector_iterator operator-(difference_type a) const
        {
            vector_iterator res(*this);
            while (a--)
                --res;
            return (res);
        }
        vector_iterator &operator+=(difference_type a)
        {
            while (a--)
                ++(*this);
            return (*this);
        }
        vector_iterator &operator-=(difference_type a)
        {
            while (a--)
                --(*this);
            return (*this);
        }
        reference   operator*() const
        {
            return (*elem);
        }
        pointer operator->() const
        {
            return (elem);
        }
        reference operator[] (difference_type n) const //not sure about this !!!
        {
            return *(elem + n);
        }
        operator vector_iterator<const T> () const
        {
            return (vector_iterator<const T>(elem));
            //return elem;
        }
        pointer get_elem() const
        {
            return (elem);
        }
        /*NON member overloads*/
        /*//template<class T>
        friend ft::vector_iterator<T>  operator+(int a, ft::vector_iterator<T>& it);
        //template<class T>
        friend ft::vector_iterator<T>  operator-(int a, ft::vector_iterator<T>& it);
        //template<class T>
        friend bool operator== (const ft::vector_iterator<T>& lhs, const ft::vector_iterator<T>& rhs);
        //template<class T>
        friend bool operator!= (const ft::vector_iterator<T>& lhs, const ft::vector_iterator<T>& rhs);
        //template<class T>
        friend bool operator< (const ft::vector_iterator<T>& lhs, const ft::vector_iterator<T>& rhs);
        //template<class T>
        friend bool operator<= (const ft::vector_iterator<T>& lhs, const ft::vector_iterator<T>& rhs);
        //template<class T>
        friend bool operator> (const ft::vector_iterator<T>& lhs, const ft::vector_iterator<T>& rhs);
        //template<class T>
        friend bool operator>= (const ft::vector_iterator<T>& lhs, const ft::vector_iterator<T>& rhs);
        //template<class T>
        friend typename ft::vector_iterator<T>::difference_type operator- (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs);*/
    };
};

namespace   ft
{
        template<class T>
    ft::vector_iterator<T>  operator+(int a, ft::vector_iterator<T>& it)
    {
        return (it.operator+(a));
    }
    template<class T>
    ft::vector_iterator<T>  operator-(int a, ft::vector_iterator<T>& it)
    {
        return (it.operator-(a));
    }
    template<class T>
    bool operator== (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs)
    {
        return (lhs.get_elem() == rhs.get_elem());
    }
    template<class T>
    bool operator!= (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs)
    {
        return (lhs.get_elem() != rhs.get_elem());
    }
    template<class T>
    bool operator< (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs)
    {
        return (lhs.get_elem() < rhs.get_elem());
    }
    template<class T>
    bool operator<= (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs)
    {
        return (lhs.get_elem() <= rhs.get_elem());
    }
    template<class T>
    bool operator> (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs)
    {
        return (lhs.get_elem() > rhs.get_elem());
    }
    template<class T>
    bool operator>= (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs)
    {
        return (lhs.get_elem() >= rhs.get_elem());
    }
    template<class T>
    typename ft::vector_iterator<T>::difference_type operator- (const ft::vector_iterator<T>& lhs,
                   const ft::vector_iterator<T>& rhs)
    {
        return (lhs.get_elem() - rhs.get_elem());
    }
};

#endif