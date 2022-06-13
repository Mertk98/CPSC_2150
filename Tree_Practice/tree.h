#ifndef _TREE_H_
#define _TREE_H_

template <typename T>
class Node
{
private:
    T data_;
    Node<T>* parent_;
    Node<T>* children_;
public:
    Node();
    Node(T data, Node<T>* parent, Node<T>* children_);
};

template <typename T>
class Tree
{
private:
    Node<T>* root;
public:
    Tree();
    Tree(T root);
};

#endif