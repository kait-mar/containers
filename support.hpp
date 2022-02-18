#ifndef SUPPORT_HPP
#define SUPPORT_HPP

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
        while (first1!=last1)
        {
            if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
                return (false);
            ++first1;
            ++first2;
        }
        return (true);
    }
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
    }
};

#endif