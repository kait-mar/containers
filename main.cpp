#include "containers/vector.hpp"
#include "containers/map.hpp"
// #define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))

// template <typename Iter1, typename Iter2>
// bool compareMaps(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
// {
//     for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
//         if (first1->first != first2->first || first1->second != first2->second)
//             return false;
//     return true;
// }

// struct classcomp
// {
//     bool operator()(const char &lhs, const char &rhs) const
//     {
//         return lhs < rhs;
//     }
// };

// bool fncomp(char lhs, char rhs) { return lhs < rhs; }

int main()
{
    /*std::map<int, std::string> m1; // fill constructor
        ft::map<int, std::string> ft_m1;
        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string2"));
        }

        std::map<int, std::string> m2;                         
        std::map<int, std::string> m3(m1.begin(), m1.end());   // range constructor with normal iterators
        std::map<int, std::string> m4(m3);                     // copy constructor
        std::map<int, std::string> m5(m1.rbegin(), m1.rend()); // range constructor with reverse iterators
        ft::map<int, std::string> ft_m2;
        ft::map<int, std::string> ft_m3(ft_m1.begin(), ft_m1.end());
        ft::map<int, std::string> ft_m4(ft_m1);
        ft::map<int, std::string> ft_m5(ft_m1.rbegin(), ft_m1.rend());
        ----------------------------------------------------
        std::cout << (m1.size() == ft_m1.size() && m2.size() == ft_m2.size() && m3.size() == ft_m3.size() && m5.size() == ft_m5.size() && m4.size() == ft_m4.size());*/

 std::map<int, std::string> m1;
        ft::map<int, std::string> ft_m1;

        for (size_t i = 0; i < 10; i++)
        {
            m1.insert(std::make_pair(i, "string2"));
            ft_m1.insert(ft::make_pair(i, "string2"));
        }

        std::map<int, std::string> const m2(m1.rbegin(), m1.rend());
        ft::map<int, std::string> const ft_m2(ft_m1.rbegin(), ft_m1.rend());

        /*-----------------------------------------------------*/
        /*------------------ ft::maps ---------------------*/
        /*----------------------------------------------------*/
        /*------------------ strings to store the results ----*/
        std::string res, ft_res, c_res, c_ft_res;
        /*----------------------------------------------------*/
        for (std::map<int, std::string>::reverse_iterator it = m1.rbegin(); it != m1.rend(); ++it) // fill res from m1
            res += it->second;
        for (std::map<int, std::string>::const_reverse_iterator rit = m2.rbegin(); rit != m2.rend(); ++rit) // fill c_res from const m1
            c_res += rit->second;

        for (ft::map<int, std::string>::reverse_iterator it = ft_m1.rbegin(); it != ft_m1.rend(); ++it) // fill ft_res from ft_m1
            ft_res += it->second;
        for (ft::map<int, std::string>::const_reverse_iterator rit = ft_m2.rbegin(); rit != ft_m2.rend(); ++rit) // fill c_ft_res from const ft_m1
            c_ft_res += rit->second;
        int arr[] = {12, 82, 37, 64, 15};
        ft::map<int, int> end_test;
        for(size_t i = 0; i < 5; ++i)
            end_test.insert(ft::make_pair(arr[i], i));
        ft::map<int, int>::reverse_iterator rit = end_test.rend();
        rit--;
        std::cout << (res == ft_res) <<std::endl;
        std::cout << (c_res == c_ft_res) << std::endl;
        std::cout << (rit->first == 12);
    return 0;
}
