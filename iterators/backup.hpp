 /* vector reverse iterator */

    template<class T>
    class   vector_reverse_iterator
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
        vector_reverse_iterator()
        {
            elem = NULL;
        }
        vector_reverse_iterator(pointer p)
        {
            elem = p;
        }
        vector_reverse_iterator(const vector_reverse_iterator<T> &a)
        {
            elem = a.elem;
        }
        ~vector_reverse_iterator()
        {}
        vector_reverse_iterator<T> &operator=(const vector_reverse_iterator<T> &v)
        {
            elem = v.elem;
            return (*this);
        }
        bool operator!=(const vector_reverse_iterator<T> &v)
        {
            return (elem != v.elem);
        }
        bool operator==(const vector_reverse_iterator<T> &v)
        {
            return (elem == v.elem);
        }
        vector_reverse_iterator<T> &operator++()
        {
            elem--;
            return (*this);
        }
        vector_reverse_iterator &operator--()
        {
            elem++;
            return (*this);
        }
        vector_reverse_iterator &operator++(int) //get_sure of this , try to compile i++
        {
            vector_reverse_iterator<T> res(*this);
            ++(-this);
            return (res);
        }
        vector_reverse_iterator &operator--(int)
        {
            vector_reverse_iterator<T> res(*this);
            --(*this);
            return (res);
        }
        vector_reverse_iterator<T> &operator+(int a)
        {
            vector_reverse_iterator<T>  &res(*this);
            while (a--)
                --res;
            return (res);
        }
        vector_reverse_iterator<T> &operator-(int a)
        {
            vector_reverse_iterator<T>  &res(*this);
            while (a--)
                ++res;
            return (res);
        }
        vector_reverse_iterator<T> &operator+=(int a)
        {
            while (a--)
                ++(*this);
            return (*this);
        }
        vector_reverse_iterator<T> &operator-=(int a)
        {
            while (a--)
                --(*this);
            return (*this);
        }
        reference  operator*() const
        {
            return (*elem);
        }
        pointer operator->()
        {
            return (elem);
        }
        operator vector_reverse_iterator<const T> ()
        {
            return elem;
        }

    };