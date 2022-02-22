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
        typedef node*                          pointer;
        typedef std::bidirectional_iterator_tag     iterator_category; 
        typedef ptrdiff_t                            difference_type;
        typedef Compare                              key_compare;
        //typedef Distance                            distance_type;
        typedef T&                                  reference;


    private:
        pointer _node;
        //node    *_node;
public:
        /************* public function **********/
        map_iterator()
        {
            _node = NULL;
        }
        map_iterator(pointer p)
        {
            _node = p;
        }
        map_iterator(const map_iterator<T> &a)
        {
            _node = a.node;
        }
        ~map_iterator()
        {}
        map_iterator &operator=(const map_iterator<T> &v)
        {
            _node = v.node;
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
        map_iterator operator++() // add the case of ++to last element in map
        {
            if (_node->right)
            {
                _node = _node->right;
                while (_node->left)
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
                    while (temp && key_compare(temp->content->first, _node->first))
                        temp = temp->parent;
                    _node = temp;
                }
                //else if _node->parent == 0 ??
            }
            return (*this);
        }
        map_iterator operator--() // add the case of --to first element in map
        {
            pointer temp = _node;
            if (_node->left)
            {
                temp = _node->left;
                while (temp->right)
                    temp = temp->right;
                return (map_iterator(temp));
            }
            else
            {   //verify if _node is a right or left child
                if (_node->parent && _node == _node->parent->right)
                    _node = _node->parent;
                else if (_node->parent && _node == _node->parent->left)
                {
                    temp = _node->parent;
                    while (temp && key_compare(_node->content.first, temp->content.first))
                        temp = temp->parent;
                    _node = temp;
                }
            }
            return (*this);
        }
        /*map_iterator operator++(int) //get_sure of this , try to compile i++
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
        map_iterator operator+(int a)
        {
            map_iterator  res(*this);
            while (a--)
                ++res;
            return (res);
        }
        map_iterator operator-(int a)
        {
            map_iterator res(*this);
            while (a--)
                --res;
            return (res);
        }
        map_iterator operator+=(int a)
        {
            while (a--)
                ++(*this);
            return (*this);
        }
        map_iterator operator-=(int a)
        {
            while (a--)
                --(*this);
            return (*this);
        }*/
        value_type  operator*()
        {
            return (_node->content);
        }
        pointer operator->()
        {
            return (&_node->content);
        }

    };
};

#endif