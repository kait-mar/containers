#include "containers/vector.hpp"
#include "containers/map.hpp"

int main()
{
    std::map<int, std::string>  m;
    m.insert(std::make_pair(5, "five"));

    for (std::map<int, std::string>::iterator i = m.begin(); i != m.end(); i++)
        std::cout<< i->first << std::endl;
    return 0;
}
