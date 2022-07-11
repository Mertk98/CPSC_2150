#ifndef _BST_H_
#define _BST_H_
#include <iostream>
#include <vector>
#include "Node.h"

template <typename T>
class BST
{
protected:
    int size_;
    Node<T>* root_;
    //helpers
    // calculate the height of the tree with respeect to root
    int height(Node<T>* node);
    // insert the node to BST recursively
    void insert(Node<T>* node, const T data);
    // find the inorder predecessor
    Node<T>* predecessor(Node<T>* node);
    // find the inorder successor
    Node<T>* successor(Node<T>* node);
    // sort the tree using inorder traversal
    void sortInOrder(Node<T>* node, std::vector<T>& list);
    // recursive delete
    Node<T>* remove(Node<T>* node, const T data);
    // traverse the tree by using in-order traversal algorithm
    void inOrderTraversal(Node<T>* node);
    // traverse the tree by using pre-order traversal algorithm
    void preOrderTraversal(Node<T>* node);
    // destructor helper
    void destroyTree(Node<T>* node);
public:
    BST();
    bool isEmpty();
    int getSize();
    // return the height of the tree 
    int height();
    // return the first node if data exists in the tree
    // else, return nullptr
    //recursive
    Node<T>* search(const T data) const;
    // insert the node to BST
    void insert(const T data);
    // use search to find the node and delete the node by either
    // merging or copying
    // calls recursive remove
    void remove(const T data);
    void printTree();
    // create a sorted list
    void sortTheTree(std::vector<T>& list);
    // destructor
    ~BST();
};

template <typename T>
BST<T>::BST()
{
    size_ = 0;
    root_ = nullptr;
}

template <typename T>
bool BST<T>::isEmpty()
{
    return (root_ == nullptr);
}

template <typename T>
int BST<T>::height(Node<T>* node)
{
    if (node == nullptr)
    {
        return -1;
    }

    int leftHeight = height(node->left_);
    int rightHeight = height(node->right_);

    if (rightHeight > leftHeight)
    {
        return 1 + rightHeight;
    }
    else
    {
        return 1 + leftHeight;
    }

    return 0;

}

template <typename T>
int BST<T>::height()
{
    return height(root_);
}

template <typename T>
int BST<T>::getSize()
{
    return size_;
}

template <typename T>
Node<T>* BST<T>::search(const T data) const
{
    Node<T>* node = root_;

    while (node != nullptr)
    {
        if (data == node->data_)
        {
            return node;
        }
        else if (data > node->data_)
        {
            node = node->right_;
        }
        else
        {
            node = node->left_;
        }
    }

    return  nullptr;
}

//recursive insert
template <typename T>
void BST<T>::insert(Node<T>* node, const T data)
{
    if (data > node->data_)
    {
        if (node->right_ != nullptr)
        {
            insert(node->right_, data);
        }
        else
        {
            node->right_ = new Node<T>(data);
        }
    }
    else
    {
        if (node->left_ != nullptr)
        {
            insert(node->left_, data);
        }
        else
        {
            node->left_ = new Node<T>(data);
        }
    }
}

// calls the recursive insert
template <typename T>
void BST<T>::insert(T data)
{
    if (isEmpty())
    {
        root_ = new Node<T>(data);
    }
    else
    {
        insert(root_, data);
    }
    size_++;
}

template <typename T>
Node<T>* BST<T>::predecessor(Node<T>* node)
{
    if (node->right_ == nullptr)
    {
        return node;
    }
    else
    {
        return predecessor(node->right_);
    }

    return nullptr;
}

template <typename T>
Node<T>* BST<T>::successor(Node<T>* node)
{
    if (node->left_ == nullptr)
    {
        return node;
    }
    else
    {
        return successor(node->left_);
    }

    return nullptr;
}

template <typename T>
Node<T>* BST<T>::remove(Node<T>* node, const T data)
{
    if (node == nullptr)
    {
        return node;
    }
    else if (data > node->data_)
    {
        node->right_ = remove(node->right_, data);
    }
    else if (data < node->data_)
    {
        node->left_ = remove(node->left_, data);
    }
    else
    {
        Node<T>* tmpNode = nullptr;

        // node is a leaf
        if (node->left_ == nullptr && node->right_ == nullptr)
        {
            delete node;
            node = nullptr;
            return node;
        }

        // node has only left child
        else if (node->left_ != nullptr && node->right_ == nullptr)
        {
            tmpNode = node;
            node = node->left_;
            delete tmpNode;
            tmpNode = nullptr;
            return node;
        }
        // node has only right child
        else if (node->right_ != nullptr && node->left_ == nullptr)
        {
            tmpNode = node;
            node = node->right_;
            delete tmpNode;
            tmpNode = nullptr;
            return node;
        }
        // node has two children
        else
        {
            // find height of left subtree and right subtree to determine what to use
            // either predecessor or successor
            int lHeight = height(node->left_);
            int rHeight = height(node->right_);

            // use predecessor since left subtree height is larger
            if (lHeight > rHeight)
            {
                tmpNode = predecessor(node->left_);
                node->data_ = tmpNode->data_;
                node->left_ = remove(node->left_, tmpNode->data_);
            }
            // use successor since right subtree height is larger
            else
            {
                tmpNode = successor(node->right_);
                node->data_ = tmpNode->data_;
                node->right_ = remove(node->right_, tmpNode->data_);
            }

        }
    }

    // add a condition here to check if the tree is balanced in AVL
    return node;
}

template <typename T>
void BST<T>::remove(const T data)
{
    root_ = remove(root_, data);
    size_--;
}

template <typename T>
void BST<T>::inOrderTraversal(Node<T>* node)
{
    if (node != nullptr)
    {
        inOrderTraversal(node->left_);
        std::cout << node->data_ << " ";
        inOrderTraversal(node->right_);
    }
}

template <typename T>
void BST<T>::preOrderTraversal(Node<T>* node)
{
    if (node != nullptr)
    {
        std::cout << node->data_ << " ";
        preOrderTraversal(node->left_);
        preOrderTraversal(node->right_);
    }
}

template <typename T>
void BST<T>::printTree()
{
    if (!isEmpty())
    {
        inOrderTraversal(root_);
    }
}

template <typename T>
void BST<T>::sortInOrder(Node<T>* node, std::vector<T>& list)
{
    if (node != nullptr)
    {
        sortInOrder(node->left_, list);
        list.push_back(node->data_);
        sortInOrder(node->right_, list);
    }
}

template <typename T>
void BST<T>::sortTheTree(std::vector<T>& list)
{
    if (!isEmpty())
    {
        sortInOrder(root_, list);
    }
}

template <typename T>
void BST<T>::destroyTree(Node<T>* node)
{
    if (node != nullptr)
    {
        destroyTree(node->left_);
        destroyTree(node->right_);
        delete node;
        node = nullptr;
    }
}

template <typename T>
BST<T>::~BST()
{
    if (root_ != nullptr)
    {
        destroyTree(root_);
    }
}
#endif // !_BST_H_