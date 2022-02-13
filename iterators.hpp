#ifndef ITERATORS_HPP
#define ITERATORS_HPP

namespace ft
{
    template<class T>
    class   vector_iterator
    {
        /*************** member type **************/
        typedef T   value_type;
        typedef T*  pointer;
        typedef std::random_access_iterator_tag iterator_type; 
    };
};


#endif