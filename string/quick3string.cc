#include <array>
#include "quick3string.h"

namespace string {
    void string::Quick3String::sort(std::vector<std::string>& strs)
    {
        int N = strs.size();
        sort(strs, 0, N - 1, 0);
    }
    int Quick3String::charAt(const std::string & str, int i)
    {
        if (i < static_cast<int>(str.size()))
            return static_cast<int>(str.at(i));
        return -1;
    }

    void Quick3String::sort(std::vector<std::string>& strs, int lo, int hi, int d)
    {
        if (hi <= lo) return;
        int lt = lo, gt = hi;
        int v = charAt(strs[lo], d);
        int i = lo + 1;
        while (i <= gt)
        {
            int t = charAt(strs[i], d);
            if (t < v) std::swap(strs[lt++], strs[i++]);
            else if (t > v) std::swap(strs[i], strs[gt--]);
            else ++i;
        }

        sort(strs, lo, lt - 1, d);
        if (v >= 0) sort(strs, lt, gt, d + 1);
        sort(strs, gt + 1, hi, d);
    }
}