#include <iostream>
#include "BinaryTree.h"

int main()
{
    int data[10] = { 11, 0, 467 ,92, 7, 3, 9846, 32, 46, 0 };
    int size = 10;

    std::cout << "Before naive sort: " << std::endl;
    std::cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "}" << std::endl;
    std::cout << "" << std::endl;

    BinaryTree<int> bt;
    bt.sort(data, size);

    std::cout << "After naive sort: " << std::endl;
    std::cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        std::cout << data[i] << " ";
    }
    std::cout << "}" << std::endl;

    return 0;
}