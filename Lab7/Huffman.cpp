#include <iostream>
#include <string>
#include <queue>
#include <functional>
#include <iomanip>
#include "Node.h"

template <typename T>
void destroyTree(Node<T>* node)
{
    if (node != nullptr)
    {
        destroyTree(node->left_);
        destroyTree(node->right_);
        delete node;
    }
}

// custom comparison function for min-heap
template <typename T>
bool compareNodes(const Node<T>* node1, const Node<T>* node2)
{
    return node1->frequency_ > node2->frequency_;
}

int* calcFrequency(std::string str, int size)
{
    int* frequency = new int[size]{ 0 };

    for (size_t i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        frequency[(int)ch]++;
    }

    return frequency;
}

template <typename T>
void printTrie(Node<T>* node, T code)
{
    if (node != nullptr)
    {
        if (node->data_.length() == 1)
        {
            std::cout << std::setw(9) << std::left << node->data_;
            std::cout << std::setw(4) << std::right << " = ";
            std::cout << std::setw(10) << std::right << code << std::endl;
        }

        printTrie(node->right_, code + "1");
        printTrie(node->left_, code + "0");
    }
}

Node<std::string>* makeHuffmanTree(std::string str)
{
    int size = 128;
    int* frequency = calcFrequency(str, size);
    std::priority_queue <Node<std::string>*, std::vector<Node<std::string>*>, decltype(&compareNodes<std::string>)> pqueue(&compareNodes);

    for (int i = 0; i < size; i++)
    {
        if (frequency[i] != 0)
        {
            char ch = char(i);
            std::string s = "";
            s += ch;
            Node<std::string>* tmp = new Node<std::string>(nullptr, nullptr, s, frequency[i]);
            pqueue.push(tmp);
        }
    }

    while (pqueue.size() > 1)
    {
        Node<std::string>* tmp = nullptr;
        Node<std::string>* left = nullptr;
        Node<std::string>* right = nullptr;

        left = pqueue.top();
        pqueue.pop();
        right = pqueue.top();
        pqueue.pop();
        tmp = new Node<std::string>(left, right, left->data_ + right->data_, left->frequency_ + right->frequency_);
        pqueue.push(tmp);
    }

    Node<std::string>* root = pqueue.top();
    pqueue.pop();
    delete[] frequency;

    return root;
}

int main()
{
    // string to compress
    std::string str = "EYEWITNESSNEWS";
    // root og the huffman tree
    Node<std::string>* root = makeHuffmanTree(str);
    // pretty print
    std::cout << std::setw(9) << std::left << "Character";
    std::cout << std::setw(4) << std::right << "   ";
    std::cout << std::setw(10) << std::right << " Code-Word" << std::endl;
    // print the huffman tree
    std::string code = "";
    printTrie(root,code);

    destroyTree(root);
    
    return 0;
}