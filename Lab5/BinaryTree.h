#include <iostream>
#include <climits>
#include <cmath>

template <typename T>
class Node
{
private:
    int next_;
    int right_;
    T data_;
    friend class BT;
public:
    Node();
    Node(int next, int right, T data);
    ~Node() = default;
};

template <typename T>
class BT
{
private:
    T* list_;
    int height_;
    int totalNodes_;
    int E_;
public:
    BT();
    void create(T* dataArr, int size);
    ~BT();
};

template <typename T>
BT<T>::BT()
{
    list_ = nullptr;
    height_ = 0;
    totalNodes_ = 0;
    E_ = INT_MAX;
}

template <typename T>
void BT<T>::create(T* dataArr, int size)
{
    height_ = std::ceil(std::log2(size)) + 1;
    totalNodes_ = (std::pow(2, height_) >= size) ? std::pow(2, height_) - 1 : std::pow(2, height_ - 1) - 1;
    list_ = new T[totalNodes_];

    int startIndex = (totalNodes_ -1 ) / 2;

// fix for the node
    for(int i = startIndex; i < totalNodes_ ; i++)
    {
        if(i < size)
        {
            list_[i] = dataArr[i];
        }
        else
        {
            list_[i] = E_;
        }
    }
}

template <typename T>
BT<T>::~BT()
{
    delete[] list_;
}