#ifndef STRING_DFA_H_
#define STRING_DFA_H_
#include<vector>
#include<string>

namespace string {
    class DFA
    {
    public:
        DFA(const std::string& pat);
        int search(const std::string& text);
    private:
        std::vector<std::vector<int>> dfa_;
        int M_;
    };
}

#endif//STRING_DFA_H_