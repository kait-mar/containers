#include "containers/vector.hpp"
#include "containers/map.hpp"

int main()
{
    /*
         * strings to store the resutls
         */
        std::string str, ft_str;
        /*
         * var to store the size and the capacity
         */
        ft::vector<std::string>::size_type s, ft_s;
        ft::vector<std::string>::size_type c, ft_c;
        /*
         * bool to store the comparison
         */
        bool cond;

        std::vector<std::string> v(200, "hello");
        ft::vector<std::string> ft_v(200, "hello");
        ft::vector<std::string>::iterator valid_it;
        std::vector<std::string>::iterator it;
        ft::vector<std::string>::iterator ft_it;
        valid_it = ft_v.begin() + 99;
        it = v.erase(v.begin() + 100);
        ft_it = ft_v.erase(ft_v.begin() + 100);
        ft_it->length();

        s = v.size();
        ft_s = ft_v.size();
        c = v.capacity();
        ft_c = ft_v.capacity();
        for (size_t i = 0; i < v.size(); ++i)
            str += v[i];
        for (size_t i = 0; i < ft_v.size(); ++i)
            ft_str += ft_v[i];
        cond = ((str == ft_str) && (s == ft_s) && (c == ft_c) && (&(*valid_it) == &(*(ft_v.begin() + 99))));
        std::cout << cond << " ";
        cond = (cond && (std::distance(v.begin(), it) == std::distance(ft_v.begin(), ft_it)));
        std::cout << cond << " ";
    return 0;
}
