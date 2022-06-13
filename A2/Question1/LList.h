#ifndef _LList_H_
#define _LList_H_
#include <iostream>
#include "Patient.h"

template <typename T>
class LList;

template <typename T>
class Node
{
private:
	T* data;
	Node<T>* next;
public:
	Node();
	Node(T* data, Node<T>* next);
	template<typename T>
	friend class LList;
	~Node() = default;
};

template <typename T>
class LList
{
private:
	Node<T>* head;
public:
	LList();
	bool is_Empty() const;
	void insert(T* data);
	int length();
	bool search(T* data);
	T* first() const;
	// remove front
	bool removeFront();
	bool remove(T* data);
	void printList();
	void destroy_list();
	~LList();
};

template <typename T>
Node<T>::Node()
{
	data = nullptr;
	next = nullptr;
}

template <typename T>
Node<T>::Node(T* data, Node* next)
{
	this->next = next;
	this->data = data;
}

template <typename T>
LList<T>::LList()
{
	head = new Node<T>;
}

template <typename T>
bool LList<T>::is_Empty() const
{
	return head->next == nullptr;
}

template <typename T>
void LList<T>::insert(T* data)
{
	Node<T>* node = new Node<T>(data, nullptr);
	Node<T>* current = head;

	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = node;
}

template <typename T>
int LList<T>::length()
{
	int size = 0;
	Node<T>* node = head->next;
	while (node->next != nullptr)
	{
		size++;
		node = node->next;
	}

	return size;
}

template <typename T>
bool LList<T>::search(T* data)
{
	Node<T>* node = head->next;

	while (node != nullptr)
	{
		if (node->data == data)
		{
			return true;
		}
		node = node->next;
	}

	return false;
}

template <typename T>
T* LList<T>::first() const
{
	if (!is_Empty())
	{
		return head->next->data;
	}

	return nullptr;
}

template <typename T>
bool LList<T>::removeFront()
{
	int removed = 0;

	if (!is_Empty())
	{
		Node<T>* tmp = head->next->next;
		
		delete head->next;
		head->next = tmp;
		removed++;
	}

	return removed > 0;
}

template <typename T>
bool LList<T>::remove(T* data)
{
	int removed = 0;

	if (!is_Empty())
	{
		Node<T>* tmp = nullptr;
		Node<T>* node = head;

		while (node->next == nullptr)
		{
			if (node->next->data == data)
			{
				tmp = node->next->next;
				delete node->next;
				node->next = tmp;
				removed++;
			}
			node = node->next;
		}
	}

	return removed > 0;
}

 template <typename T>
 void LList<T>::printList()
 {
	 Node<T>* tmp = head->next;
	 //std::cout << "[";

	 while (tmp != nullptr)
	 {
		 std::cout << "====================" << std::endl;
		 std::cout << "Priority: " << tmp->data->getPriority() << std::endl;
		 std::cout << "First Name: " << tmp->data->getName() << std::endl;
		 std::cout << "====================" << std::endl;

		 tmp = tmp->next;
	 }

	 //std::cout << "]";
 }

template <typename T>
void LList<T>::destroy_list()
{
	Node<T>* current = head;
	Node<T>* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		delete current->data;
		delete current;
		current = next;	
	}
}

template <typename T>
LList<T>::~LList()
{
	destroy_list();
}

#endif // !_LList_H_
