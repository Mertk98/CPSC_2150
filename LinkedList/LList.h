#pragma once
#ifndef _LList_H_
#define _LList_H_
#include <iostream>
template <typename T>
class Node
{
	public:
	Node();
	Node(T data, Node<T>* next);
	Node<T>* next;
	T data;
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
	friend std::ostream& operator<<(std::ostream&, const LList&);
	void destroy_list();
	LList(const LList&);
	LList& operator=(const LList&);
	~LList();
};
#endif // !_LList_H_
