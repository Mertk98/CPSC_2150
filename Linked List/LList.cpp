#include <iostream>
#include "LList.h"

LList::LList()
{
	head = new Node;
	head->next = nullptr;
}

bool LList::is_Empty() const
{
	return head->next == nullptr;
}

void LList::insert(int data)
{
	Node* node = new Node;
	node->data = data;
	node->next = nullptr;

	Node* current = head;

	while(current->next != nullptr)
	{
		current = current->next;
	}

	current->next = node;
}

int LList::length()
{
	int size = 0;
	Node* node = head;
	while(node->next != nullptr)
	{
		size++;
		node = node->next;
	}

	return size;
}

bool LList::search(int data)
{
	Node* node = head->next;

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

int LList::first() const
{
	if (!is_Empty())
	{
		return head->next->data;
	}

	return 0;
}

int LList::last() const
{
	if (!is_Empty())
	{
		Node* node = head;
		while (node->next != nullptr)
		{
			node = node->next;
		}
		return node->data;
	}

	return 0;
}

bool LList::removeAll(int data)
{
	int count = 0;
	if (!is_Empty())
	{
		Node* tmp = nullptr;
		Node* node = head;

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

std::ostream& operator<<(std::ostream& out, const LList& list)
{
	out << "[";
	LList::Node* node = list.head->next;
	while (node != nullptr)
	{
		out << " " << node->data;
		node = node->next;
	}
	out << " ]";

	return out;
}


void LList::destroy_list()
{
	Node* current = head;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
}

LList::LList(const LList& other)
{
	operator=(other);
}

LList& LList::operator=(const LList& other)
{
	if (this == &other)
	{
		return *this;
	}

	destroy_list();
	head = new Node;
	head->next = nullptr;
	Node* other_node = other.head;
	Node* node = head;

	while (other_node->next != nullptr)
	{
		node->next = new Node;
		node = node->next;
		other_node = other_node->next;
		node->data = other_node->data;
		node->next = nullptr;
	}

	return *this;
}

LList::~LList()
{
	destroy_list();
}
