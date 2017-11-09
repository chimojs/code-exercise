#include <random>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>
#include "count-sort/count-sort.hpp"

int main()
{
    std::default_random_engine dre(static_cast<unsigned long>(time(0)));
    std::uniform_int_distribution<int> di(1,1000);
    std::vector<int> sort_array;
    for (int i = 0; i < 5; ++i)
    {
        int value = di(dre);
        sort_array.push_back(value);
        std::cout << value << " ";
    }
    std::cout << std::endl;
    CountSort is_sorter;
    is_sorter.Sort2(sort_array, *std::max_element(sort_array.begin(), sort_array.end()));
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
