#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <exception>
#include "../iterators/map_iterators.hpp"
#include "../STL/utility.hpp"

namespace   ft
{
    template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > class map
    {
    private:
        struct node
        {
            ft::pair<const Key, T>                  content;
            node*                                   parent;
            node*                                   left;
            node*                                   right;
            int                                     balance_factor;    /* = h(left) - h(right) */
            // bool        is_right;
            // bool        is_left;
            // bool        is_leaf;
        };
    public:

                    /**** member type  ****/
        typedef Key                                                 key_type;
        typedef T                                                   mapped_type;
        typedef ft::pair<const key_type, mapped_type>               value_type;
        typedef Compare                                             key_compare;
        //typedef value_compare                                     nested function class
        typedef Alloc                                                               allocator_type;
        typedef ft::map_iterator<key_type, mapped_type, node, key_compare>          iterator;
    // typedef typename ft::map_iterator<Key, T, Compare, Node, false>     iterator;
    //typedef typename ft::map_iterator<Key, T, Compare, Node, true>      const_iterator;
        typedef typename allocator_type::reference                  reference;
        typedef typename allocator_type::const_reference            const_reference;
        typedef typename allocator_type::pointer                    pointer;
        typedef typename allocator_type::const_pointer              const_pointer;
        typedef ptrdiff_t                                           difference_type;
        typedef size_t                                              size_type;
        typedef std::allocator<node>                                allocator_node;

    private:
        size_type           _size;
        allocator_type      _alloc;
        allocator_node      _alloc_node;
        key_compare         _comp;
        node                *_root;
        node                *_last_elem;

    public:
        explicit map (const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()):
                _size(0), _alloc(alloc), _alloc_node(allocator_node()), _comp(comp)
        {
            _root = NULL;
            _last_elem = _alloc_node.allocate(1);
            _alloc.construct(&(_last_elem->content), value_type());
            _last_elem->left = _root;
            _last_elem->right = _root;
        }
        template <class InputIterator>
        map (InputIterator first, InputIterator last,
        const key_compare& comp = key_compare(),
        const allocator_type& alloc = allocator_type()):
        _alloc(alloc), _alloc_node(allocator_node()), _size(0), _comp(comp)
        {
            _root = NULL;
            _last_elem = _alloc_node.allocate(1);
            _alloc.construct(&(_last_elem->content), value_type());
            _last_elem->left = _root;
            _last_elem->right = _root;
            while (first != last)
                insert(*(first++));
        }
        map (const map& x);

        /**   iterators  **/

        iterator begin() { return (iterator(_last_elem->right, _last_elem));}
        iterator    end() { return (iterator(_last_elem, _last_elem));}

        /**     capacity    **/
        size_t  size() {return (_size);}
        bool    empty() {return (_size == 0);}
        // size_type max_size() const;

        /** element access  **/
        mapped_type& operator[] (const key_type& k)
        {
            iterator    i;
            if ((i = find(k)) != end())
                return (i->second);
            T m = T();
            const value_type  _new(k, m);
            return const_cast<int&>(insert(_new).first->first);
        }

        /** modifiers   **/

        ft::pair<iterator,bool> insert (const value_type& val)
        {
            if (!_root)
            {
                _size++;
                _root = allocate_node(val);
                _root->right = _last_elem;
                _root->left = _last_elem;
                _last_elem->left = _root;
                _last_elem->right = _root;
                return (ft::make_pair<iterator, bool>(iterator(_root, _last_elem), true));
            }
            iterator i;
            if ((i = find(val.first)) != end())
                return (ft::make_pair<iterator, bool>(i, false));
            _size++;
            return ft::make_pair<iterator, bool>(_put(val, _root), true);
        }

    /*
        The function optimizes its insertion time if position points to the element that will precede the inserted element.
    */
        iterator insert (iterator position, const value_type& val)
        {
            //how to know if it precede or not !!
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last,
                    typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type var = 0)
        {
            //enable if is not a value type
        }

        void erase (iterator position);
            /** operations **/
        iterator find (const key_type& k)
        {
            iterator    i = begin();
            while (i != end())
            {
                if (!_comp(i->first, k) && !_comp(k, i->first)) //use compare
                    return (i);
                ++i;
            }
            return (i);
        }
        // const_iterator find (const key_type& k) const;
        size_type count (const key_type& k) const
        {
            if (find(k) == end())
                return 0;
            else
                return 1;
        }

        /*
            observers
        */

       key_compare key_comp() const {return (_comp);}

    protected:

        node    *allocate_node(const value_type& val, node *parent = NULL)
        {
            node    *_node;

            _node = _alloc_node.allocate(1);
            _alloc.construct(&(_node->content), val);
            _node->left = NULL;
            _node->right = NULL;
            _node->parent = parent;
            _node->balance_factor = 0;
            return (_node);
        }

        iterator    _put(const value_type& val, node *_node)
        {
            node    *_new = allocate_node(val, _node); //this is the new node we'll insert

            if (_comp(val.first, _node->content.first))
            {
                if (!_node->left)
                {
                    _node->left = _new;
                    update_balance(_new);
                }
                else if (_node->left && _node->left == _last_elem)
                {
                    _node->left = _new;
                    _new->left = _last_elem;
                    _last_elem->right = _new;
                    update_balance(_new);
                }
                else
                    _put(val, _node->left);
            }
            else
            {
                if (!_node->right)
                {
                    _node->right = _new;
                    update_balance(_new);
                }
                else if (_node->right && _node->right == _last_elem)
                {
                    _node->right = _new;
                    _new->right = _last_elem;
                    _last_elem->left = _new;
                    update_balance(_new);
                }
                else
                    _put(val, _node->right);
            }
            return (iterator(_new, _last_elem));
        }

        void    update_balance(node *_node)
        {
            if (_node->balance_factor > 1 || _node->balance_factor < -1)
            {
                rebalance(_node);
                return ;
            }
            if (_node->parent)
            {
                if (_node->parent->left == _node)
                    _node->parent->balance_factor++;
                else if (_node->parent->right == _node)
                    _node->parent->balance_factor--;
                if (_node->parent->balance_factor != 0)
                    update_balance(_node->parent);
            }
        }

        void    rebalance(node *_node)
        {
            if (_node->balance_factor < 0 && _node->right)
            {
                if (_node->right->balance_factor > 0)
                {
                    rotate_right(_node->right);
                    rotate_left(_node);
                }
                else
                    rotate_left(_node);
            }
            else if (_node->balance_factor > 0 && _node->left)
            {
                if (_node->left->balance_factor < 0)
                {
                    rotate_left(_node->left); 
                    rotate_right(_node);
                }
                else
                    rotate_right(_node);
            }
        }

        void    rotate_left(node *_node)  //don't yu need to update the is_right/left of nodes ?
        {
            node    *new_root = _node->right;
            _node->right = new_root->left;
            if (new_root->left /*this has just been added*/ && new_root->left != _last_elem)
                new_root->left->parent = _node;
            new_root->parent = _node->parent;
            if (!_node->parent)
                _root = new_root;
            else
            {
                if (_node->parent->left == _node /*is_left*/)
                    _node->parent->left = new_root;
                else /*is_right*/
                    _node->parent->right = new_root;
            }
            new_root->left = _node;
            _node->parent = new_root;
            _node->balance_factor = _node->balance_factor + 1 - std::min(new_root->balance_factor, 0);
            new_root->balance_factor = new_root->balance_factor + 1 + std::max(_node->balance_factor, 0);
        }

        void    rotate_right(node *_node) //don't yu need to update the is_right/left of nodes ?
        {
            node    *new_root = _node->left;
            _node->left = new_root->right;
            if (new_root->right /*this has just been added*/ && new_root->right != _last_elem)
                new_root->right->parent = _node;
            new_root->parent = _node->parent;
            if (!_node->parent)
                _root = new_root;
            else
            {
                if (_node->parent->left == _node)
                    _node->parent->left = new_root;
                else
                    _node->parent->right = new_root;
            }
            new_root->right = _node;
            _node->parent = new_root;
            _node->balance_factor = _node->balance_factor + 1 - std::min(new_root->balance_factor, 0);
            new_root->balance_factor = new_root->balance_factor + 1 + std::max(_node->balance_factor, 0);
            //_node->left = NULL; /*this has just been added and could be wrong*/
        }

        int height(node *_node)
        {
            if (!_node)
                return (0);
            return (1 + std::max(height(_node->left), height(_node->right)));
        }
    };
}


/*
    _comp is equivalent to operator <. So:
        - operator>(lhs, rhs)  <==>  _comp(rhs, lhs)
        - operator<=(lhs, rhs)  <==>  !_comp(rhs, lhs)
        - operator>=(lhs, rhs)  <==>  !_comp(lhs, rhs)
*/
#endif