#ifndef SUPPORT_HPP
#define SUPPORT_HPP

namespace   ft
{
    //    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
    /*       enable_if       */
    template <bool B>
    struct enable_if {};
    template <>
    struct enable_if<true> { typedef char type; };

    /*   is_integral   */
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

    

    
};

#endif