#include <vector>
#include <iostream>

int main()
{
    std::vector<int> vax(5, 42);
    std::cout << "********before resizing\n";
    for (int i = 0; i < vax.size(); i++)
        std::cout<< vax[i] << " ";
    std::cout<< " | capacity = " << vax.capacity();
    vax.resize(13, 7);
     std::cout << "\n*****AFTER resizing\n";
    for (int i = 0; i < vax.size(); i++)
        std::cout<< vax[i] << " ";
    std::cout<< " | capacity = " << vax.capacity();
}
