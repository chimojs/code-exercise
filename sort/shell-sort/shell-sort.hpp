#ifndef SS_SHELLSORT_H_
#define SS_SHELLSORT_H_
#include <vector>

template<typename T>
class ShellSort
{
public:
    void Sort(std::vector<T>& t_vec)
    {
        int N = t_vec.size();
        int h = 1;
        while(h < N / 3) h = 3 * h + 1;
        while(h >= 1)
        {
            for (int i = h; i < N; ++i)
            {
                for (int j = i; j >= h && t_vec[j] < t_vec[j - h]; j= j - h)
                    std::swap(t_vec[j],t_vec[j - h]);
            }
            h = h / 3;
        }
    }
};
#endif