#ifndef SUPPORT_HPP
#define SUPPORT_HPP
#include "../iterators/vector_iterators.hpp"
#include <cstddef>

namespace   ft
{
    /*   enable_if  */
    template <bool B>
    struct enable_if {};
    template <>
    struct enable_if<true> { typedef char type; };
  
    /*  is_integral  */
    template <class T>
    struct is_integral { 
        static const bool value = false;
    };

    template <>
    struct is_integral<short> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<bool> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<int> { 
        static const bool value = true;
    };
    template <>
    struct is_integral<long> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<unsigned char> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<char> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<long long> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<unsigned long> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<unsigned long long> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<unsigned short> { 
        static const bool value = true; 
    };
    template <>
    struct is_integral<unsigned int> { 
        static const bool value = true; 
    };

   /*
        ft::equal : Compares the elements in the range [first1,last1) with those in the range beginning at first2, 
        and returns true if all of the elements in both ranges match.
   */

    template <class InputIterator1, class InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1,
                InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return (false);
            ++first1;
            ++first2;
        }
        return (true);
    };
    template <class InputIterator1, class InputIterator2, class BinaryPredicate>
    bool equal (InputIterator1 first1, InputIterator1 last1,
              InputIterator2 first2, BinaryPredicate pred)
    {
        while (first1!=last1)
        {
            if (!pred(*first1,*first2))
                return (false);
            ++first1;
            ++first2;
        }
        return (true);
    };
    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                    InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1)
        {
            if (first2 ==last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2)
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    };
    /** ft::pair **/
    template <class T1, class T2>
    struct pair
    {
    public:
        /* member types */
        typedef T1  first_type;
        typedef T2  second_type;

        /* member variables */

        first_type  first;
        second_type second;

        pair(): first(first_type()), second(second_type()) {}
        pair (const first_type& a, const second_type& b): first(a), second(b) {}
        template<class U, class V>
        pair (const pair<U,V>& pr): first(pr.first), second(pr.second) {}

        pair& operator= (const pair& pr)
        {
            first = pr.first;
            second = pr.second;
            return (*this);
        }
    };

    template <class T1,class T2>
    ft::pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( ft::pair<T1,T2>(x,y) );
    };
};

namespace   ft
{
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }

    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first < rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(rhs<lhs); }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return rhs<lhs; }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { return !(lhs<rhs); }
}

#endif