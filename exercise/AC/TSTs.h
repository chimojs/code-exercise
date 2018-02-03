#ifndef TSTS_H_
#define TSTS_H_
#include<string>

#ifdef DEBUG
extern int g_NodeIndex;
#endif // DEBUG

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
        char  ch_;
#ifdef DEBUG
        int idx_;
#endif // DEBUG
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

#if 0 // debugging
    std::string getstr(TSTs::Node* p)
    {
        std::string val;
        if (!p)
            return val;
        while (p != pNode_)
        {
            val.insert(val.begin(), p->ch_);
            p = p->parent_;
        }
        return val;
    }
#endif
private:
	Node* pNode_;
};
#endif //TSTS_H_