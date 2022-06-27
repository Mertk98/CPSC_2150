#include <iostream>
#include <ctime>
#include <vector>
#include "BST.h"
#include "BT.h"

// instructions for random number generating algorithm
void printInstructions()
{
    std::cout << "To generate a random positive integer, enter 0." << std::endl;
    std::cout << "Otherwise, enter a positive integer." << std::endl;
}

// generate either a random num or user input depending on the input
int getInput()
{
    int num = -1;

    while (num < 0)
    {
        printInstructions();
        std::cin >> num;
    }

    if (num == 0)
    {
        num = rand() % 1000;
    }

    return num;
}

// generate a list of random integers in an interval of [-n,n]
std::vector<int> genData(int n)
{
    std::vector<int> list;

    for (int i = 0; i < n; i++)
    {
        // generate a random num in [-n, n]
        list.push_back(2 * (rand() % (n + 1)) - n);
    }

    return list;

}

// print the list items
void printList(const std::vector<int>& list)
{
    std::cout << "{ ";
    for (size_t i = 0; i < list.size(); i++)
    {
        std::cout << list[i] << " ";
    }
    std::cout << " }\n";
}

template <typename T>
BST<T>& makeBST(const std::vector<T>& list)
{
    BST<T>* bst = new BST<T>();

    for (size_t i = 0; i < list.size(); i++)
    {
        bst->insert(list[i]);
    }
    
    return *bst;
}

template <typename T>
void printBT(T& bt)
{
    bt.printTree();
    std::cout << " " << std::endl;
}

template <typename T>
void remove(const T data, BST<T>& bst)
{
    bst.remove(data);
}

template <typename T>
void balancedInsert(BST<T>& bst, std::vector<T>& list, int start, int end)
{
    int mid = start + (end-start) / 2;
    if (start > end)
    {
        return;
    }
    
    bst.insert(list[mid]);
    balancedInsert(bst, list, start, mid-1);
    balancedInsert(bst, list, mid+1, end);
    
}

template <typename T>
BST<T>& mergeBST(BST<T>& bst1, BST<T>& bst2)
{
    // size of the BSTs
    int size1 = bst1.getSize();
    int size2 = bst2.getSize();
    // list to store the ascending order of both datasets
    std::vector<T> list1;
    std::vector<T> list2;
    std::vector<T> list3;

    //sort both trees and store in given lists
    bst1.sortTheTree(list1);
    bst2.sortTheTree(list2);

    //iterators
    int i = 0;
    int j = 0;

    //merge two sorted list in O(m+n) time
    while (i + j < size1 + size2)
    {
        if (j == size2)
        {
            list3.push_back(list1[i]);
            i++;
        }
        else if (i < size1 && list1[i] < list2[j])
        {
            list3.push_back(list1[i]);
            i++;
        }
        else if (i == size1)
        {
            list3.push_back(list2[j]);
            j++;
        }
        else if (j < size2 && list1[i] > list2[j])
        {
            list3.push_back(list2[j]);
            j++;
        }
        else if(i < size1 && j < size2 && list1[i] == list2[j])        
        {
            list3.push_back(list1[i]);
            list3.push_back(list2[j]);
            i++;
            j++;
        }
    }
    
    size_t size3 = list3.size();

    // create a new bst with the merged list
    BST<T>* bst3 = new BST<T>();
    balancedInsert(*bst3, list3, 0, (int)size3-1);

    return *bst3;
}

template <typename T>
int height(BST<T>& bst)
{
    return bst.height();
}

std::string getExpression()
{
    std::string exp = "";

    std::cout << "Please enter an infix expression: " << std::endl;

    std::cin >> exp;

    return exp;
}

BT<char>& infixExprTree(std::string infix)
{
    BT<char>* bt = new BT<char>();

    bt->createExprTree(infix);

    return *bt;
}

std::string infixPostfixExpr(std::string infix)
{
    BT<char> bt;
    std::string str = "";
    bt.createExprTree(infix);
    bt.postfix(str);

    return str;
}

int main()
{
    // get different random nums all the time
    srand(time(0));

    // first data list
    int n1 = getInput();
    std::vector<int> list1 = genData(n1);
    printList(list1);

    // second data list
    int n2 = getInput();
    std::vector<int> list2 = genData(n2);
    printList(list2);

    BST<int> bst1 = makeBST(list1);
    std::cout << "In-order traversal of bt1 is: " << std::endl;
    printBT(bst1);

    remove(list1[n1/2], bst1);
    
    std::cout << "In-order traversal of bt1 after deleting: " << std::endl;
    printBT(bst1);

    BST<int> bst2 = makeBST(list2);
    std::cout << "In-order traversal of bt2 is: " << std::endl;
    printBT(bst2);

    BST<int> bst3 = mergeBST(bst1, bst2);
    std::cout << "In-order traversal of bt3 is: " << std::endl;
    printBT(bst3);

    std::cout << "The height of bst1 is " << height(bst1) << std::endl;
    std::cout << "The height of bst2 is " << height(bst2) << std::endl;
    std::cout << "The height of bst3 is " << height(bst3) << std::endl;

    std::string infix = getExpression();
    BT<char> bt4 = infixExprTree(infix);
    printBT(bt4);

    std::cout << "The postfix expression is " << infixPostfixExpr(infix) << std::endl;

    return 0;
}