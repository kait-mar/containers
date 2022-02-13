#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v(5, 42);
    std::cout << "********before resizing\n";
    for (int i = 0; i < v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    v.resize(13, 7);
     std::cout << "\n*****AFTER resizing\n";
    for (int i = 0; i < v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
}