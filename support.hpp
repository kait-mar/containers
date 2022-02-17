#ifndef SUPPORT_HPP
#define SUPPORT_HPP

namespace   ft
{
    template< true, class T = void >
    struct enable_if {
        /*    member type    */
        typedef T   type;
    };
    template<false>
    struct enable_if {
        /*   no member type    */
    };
    //    typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
    template< class T >
    struct is_integral
    {
    public:
        static const bool value;
        is_integral()
        {
            bool   *a = dynamic_cast<bool*>(input);
            char    *b = dynamic_cast<char*>(input);
            wchar_t    *c = dynamic_cast<wchar_t*>(input);
            short int    *d = dynamic_cast<short int*>(input);
            char32_t    *e = dynamic_cast<char32_t*>(input);
            unsigned short int    *f = dynamic_cast<unsigned short int*>(input);
            int    *j = dynamic_cast<int*>(input);
            long int    *h = dynamic_cast<long int*>(input);
            unsigned long int    *i = dynamic_cast<unsigned long int*>(input);
            size_t                *g = dynamic_cast<size_t*>(input);
            if (a != NULL || b != NULL || c != NULL 
                || d != NULL || e != NULL || f != NULL 
                || j != NULL || h != NULL || i != NULL || g != NULL)
            {
                value = true;
            }
            else
                value = false;
        }
    }
}

#endif