#include "containers/vector.hpp"
#include "containers/map.hpp"

int main()
{
    ft::map<int, int> a;
    int i = 5;
    ft::pair<const int, int>  s(i = 7, i);
    a.insert(s);
    ft::pair<const int, int>  t(i = 1, i);
    a.insert(t);
    ft::pair<const int, int>  u(i = 3, i);
    a.insert(u);
    a[3] = 9835;
    // a[12] = 12;
    // a[5] = 5;
    // a[75] = 75;
    //a[98] = 42;
    /*a.erase(75);
    a.erase(3);
    a.erase(7);*/
    // for (ft::map<int, int>::iterator j = a.begin(); j != a.end(); ++j)
    //     std::cout<< j->first << std::endl;
    a.clear();
    for (ft::map<int, int>::iterator j = a.begin(); j != a.end(); ++j)
    {
        if (j == a.end())
            std::cout << "yes\n";
        std::cout<< j->first << std::endl;
    }
        
    /*ft::vector<int>  a(5);
    ft::vector<int> b(6);
    if (a == b)
        std::cout << "yes";*/
    return 0;
}
