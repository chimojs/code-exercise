#ifndef IS_INSERTIONSORT_H_
#define IS_INSERTIONSORT_H_
#include <vector>
namespace CompareSort{
template<typename T>
    class InsertionSort
    {
    public:
        void Sort(std::vector<T>& t_vec)
        {
            for (typename std::vector<T>::iterator it = t_vec.begin() + 1; it != t_vec.end(); ++it)
            {
                typename std::vector<T>::iterator temp_it = it;
                while(temp_it != t_vec.begin() && *temp_it < *std::prev(temp_it))
                {
                    std::swap(*temp_it, *std::prev(temp_it));
                    std::advance(temp_it, -1);
                }
            }
        }
    };
}
#endif