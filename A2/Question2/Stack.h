// Mert Kilic
// 100334228
#ifndef _STACK_H_
#define _STACK_H_
#include <iostream>
#include <vector>
#include "StackEmpty.h"

template <typename T>
class Stack
{
private:
	int count;
	std::vector<T> stack;
public:
	Stack();
	int size() const;
	bool isEmpty() const;
	const T& peek() const;
	void push(const T& data);
	void pop();
};

template <typename T>
Stack<T>::Stack()
{
	count = -1;
}

template <typename T>
int Stack<T>::size() const
{
	return (count + 1);
}

template <typename T>
bool Stack<T>::isEmpty() const
{
	return (size() == 0);
}

template <typename T>
const T& Stack<T>::peek() const
{
	if (isEmpty())
	{
		throw StackEmpty();
	}

	return stack[count];
}

template <typename T>
void Stack<T>::push(const T& data)
{
	stack.push_back(data);
	count++;
}

template <typename T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		throw StackEmpty();
	}

	stack.pop_back();
	count--;
}

#endif // !_STACK_H_
