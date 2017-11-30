#include <array>
#include "msd_sort.h"

namespace string {
#define CUTOFF 15
    void string::MSD::sort(std::vector<std::string>& strs)
    {
        int N = strs.size();
        sort(strs, 0, N - 1, 0);
    }
    int MSD::charAt(const std::string & str, int i)
    {
        if (i < static_cast<int>(str.size()))
            return static_cast<int>(str.at(i));
        return -1;
    }

    void MSD::sort(std::vector<std::string>& strs, int lo, int hi, int d)
    {
        if (hi <= lo + CUTOFF)
        {
            return insertion_sort(strs, lo, hi, d);
        }

        constexpr int R = 128;
        std::vector<std::string> aux(hi - lo + 1);
        std::array<int, R + 2> freq;
        freq.assign(0);
        for (int j = lo; j <= hi; ++j)
        {
            int k = static_cast<int>(charAt(strs[j], d));
            ++freq[k + 2];
        }

        for (int j = 1; j < R + 2; ++j)
        {
            freq[j] += freq[j - 1];
        }

        for (int j = lo; j <= hi; ++j)
        {
            int index = freq[charAt(strs[j], d) + 1];
            aux[index] = strs[j];
            ++freq[charAt(strs[j], d) + 1];
        }

        for (int j = lo; j <= hi; ++j)
        {
            strs[j] = aux[j - lo];
        }

        for (int j = 0; j < R; ++j)
        {
            sort(strs, lo + freq[j], lo + freq[j + 1] - 1, d + 1);
        }
    }
    void MSD::insertion_sort(std::vector<std::string>& strs, int lo, int hi, int d)
    {
        for (int i = lo; i <= hi; ++i)
        {
            for (int j = i; j > lo && less(strs[j], strs[j - 1], d); --j)
            {
                std::swap(strs[j], strs[j - 1]);
            }
        }
    }
    bool MSD::less(const std::string & str1, const std::string & str2, int d)
    {
        for (int i = d; i < static_cast<int>(std::min(str1.length(), str2.length())); i++) {
            if (charAt(str1, i) < charAt(str2, i)) return true;
            if (charAt(str1, i) > charAt(str2, i)) return false;
        }
        return str1.length() < str2.length();
    }
}