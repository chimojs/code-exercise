#include <stack>
#include<cassert>
#include "TSTs.h"

#ifdef DEBUG
int g_NodeIndex = 0;
#endif // DEBUG

TSTs::Node::Node() 
    : left_(nullptr), mid_(nullptr), right_(nullptr)
    , fail_(nullptr), parent_(nullptr), key_(false)
    , num_(0)
{
#ifdef DEBUG
    idx_ = g_NodeIndex++;
#endif // DEBUG
}
TSTs::Node::~Node()
{
    delete (left_);
    delete (mid_);
    delete (right_);
}

TSTs::TSTs() : pNode_(nullptr)
{
    pNode_ = new Node;
}

TSTs::~TSTs()
{
    delete pNode_;
}

void TSTs::insert(const std::string& str)
{
    Node* parent = pNode_;
    Node* p = nullptr;
    for (int i = 0, c = str.length(); i < c; ++i)
    {
        char val = str[i];
        p = find(parent, val);
        if (p == nullptr)
        {
            p = put(parent, val);
        }
        if (i == c - 1)
        {
            p->key_ = true;
            p->num_ = 1;
        }
        parent = p;
    }
}

void TSTs::construct_fail()
{
    std::stack<Node*> nodes;
    nodes.push(pNode_);
    while(!nodes.empty())
    {
        Node* p = nodes.top();
        if (p == pNode_ || p->fail_);
        else if (p->parent_ == pNode_)
            p->fail_ = pNode_;
        else
        {
            char val = p->ch_;
            Node* pParent_fail = p->parent_->fail_;
            if (!pParent_fail)
            {
                assert(p->parent_);
                nodes.push(p->parent_);
                continue;
            }

            Node* pfail = nullptr;
            while (!(pfail = find(pParent_fail, val)))
            {
                if (pParent_fail == pNode_)
                {
                    pfail = pNode_;
                    break;
                }
                else if (pParent_fail->fail_ == nullptr)
                {
                    assert(pParent_fail);
                    nodes.push(pParent_fail);
                    break;
                }
                else
                    pParent_fail = pParent_fail->fail_;
            }
            p->fail_ = pfail;
        }
        if (p != pNode_ && !p->fail_) continue;
        nodes.pop();
        if (p->fail_)
            p->num_ += p->fail_->num_;
        if (p->mid_ && !p->mid_->fail_)
            nodes.push(p->mid_);
        if (p->left_ && !p->left_->fail_)
            nodes.push(p->left_);
        if (p->right_ && !p->right_->fail_)
            nodes.push(p->right_);
    }
}

int TSTs::recognize(const std::string& text)
{
    Node* p = pNode_;
    int count = 0;
    for (int i = 0, c = text.length(); i < c; ++i)
    {
        char val = text[i];
        Node* pValue = nullptr;
        while (!(pValue = find(p, val)))
        {
            if (p == pNode_)
            {
                pValue = pNode_;
                break;
            }
            else
                p = p->fail_;
        }
        count += pValue->num_;
        p = pValue;
    }
    return count;
}
