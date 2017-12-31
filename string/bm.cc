#include "BM.h"

namespace string {
    BM::BM(const std::string & pat) : right_(), pat_(pat)
    {
        const int Alphabat = 128;
        right_.resize(Alphabat, -1);
        int M = pat_.length();
        for (int i = 0; i < M; ++i)
        {
            right_[pat_[i]] = i;
        }
    }
    int BM::search(const std::string & text)
    {
        int M = pat_.length(), N = text.length(), skip = 0;
        for (int i = 0; i <= N - M; i += skip)
        {
            skip = 0;
            for (int j = M - 1; j >= 0; --j)
            {
                if (pat_[j] != text[i + j])
                {
                    skip = j - right_[text[i + j]];
                    if (skip < 1) skip = 1;
                    break;
                }
                if (skip == 0) return i;
            }
        }
        return N;
    }
}