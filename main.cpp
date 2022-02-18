#include "vector.hpp"

int main()
{
    ft::vector<int> v(3, 42);
    std::vector<int> a(3,42);
    std::vector<int> temp(3, 5);
    //v.reserve(11);
    //a.reserve(11);
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    v.insert(v.begin() + 2, temp.begin(), temp.end() - 1);
     std::cout << "\n*****AFTER\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    std::cout << "\n----------------\n";
    for (int i = 0; i < (int)a.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();
    a.insert(a.begin() + 2, temp.begin(), temp.end() - 1);
     std::cout << "\n*****AFTER\n";
    for (int i = 0; i < (int)a.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();
    return 0;
}
