#include "containers/vector.hpp"
#include "containers/map.hpp"

int main()
{
    ft::map<int, int> a;
    int i = 5;
    // ft::pair<const int, int>  q(i, i);
    // a.insert(q);
    ft::pair<const int, int>  s(i = 7, i);
    a.insert(s);
    ft::pair<const int, int>  t(i = 1, i);
    a.insert(t);
    ft::pair<const int, int>  u(i = 3, i);
    a.insert(u);
    a[3] = 9835;
    // ft::pair<const int, int>  v(i = 15, i);
    // a.insert(u);
    // ft::map<int, int>::iterator k = a.find(3);
    // std::cout<< k->first << std::endl;
    a[98] = 42;
    for (ft::map<int, int>::iterator j = a.begin(); j != a.end(); ++j)
        std::cout<< j->first << std::endl;
    //std::cout<< a[3] << std::endl;
    //a.insert(const_cast<const ft::pair<int,int>& >(ft::make_pair(6, 7)));
    /*std::map<int, std::string>  m;
    m.insert(std::make_pair(5, "five"));

    for (std::map<int, std::string>::iterator i = m.begin(); i != m.end(); i++)
        std::cout<< i->first << std::endl;*/
    return 0;
}
