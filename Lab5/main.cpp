#include <iostream>
#include "BinaryTree.h"

int main()
{
    int data[5] = {8, 20, 0, 7 ,2};
    int size = 5;
    BT<int> bt;
    bt.create(data, size);
    return 0;
}