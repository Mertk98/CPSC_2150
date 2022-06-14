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
    void create(const T* dataArr, const int size);
    // perform the naive sort algorithm
    void sort(T* dataArr, const int size);
    // perform a right to left - bottom up traversal
    void populate();
    void replace(T* dataArr, const int size, int index);
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
void BinaryTree<T>::sort(T* dataArr, const int size)
{
    create(dataArr, size);

    for (int i = 0; i < size; i++)
    {
        populate();
        replace(dataArr, size, i);
    }
}

template <typename T>
void BinaryTree<T>::create(const T* dataArr, const int size)
{
    height_ = (int)(std::ceil(std::log2(size)) + 1);
    totalNodes_ = (std::pow(2, height_) >= size) ? std::pow(2, height_) - 1 : std::pow(2, height_ - 1) - 1;
    list_ = new Node<T>[totalNodes_];

    // iterators
    int startIndex = (totalNodes_ - 1) / 2;
    int count = 0;

    // fix for the node
    for (int i = startIndex; i < totalNodes_; i++)
    {
        if (count < size)
        {
            Node<T> node(-1, -1, dataArr[count]);
            list_[i] = node;
            count++;
        }
        else
        {
            Node<T> node(-1, -1, E_);
            list_[i] = node;
        }
    }
}



template <typename T>
void BinaryTree<T>::populate()
{
    int startIndex = std::pow(2, height_ - 1) - 1;

    for (int i = startIndex-1; i > -1; i--)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        list_[i].left_ = left;
        list_[i].right_ = right;

        list_[i].data_ = (list_[left].data_ <= list_[right].data_) ? list_[left].data_ : list_[right].data_;
    }
}

template <typename T>
void BinaryTree<T>::replace(T* dataArr, const int size, int index)
{
    int startIndex = (totalNodes_ - 1) / 2;
    int min = list_[0].data_;

    for (int i = 0; i < size; i++)
    {
        int indexOfMin = startIndex + i;

        if (list_[indexOfMin].data_ == min)
        {
            list_[indexOfMin].data_ = E_;
            break;
        }
    }
    
    dataArr[index] = min;
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