#pragma once
#ifndef _LList_H_
#define _LList_H_
#include <iostream>

class LList
{
private:
	struct Node
	{
		int data;
		Node* next;
	};
	
	Node* head;

	// recursive
	static Node* last_node(Node* node);

public:
	LList();
	bool is_Empty() const;
	void insert(int);
	int length();
	bool search(int);
	int first() const;
	int last() const;
	bool removeAll(int);
	void twice();
	LList halve();
	friend std::ostream& operator<<(std::ostream&, const LList&);
	void destroy_list();
	LList(const LList&);
	LList& operator=(const LList&);
	~LList();
};
#endif // !_LList_H_
