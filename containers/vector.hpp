#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include "../iterators/vector_iterators.hpp"

namespace   ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        /***************** member type *****************/
        typedef T                                           value_type;
        typedef Alloc                                       allocator_type;
        typedef T&                                          reference;
        typedef const T&                                    const_reference;
        typedef T*                                          pointer;
        typedef const T*                                    const_pointer;
        typedef typename ft::vector_iterator<T>             iterator;
        typedef typename ft::const_vector_iterator<T>       const_iterator;
        typedef typename ft::vector_reverse_iterator<T>     reverse_iterator; //add const
        typedef ptrdiff_t                                   difference_type;
        typedef size_t                                      size_type;


    private:
        T               *array;
        size_type             _capacity;
        size_type             _size;
        allocator_type  _alloc;
    public:

        /*
            Constructs an empty container, with no elements.
        */
    
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            _size = 0;
            _capacity = 0;
            _alloc = alloc;
        }

        /*
            Constructs a container with n elements. Each element is a copy of val.
        */

        explicit vector (size_type n, const value_type& val = value_type(),
                    const allocator_type& alloc = allocator_type())
        {
            _size = n;
            _capacity = n;
            _alloc = alloc;
            array = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++)
                _alloc.construct(array + i, val);
        }

        /*
            Constructs a container with a copy of each of the elements in x, in the same order.
        */
        vector (const vector& x)
        {
            _size = x._size;
            _capacity = x._capacity;
            _alloc = x.alloc;
            array = _alloc.allocate(_capacity);
            for (size_type i = 0; i < _size; i++)
                _alloc.construct(array + i, x[i]);
        }

        /*
            Constructs a container with as many elements as the range [first,last), 
            with each element constructed from its corresponding element in that range, in the same order.
        */                                                                            
        template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type(),
                typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type var = 0)
        {
            var = 0;
            _alloc = alloc;
            size_type   n = 0;
            size_type   i = 0;
            InputIterator   temp(first);
            while (temp != last)
            {
                temp++;
                n++;
            }
            _size = n;
            _capacity = n;
            array = _alloc.allocate(_capacity);
            while (first != last)
                _alloc.construct(array + i++, *(first++));
        }
                /***** destructor ******/
        ~vector()
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(array + i);
            if (_size)
                _alloc.deallocate(array, this->_capacity);
            _capacity = 0;
            _size = 0;
        }

        /****************** member functions **********/

        vector<T>    &operator=(const vector<T> &v )
        {
            if (v._size > this->_capacity)
            {
                this->~vector();
                this->_capacity = v._size;
                _alloc.allocate(this->_capacity);
            }
            for(size_type i = 0; i < v._size; i++)
            {
                _alloc.construct(array + i, v[i]);
            }
            this->_size = v._size;
            return (*this);
        }
        /****************  allocator  ****************/
        allocator_type   get_allocator() const
        {
            return(_alloc);
        }
        /*************** iterators ******************/
        const_iterator    begin() const
        {
            const_iterator    x(this->array);
            return (x);
        }

        iterator    begin()
        {
            iterator    x(this->array);
            return (x);
        }
        iterator    end()
        {
            iterator    x(array + _size);
            return (x);
        }
        /*const_iterator    end() const
        {
            const_iterator    x(array + _size);
            return (x);
        }*/
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
        size_type   size()
        {
            return (_size);
        }
        //size_t  max_size()
        size_type capacity()
        {
            return (_capacity);
        }
        void resize (size_type n, value_type val = value_type())
        {
            if (n == _size)
                return ;
            if (n < _size)
            {
                for (size_type i = n; i < _size; i++)
                    _alloc.destroy(array + i);
                _size = n;
            }
            else
            {
                if (n <= _capacity)
                {
                    for (size_type i = _size; i < n; i++)
                        _alloc.construct(array + i, val);
                    _size = n;
                }
                else
                {
                    size_type   new_capacity;
                    // n > _capacity * 2 ? n : _capacity * 2;
                    if (n > (size_type)(_capacity * 2))
                        new_capacity = n;
                    else
                        new_capacity = _capacity * 2;
                    pointer b = _alloc.allocate(new_capacity);
                    for (size_type i = 0; i < _size; i++)
                        _alloc.construct(b + i, array[i]);
                    for (size_type i = _size; i < n; i++)
                        _alloc.construct(b + i, val);
                    this->~vector();
                    _capacity = new_capacity;
                    _size = n;
                    array = b;
                }
            }
        }
        bool    empty()
        {
            if (this->_size == 0)
                return (true);
            return (false);
        }
        void reserve (size_type n)
        {
            if (n <= _capacity)
                return ;
            size_type   copy_size = _size;
            pointer     b = _alloc.allocate(n);
            for (size_type i = 0; i < _size; i++)
                _alloc.construct(b + i, array[i]);
            this->~vector();
            array = b;
            _size = copy_size;
            _capacity = n;
        }
        /**************** modifiers  *****************/

        /*
            Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
        */
        void assign (size_type n, const value_type& val)
        {
            vector  v(n, val);
            *this = v;
        }
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type var = 0)
        {
            var = 0;
            vector  v(first, last);
            *this = v;
        }
        void    push_back(const_reference val)
        {
            if (this->_size == this->_capacity)
            {
                size_type   cap = _capacity;
                if (_capacity)
                    cap = cap * 2;
                else
                    cap = cap + 1;
                pointer b = get_allocator().allocate(cap);
                for(size_type i = 0; i < this->_size; i++)
                    _alloc.construct(b + i, array[i]);
                _alloc.construct(b + _size, val);
                size_type   cap2 = _capacity;
                size_type   cap3 = _size;
                this->~vector();
                this->array = b;
                _size = cap3 + 1;
                if (cap2)
                    _capacity = cap2 * 2;
                else
                    _capacity = cap2 + 1;
            }
            else
            {
                _alloc.construct(array + _size, val);
                _size++;
            }
        }
        void    pop_back()
        {
            if (_size > 0)
            {
                _alloc.destroy(array + _size-- - 1);
            }
        }
        iterator erase (iterator position)
        {
            int _end = 0;
            iterator    check;
            int         ch = 0;

            if (*position == array[_size])
                _end = 1;
            pointer     b = _alloc.allocate(_capacity);
            size_type   copy_size = _size;
            size_type   copy_capacity = _capacity;
            int j = 0;
            int k = -1;
            for (iterator i = begin(); i != end(); ++i)
            {
                k++;
                if (i == position)
                {
                    ch = 1;
                    continue ;
                }
                _alloc.construct(b + j, array[k]);
                j++;
                if (ch == 1)
                {
                    check = i;
                    ch = 0;
                }
            }
            this->~vector();
            array = b;
            _size = copy_size - 1;
            _capacity = copy_capacity;
            if (_end == 1)
                return (end());
            return (check);
        }
        iterator erase (iterator first, iterator last)
        {
            int _end = 0;
            iterator    check;
            int         ch = 0;
            int         dec = 0;

            if (*last == array[_size])
                _end = 1;
            pointer     b = _alloc.allocate(_capacity);
            size_type   copy_size = _size;
            size_type   copy_capacity = _capacity;
            int j = 0;
            int k = -1;
            for (iterator i = begin(); i != end(); ++i)
            {
                k++;
                if (i == first)
                {
                    while (i != last)
                    {
                        k++; ++i; dec++;
                    }
                    ch = 1;
                }
                _alloc.construct(b + j, array[k]);
                j++;
                if (ch == 1)
                {
                    check = i;
                    ch = 0;
                }
            }
            this->~vector();
            array = b;
            _size = copy_size - dec;
            _capacity = copy_capacity;
            if (_end == 1)
                return (end());
            return (check);
        }
        iterator insert (iterator position, const value_type& val)
        {
            size_type j = 0;
            if (position == end())
            {
                push_back(val);
                return ;
            }
            if (_size == _capacity)
            {
                size_type   copy_capacity = _capacity * 2;
                size_type   copy_size = _size + 1;
                iterator    ret;
                pointer b = _alloc.allocate(copy_capacity);
                iterator i = begin();
                int check = 0;
                while ( i != end())
                {
                    if (i  == position && check == 0)
                    {
                        _alloc.construct(b + j, val);
                        ret = iterator(b + j);
                        check = 1;
                    }
                    else
                    {
                        _alloc.construct(b + j, *i);
                        ++i;
                    }
                    j++;
                }
                this->~vector();
                array = b;
                _size = copy_size;
                _capacity = copy_capacity;
                return (ret);
            }
            else
            {
                j = _size - 1;
                iterator i = end();
                while (i != position) //try it with rbegin
                {
                    --i;
                    _alloc.construct(array + j + 1, *(array + j));
                    //if (j != _size - 1)
                    _alloc.destroy(array + j);
                    j--;
                }
                _alloc.destroy(array + j);
                _alloc.construct(array + j + 1, val);
                _size++;
                return (position);
            }
        }
        void insert (iterator position, size_type n, const value_type& val)
        {
            if (position == end())
            {
                while (n-- > 0)
                {
                    push_back(val);
                }
                return ;
            }
            if (_size + n > _capacity)
            {
                size_type   j = 0;
                size_type   copy_capacity;
                if (_size + n <= _capacity * 2)
                    copy_capacity = _capacity * 2;
                else
                    copy_capacity = _size + n;
                size_type   copy_size = _size + n;
                iterator    ret;
                pointer b = _alloc.allocate(copy_capacity);
                iterator i = begin();
                int check = 0;
                while ( i != end())
                {
                    if (i  == position && check == 0)
                    {
                        while (n-- > 0)
                            _alloc.construct(b + j++, val);
                        check = 1;
                    }
                    else
                    {
                        _alloc.construct(b + j, *i);
                        ++i;
                        j++;
                    }
                }
                this->~vector();
                array = b;
                _size = copy_size;
                _capacity = copy_capacity;
            }
            else
            {
                size_type   j = 0;
                for (iterator i = begin(); i != end(); ++i)
                {
                    if (i == position)
                    {
                        vector  v(array + j, array + _size, _alloc);
                        _size += n;
                        while (n-- > 0)
                        {
                            _alloc.destroy(array + j);
                            _alloc.construct(array + j, val);
                            j++;
                        }
                        for (size_type i = 0; i < v.size(); i++)
                        {
                            _alloc.destroy(array + j);
                            _alloc.construct(array + j++, v[i]);
                        }
                    }
                    j++;
                }
            }
        }
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, 
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type var = 0)
        {
            var = 1;
            size_type   j = 0;
            size_type   copy_capacity;
            InputIterator   temp(first);
            size_type       n = 0;

            if (position == end())
            {
                while (first != last)
                {
                    push_back(*first);
                    first++;
                }
                return ;
            }
            while (temp != last)
            {
                n++;
                temp++;
            }
            if (_size + n > _capacity)
            {
                if (_size + n <= _capacity * 2)
                    copy_capacity = _capacity * 2;
                else
                    copy_capacity = _size + n;
                size_type   copy_size = _size + n;
                pointer b = _alloc.allocate(copy_capacity);
                iterator i = begin();
                int check = 0;
                while ( i != end())
                {
                    if (i  == position && check == 0)
                    {
                        while (first != last)
                            _alloc.construct(b + j++, *(first++));
                        check = 1;
                    }
                    else
                    {
                        _alloc.construct(b + j, *i);
                        ++i;
                        j++;
                    }
                }
                this->~vector();
                array = b;
                _size = copy_size;
                _capacity = copy_capacity;
            }
            else
            {
                size_type   j = 0;
                for (iterator i = begin(); i != end(); i++)
                {
                    if (i == position)
                    {
                        vector  v(array + j, array + _size , _alloc);
                        while (first != last)
                        {
                            _alloc.destroy(array + j);
                            _alloc.construct(array + j, *(first++));
                            j++;
                        }
                        for (size_type i = 0; i < v.size(); i++)
                        {
                            _alloc.destroy(array + j); //what if it's not constructed before, is it okey ?
                            _alloc.construct(array + j, v[i]);
                            j++;
                        }
                        break ;
                    }
                    j++;
                }
                _size += n;
            }
        }
        void swap (vector& x)
        {
            vector  temp(*this);

            this.~vector();
            _size = x.size();
            _capacity = x.capacity();
            _alloc = x.get_allocator();
            array = _alloc.allocate(_capacity);
            for (size_type i = 0; i < x.size(); i++)
                _alloc.construct(array + i, x[i]);
            x = temp;
            temp.~vector();
        }
        void    clear()
        {
            for (size_type i = 0; i < _size; i++)
                _alloc.destroy(array + i);
            _size = 0;
        }
        /*************** element access ***************/
        reference    operator[](int o)
        {
            return (this->array[o]);
        }
        const_reference    operator[](int o) const
        {
            return (this->array[o]);
        }
        reference    at(int o)
        {
            if (o >= this->_size)
                throw(std::out_of_range("vector"));
            else
                return (this->array[o]);
        }
        const_reference    at(int o) const
        {
            if (o >= this->_size)
                throw(std::out_of_range("vector"));
            else
                return (this->array[o]);
        }
        reference    front()
        {
            return(this->array[0]);
        }
        const_reference    front() const
        {
            return(this->array[0]);
        }
        reference    back()
        {
            return(this->array[this->_size - 1]);
        }
        const_reference    back() const
        {
            return(this->array[this->_size - 1]);
        }
                /***** non member function overload  ******/
        friend void swap (vector& x, vector& y)
        {
            x.swap(y);
        }

    };
};
    /*
        relational operators
    */
    /*template <class T, class Alloc>
    bool operator== (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
    {
        return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template <class T, class Alloc>
    bool operator!= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
    {
        return (!operator==(lhs, rhs));
    }
    template <class T, class Alloc>
    bool operator< (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
    {
        return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
    }
    template <class T, class Alloc>
    bool operator> (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
    {
        return (operator<(rhs, lhs));
    }
    template <class T, class Alloc>
    bool operator<= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
    {
        return (!operator>(rhs, lhs));
    }
    template <class T, class Alloc>
    bool operator>= (const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
    {
        return (!operator<(lhs, rhs));
    }*/



#endif