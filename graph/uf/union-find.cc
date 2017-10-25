#include "union-find.h"

UnionFind::UnionFind(int N) : m_parent_(N), m_size_(N), m_count_(N)
{
    for (std::vector<int>::iterator it = m_parent_.begin(); it != m_parent_.end(); ++it)
        *it = it - m_parent_.begin();
    for (std::vector<int>::iterator it = m_size_.begin(); it != m_size_.end(); ++it)
        *it = 1;
}

void UnionFind::Union(int p, int q)
{
    int pid = Find(p);
    int qid = Find(q);
    if (pid == qid)
        return;

    if (m_size_[pid] > m_size_[qid])
    {
        m_parent_[qid] = pid;
        m_size_[pid] += m_size_[qid];
    }
    else
    {
        m_parent_[pid] = qid;
        m_size_[qid] += m_size_[pid];
    }
    --m_count_;
}

int UnionFind::Find(int p)
{
    int k = p;
    while(k != m_parent_[k])
        k = m_parent_[k];

    int s = p;
    while(s != k)
    {
        int r = m_parent_[s];
        m_parent_[s] = k;
        s = r;
    }

    return k;
}

bool UnionFind::Connected(int p, int q)
{
    return Find(p) == Find(q);
}

int UnionFind::Count()
{
    return m_count_;
}
