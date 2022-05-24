#pragma once
#ifndef _LList_H_
#define _LList_H_
#include <iostream>

template <typename T>
class LList;

template <typename T>
class Node
{
private:
	Node<T>* next;
	T data;
public:
	Node();
	Node(T data, Node<T>* next);
	friend class LList;	
};

template <typename T>
class LList
{
private:
	Node<T>* head;

	// recursive
	static Node<T>* last_node(Node<T>* node);

public:
	LList();
	bool is_Empty() const;
	void insert(T);
	T length();
	bool search(T);
	T first() const;
	T last() const;
	bool removeAll(T);
	void twice();
	LList halve();
	friend std::ostream& operator<<(std::ostream& out, const LList<T>& list)
	{
		out << "[";
		Node<T>* node = list.head->next;
		while (node != nullptr)
		{
			out << " " << node->data;
			node = node->next;
		}
		out << " ]";

		return out;
	}

	void destroy_list();
	LList(const LList&);
	LList& operator=(const LList&);
	~LList();
};

template <typename T>
Node<T>::Node()
{
	next = nullptr;
}

template <typename T>
Node<T>::Node(T data, Node* next)
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
void LList<T>::insert(T data)
{
	Node<T>* node = new Node<T>(data, nullptr);
	Node<T>* current = head;

	while(current->next != nullptr)
	{
		current = current->next;
	}

	current->next = node;
}

template <typename T>
T LList<T>::length()
{
	int size = 0;
	Node<T>* node = head->next;
	while(node->next != nullptr)
	{
		size++;
		node = node->next;
	}

	return size;
}

template <typename T>
bool LList<T>::search(T data)
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
T LList<T>::first() const
{
	if (!is_Empty())
	{
		return head->next->data;
	}

	return 0;
}

template <typename T>
T LList<T>::last() const
{
	if (!is_Empty())
	{
		Node<T>* node = head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		return node->data;
	}

	return 0;
}

template <typename T>
Node<T>* LList<T>::last_node(Node<T>* node)
{
	if(node->next != nullptr)
	{
		node = last_node(node->next);
	}
	
	return node;
}

template <typename T>
void LList<T>::twice()
{
	// make it efficient
	// O(n)	
	Node<T>* first = head->next;
	Node<T>* last = last_node(first);
	int size = length();

	for(int i = 0; i < size+1; i++)
	{
		Node<T>* node = new Node<T>(first->data, nullptr);
		last->next = node;
		first = first->next;
		last = last->next;
	}

}

template <typename T>
LList<T> LList<T>::halve()
{
	LList halve_list;
	int size = length();
	int half = ((size / 2));
	Node<T>* node = head->next;
	for(int i = 0; i < half; i++)
	{
		node = node->next;
	}

	Node<T>* next = nullptr;

	for(int i = half; i < size+1; i++)
	{
		next = node->next;
		halve_list.insert(node->data);
		delete node;
		node = next;
	}

	return halve_list;
}

template <typename T>
bool LList<T>::removeAll(T data)
{
	int count = 0;
	if (!is_Empty())
	{
		Node<T>* tmp = nullptr;
		Node<T>* node = head;

		while (node->next != nullptr)
		{
			 if(node->next->data == data)
			 {
				 tmp = node->next->next;
				 delete node->next;
				 node->next = tmp;
				 count++;
				 if (tmp == nullptr)
				 {
					 break;
				 }
			 }
			 node = node->next;
		}
	}

	return count > 0;
}

// template <typename T>
// std::ostream& operator<<(std::ostream& out, const LList<T>& list)
// {
// 	out << "[";
// 	Node<T>* node = list.head->next;
// 	while (node != nullptr)
// 	{
// 		out << " " << node->data;
// 		node = node->next;
// 	}
// 	out << " ]";

// 	return out;
// }

template <typename T>
void LList<T>::destroy_list()
{
	Node<T>* current = head;
	Node<T>* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
}

template <typename T>
LList<T>::LList(const LList& other)
{
	head = new Node<T>;
	head->next = nullptr;
	operator=(other);
}

template <typename T>
LList<T>& LList<T>::operator=(const LList& other)
{
	if (this == &other)
	{
		return *this;
	}

	destroy_list();
	head = new Node<T>;
	head->next = nullptr;
	Node<T>* other_node = other.head;
	Node<T>* node = head;

	while (other_node->next != nullptr)
	{
		node->next = new Node<T>;
		node = node->next;
		other_node = other_node->next;
		node->data = other_node->data;
		node->next = nullptr;
	}

	return *this;
}

template <typename T>
LList<T>::~LList()
{
	destroy_list();
}

#endif // !_LList_H_
