#ifndef _NODE_H_
#define _NODE_H_

template <typename T>
class Node
{
private:
    T data_;
    Node* left_;
    Node* right_;
    template <typename U>
    friend class BST;
    template <typename U>
    friend class BT;
    template <typename U>
    friend class AVLTree;
public:
    Node();
    Node(T data);
    Node(Node* left, Node* right, T data);
    ~Node() = default;
};

template <typename T>
Node<T>::Node()
{
    left_ = nullptr;
    right_ = nullptr;
}

template <typename T>
Node<T>::Node(T data)
{
    data_ = data;
    left_ = nullptr;
    right_ = nullptr;
}

template <typename T>
Node<T>::Node(Node<T>* left, Node<T>* right, T data)
{
    data_ = data;
    left_ = left;
    right_ = right;
}

#endif // !_NODE_H_