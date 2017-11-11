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
    _Value get(const _Key& key) const
    {
        Node* node = get(_pRoot, key);
        if (node)
            return node->_val;
        return _Value();
    }

    void put(const _Key& key, const _Value& val)
    {
        _pRoot = put(_pRoot, key, val);
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
        deleteMin(_pRoot);
    }

    void deleteKey(const _Key& key)
    {
        Node* node = get(_pRoot, key);
        if (node == nullptr) return;
        deleteNode(node);
    }
private:
    struct Node
    {
        _Key _key;
        _Value _val;
        Node*   _parent;
        Node*   _left;
        Node*   _right;
        Node(const _Key& key, const _Value& val)
            : _key(key), _val(val), _parent(nullptr)
              , _left(nullptr), _right(nullptr)
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

    Node* get(Node* node, const _Key& key) const
    {
        if (node == nullptr) return nullptr;
        if (_pr(key, node->_key)) return get(node->_left, key);
        else if (_pr(node->_key, key)) return get(node->_right, key);
        else return node;
    }

    Node* put(Node* node, const _Key& key, const _Value& val)
    {
        if (node == nullptr)
            return new Node(key, val);
        if (_pr(key, node->_key))
        {
            node->_left = put(node->_left, key, val);
            node->_left->_parent = node;
        }
        else if (_pr(node->_key, key))
        {
            node->_right = put(node->_right, key, val);
            node->_right->_parent = node;
        }
        else  node->_val = val;
        return node;
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

    void deleteMin(Node* node)
    {
        Node* minimal = min(node);
        if (minimal == nullptr) return;
        transplant(minimal, minimal->_right);
        minimal->_right = nullptr;
        delete minimal;
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

    void deleteNode(Node* node)
    {
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
private:
    Node* _pRoot;
    _Pr   _pr;
    template<typename _BST>
    friend class BSTPrint;
};
#endif