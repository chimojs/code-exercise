#ifndef MS_MERGESORT_H_
#define MS_MERGESORT_H_
#include <vector>

template<typename T>
class MergeSort
{
public:
    void Sort(std::vector<T>& t_vec)
    {
        _Sort(t_vec, 0, t_vec.size) - 1);
    }
    
private:
    void _Sort(std::vector<T>& t_vec, int low, int high)
    {
        if (low == high) return;
        int mid = (low + high) / 2;
        std::vector<T> vec_left(low, mid + 1, t_vec);
        std::vector<T> vec_right(mid + 1, high + 1, t_vec);
        _Sort(vec_left, 0, vec_left.size() - 1）;
        _Sort(vec_left, 0, vec_right.size() - 1）;
        Merge(t_vec, vec_left, vec_right, low);
    }
    
    void Merge(std::vector<T>& t_vec, std::vector<T>& vec_left, std::vector<T>& vec_right, int low)
    {
        int _left = 0, _right = 0;
        for (; _left < vec_left.size() &&  _right < vec_right.size();)
        {
            if (vec_left[_left] <= vec_right[_right])
            {
                t_vec[low++] = vec_left[_left++];
            }
           else
           {
                t_vec[low++] = vec_right[_right++];
           }
        }

        for (; _left < vec_left.size();)
        {
             t_vec[low++] = vec_left[_left++];
        }

        for (; _right < vec_right.size();)
        {
            t_vec[low++] = vec_right[_right++];
        }
    }
};
#endif