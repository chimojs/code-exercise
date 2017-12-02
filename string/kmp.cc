#include "kmp.h"

namespace string {
    KMP::KMP(const std::string & pat) : dfa_(), M_(pat.length())
    {
        constexpr int Alphbat = 128;
        dfa_.resize(Alphbat, std::vector<int>(M_));
        dfa_[pat.at(0)][0] = 1;
        for (int X = 0, j = 1; j < M_; ++j)
        {
            for (int c = 0; c < Alphbat; ++c)
                dfa_[c][j] = dfa_[c][X];
            dfa_[pat.at(j)][j] = j + 1;
            X = dfa_[pat.at(j)][X];
        }
    }
    int KMP::search(const std::string & text)
    {
        int i, j, N = text.length();
        for (i = 0, j = 0; i < N && j < M_; ++i)
            j = dfa_[text.at(i)][j];
        if (j == M_)
            return i - M_;
        else return N;
    }
}