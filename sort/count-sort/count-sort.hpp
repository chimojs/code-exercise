#ifndef CS_COUNTSORT_H_
#define CS_COUNTSORT_H_
#include<vector>
#include <algorithm>
namespace LinearSort{
class CountSort
{
    public:
        void Sort1(std::vector<int>& vals, int max_val)
        {
            std::vector<int> vec_freq(max_val + 1, 0);
            auto f = [&vec_freq](int& value){ ++vec_freq[value]; };
            for_each(vals.begin(), vals.end(), f);
            for (int i = 1,c = vec_freq.size(); i < c; ++i)
                vec_freq[i] += vec_freq[i - 1];

            std::vector<int> vec_sorted(vals.size());
            for (int i = vals.size() - 1; i >= 0; --i)
            {
                int index = vec_freq[vals[i]] - 1;
                vec_sorted[index] = vals[i];
                --vec_freq[vals[i]];
            }
            vals = std::move(vec_sorted);
        }

        void Sort2(std::vector<int>& vals, int max_val)
        {
            std::vector<int> vec_freq(max_val + 2, 0);
            auto f = [&vec_freq](int& value){ ++vec_freq[value + 1]; };
            for_each(vals.begin(), vals.end(), f);
            for (int i = 1,c = vec_freq.size(); i < c; ++i)
                vec_freq[i] += vec_freq[i - 1];

            std::vector<int> vec_sorted(vals.size());
            for (int i = 0, c = vals.size(); i < c; ++i)
            {
                int index = vec_freq[vals[i]];
                vec_sorted[index] = vals[i];
                ++vec_freq[vals[i]];
            }
                
            vals = std::move(vec_sorted);
        }
    };
}
#endif // CS_COUNTSORT_H_
