#ifndef _AVLTREE_H_
#define _AVLTREE_H_
#include <iostream>
#include "BST.h"
#include "Node.h"

template <typename T>
class AVLTree : public BST<T>
{
private:
	// recursive rotations
	Node<T>* leftRotation(Node<T>* node);
	Node<T>* rightRotation(Node<T>* node);
	Node<T>* LRRotation(Node<T>* node);
	Node<T>* RLRotation(Node<T>* node);
	// overridden recursive insert
	Node<T>* insert(Node<T>* node, const T data);
public:
	// handles all the required rotations on the provided node
	Node<T>* handleRotation(Node<T>* node);
	// return negative if left subtree height is greater than right subtree
	// return positive if right subtree height is greater than left subtree
	// return 0 if left and right subtree height is equal
	int balanceFactor(Node<T>* node);
	// if the tree is balanced, return true 
	// else, return false
	bool checkBalance(Node<T>* node);
	// overridden insert
	void insert(const T data);
	// print the AVL Tree by using pre-order and in-order algorithm
	void printInNPreOrder();
	// reset the tree
	void deleteAVL();

};

template <typename T>
Node<T>* AVLTree<T>::leftRotation(Node<T>* node)
{
	Node<T>* tmp = node;
	Node<T>* tmpR = tmp->right_;
	Node<T>* tmpRL = tmpR->left_;

	tmpR->left_ = tmp;
	tmp->right_ = tmpRL;

	if (tmp == BST<T>::root_)
	{
		BST<T>::root_ = tmpR;
	} 

	return tmpR;
}

template <typename T>
Node<T>* AVLTree<T>::rightRotation(Node<T>* node)
{
	Node<T>* tmp = node;
	Node<T>* tmpL = tmp->left_;
	Node<T>* tmpLR = tmpL->right_;
	
	tmpL->right_ = tmp;
	tmp->left_ = tmpLR;

	if (tmp == BST<T>::root_)
	{
		BST<T>::root_ = tmpL;
	}

	return tmpL;
}

template <typename T>
Node<T>* AVLTree<T>::LRRotation(Node<T>* node)
{
	Node<T>* tmp = node;
	Node<T>* tmpL = leftRotation(tmp->left_);
	tmp->left_ = tmpL;
	tmp = rightRotation(tmp);

	return tmp;
}

template <typename T>
Node<T>* AVLTree<T>::RLRotation(Node<T>* node)
{
	Node<T>* tmp = node;
	Node<T>* tmpR = rightRotation(tmp->right_);
	tmp->right_ = tmpR;
	tmp = leftRotation(tmp);

	return tmp;
}

template <typename T>
Node<T>* AVLTree<T>::handleRotation(Node<T>* node)
{
	int bf = balanceFactor(node);
	int bfLeft = (node->left_ != nullptr) ? balanceFactor(node->left_) : 0;
	int bfRight = (node->right_ != nullptr) ? balanceFactor(node->right_) : 0;
	Node<T>* tmp = node;

	if (bf == 2 && bfRight == 1)
	{
		tmp = leftRotation(node);
	}
	else if (bf == -2 && bfLeft == 1)
	{
		tmp = LRRotation(node);
	}
	else if (bf == -2 && bfLeft == -1)
	{
		tmp = rightRotation(node);
	}
	else if (bf == 2 && bfRight == -1)
	{
		tmp = RLRotation(node);
	}

	return tmp;
}

template <typename T>
int AVLTree<T>::balanceFactor(Node<T>* node)
{
	return (BST<T>::height(node->right_) - BST<T>::height(node->left_));
}

template <typename T>
bool AVLTree<T>::checkBalance(Node<T>* node)
{
	return (std::abs(balanceFactor(node)) < 2);
}

template <typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, const T data)
{
	if (data > node->data_)
	{
		if (node->right_ != nullptr)
		{
			node->right_ = insert(node->right_, data);
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
			node->left_ = insert(node->left_, data);
		}
		else
		{
			node->left_ = new Node<T>(data);
		}
	}

	if (node != nullptr && !checkBalance(node))
	{
		node = handleRotation(node);
	}

	return node;
}

template <typename T>
void AVLTree<T>::insert(const T data)
{
	if (BST<T>::isEmpty())
	{
		BST<T>::root_ = new Node<T>(data);
	}
	else
	{
		BST<T>::root_ = insert(BST<T>::root_, data);
	}

	BST<T>::size_++;
}

template <typename T>
void AVLTree<T>::printInNPreOrder()
{
	if(BST<T>::root_ != nullptr)
	{
		std::cout << "pre-order of the AVL tree: " << std::endl;
		BST<T>::preOrderTraversal(BST<T>::root_);
		std::cout << "" << std::endl;
		std::cout << "in-order of the AVL tree: " << std::endl;
		BST<T>::inOrderTraversal(BST<T>::root_);
	}
}

template <typename T>
void AVLTree<T>::deleteAVL()
{
	BST<T>::destroyTree(BST<T>::root_);
}
#endif // !_AVLTREE_H_