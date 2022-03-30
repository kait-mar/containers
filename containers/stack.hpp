#ifndef STACK_HPP
#define STACK_HPP
#include "vector.hpp"

namespace   ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T   value_type;
        typedef Container   container_type;
        typedef typename container_type::size_type   size_type;

       /*
            constructor
        */
       explicit stack (const container_type& ctnr = container_type()): _c(ctnr) {}
       /*
            member functions
        */
       bool empty() const                   { return (_c.size() == 0);    }
       size_type size() const               { return (_c.size());         }
       value_type& top()                    {  return _c.back();          }
       const value_type& top() const        {  return _c.back();          }
        void push (const value_type& val)   { return _c.push_back(val);   }
        void pop()                          {   _c.pop_back();            }

    protected:
        /*
            adaptor object
        */
       container_type   _c;

       /*
            ft::relational operators (stack)
        */
    public:
        friend bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs._c == rhs._c);
        }
        friend bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs._c != rhs._c);
        }
        friend bool operator< (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs._c < rhs._c);
        }
        friend bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs._c <= rhs._c);
        }
        friend bool operator> (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs._c > rhs._c);
        }
        friend bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs._c >= rhs._c);
        }
    };
}


#endif