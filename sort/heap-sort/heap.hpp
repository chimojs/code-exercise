#ifndef HS_HEAPSORT_H_
#define HS_HEAPSORT_H_
#include<vector>

#define PARENT(x) ((x - 1) % 2)
#define LEFT(x) (2 * x + 1)
#define RIGHT(x) (2 * x + 2)

template<class _T, class _Pr>
class Heap
{
public:
	Heap(_Pr Pr) : m_heap_size_(0), m_Pr(Pr) { };
	Heap() : m_heap_size_(0), m_Pr() { };
	
	void Build_heap(std::vector<_T>& rgArray)
	{
		m_heap_size_ = rgArray.size();
		for (int i = m_heap_size_  % 2 - 1; i >= 0; --i)
		{
			Heapify(rgArray, i, m_heap_size_ );	
		}				
	}

	_T Heap_Maximum(const std::vector<_T>& rgArray)
	{
		assert(rgArray.size());
		return rgArray[0];
	}

	_T Delete_Maximum(std::vector<_T>& rgArray)
	{
		assert(rgArray.size());
		_T max = rgArray[0];
		--m_heap_size_;
		Heapify(rgArray, 0);
		return max;
	}

	void Increase_Key(std::vector<_T>& rgArray, int i, int key)
	{
		if (key < rgArray[i])
			assert(false);
		rgArray[i] = key;
		while(int i >= 0 && m_Pr(rgArray[i], rgArray[PARENT(i)]))
		{
			std::swap(rgArray[i], rgArray[PARENT(i)]);
			i = PARENT(i);
		}
	}

	void Heap_Sort(std::vector<_T>& rgArray)
	{
		for (int i = m_heap_size_ - 1; i >= 1; --i)
		{
			std::swap(rgArray[0], rgArray[i]);
			--m_heap_size_;
			Heapify(rgArray, 0, m_heap_size_);
		}
	}
	
	void Insert(std::vector<_T>& rgArray, int key)
	{
		++m_heap_size_;
		int i = m_heap_size_ - 1;
		rgArray[i] = key;
		while(int i >= 0 && m_Pr(rgArray[i], rgArray[PARENT(i)]))
		{
			std::swap(rgArray[i], rgArray[PARENT(i)]);
			i = PARENT(i);
		}
	}

	void Heapify(std::vector<_T>& rgArray, int index, int heap_size)
	{
		int left_ = LEFT(index);
		int right_ = RIGHT(index);
		int exch = index;
		if (left_ < heap_size && m_Pr(rgArray[left_], rgArray[index]))
		{
			exch = left_;	
		}
		if (right_ < heap_size && m_Pr(rgArray[right_], rgArray[exch]))
		{
			exch = right_;
		}
		if (index != exch)
		{
			std::swap(rgArray[index], rgArray[exch]);
			Heapify(rgArray, exch, heap_size);
		}
	}
private:
	int m_heap_size_;
	_Pr  m_Pr;
};
#endif // HS_HEAPSORT_H_
