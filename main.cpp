#include "containers/vector.hpp"

int main()
{
    std::vector<int> v(5, 2);
    std::vector<int>::const_iterator   i = v.begin();
    //*i = 7;
    std::cout<< *i;
    ft::vector<int> a(5, 2);
    ft::vector<int>::const_iterator   j = a.begin();
    j++;
    std::cout<< *i;
    return 0;
}
