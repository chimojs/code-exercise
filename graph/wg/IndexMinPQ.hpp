#ifndef WG_INDEXMINPQ_H_
#define WG_INDEXMINPQ_H_

namespace WeightedGraph{
    template<class _Ty>
    class  IndexMinPQ
    {
    public:
        typedef _Ty KeyType;
        IndexMinPQ(int N) : n_(0), pq_(N), qp_(N, -1), keys_(N)
        {
        }

        bool empty()
        {
            return n_ == 0;
        }

        bool contains(int k)
        {
            return qp_[k] != -1;
        }

        void insert(int k, const KeyType& key)
        {
            qp_[k] = n_;
            pq_[n_] = k;
            keys_[k] = key;
            swim(n_++);
        }

        void change(int k, const KeyType& key)
        {
            keys_[k] = key;
            swim(qp_[k]);
            sink(qp_[k]);
        }

        void deletek(int k)
        {
            int index = qp_[k];
            exch(index, --n_);
            swim(index);
            sink(index);
            keys_[k] = KeyType();
            qp_[k] = -1;
        }

        int delmin()
        {
            int i = minIndex();
            deletek(i);
            return i;
        }

        KeyType min()
        {
            return keys_[pq_[0]];
        }

        int minIndex()
        {
            return pq_[0];
        }

        int size()
        {
            return n_;
        }
    private:
        bool greater(int lhs, int rhs)
        {
            return keys_[pq_[lhs]] > keys_[pq_[rhs]];
        }
        void swim(int i)
        {
            if (i > 0)
            {
                int p = (i - 1) / 2;
                if (greater(p, i))
                {
                    exch(i, p);
                    swim(p);
                }
            }
        }
        void sink(int i)
        {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int min = i;
            if (l < n_ && keys_[pq_[l]] < keys_[pq_[min]])
                min = l;
            if (r < n_ && keys_[pq_[r]] < keys_[pq_[min]])
                min = r;
            if (min != i)
            {
                exch(i, min);
                sink(min);
            }
        }
        void exch(int k, int j)
        {
            std::swap(pq_[k], pq_[j]);
            qp_[pq_[k]] = k;
            qp_[pq_[j]] = j;
        }
    private:
        int n_;
        std::vector<int> pq_;
        std::vector<int> qp_;
        std::vector<KeyType> keys_;
    };
}
#endif // WG_INDEXMINPQ_H_