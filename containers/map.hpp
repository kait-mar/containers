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
        typedef ft::map_iterator<const key_type, mapped_type, node, key_compare>          const_iterator;
        typedef ft::map_reverse_iterator<key_type, mapped_type, node, key_compare>          reverse_iterator;
        typedef typename allocator_type::reference                  reference;
        typedef typename allocator_type::const_reference            const_reference;
        typedef typename allocator_type::pointer                    pointer;
        typedef typename allocator_type::const_pointer              const_pointer;
        typedef ptrdiff_t                                           difference_type;
        typedef size_t                                              size_type;
        typedef std::allocator<node>                                allocator_node;

        // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
		class value_compare : std::binary_function<value_type, value_type, bool>
		{
		protected:
			key_compare _comp;

		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;

            value_compare(key_compare &c = key_compare()) : _comp(c) {} // constructed with map's comparison object
			bool operator()(const value_type &x, const value_type &y) const
			{
				return _comp(x.first, y.first);
			}
		};

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
        map (const map& x): map(x.begin(), x.end())
        {}

        /**     destructor  **/
        ~map()
        {
            clear();
        }

        map& operator= (const map& x)
        {
            this->clear();
             _root = NULL;
            _last_elem = _alloc_node.allocate(1);
            _alloc.construct(&(_last_elem->content), value_type());
            _last_elem->left = _root;
            _last_elem->right = _root;
            iterator    i = x.begin();
            while (i != x.end())
                insert(*(i++));
        }
        /**   iterators  **/

        iterator begin()
        { 
            return (iterator(_last_elem->right, _last_elem));
        }
        const_iterator begin() const
        { 
            return (const_iterator(_last_elem->right, _last_elem));
        }
        iterator    end()
        {
            return (iterator(_last_elem, _last_elem));
        }
        const_iterator    end() const
        {
            return (const_iterator(_last_elem, _last_elem));
        }
        reverse_iterator rbegin()
        { 
            return (reverse_iterator(_last_elem->left, _last_elem));
        }
        //const_reverse_iterator rbegin() const;
        reverse_iterator rend()
        {
            return (reverse_iterator(_last_elem, _last_elem));
        }
        // const_reverse_iterator rend() const;


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
            // value_type val = make_pair<key_type, mapped_type>(k, mapped_type());
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
            iterator    check;

            if ((check = find(val.first)) != end())
                return (check);
            check = position;
            if (position->first < val.first)
            {
                check++;
                while (check != end() && check->first < val.first)
                {
                    check++;
                    position++;
                }
            }
            else
            {
                check--;
                while (check != end() && check->first > val.first)
                {
                    check--;
                    position--;
                }
            }
            return (_put(val, position._node));
        }

        template <class InputIterator>
        void insert (InputIterator first, InputIterator last
                    /*, typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0*/)
        {
            //enable if is not a value type
            //try to remove the enable if !!!!!!!!!!!!!
            while (first != last)
                insert(*first++);
        }

        size_type erase (const key_type& k)
        {
            iterator    i = find(k);

            if (i == end())
                return (0);
            node    *_node = i._node;
            deleteNode(_node);
            _size--;

            return (1);
        }
        void erase (iterator position)
        {
            erase(position->first);
        }
        void erase (iterator first, iterator last)
        {
            while (first != last)
            {
                erase(first++);
            }
        }

        /*
            Removes all elements from the map container
        */
        void clear()
        {
            iterator j, i;
            i = begin();
            while (i != end())
             {
                j = i++;
                erase(j);
             }
        }

        /*
            Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
        */
        void swap (map& x)
        {
            map temp1(begin(), end());
            this->operator=(x);
            x = temp1;
        }

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
        const_iterator find (const key_type& k) const
        {
            const_iterator    i = begin();
            while (i != end())
            {
                if (!_comp(i->first, k) && !_comp(k, i->first)) //use compare
                    return (i);
                ++i;
            }
            return (i);
        }
        size_type count (const key_type& k) const
        {
            if (find(k) == end())
                return 0;
            else
                return 1;
        }

         iterator upper_bound(const key_type& k)
        {
            iterator i = begin();

            while (i != end())
            {
                if (_comp(k, i->first))
                    break;
                i++;
            }
            return i;  
        }
        const_iterator upper_bound(const key_type& k) const
        {
            const_iterator i = begin();

            while (i != end())
            {
                if (_comp(k, i->first))
                    break;
                i++;
            }
            return i;  
        }
        iterator lower_bound(const key_type& k)
        {
            iterator i = begin();

            while  (i != end())
            {
                if (!_comp(i->first, k))
                    break;
            }
            return i;  
        }
        const_iterator lower_bound(const key_type& k) const
        {
            const_iterator i = begin();

            while  (i != end())
            {
                if (!_comp(i->first, k))
                    break;
            }
            return i;  
        }

        /*
            Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
        */
        pair<iterator, iterator> equal_range(const key_type &k)
		{
			return (pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
		}
        pair<const_iterator,const_iterator> equal_range (const key_type& k) const
        {
			return (pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
		}

        /*
            observers
        */

       key_compare key_comp() const {return (_comp);}
       value_compare value_comp() const { return (_comp); }

        allocator_type get_allocator() const {return (_alloc);}

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

        void    deallocate_node(node *_node)
        {
            if (!_node)
                return ;
            _alloc.destroy(&(_node->content));
            _alloc_node.deallocate(_node, 1);
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

        void    deleteNode(node *_node)
        {
            node    *tmp;

            if (_node == _root && _size == 1)
            {
                _root = _last_elem;
                _last_elem->left = _root;
                _last_elem->right = _root;
                deallocate_node(_node);
            }
            else if (_node == _root)
            {
                if (_node == _last_elem->left && _size == 2)
                {
                    _root = _node->left;
                    _last_elem->left = _node->left;
                    _root->right = _last_elem;
                    deallocate_node(_node);
                    return ;
                }
                /*else if (_node == _last_elem->left)
                {
                    //search for the max node in _node->left or the node that preceede our _node
                    iterator    i(_node, _last_elem);
                    i--;
                    tmp = i._node;
                }*/
                else
                    tmp = minNode(_node->right);
                if (tmp == _node->right)
                {
                    _root = tmp;
                    tmp->parent = NULL;
                    tmp->left = _node->left;
                    if (tmp->left)
                        tmp->left->parent = tmp;
                    if (_node == _last_elem->left)
                        _last_elem->left = tmp;
                    if (_last_elem->right == _node)
                        _last_elem->right = tmp;
                    deallocate_node(_node);
                    update_balance(tmp);
                    return ;
                }
                node    *_temp = tmp->parent;
                node    *replace = construct_node(tmp);
                deleteNode2(tmp);
                if (_node->left)
                    _node->left->parent = replace;
                if (_node->right)
                    _node->right->parent = replace;
                replace->left = _node->left;
                replace->right = _node->right;
                if (replace->left)
                    replace->left->parent = replace;
                if (replace->right)
                    replace->right->parent = replace;
                _root = replace;
                //deleteNode(_node);
                deallocate_node(_node);
                update_balance(_temp);
            }
             // node with only one child or no child
            else if (_node->left == _last_elem || _node->right == _last_elem)
            {
                tmp = _node->parent;
                if (_node->left == _last_elem)
                {
                    //the last node will always be in left of her parent
                    _node->parent->left = _last_elem;
                    _last_elem->right = _node->parent;
                }
                else
                {
                    _node->parent->right = _last_elem;
                    _last_elem->left = _node->parent;
                }
                deallocate_node(_node);
                update_balance(tmp);
            }
            else if (_node->left == NULL || _node->right == NULL)
            {
                if (_node->left)
                    tmp = _node->left;
                else if (_node->right)
                    tmp = _node->right;
                else
                {
                    tmp = NULL;
                    //_node = NULL;
                }
                if (tmp)
                    tmp->parent = _node->parent;
                if (_node->parent->left == _node) /*is left*/
                    _node->parent->left = tmp;
                else                              /*is right*/
                    _node->parent->right = tmp;
                deallocate_node(_node);
                /*_node->parent = tmp->parent;
                if (tmp->parent->left == tmp)
                    tmp->parent->left = _node;
                else
                    tmp->parent->right = _node;
                _node->content = tmp->content;
                _node->right = tmp->right;
                _node->left = tmp->left;
                deallocate_node(tmp);*/
                update_balance(tmp);
            }
            else
            {
                tmp = minNode(_node->right);
                node    *_temp = tmp->parent;
                node    *replace = construct_node(tmp, _node->parent);
                deleteNode2(tmp);
                if (_node->parent && _node->parent->left == _node)
                    _node->parent->left = replace;
                else if (_node->parent)
                    _node->parent->right = replace;
                replace->left = _node->left;
                replace->right = _node->right;
                if (_node->left)
                    _node->left->parent = replace;
                if (_node->right)
                    _node->right->parent = replace;
                //deleteNode(_node);
                deallocate_node(_node);
                update_balance(_temp);
            }
        }

        void    deleteNode2(node *_node)
        {
            node    *tmp;

            if (!_node)
                return ;
             // this version is only for a node with only one child or no child wich is right
            if (_node->right == _last_elem)
            {
                tmp = _node->parent;
                _node->parent->right = _last_elem;
                //_last_elem->left = _node->parent;
                deallocate_node(_node);
                update_balance(tmp);
            }
            else if (_node->left == NULL || _node->right == NULL)
            {
                node    *temp2;
                if (_node->left)
                    tmp = _node->left;
                else if (_node->right)
                    tmp = _node->right;
                else
                {
                    tmp = NULL;
                    if (_node->parent)
                        temp2 = _node->parent;
                }
                if (tmp)
                    tmp->parent = _node->parent;
                if (_node->parent->left == _node) /*is left*/
                    _node->parent->left = tmp;
                else                              /*is right*/
                    _node->parent->right = tmp;
                deallocate_node(_node);
                /*_node->parent = tmp->parent;
                if (tmp->parent->left == tmp)
                    tmp->parent->left = _node;
                else
                    tmp->parent->right = _node;
                _node->content = tmp->content;
                _node->right = tmp->right;
                _node->left = tmp->left;
                deallocate_node(tmp);*/
                if (tmp)
                    update_balance(tmp);
                else if (temp2)
                    update_balance(temp2);
            }
        }

        node    *construct_node(node *_node, node *parent = NULL)
        {
            node    *_new = allocate_node(_node->content, parent);
            _new->left = _node->left;
            _new->right = _node->right;
            if (_last_elem->left == _node)
                _last_elem->left = _new;
            return (_new);
        }

        int     balance_factor(node *_node)
        {
            if (_node == NULL)
                return 0;
            return (height(_node->left) - height(_node->right));
        }

        void    update_balance(node *_node)
        {
            //if (_node->balance_factor > 1 || _node->balance_factor < -1)
            if (balance_factor(_node) > 1 || balance_factor(_node) < -1)
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
                // if (_node->parent->balance_factor != 0)
                if (balance_factor(_node->parent) != 0)
                    update_balance(_node->parent);
            }
        }

        void    rebalance(node *_node)
        {
            // if (_node->balance_factor < 0 && _node->right)
            if (balance_factor(_node) < 0 && _node->right)
            {
                if (balance_factor(_node->right) > 0)
                {
                    rotate_right(_node->right);
                    rotate_left(_node);
                }
                else
                    rotate_left(_node);
            }
            else if (balance_factor(_node) > 0 && _node->left)
            {
                if (balance_factor(_node->left) < 0)
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

        node    *minNode(node *_node)
        {
            if (_node->left && _node->left != _last_elem)
                return (minNode(_node->left));
            return (_node);
        }

        int height(node *_node)
        {
            if (!_node || _node == _last_elem)
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