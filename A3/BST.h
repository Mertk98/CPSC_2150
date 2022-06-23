#include <iostream>

template <typename T>
class Node
{
private:
    T data_;
    Node* left_;
    Node* right_;
    template <typename U>
    friend class BST;
public:
    Node();
    Node(T data, Node* left, Node* right);
    ~Node() = default;
};

template <typename T>
class BST
{
private:
    int size_;
    Node* root;
public:
    BST();
    bool isEmpty();
    int height();
    // return the first node if data exists in the tree
    // else, return nullptr
    Node* search(Node* node, const T data) const;
    // insert the node to BST
    void insert(const T data);
    // use search to find the node and delete the node by either
    // merging or copying
    void remove(const T data);
    // traverse the tree by using inorder traversal algorithm
    void inOrderTraversal(Node* node);
};