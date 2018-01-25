#include<string>
#include<queue>
#include<cassert>
class AhoCroasick
{
public:
    AhoCroasick();
    ~AhoCroasick();
	
    void insert(const std::string& str);
	
	void construct_fail();
	
    int recognize(const std::string& text);
private:
    class Node
    {
	public:
		Node() : key_(false), parent_(nullptr), fail_(nullptr), 
            id_(-1), num_(0), ch(0x0)
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
        bool  key_;//indicate trie node is a pattern
        Node* fail_;//prefix function
		Node* parent_;//for construct fail pointer
		int   id_;//indicate node index
		int   num_;//for merge output
        char  ch;//for debugging
    };
private:
	Node* pNode_;
};