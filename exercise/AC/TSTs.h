#include<string>
class TSTs
{
public:
    TSTs();
    ~TSTs();
	
    void insert(const std::string& str);
	
	void construct_fail();
	
    int recognize(const std::string& text);
private:
    class Node
    {
	public:
        Node();
        ~Node();
        Node* left_;
        Node* mid_;
        Node* right_;
        Node* fail_;
        Node* parent_;
        bool  key_;
        int   num_;
        bool  valid_num_;
        char  ch_;
    };

    Node* find(Node* pNode, char val)
    {
        if (pNode == nullptr)
            return nullptr;
        if (pNode->mid_ == nullptr)
            return nullptr;
        Node* p = pNode->mid_;
        if (val == p->ch_)
            return p;
        pNode = p;
        while (pNode)
        {
            if (val < pNode->ch_)
            {
                pNode = pNode->left_;
            }
            else if (val > pNode->ch_)
            {
                pNode = pNode->right_;
            }
            else
                break;
        }
        return pNode;
    }
    Node* put(Node* pNode, char val)
    {
        Node* pParent = pNode;
        Node* p = pParent->mid_;
        if (p == nullptr)
        {
            p = new Node;
            p->parent_ = pNode;
            p->ch_ = val;
            pParent->mid_ = p;
            return p;
        }
        if (p && val == p->ch_)
            return p;
        pParent = p;
        while (true)
        {
            if (val < p->ch_)
            {
                if (!pParent->left_)
                {
                    p = new Node;
                    p->parent_ = pNode;
                    p->ch_ = val;
                    pParent->left_ = p;
                    return p;
                }
                else if (pParent->left_->ch_ == val)
                    return pParent->left_;
                else
                {
                    pParent = pParent->left_;
                    p = pParent;
                }
            }
            else
            {
                if (!pParent->right_)
                {
                    p = new Node;
                    p->parent_ = pNode;
                    p->ch_ = val;
                    pParent->right_ = p;
                    return p;
                }
                else if (pParent->right_->ch_ == val)
                    return pParent->right_;
                else
                {
                    pParent = pParent->right_;
                    p = pParent;
                }
            }
        }
        return nullptr;
    }
    void collectnum(Node* p);
private:
	Node* pNode_;
};