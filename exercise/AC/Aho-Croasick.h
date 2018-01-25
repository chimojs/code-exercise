#include<string>
#include<queue>
#include<cassert>
class AhoCroasick
{
public:
    AhoCroasick() : count_(0), pNode_(nullptr) {
		pNode_ = new Node;
	}
	~AhoCroasick() { delete pNode_; }
	
    void Build(const std::string& str);
	
	void construct_fail();
	
    void Recognize(const std::string& text);

	int GetCount() { return count_;  }

    class Node
    {
	public:
		Node() : key_(false), parent_(nullptr), fail_(nullptr), id_(-1), num_(0)
		{
			for (int i = 0, c = sizeof(nodes) / sizeof(nodes[0]); i < c; ++i)
				nodes[i] = nullptr;
		}
        ~Node() 
		{
			for (int i = 0, c = sizeof(nodes) / sizeof (nodes[0]); i < c; ++i)
				delete nodes[i];
		}
        Node* nodes[26];
        bool  key_;
        Node* fail_;
		Node* parent_;
		int   id_;
		int   num_;
    };
private:
    int count_;
	Node* pNode_;
};