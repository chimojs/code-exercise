#include "Aho-Croasick.h"

void AhoCroasick::Build(const std::string& str)
{
	Node* p = pNode_;
	for (int i = 0, c = str.length(); i < c; ++i)
	{
		int alpha_idx = str[i] - 0x61;
		assert(alpha_idx >= 0 && alpha_idx < 26);
		if (p->nodes[alpha_idx] == nullptr)
		{
			p->nodes[alpha_idx] = new Node;
			p->nodes[alpha_idx]->key_ = i == c - 1;
			p->nodes[alpha_idx]->parent_ = p;
			p->nodes[alpha_idx]->id_ = alpha_idx;
			p->nodes[alpha_idx]->num_ = i == c - 1 ? 1 : 0;
			p = p->nodes[alpha_idx];
		}
	}
}

void AhoCroasick::construct_fail()
{
	std::queue<Node*> nodes;
	for (int i = 0, c = sizeof(pNode_->nodes) / sizeof(pNode_->nodes[0]); i < c; ++i)
	{
		if (pNode_->nodes[i])
			nodes.push(pNode_->nodes[i]);
	}
	while(!nodes.empty())
	{
		Node* p = nodes.front();
		nodes.pop();
		if (p != pNode_)
		{
			int id = p->id_;
			Node* parent = p->parent_;
			while(parent != pNode_ && !parent->nodes[id])
				parent = parent->fail_;
			if (parent->nodes[id])
				p->fail_ = parent->nodes[id]->fail_;
			else
				p->fail_ = pNode_;
		}
		if (p->fail_ && p->fail_->key_)
			p->num_ += p->fail_->num_;
		for (int i = 0, c = sizeof(p->nodes) / sizeof (p->nodes[0]); i < c; ++i)
		{
			if (p->nodes[i])
				nodes.push(p->nodes[i]);
		}
	}
}

void AhoCroasick::Recognize(const std::string& text)
{
	Node* p = pNode_;
	for (int i = 0, c = text.length(); i < c; ++i)
	{
		int alpha_idx = text[i] - 0x61;
		assert(alpha_idx >= 0 && alpha_idx < 26);
		if (p->nodes[alpha_idx])
		{
			p = p->nodes[alpha_idx];
			count_ += p->num_;
		}
		else
		{
			Node* next = p->fail_;
			while(next && !next->nodes[alpha_idx])
			{
				next = next->fail_;
			}
			if (next && next->nodes[alpha_idx])
				p = next->nodes[alpha_idx];
			else
				p = pNode_;
		}
	}
}
