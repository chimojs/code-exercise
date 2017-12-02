#ifndef STRING_KMP_H_
#define STRING_KMP_H_
#include<vector>
#include<string>

namespace string {
    class KMP
    {
    public:
        KMP(const std::string& pat);
        int search(const std::string& text);
    private:
        std::vector<std::vector<int>> dfa_;
        int M_;
    };
}

#endif//STRING_KMP_H_