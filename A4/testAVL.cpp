#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "BST.h"
#include "AVLTree.h"
#include "Node.h"

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

void genInputFile(int n, std::string myFile)
{
    std::ofstream outFile;
    outFile.open(myFile);
    outFile << n << std::endl;

    for (int i = 0; i < n; i++)
    {
        // generate a random num in range (1000, 5000)
        int num = (rand() % (4999-1001+1)) + 1001;
        outFile << num << std::endl;
    }

    outFile.close();
}

template <typename T>
void InsertNodeAVL(AVLTree<T>* avl, T node)
{
    avl->insert(node);
}

template <typename T>
void printAVL(AVLTree<T>* avl)
{
    if (avl != nullptr)
    {
        avl->printInNPreOrder();
        std::cout << " " << std::endl;
    }
    else
    {
        std::cout << "Tree does not exist!!!" << std::endl;
    }
}

template <typename T>
AVLTree<T>* BuildAVLTree(std::string myFile)
{
    // for the first line
    int i = -1;
    // number of data points from the first line of the file
    int j = 1;

    AVLTree<T>* avl = new AVLTree<T>();

    std::fstream inFile;
    inFile.open(myFile);

	if (inFile.is_open())
	{
		std::string tmp;

		while (std::getline(inFile, tmp))
		{
            if (i == j)
            {
                break;
            }
            else if (i > -1 && tmp != "")
            {
                int data = std::stoi(tmp);
                InsertNodeAVL(avl, data);
            }
            else
            {
                j = std::stoi(tmp);
            }
            i++;
		}

		inFile.close();
	}

    return avl;
}

template <typename T>
void DeleteNodeAVL(AVLTree<T>* tree, const T node)
{
    tree->remove(node);
}

template <typename T>
void DeleteAVLTree(AVLTree<T>* tree)
{
    tree->deleteAVL();
}

int main()
{
    // get different random nums all the time
    srand(time(0));
    // filename
    std::string myFile = "test1.txt";
    int node;
    // creating input
    int n = getInput();
    genInputFile(n, myFile);

    // tree initialization
    AVLTree<int>* avl = BuildAVLTree<int>(myFile);
    std::cout << "height of AVL tree is: " << avl->height() << std::endl;
    printAVL(avl);
    
    // inserting an element
    std::cout << "Enter a value to insert: ";
    std::cin >> node;
    InsertNodeAVL(avl, node);
    std::cout << "height of the AVL tree is: " << avl->height() << std::endl;
    printAVL(avl);

    // deleting an element
    std::cout << "Enter a value to delete: ";
    std::cin >> node;
    DeleteNodeAVL(avl, node);
    std::cout << "height of AVL tree is: " << avl->height() << std::endl;
    printAVL(avl);

    // deleting the tree
    DeleteAVLTree(avl);
    printAVL(avl);

	return 0;
}