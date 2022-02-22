#ifndef MAP_HPP
#define MAP_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <exception>
#include "../iterators/map_iterators.hpp"
#include "../STL/utility.hpp"

template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = std::less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
           > class map
{
private:
    struct node
    {
        ft::pair<const key_type, mapped_type>  content;
        node*                                   parent;
        node*                                   left;
        node*                                   right;
        int                                     balance_factor    /* = h(left) - h(right) */
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
    typedef ft::map_iterator<key_type, mapped_type, node, key_compare>          itertor;
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
            _alloc(alloc), _alloc_node(allocator_node()), _size(0), _comp(comp)
    {
        //_root = allocate_node();
        _root = NULL;
        _last_elem = _root;
    }
    template <class InputIterator>
    map (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type()):
       _alloc(alloc), _alloc_node(allocator_node()), _size(0), _comp(comp)
    {
        while (first != last)
            insert(*(first++));
    }
    map (const map& x);

    /**   iterators  **/
    
    iterator begin() { return (iterator(_root));}
    iterator    end() { return (iterator(_last_elem));}

    /**     capacity    **/
    size_t  size() {return (_size);}
    bool    empty() {return (_size == 0);}
    // size_type max_size() const;

    /** modifiers   **/

    pair<iterator,bool> insert (const value_type& val)
    {
        if (!_root)
        {
            _root = allocate_node(val);
            _last_elem = root;
            return (ft::make_pair<iterator, bool>(iterator(&_root->content), true));
        }
        itertor i;
        if ((i = find(val.first)) != end())
            return (ft::make_pair<iterator, bool>(i, false));
        _put(val, _root);
    }

        /** operations **/
    iterator find (const key_type& k)
    {
        iterator    i = begin();
        while (i != end())
        {
            if (*i->first == k)
                break ;
            i++;
        }
        return (i);
    }
    // const_iterator find (const key_type& k) const;

protected:
    node    *allocate_node(const value_type& val)
    {
        node    *_node;
        _node = _alloc_node(1);
        _node->content = _alloc(1);
        _alloc_node.construct(_node->content, val);
        _node->left = NULL;
        _node->right = NULL;
        _node->is_right = 0;
        _node->is_left = 0;
        _node->is_leaf = 0;
    }

    node    *allocate_node(const value_type& val, node *parent)
    {
        node    *_node;

        _node = _alloc_node.allocate(1);
        // _alloc_node.construct(_node->content, val);
        _alloc.construct(&(_node->content), val);
        _node->left = NULL;
        _node->right = NULL;
        _node->is_right = 0;
        _node->is_left = 0;
        _node->is_leaf = 1;
        _node->parent = parent; //check if we have no parent or just delete this link to parent
        _node->balance_factor = height(_node->left) - height(_node->right); //we don't need it saraha
        return (_node);
    }

    void    _put(const value_type& val, node *_node)
    {
        if (key_compare(val.key, node->content.key))
        {
            if (!node->left)
            {
                node->left = allocate_node(val, node);
                update_balance(node->left);
            }
            else
                _put(val, node->left);
        }
        else
        {
            if (!node->right)
            {
                node->right = allocate_node(val, node);
                update_balance(node->right);
            }
            else
                _put(val, node->right);
        }
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
            if (_node->is_left)
                _node->parent->balance_factor++;
            else if (_node->is_right)
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
        if (new_root->left)
            new_root->left->parent = _node;
        new_root->parent = _node->parent;
        if (!_node->parent)
            _root = new_root;
        else
        {
            if (_node->is_left)
                _node->parent->left = new_root;
            else
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
        _node->right = new_root->right;
        if (new_root->right)
            new_root->right->parent = _node;
        new_root->parent = _node->parent;
        if (!_node->parent)
            _root = new_root;
        else
        {
            if (_node->is_left)
                _node->parent->left = new_root;
            else
                _node->parent->right = new_root;
        }
        new_root->right = _node;
        _node->parent = new_root;
        _node->balance_factor = _node->balance_factor + 1 - std::min(new_root->balance_factor, 0);
        new_root->balance_factor = new_root->balance_factor + 1 + std::max(_node->balance_factor, 0);
    }
    int height(node *_node)
    {
        if (!_node)
            return (0);
        return (1 + std::max(height(_node->left), height(_node->right)));
    }
};

// _comp is equivalent to operator <. So:
//      - operator>(lhs, rhs)  <==>  _comp(rhs, lhs)
//      - operator<=(lhs, rhs)  <==>  !_comp(rhs, lhs)
//      - operator>=(lhs, rhs)  <==>  !_comp(lhs, rhs)
#endif