#ifndef STRING_LSDSORT_H_
#define STRING_LSDSORT_H_
#include<vector>
#include<string>
namespace string {
    class LSD
    {
    public:
        static void sort(std::vector<std::string>& strs, int w);
    };
}

#endif