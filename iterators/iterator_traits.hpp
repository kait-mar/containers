#ifndef ITERATOR_TRAITS
#define ITERATOR_TRAITS

namespace ft
{
    template <class Iterator> class iterator_traits
    {
    public:
        typedef Iterator::value_type    value_type;
        typedef Iterator::pointer       pointer;
        typedef Iterator::reference     reference;
        typedef Iterator::difference_type   difference_type;
        typedef Iterator::iterator_category iterator_category;
    };
};

#endif