#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <exception>
#include "../iterators/map_iterators.hpp"

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<pair<const Key,T> >    // map::allocator_type
           > class map
{
public:

                /**** member type  ****/
    typedef Key                                 key_type;
    typedef T                                   mapped_type;
    typedef pair<const key_type, mapped_type>   value_type;
    typedef Compare                             key_compare;
    //typedef value_compare                     nested function class
    typedef Alloc                               allocator_type;
    typedef 	allocator_type::reference       reference;
    typedef allocator_type::const_reference     const_reference;
    typedef allocator_type::pointer             pointer;
    typedef allocator_type::const_pointer       const_pointer;
    typedef ptrdiff_t                           difference_type;
    typedef size_t                              size_type;

private:
    size_type       _size;
    allocator_type  _alloc;
    key_compare     _comp;
    struct node
    {
        value_type  content;
        node*       parent;
        node*       left;
        node*       right;
    };
    

public:


}

#endif