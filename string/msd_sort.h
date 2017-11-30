#ifndef STRING_MSDSORT_H_
#define STRING_MSDSORT_H_
#include<vector>
#include<string>
namespace string {
    class MSD
    {
    public:
        static void sort(std::vector<std::string>& strs);
    private:
        static void sort(std::vector<std::string>& strs, int lo, int hi, int d);
        static void insertion_sort(std::vector<std::string>& strs, int lo, int hi, int d);
        static bool less(const std::string& str1, const std::string& str2, int i);
        static int charAt(const std::string& str, int i);
    };
}
#endif //STRING_MSDSORT_H_
