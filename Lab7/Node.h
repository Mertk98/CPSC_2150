#ifndef _NODE_H_
#define _NODE_H_

template <typename T>
class Node
{
public:
    T data_;
    int frequency_;
    Node* left_;
    Node* right_;
    Node();
    Node(T data);
    Node(Node* left, Node* right, T data, int frequency);
    ~Node() = default;
};

template <typename T>
Node<T>::Node()
{
    frequency_ = 0;
    left_ = nullptr;
    right_ = nullptr;
}

template <typename T>
Node<T>::Node(T data)
{
    data_ = data;
    frequency_ = 0;
    left_ = nullptr;
    right_ = nullptr;
}

template <typename T>
Node<T>::Node(Node<T>* left, Node<T>* right, T data, int frequency)
{
    data_ = data;
    frequency_ = frequency;
    left_ = left;
    right_ = right;
}

#endif // !_NODE_H_