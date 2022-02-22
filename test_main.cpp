#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<int, std::string>  m;
    m.insert(std::make_pair<int, std::string>(5, "five"));
    m.insert(std::make_pair<int, std::string>(3, "three"));
    m.insert(std::make_pair<int, std::string>(2, "two"));
    m.insert(std::make_pair<int, std::string>(20, "twenty"));
    m.insert(std::make_pair<int, std::string>(9, "five"));
    m.insert(std::make_pair<int, std::string>(-6, "five"));
    m.insert(std::make_pair<int, std::string>(15, "five"));
    m.insert(std::make_pair<int, std::string>(10, "five"));
    m.insert(std::make_pair<int, std::string>(-20, "five"));
    m.insert(std::make_pair<int, std::string>(7, "five"));
    m.insert(std::make_pair<int, std::string>(-13, "five"));

    // std::map<int, std::string>::iterator j(&(std::pair<int, std::string>(3, "three")));


    



    for (std::map<int, std::string>::iterator i = m.begin(); i != m.end(); i++)
        std::cout<<  i->first << std::endl;
    return 0;
}