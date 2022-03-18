#ifndef MAP_ITERATORS
#define MAP_ITERATORS

#include "../STL/utility.hpp"

namespace ft
{
    template<class key, class T, class node, class Compare>
    class   map_iterator
    {
    public:
        /*************** member type **************/
        typedef ft::pair<const key, T>      value_type;
        // typedef value_type*                          pointer;
        typedef value_type*                               pointer;
        typedef std::bidirectional_iterator_tag     iterator_category; 
        typedef ptrdiff_t                            difference_type;
        typedef Compare                              key_compare;
        //typedef Distance                            distance_type;
        typedef value_type&                                  reference;
        typedef const value_type&                            const_reference;


    protected:
        node    *_lastElem;
        key_compare _comp;
    public:
        node* _node;
        /************* public function **********/
        map_iterator()
        {
            _node = NULL;
            _lastElem = _node;
            _comp = key_compare();
        }
        map_iterator(node *p, node *last)
        {
            _node = p;
            _lastElem = last;
            _comp = key_compare();
        }
        template<class key1, class T1, class node1, class Compare1>
        map_iterator(const map_iterator<key1, T1, node1, Compare1>& a)
        {
            _node = a.get_node(); //_node;
            _lastElem = a.get_last(); //_lastElem;
        }
        ~map_iterator()
        {}
        map_iterator &operator=(const map_iterator &v)
        {
            _node = v._node;
            _lastElem = v._lastElem;
            return (*this);
        }
        bool operator!=(const map_iterator &v)
        {
            return (_node != v._node);
        }
        bool operator==(const map_iterator &v)
        {
            return (_node == v._node);
        }
        map_iterator operator++()
        {
           // if (_node->right && _node->right == _lastElem) this will maybe replaced with this
           if (_node == _lastElem->left) /*means it's the last element*/
                _node = _lastElem;
            else if (_node->right && _node->right != _lastElem)
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
        map_iterator operator--() // add the case of --to first element in map
        {
            node* temp = _node;

            if (_node == _lastElem)
                _node = _lastElem->left;
            else if (_node == _lastElem->right)
                _node = _lastElem;
            else if (_node->left)
            {
                temp = _node->left;
                while (temp->right && temp->right != _lastElem)
                    temp = temp->right;
                _node = temp;
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
        map_iterator operator++(int) //get_sure of this , try to compile i++
        {
            map_iterator res(*this);
            ++(*this);
            return (res);
        }
        map_iterator operator--(int)
        {
            map_iterator res(*this);
            --(*this);
            return (res);
        }
        // map_iterator operator+(int a)
        // {
        //     map_iterator  res(*this);
        //     while (a--)
        //         ++res;
        //     return (res);
        // }
        // map_iterator operator-(int a)
        // {
        //     map_iterator res(*this);
        //     while (a--)
        //         --res;
        //     return (res);
        // }
        // map_iterator operator+=(int a)
        // {
        //     while (a--)
        //         ++(*this);
        //     return (*this);
        // }
        // map_iterator operator-=(int a)
        // {
        //     while (a--)
        //         --(*this);
        //     return (*this);
        // }
        reference  operator*() const
        {
            return (_node->content);
        }
        pointer operator->() const
        {
            return (&(_node->content));
        }
       operator map_iterator<const key, T, node, Compare> ()
        {
            return map_iterator<const key, T, node, Compare>(_node, _lastElem);
        }
        node *get_node() const {return _node;}
        node *get_last() const {return _lastElem;}
    };
};

    template<class key, class T, class node, class Compare>
    bool operator== (const ft::map_iterator<key, T, node, Compare>& lhs,
                   const ft::map_iterator<key, T, node, Compare>& rhs)
    {
        return (lhs.get_node() == rhs.get_node());
    }
    template<class key, class T, class node, class Compare>
    bool operator!= (const ft::map_iterator<key, T, node, Compare>& lhs,
                   const ft::map_iterator<key, T, node, Compare>& rhs)
    {
        return (lhs.get_node() != rhs.get_node());
    }


#endif