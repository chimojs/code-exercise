#include "insertion-sort/insertion-sort.hpp"
#include "quick-sort/quick-sort.hpp"
#include <random>
#include <vector>
#include <iostream>
#include <ctime>

int main()
{
    std::default_random_engine dre(static_cast<unsigned long>(time(0)));
    std::uniform_int_distribution<int> di(1,50);
    std::vector<int> sort_array;
    for (int i = 0; i < 5; ++i)
    {
        int value = di(dre);
        sort_array.push_back(value);
        std::cout << value << " ";
    }
    std::cout << std::endl;

    QuickSort<int> is_sorter;
    is_sorter.Sort(sort_array);
    
    //for (auto& element : sort_array)
    //{
    //  std::cout << element << " ";
    //}
    for (std::vector<int>::iterator it = sort_array.begin(); it != sort_array.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}