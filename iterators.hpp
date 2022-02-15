#ifndef ITERATORS_HPP
#define ITERATORS_HPP

namespace ft
{
    template<class T>
    class   vector_iterator
    {
    public:
        /*************** member type **************/
        typedef T                                   value_type;
        typedef T*                                  pointer;
        typedef std::random_access_iterator_tag     iterator_category; 
        //typedef Distance                            difference_type;
        //typedef Distance                            distance_type;
        typedef T&                                  reference;
    private:
        pointer elem;
    public:
        /************* public function **********/
        vector_iterator()
        {
            elem = NULL;
        }
        vector_iterator(pointer p)
        {
            elem = p;
        }
        vector_iterator(const vector_iterator<T> &a)
        {
            elem = a.elem;
        }
        ~vector_iterator() //add a definition
        {}
        vector_iterator<T> &operator=(const vector_iterator<T> &v)
        {
            elem = v.elem;
            return (*this);
        }
        bool operator!=(const vector_iterator<T> &v)
        {
            return (elem != v.elem);
        }
        bool operator==(const vector_iterator<T> &v)
        {
            return (elem == v.elem);
        }
        vector_iterator<T> &operator++()
        {
            elem++;
            return (*this);
        }
        vector_iterator<T> &operator--()
        {
            elem--;
            return (*this);
        }
        vector_iterator<T> &operator++(int) //get_sure of this , try to compile i++
        {
            vector_iterator<T> res(*this);
            elem++;
            return (res);
        }
        vector_iterator<T> &operator--(int)
        {
            vector_iterator<T> res(*this);
            elem--;
            return (res);
        }
        vector_iterator<T> &operator+(int a)
        {
            vector_iterator<T>  &res(*this);
            while (a--)
                ++res;
            return (res);
        }
        vector_iterator<T> &operator-(int a)
        {
            vector_iterator<T>  &res(*this);
            while (a--)
                --res;
            return (res);
        }
        value_type  operator*()
        {
            return (*elem);
        }
    };
};


#endif