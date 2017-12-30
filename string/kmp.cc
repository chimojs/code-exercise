#include "kmp.h"
#include<algorithm>

namespace string {
    KMP::KMP(const std::string & pat) : prefixfunc_(pat.length() + 1),
        pat_(pat)
    {
        prefixfunc_[1] = 0;
        int len = pat.length();
        int k = 0;
        for (int q = 2; q < len + 1; ++q)
        {
            while (k > 0 && pat[k] != pat[q - 1])
                k = prefixfunc_[k];
            if (pat[k] == pat[q - 1])
                k += 1;
            prefixfunc_[q] = k;
        }
    }
    int KMP::search(const std::string & text)
    {
        int j = 0, N = text.length(), M = pat_.length();
        for (int i = 0; i < N; ++i)
        {
            while (j > 0 && pat_[j] != text[i])
            {
                j = prefixfunc_[j];
            }
            if (pat_[j] == text[i])
            {
                j += 1;
            }
            if (j == M)
                return i - M + 1;
        }
        return N;
    }
}