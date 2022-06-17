#include <iostream>
#include <climits>
#include <cmath>

template <typename T>
class Node
{
private:
    int left_;
    int right_;
    T data_;
    template <typename T>
    friend class BinaryTree;
public:
    Node();
    Node(int left, int right, T data);
    ~Node() = default;
};

template <typename T>
Node<T>::Node()
{
    left_ = 0;
    right_ = 0;
    data_ = 0;
}

template <typename T>
Node<T>::Node(int left, int right, T data)
{
    left_ = left;
    right_ = right;
    data_ = data;
}

template <typename T>
class BinaryTree
{
private:
    Node<T>* list_;
    int height_;
    int totalNodes_;
    int E_;
public:
    BinaryTree();
    void insert(T* data, int size);
    void heapify(T* data, int size);
    void printTree();
    ~BinaryTree();
};


template <typename T>
BinaryTree<T>::BinaryTree()
{
    list_ = nullptr;
    height_ = 0;
    totalNodes_ = 0;
    E_ = INT_MAX;
}

template <typename T>
void BinaryTree<T>::insert(T* data, int size)
{
    height_ = std::ceil(std::log(size)) + 1;
    totalNodes_ = size;
    list_ = new Node<T>[totalNodes_];

    for(int i = 0; i < size; i++)
    {

    }
}

template <typename T>
void BinaryTree<T>::printTree()
{
    for (int i = 0; i < totalNodes_; i++) 
    {
        std::cout << "index: " << i << ", data: " << list_[i].data_ << ", left: ";
        std::cout << list_[i].left_ << ", right: " << list_[i].right_ << std::endl;
    }
}

template <typename T>
BinaryTree<T>::~BinaryTree()
{
    delete[] list_;
}