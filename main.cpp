#include "containers/vector.hpp"
#include "containers/map.hpp"
#include <random>
#include <iomanip>
#include <sys/time.h>
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20


template <typename Iter1, typename Iter2>
bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
{
    std::cout << "begin\n";
    for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        if (first1->first != first2->first || first1->second != first2->second)
        {
            std::cout << first1->first << " | " << first2->first << std::endl;
            return false;
        }
    std::cout << "end\n";  
    return true;
}




int main()
{
    ft::map<int, char> m1;
        for (int i = 0; i < 10; i++)
            m1.insert(ft::make_pair(i, 'a'));
        std::cout << "************1*********\n";
        ft::map<int, char> copy_m(m1);
        std::cout << "************2*********\n";
        /*-----------------------------------------------------------------------------------------------------------*/
        /*--------------- declare tow strings to store the results ------*/
        std::string res, res1;
        /*--------------------------------------------------------*/
        for (ft::map<int, char>::iterator it = m1.begin(); it != m1.end(); ++it) // fill res from m1
            res += it->second;

        for (ft::map<int, char>::iterator it = copy_m.begin(); it != copy_m.end(); ++it) // fill res from copy_m
            res1 += it->second;
        EQUAL(res == res1);
        std::cout << "************3*********\n";

    return 0;
}
