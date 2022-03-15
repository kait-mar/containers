#include "containers/vector.hpp"
#include "containers/map.hpp"

int main()
{
    /*ft::map<int, int> a;
    int i = 5;
    ft::pair<const int, int>  s(7, i);
    a.insert(s);
    ft::pair<const int, int>  t(1, i);
    a.insert(t);
    ft::pair<const int, int>  u(3, i);
    a.insert(u);
    a[3] = 9835;
    // a[12] = 12;
    // a[5] = 5;
    // a[75] = 75;
    //a[98] = 42;
    a.erase(75);
    a.erase(3);
    a.erase(7);
    // for (ft::map<int, int>::iterator j = a.begin(); j != a.end(); ++j)
    //     std::cout<< j->first << std::endl;
    for (ft::map<int, int>::iterator j = a.begin(); j != a.end(); ++j)
    {
        std::cout<< j->first << std::endl;
    }
    a.clear();
    for (ft::map<int, int>::iterator j = a.begin(); j != a.end(); ++j)
    {
        std::cout<< j->first << std::endl;
    }*/
    /*ft::map<int, int>::const_iterator j = a.begin();*/
    std::vector<int> a(6, 43);
    ft::vector<double>  a2;
    std::vector<int>::iterator it = a.begin() + 3;
    std::cout << it[2] << std::endl;
    // ft::vector<int> av;
    // for (int i = 0; i < 8; i++)
    //     av.push_back(i);
    // for (ft::vector<int>::const_reverse_iterator it = av.rbegin(); it != av.rend(); it++)
    //     std::cout << *it << std::endl;
    return 0;
}
