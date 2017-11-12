#ifndef SEARCH_BSTREE_H_
#define SEARCH_BSTREE_H_

template<typename _Key, typename _Value, typename _Pr>
class BST
{
public:
    BST() : _pRoot(nullptr), _pr() {}
    ~BST()
    { 
        delete _pRoot;
    }

    int size() const
    {
        return size(_pRoot);
    }
    //unreliable
    _Value find(const _Key& key) const
    {
        Node* node = find(_pRoot, key);
        if (node)
            return node->_val;
        return _Value();
    }

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
    }

    //unreliable
    _Key min() const
    {
        Node* node = min(_pRoot);
        if (node)
            return node->_val;
        return _Key();
    }
    //unreliable
    _Key max() const
    {
        Node* node = max(_pRoot);
        if (node)
            return node->_val;
        return _Key();
    }

    void deleteMin()
    {
		Node* minimal = min(_pRoot);
		if (minimal == nullptr) return;
		transplant(minimal, minimal->_right);
		minimal->_right = nullptr;
		delete minimal;
    }

    void deleteKey(const _Key& key)
    {
        Node* node = get(_pRoot, key);
		if (node == nullptr) return;

		if (node->_left == nullptr)
		{
			transplant(node, node->_right);
			node->_right = nullptr;
			delete node;
		}
		else if (node->_right == nullptr)
		{
			transplant(node, node->_left);
			node->_left = nullptr;
			delete node;
		}
		else
		{
			Node* successor = min(node->_right);
			transplant(successor, successor->_right);

			successor->_right = node->_right;
			node->_right = nullptr;
			successor->_left = node->_left;
			node->_left = nullptr;

			transplant(node, successor);
			delete node;
		}
    }
protected:
    struct Node
    {
        _Key _key;
        _Value _val;
        Node*   _parent;
        Node*   _left;
        Node*   _right;
		bool	_color; //true means black,otherwise red.
        Node(const _Key& key, const _Value& val)
            : _key(key), _val(val), _parent(nullptr)
              , _left(nullptr), _right(nullptr)
			  , _color(false)
        {}
        ~Node()
        {
            if (_left) delete _left;
            if (_right) delete _right;
        }
    };

    int size(const Node* node) const
    {
        if (node == nullptr) return 0;
        return size(node->_left) + size(node->_right) + 1;
    }

    Node* find(Node* node, const _Key& key) const
    {
        if (node == nullptr) return nullptr;
        if (_pr(key, node->_key)) return find(node->_left, key);
        else if (_pr(node->_key, key)) return find(node->_right, key);
        else return node;
    }

    Node* min(Node* node) const
    {
        if (node == nullptr) return nullptr;
        if (node->_left)
            return min(node->_left);
        return node;
    }

    Node* max(Node* node) const
    {
        if (node == nullptr) return nullptr;
        if (node->_right)
            return max(node->_right);
        return node;
    }

    void transplant(Node* u, Node* v)
    {
        if (u->_parent == nullptr) _pRoot = v;
        else if (u == u->_parent->_left)
            u->_parent->_left = v;
        else u->_parent->_right = v;
        if (v != nullptr)
            v->_parent = u->_parent;
    }
protected:
    Node* _pRoot;
    _Pr   _pr;
    template<typename _BST>
    friend class BSTPrint;
};
#endif //SEARCH_BSTREE_H_