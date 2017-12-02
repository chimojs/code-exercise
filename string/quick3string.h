#ifndef STRING_QUICK3STRING_H_
#define STRING_QUICK3STRING_H_
#include<vector>
#include<string>
namespace string {
    class Quick3String
    {
    public:
        static void sort(std::vector<std::string>& strs);
    private:
        static void sort(std::vector<std::string>& strs, int lo, int hi, int d);
        static int charAt(const std::string& str, int i);
    };
}
#endif //STRING_QUICK3STRING_H_
