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
    std::string m = "labhairi";
    ft::vector<std::string> av(m, m);
    //std::vector<std::string> av(m, m);
   
    //ft::vector<std::string>::iterator   k = av.begin();
   // ft::vector<std::string>::iterator   l = 3 + k;

    std::cout << av[0] << std::endl;
    return 0;
}
