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
        /*  map reverse iterator    */
    template<class key, class T, class node, class Compare>
    class   map_reverse_iterator
    {
    public:
        /*************** member type **************/
        typedef ft::pair<const key, T>      value_type;
        // typedef value_type*                          pointer;
        typedef node*                               pointer;
        typedef std::bidirectional_iterator_tag     iterator_category; 
        typedef ptrdiff_t                            difference_type;
        typedef Compare                              key_compare;
        //typedef Distance                            distance_type;
        typedef T&                                  reference;


    private:
        pointer _lastElem;
        key_compare _comp;
    public:
        pointer _node;
        /************* public function **********/
        map_reverse_iterator()
        {
            _node = NULL;
            _lastElem = _node;
            _comp = key_compare();
        }
        map_reverse_iterator(pointer p, pointer last)
        {
            _node = p;
            _lastElem = last;
            _comp = key_compare();
        }
        map_reverse_iterator(const map_reverse_iterator &a)
        {
            _node = a._node;
            _lastElem = a._lastElem;
        }
        ~map_reverse_iterator()
        {}
        map_reverse_iterator &operator=(const map_reverse_iterator &v)
        {
            _node = v._node;
            _lastElem = v._lastElem;
            return (*this);
        }
        bool operator!=(const map_reverse_iterator &v)
        {
            return (_node != v._node);
        }
        bool operator==(const map_reverse_iterator &v)
        {
            return (_node == v._node);
        }
        map_reverse_iterator operator++()
        {
            pointer temp = _node;

            if (_node == _lastElem->right)
                _node = _lastElem;
            else if (_node == _lastElem->right)
                _node = _lastElem;
            else if (_node->left)
            {
                temp = _node->left;
                while (temp->right && temp->right != _lastElem)
                    temp = temp->right;
                return (map_reverse_iterator(temp));
            }
            else
            {
                if (_node->parent && _node == _node->parent->right)
                    _node = _node->parent;
                else if (_node->parent && _node == _node->parent->left)
                {
                    temp = _node->parent;
                    while (temp && _comp(_node->content.first, temp->content.first))
                        temp = temp->parent;
                    _node = temp;
                }
            }
            return (*this);
        }
        map_reverse_iterator operator--() // add the case of --to first element in map
        {
           if (_node == _lastElem) /*means it's the last element*/
                _node = _lastElem->right;
            else if (_node->right)
            {
                _node = _node->right;
                while (_node->left && _node->left != _lastElem)
                    _node = _node->left;
            }
            else
            {
                //verify if _node is a right or left child
                if (_node->parent && _node == _node->parent->left)
                    _node = _node->parent;
                else if (_node->parent && _node == _node->parent->right)
                {
                    node* temp = _node->parent;
                    while (temp && _comp(temp->content.first, _node->content.first))
                        temp = temp->parent;
                    _node = temp;
                }
                //else if _node->parent == 0 ??
            }
            return (*this);
        }
        map_reverse_iterator operator++(int) //get_sure of this , try to compile i++
        {
            map_reverse_iterator res(*this);
            ++(*this);
            return (res);
        }
        map_reverse_iterator operator--(int)
        {
            map_reverse_iterator res(*this);
            --(*this);
            return (res);
        }
        map_reverse_iterator operator+(int a)
        {
            map_reverse_iterator  res(*this);
            while (a--)
                ++res;
            return (res);
        }
        map_reverse_iterator operator-(int a)
        {
            map_reverse_iterator res(*this);
            while (a--)
                --res;
            return (res);
        }
        map_reverse_iterator operator+=(int a)
        {
            while (a--)
                ++(*this);
            return (*this);
        }
        map_reverse_iterator operator-=(int a)
        {
            while (a--)
                --(*this);
            return (*this);
        }
        value_type  operator*()
        {
            return (_node->content);
        }
        value_type *operator->()
        {
            return (&_node->content);
        }
        operator map_reverse_iterator<const key, T, node, Compare> ()
        {
            return map_reverse_iterator<const key, T, node, Compare>(_node, _lastElem);
        }
    };