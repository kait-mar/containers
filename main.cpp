#include "containers/vector.hpp"
#include "containers/map.hpp"

int main()
{
    ft::map<int, char> my_m;
    my_m.insert(ft::make_pair(1, static_cast<char>('g')));
    ft::map<int, char>::iterator ft_iter = my_m.begin();
    char ft_res = 'a';
    char b = ft_iter->second;
    std::cout << b <<  std::endl;
    for (ft::map<int, char>::reverse_iterator it = my_m.rbegin(); it != my_m.rend(); ++it) // fill ft_res from ft_m1
         ft_res = it->first;
    ft::map<int, int> my_m2;
    my_m2.insert(ft::make_pair(1, 5));
    my_m2.insert(ft::make_pair(3, 3));
    ft::map<int, int>::reverse_iterator it2 = my_m2.rbegin();
    std::cout << it2->second;
    return 0;
}
