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
       explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}
       /*
            member functions
        */
       bool empty() const                   { return (c.size() == 0);    }
       size_type size() const               { return (c.size());         }
       value_type& top()                    {  return c.back();          }
       const value_type& top() const        {  return c.back();          }
        void push (const value_type& val)   { return c.push_back(val);   }
        void pop()                          {   c.pop_back();            }

    protected:
        /*
            adaptor object
        */
       container_type   c;

       /*
            ft::relational operators (stack)
        */
    public:
        friend bool operator== (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs.c == rhs.c);
        }
        friend bool operator!= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs.c != rhs.c);
        }
        friend bool operator< (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs.c < rhs.c);
        }
        friend bool operator<= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs.c <= rhs.c);
        }
        friend bool operator> (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs.c > rhs.c);
        }
        friend bool operator>= (const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs)
        {
            return (lhs.c >= rhs.c);
        }
    };
}


#endif