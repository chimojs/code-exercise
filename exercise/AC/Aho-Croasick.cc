#include "Aho-Croasick.h"

AhoCroasick::AhoCroasick() : pNode_(nullptr)
{
    pNode_ = new Node;
    //goto function
    for (int i = 0, c = sizeof(pNode_->nodes) / sizeof(pNode_->nodes[0]); i < c; ++i)
        pNode_->nodes[i] = pNode_;
}

AhoCroasick::~AhoCroasick()
{
    for (int i = 0, c = sizeof(pNode_->nodes) / sizeof(pNode_->nodes[0]); i < c; ++i)
    {
        if (pNode_->nodes[i] == pNode_)
            pNode_->nodes[i] = nullptr;
    }
    delete pNode_;
}

void AhoCroasick::insert(const std::string& str)
{
	Node* p = pNode_;
	for (int i = 0, c = str.length(); i < c; ++i)
	{
		int alpha_idx = str[i] - 0x61;
		assert(alpha_idx >= 0 && alpha_idx < 26);
		if (p->nodes[alpha_idx] == nullptr || p->nodes[alpha_idx] == p)
		{
			p->nodes[alpha_idx] = new Node;
			
			p->nodes[alpha_idx]->parent_ = p;
			p->nodes[alpha_idx]->id_ = alpha_idx;
			
            p->nodes[alpha_idx]->ch = str[i];
		}
        p = p->nodes[alpha_idx];
        if (i == c - 1)
        {
            p->key_ = true;
            p->num_ = 1;
        }
	}
}

void AhoCroasick::construct_fail()
{
	std::queue<Node*> nodes;
    for (int i = 0, c = sizeof(pNode_->nodes) / sizeof(pNode_->nodes[0]); i < c; ++i)
    {
        if (pNode_->nodes[i] != pNode_)
            nodes.push(pNode_->nodes[i]);
    }
	while(!nodes.empty())
	{
		Node* p = nodes.front();
		nodes.pop();
		int id = p->id_;
        Node* pParent_fail = p->parent_->fail_;
        if (!pParent_fail)
            p->fail_ = p->parent_;
        else
        {
            while (!pParent_fail->nodes[id])
                pParent_fail = pParent_fail->fail_;
            p->fail_ = pParent_fail->nodes[id];
            if (p->fail_->key_)
                p->num_ += p->fail_->num_;
        }

		for (int i = 0, c = sizeof(p->nodes) / sizeof (p->nodes[0]); i < c; ++i)
		{
			if (p->nodes[i])
				nodes.push(p->nodes[i]);
		}
	}
}

int AhoCroasick::recognize(const std::string& text)
{
	Node* p = pNode_;
    int count = 0;
	for (int i = 0, c = text.length(); i < c; ++i)
	{
		int alpha_idx = text[i] - 0x61;
        char ch = text[i];
		assert(alpha_idx >= 0 && alpha_idx < 26);
		if (p->nodes[alpha_idx])
		{
			p = p->nodes[alpha_idx];
		}
		else
		{
			Node* next = p->fail_;
			while(!next->nodes[alpha_idx])
			{
				next = next->fail_;
			}
			p = next->nodes[alpha_idx];
		}
        count += p->num_;
	}
    return count;
}
