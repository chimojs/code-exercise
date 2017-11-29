#include <array>
#include "lsd_sort.h"

namespace string {
    void string::LSD::sort(std::vector<std::string>& strs, int w)
    {
        int N = strs.size();
        constexpr int R = 128;

        for (int i = w - 1; i >= 0; --i)
        {
            std::vector<std::string> aux(N);
            std::array<int, R + 1> freq;
            freq.assign(0);
            for (int j = 0; j < N; ++j)
            {
                int k = static_cast<int>(strs[j].at(i));
                ++freq[k + 1];
            }

            for (int j = 1; j < R + 1; ++j)
            {
                freq[j] += freq[j - 1];
            }

            for (int j = 0; j < N; ++j)
            {
                int index = freq[strs[j].at(i)];
                aux[index] = strs[j];
                ++freq[strs[j].at(i)];
            }
            strs = std::move(aux);
        }
    }
}