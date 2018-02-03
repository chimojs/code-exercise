#include<queue>
#include "TSTs.h"

TSTs::Node::Node() 
    : left_(nullptr), mid_(nullptr), right_(nullptr)
    , fail_(nullptr), parent_(nullptr), key_(false)
    , num_(0), valid_num_(false)
{
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
    std::queue<Node*> nodes;
    if (pNode_->mid_)
        nodes.push(pNode_->mid_);
    if (pNode_->left_)
        nodes.push(pNode_->left_);
    if (pNode_->right_)
        nodes.push(pNode_->right_);
    while(!nodes.empty())
    {
        Node* p = nodes.front();
        nodes.pop();
        char val = p->ch_;
        Node* pParent_fail = p->parent_->fail_;
        Node* pfail = nullptr;
        while (pParent_fail && !(pfail = find(pParent_fail, val)))
            pParent_fail = pParent_fail->fail_;
        if (pfail == nullptr)
            pfail = pNode_;
        p->fail_ = pfail;

        if (p->mid_)
            nodes.push(p->mid_);
        if (p->left_)
            nodes.push(p->left_);
        if (p->right_)
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
        if (!pValue->valid_num_)
            collectnum(pValue);
        count += pValue->num_;
        p = pValue;
    }
    return count;
}

void TSTs::collectnum(Node* p)
{
    if (p == nullptr)
        return;
    if (p->valid_num_)
        return;
    Node* pFail = p->fail_;
    if (pFail)
        collectnum(pFail);
    p->valid_num_ = true;
    if (pFail)
        p->num_ += pFail->num_;
}
