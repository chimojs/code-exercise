#ifndef QS_QUICKSORT_H_
#define QS_QUICKSORT_H_
#include <vector>
namespace CompareSort{
    template<typename T>
    class QuickSort
    {
    public:
        typedef typename std::vector<T>::iterator this_iterator;
        
        void Sort(std::vector<T>& t_vec)
        {
            _Sort(t_vec, t_vec.begin(), t_vec.end() - 1);
        }
        
    private:
        void _Sort(std::vector<T>& t_vec, this_iterator low, this_iterator high)
        {
            if (low >= high) return;
            this_iterator partial_pos = Partition(t_vec, low, high);
            _Sort(t_vec, low, partial_pos);
            _Sort(t_vec, partial_pos + 1,high);
        }
        
        this_iterator Partition(std::vector<T>& t_vec, this_iterator low, this_iterator high)
        {
            this_iterator left = low;
            this_iterator right = high;
            T val = *left;
            while(left < right)
            {
                while(right > left && *right >= val) 
                    --right;
                std::swap(*left, *right);
                while(left < right && *left <= val) 
                    ++left;
                std::swap(*left, *right);
            }
            return left;
        }
    };
}
#endif