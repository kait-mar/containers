#include <vector>
#include <iostream>

int main()
{
    /*std::vector<int> v;
    int i = 1;
    v.push_back(i); i = 2;v.push_back(i);i = 3;v.push_back(i);i = 4;v.push_back(i);i = 5;v.push_back(i);
    std::cout << "********before erasing\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    std::cout << "\n erasing return = " << *(v.erase(v.begin(), v.end() - 2));
     std::cout << "\n*****AFTER erasing\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    std::cout << "\n----------------\n";
    //   **********************
    //ft::vector<int>    a(5, 25);
    ft::vector<int>    a;
     i = 1;
    a.push_back(i); i = 2;a.push_back(i);i = 3;a.push_back(i);i = 4;a.push_back(i);i = 5;a.push_back(i);
    std::cout << "********before erasing\n";
    for (int i = 0; i < (int)a.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();
    std::cout << "\n erasing return = " << *(a.erase(a.begin(), a.end() - 2));
     std::cout << "\n*****AFTER erasing\n";
    for (int i = 0; i < (int)a.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();*/
    //inserting
    /*std::vector<int> v;
    int i = 1;
    v.resize(3, 42);
    v.push_back(1);
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    std::cout << "\n inserting return = " << *(v.insert(v.begin(), 85));
     std::cout << "\n*****AFTER\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    std::cout << "\n----------------\n";*/
    //   **********************
    //ft::vector<int>    a(5, 25);
   /* ft::vector<int>    a;
     i = 1;
    a.resize(3, 42);
    a.push_back(i);
    for (int i = 0; i < (int)a.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();
    std::cout << "\n insrting return = " << *a.insert(a.begin(), 85);
     std::cout << "\n*****AFTER\n";
    for (int i = 0; i < (int)a.size(); i++)
        std::cout<< a[i] << " ";
    std::cout<< " | capacity = " << a.capacity();*/
    // resize
    /*std::vector<int> v;
    int i = 1;
    v.push_back(i); i = 2;v.push_back(i);v.push_back(i);v.push_back(i);v.push_back(i);
    std::cout << "********before resizing\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();
    v.resize(17, 7);
     std::cout << "\n*****AFTER resizing\n";
    for (int i = 0; i < (int)v.size(); i++)
        std::cout<< v[i] << " ";
    std::cout<< " | capacity = " << v.capacity();

    std::cout<< " ------------------------\n";

    ft::vector<int> vax;
    i = 1;
    vax.push_back(i); i = 2;vax.push_back(i);vax.push_back(i);vax.push_back(i);vax.push_back(i);
    std::cout << "********before resizing\n";
    for (int i = 0; i < (int)vax.size(); i++)
        std::cout<< vax[i] << " ";
    std::cout<< " | capacity = " << vax.capacity();
    vax.resize(17, 7);
     std::cout << "\n*****AFTER resizing\n";
    for (int i = 0; i < (int)vax.size(); i++)
        std::cout<< vax[i] << " ";
    std::cout<< " | capacity = " << vax.capacity();*/
     // pop back
    /*ft::vector<int> v;
     int i = 1;
    v.push_back(i); i = 2;v.push_back(i);v.push_back(i);v.push_back(i); i = 5;v.push_back(i);
    std::cout<< v.back() << std::endl;
     v.pop_back();
     std::cout<< v.back() << std::endl;*/
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
    /*****************/
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
}
