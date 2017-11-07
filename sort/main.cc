#include <random>
#include <vector>
#include <iostream>
#include <ctime>
#include "heap-sort/heap.hpp"

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
	std::cout << std::endl;
	//auto f = [](int&a, int&b)->bool{return a < b; };
	//Heap<int, decltype(f)> is_sorter(f);
    Heap<int, std::less<int>> is_sorter;
    is_sorter.Build_heap(sort_array);
    is_sorter.Heap_Sort(sort_array);
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
