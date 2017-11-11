#include <random>
#include <vector>
#include <ctime>
#include<algorithm>
#include <iostream>
#include "BSTree.hpp"
#include "utils.hpp"

int main()
{
    BST<int, int, std::less<int>> bst;
    std::default_random_engine dre(static_cast<unsigned long>(time(0)));
    std::uniform_int_distribution<int> di(1, 100);
    std::vector<int> sort_array;
    int test;
    for (int i = 0; i < 5; ++i)
    {
        int value = di(dre);
        std::cout << value << ' ';
        bst.put(value, value);
        test =  value;
    }
    int N = bst.size();
    int val  = bst.get(test);
    int min = bst.min();
    int max = bst.max();
    std::cout << std::endl;
    BSTPrint<BST<int, int, std::less<int>>>::print(bst);
    bst.deleteMin();
    std::cout << std::endl;
    BSTPrint<BST<int, int, std::less<int>>>::print(bst);
    getchar();
    return 0;
}
