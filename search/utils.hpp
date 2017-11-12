#ifndef SEARCH_UTILS_H_
#define SEARCH_UTILS_H_
#include<iostream>

template<typename _BST>
class BSTPrint
{
public:
    typedef typename _BST::Node Node;
    static void print(const _BST& tree)
    {
        Node* node = tree._pRoot;
        print(node);
    }
    static void print(const Node* node)
    {
        if (node == nullptr) return;
        std::cout << node->_key << '(';
		if (node->_color)
			std::cout << "black" << ' ';
		else
			std::cout << "red" << ' ';
        if (node->_left)
            std::cout << "L:" << node->_left->_key << '|';
        if (node->_right)
            std::cout << "R:" << node->_right->_key ;
        std::cout << ')' << std::endl;
        print(node->_left);
        print(node->_right);
    }
};
#endif // !SEARCH_UTILS_H_

