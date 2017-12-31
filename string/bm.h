#ifndef STRING_BM_H_
#define STRING_BM_H_
#include<vector>
#include<string>

namespace string {
    class BM
    {
    public:
        BM(const std::string& pat);
        int search(const std::string& text);
    private:
        std::vector<int> right_;
        std::string pat_;
    };
}

#endif//STRING_BM_H_