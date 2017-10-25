#ifndef UF_UNIONFIND_H_
#define UF_UNIONFIND_H_
#include <vector>

class UnionFind
{
public:
    explicit UnionFind(int N);
    void Union(int p, int q);
    int Find(int p);
    bool Connected(int p, int q);
    int Count();
protected:
    std::vector<int> m_parent_;
	std::vector<int> m_size_;
    int m_count_;
};
#endif // UF_UNIONFIND_H_