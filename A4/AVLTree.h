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
	// overridden recursive remove
	Node<T>* remove(Node<T>* node, const T data);
	// efficient height
	void setHeight(Node<T>* node);
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
	// overridden remove
	void remove(const T data);
	// print the AVL Tree by using pre-order and in-order algorithm
	void printInNPreOrder();
	// reset the tree
	void deleteAVL();
};

template <typename T>
int AVLTree<T>::balanceFactor(Node<T>* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else if ((node->left_ == nullptr && node->right_ == nullptr))
	{
		return 0;
	}
	else if (node->left_ != nullptr && node->right_ == nullptr)
	{
		return 0 - node->height;
	}
	else if (node->left_ == nullptr && node->right_ != nullptr)
	{
		return node->height;
	}
	else
	{
		return node->right_->height - node->left_->height;
	}
}

template <typename T>
bool AVLTree<T>::checkBalance(Node<T>* node)
{
	return (std::abs(balanceFactor(node)) < 2);
}

template <typename T>
void AVLTree<T>::setHeight(Node<T>* node)
{
	if (node == nullptr)
	{
		return;
	}
	else if (node->left_ == nullptr && node->right_ == nullptr)
	{
		node->height = 0;
	}
	else if (node->left_ == nullptr && node->right_ != nullptr)
	{
		node->height = node->right_->height + 1;
	}
	else if (node->left_ != nullptr && node->right_ == nullptr)
	{
		node->height = node->left_->height + 1;
	}
	else
	{
		if (node->left_->height > node->right_->height)
		{
			node->height = node->left_->height + 1;
		}
		else
		{
			node->height = node->right_->height + 1;
		}
	}
}

template <typename T>
Node<T>* AVLTree<T>::leftRotation(Node<T>* node)
{
	Node<T>* tmp = node;
	Node<T>* tmpR = tmp->right_;
	Node<T>* tmpRL = tmpR->left_;

	tmpR->left_ = tmp;
	tmp->right_ = tmpRL;

	setHeight(tmp);
	setHeight(tmp->left_);
	setHeight(tmp->right_);

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

	setHeight(tmp);
	setHeight(tmp->left_);
	setHeight(tmp->right_);

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

	setHeight(tmpL);
	setHeight(tmpL->left_);
	setHeight(tmpL->right_);

	tmp->left_ = tmpL;
	tmp = rightRotation(tmp);

	setHeight(tmp);
	setHeight(tmp->left_);
	setHeight(tmp->right_);

	return tmp;
}

template <typename T>
Node<T>* AVLTree<T>::RLRotation(Node<T>* node)
{
	Node<T>* tmp = node;
	Node<T>* tmpR = rightRotation(tmp->right_);

	setHeight(tmpR);
	setHeight(tmpR->left_);
	setHeight(tmpR->right_);

	tmp->right_ = tmpR;
	tmp = leftRotation(tmp);

	setHeight(tmp);
	setHeight(tmp->left_);
	setHeight(tmp->right_);

	return tmp;
}

template <typename T>
Node<T>* AVLTree<T>::handleRotation(Node<T>* node)
{
	int bf = balanceFactor(node);
	int bfLeft = balanceFactor(node->left_);
	int bfRight = balanceFactor(node->right_);
	Node<T>* tmp = node;

	if (bf == 2 && (bfRight == 1 || bfRight == 0))
	{
		tmp = leftRotation(node);
	}
	else if (bf == -2 && bfLeft == 1)
	{
		tmp = LRRotation(node);
	}
	else if (bf == -2 && (bfLeft == -1 || bfLeft == 0))
	{
		tmp = rightRotation(node);
	}
	else if (bf == 2 && bfRight == -1)
	{
		tmp = RLRotation(node);
	}

	setHeight(tmp);
	setHeight(tmp->left_);
	setHeight(tmp->right_);

	return tmp;
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

	setHeight(node);

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
Node<T>* AVLTree<T>::remove(Node<T>* node, const T data)
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
		}

		// node has only left child
		else if (node->left_ != nullptr && node->right_ == nullptr)
		{
			tmpNode = node;
			node = node->left_;
			delete tmpNode;
			tmpNode = nullptr;
		}
		// node has only right child
		else if (node->right_ != nullptr && node->left_ == nullptr)
		{
			tmpNode = node;
			node = node->right_;
			delete tmpNode;
			tmpNode = nullptr;
		}
		// node has two children
		else
		{
			// find height of left subtree and right subtree to determine what to use
			// either predecessor or successor
			int lHeight = node->left_->height;
			int rHeight = node->right_->height;

			// use predecessor since left subtree height is larger
			if (lHeight > rHeight)
			{
				tmpNode = BST<T>::predecessor(node->left_);
				node->data_ = tmpNode->data_;
				node->left_ = remove(node->left_, tmpNode->data_);
			}
			// use successor since right subtree height is larger
			else
			{
				tmpNode = BST<T>::successor(node->right_);
				node->data_ = tmpNode->data_;
				node->right_ = remove(node->right_, tmpNode->data_);
			}
		}
	}

	setHeight(node);

	if (node != nullptr && !checkBalance(node))
	{
		node = handleRotation(node);
	}

	return node;
}

template <typename T>
void AVLTree<T>::remove(const T data)
{
	remove(BST<T>::root_, data);
	BST<T>::size_--;
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
	else
	{
		std::cout << "Tree is empty!!!" << std::endl;
	}
}

template <typename T>
void AVLTree<T>::deleteAVL()
{
	BST<T>::destroyTree(BST<T>::root_);
	BST<T>::root_ = nullptr;
}

#endif // !_AVLTREE_H_