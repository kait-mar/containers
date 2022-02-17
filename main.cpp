#include "vector.hpp"
 //fixing push back prototype why can't give it directly number
int main()
{
    ft::vector<int> v(5, 42);
    std::vector<int> a(5,42);
    //v.push_back(i = 1);
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    /*std::cout << "\n inserting return = " << *(*/v.insert(v.begin() + 1, 4, -42);
     std::cout << "\n*****AFTER\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    std::cout << "\n----------------\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();
    /*std::cout << "\n inserting return = " << *(*/a.insert(a.begin() + 1, 4, -42);
     std::cout << "\n*****AFTER\n";
    for (int i = 0; i < (int)a.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();
    return 0;
}