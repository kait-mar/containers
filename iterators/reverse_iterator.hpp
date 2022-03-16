#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace   ft
{
    template <class Iterator>
    class reverse_iterator {
    private:
        Iterator    _it;
        //pointer     _elem;
    public:
        /*member types */
        typedef Iterator    iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category    iterator_category;
        typedef typename iterator_traits<Iterator>::value_type   value_type;
        typedef typename iterator_traits<Iterator>::difference_type  difference_type;
        typedef typename iterator_traits<Iterator>::pointer  pointer;
        typedef typename iterator_traits<Iterator>::reference    reference;
        // typedef Iterator<const Iterator::value_type>       const_iterator;

            /*constructors*/
        reverse_iterator() {_it = iterator_type();}
        explicit reverse_iterator (iterator_type it): _it(it)
        {}
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it)
        {
            _it = rev_it.base();
        }
        reverse_iterator    operator=(const reverse_iterator<Iterator>& rev_it)
        {
            _it = rev_it._it;
            return (*this);
        }
        iterator_type base() const
        {
            return _it;
        }
        reference operator*() const
        {
            iterator_type   res(_it - 1);
            return *res;
        }
        reverse_iterator& operator++()
        {
            --_it;
            return (*this);
        }
        reverse_iterator  operator++(int)
        {
            reverse_iterator    res(*this);
            ++(*this);
            return (res);
        }
        reverse_iterator operator+ (difference_type n) const
        {
           reverse_iterator  res(*this);
            while (n--)
                ++res;
            return (res);
        }
        reverse_iterator& operator+= (difference_type n)
        {
            while (n--)
                ++(*this);
            return *this;
        }
        reverse_iterator operator- (difference_type n) const
        {
           reverse_iterator  res(*this);                                                                                                    
            while (n--)
                --res;
            return (res);
        }
        reverse_iterator& operator--()
        {
            ++_it;
            return (*this);
        }
        reverse_iterator  operator--(int)
        {
            reverse_iterator    res(*this);
            --(*this);
            return (res);
        }
        reverse_iterator& operator-= (difference_type n)
        {
            while (n--)
                --(*this);
            return *this;
        }
        pointer operator->() const
        {
            return &((_it - 1).operator*());
        }
        reference operator[] (difference_type n) const //not sure about this !!!
        {
            return *(_it - n - 1);
        }
    };
};

namespace   ft
{
    template <class Iterator>
  bool operator== (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
template <class Iterator>
  bool operator!= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return !(lhs == rhs);
    }
template <class Iterator>
  bool operator<  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
template <class Iterator>
  bool operator<= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return !(rhs < lhs);
    }
template <class Iterator>
  bool operator>  (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return !(lhs <= rhs);
    }
template <class Iterator>
  bool operator>= (const ft::reverse_iterator<Iterator>& lhs,
                   const ft::reverse_iterator<Iterator>& rhs)
    {
        return !(lhs < rhs);
    }

template <class Iterator>
  ft::reverse_iterator<Iterator> operator+ (
             typename ft::reverse_iterator<Iterator>::difference_type n,
             const ft::reverse_iterator<Iterator>& rev_it)
    {
        return rev_it.operator+(n);
    }

template <class Iterator>
  typename ft::reverse_iterator<Iterator>::difference_type operator- (
    const ft::reverse_iterator<Iterator>& lhs,
    const ft::reverse_iterator<Iterator>& rhs)  //The number of elements between lhs and rhs.
    {
        return rhs.base() - lhs.base();
    }
};

#endif