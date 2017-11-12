#ifndef SEARCH_RBTREE_H_
#define SEARCH_RBTREE_H_
#include<cassert>
#include "BSTree.hpp"
//1.Evervy node is either red or black
//2.The root is black
//3.Every leaf is black
//4.If a node is red,then its children are black
//5.all simple paths have same black height.
//A RBTree with n internal nodes has height at most 2lg(n + 1)

template<typename _Key, typename _Value, typename _Pr>
class RBT : public BST<_Key, _Value, _Pr>
{
public:
	void insert(const _Key& key, const _Value& val)
	{
		Node* parent = nullptr;
		Node* inspos = _pRoot;
		while (inspos)
		{
			parent = inspos;
			if (_pr(key, inspos->_key))
				inspos = inspos->_left;
			else if (_pr(inspos->_key, key))
				inspos = inspos->_right;
			else
			{
				inspos->_val = val;
				return;
			}
		}
		Node* node = new Node(key, val);
		node->_parent = parent;
		if (parent == nullptr)
			_pRoot = node;
		else if (_pr(key, parent->_key))
			parent->_left = node;
		else
			parent->_right = node;
		insert_fixcolor(node);
	}

	void deleteKey(const _Key& key)
	{
		Node* node = get(_pRoot, key);
		if (node == nullptr) return;

		Node* x = nullptr;
		bool ori_color = node->_color;
		if (node->_left == nullptr)
		{
			transplant(node, node->_right);
			x = node->_right;
			node->_right = nullptr;
			delete node;
		}
		else if (node->_right == nullptr)
		{
			transplant(node, node->_left);
			x = node->_left;
			node->_left = nullptr;
			delete node;
		}
		else
		{
			Node* successor = min(node->_right);
			ori_color = successor->_color;
			transplant(successor, successor->_right);
			x = successor->_right;
			successor->_right = node->_right;
			node->_right = nullptr;
			successor->_left = node->_left;
			node->_left = nullptr;

			transplant(node, successor);
			successor->_color = node->_color;
			delete node;
		}
		if (ori_color == true)
			delete_fixcolor(x);
	}

protected:
	typedef BST<_Key, _Value, _Pr> BaseClass;

	void left_rotate(Node* x)
	{
		assert(x);
		Node* y = x->_right;
		assert(y);
		x->_right = y->_left;
		if (y->_left)
			y->_left->_parent = x;
		y->_parent = x->_parent;
		if (x->_parent == nullptr)
			_pRoot = y;
		else if (x == x->_parent->_left)
			x->_parent->_left = y;
		else
			x->_parent->_right = y;
		y->_left = x;
		x->_parent = y;
	}

	void right_rotate(Node* x)
	{
		assert(x);
		Node* y = x->_left;
		assert(y);
		x->_left = y->_right;
		if (y->_right)
			y->_right->_parent = x;
		y->_parent = x->_parent;
		if (x->_parent == nullptr)
			_pRoot = y;
		else if (x == x->_parent->_left)
			x->_parent->_left = y;
		else
			x->_parent->_right = y;
		y->_right = x;
		x->_parent = y;
	}

	void insert_fixcolor(Node* x)
	{
		while (x->_parent && x->_parent->_color == false)
		{
			Node* p = x->_parent;
			if (p == p->_parent->_left)
			{
				Node* y = p->_parent->_right;
				if (y && y->_color == false)
				{
					y->_color = true;
					p->_color = true;
					p->_parent->_color = false;
					x = p->_parent;
					continue;
				}
				else if (x == x->_parent->_right)
				{
					x = x->_parent;
					left_rotate(x);
				}
				x->_parent->_color = true;
				x->_parent->_parent->_color = false;
				right_rotate(x->_parent->_parent);
			}
			else
			{
				Node* y = p->_parent->_left;
				if (y && y->_color == false)
				{
					y->_color = true;
					p->_color = true;
					p->_parent->_color = false;
					x = p->_parent;
					continue;
				}
				else if (x == x->_parent->_left)
				{
					x = x->_parent;
					right_rotate(x);
				}
				x->_parent->_color = true;
				x->_parent->_parent->_color = false;
				left_rotate(x->_parent->_parent);
			}
		}
		_pRoot->_color = true;
	}
	
	void delete_fixcolor(Node* x)
	{

	}
    template<typename _BST>
    friend class BSTPrint;
};
#endif //SEARCH_RBTREE_H_