#ifndef _PRIORITY_QUEUE_
#define _PRIORITY_QUEUE_
#include "LList.h"
#include "Patient.h"

template <typename T>
class PriorityQueue
{
private:
	LList<T>* list;
	int listSize;
	int count;
public:
	PriorityQueue();
	int size() const;
	bool isEmpty() const;
	void insert(T* data);
	T* min();
	void removeMin();
	void printQueue();
	~PriorityQueue();
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	listSize = 11;
	list = new LList<T>[listSize];
	count = -1;
}

template <typename T>
int PriorityQueue<T>::size() const
{
	return count + 1;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (count == -1);
}

template <typename T>
void PriorityQueue<T>::insert(T* data)
{
	list[data->getPriority()].insert(data);
}

template <typename T>
T* PriorityQueue<T>::min()
{
	// implement a patient class
	T* min = nullptr;

	for (int i = 0; i < listSize; i++)
	{
		if (!list[i].is_Empty())
		{
			min = list[i].first();
			return min;
		}
	}
	return min;
}

template <typename T>
void PriorityQueue<T>::removeMin()
{
	T* data = min();
	list[data->getPriority()].removeFront();
}

template <typename T>
void PriorityQueue<T>::printQueue()
{
	std::cout << "====ER Waitlist====" << std::endl;

	for (int i = 0; i < listSize; i++)
	{
		if (i > 0)
		{
			std::cout << "=======================" << std::endl;
			std::cout << "Priority Level: " << i << std::endl;
			std::cout << "=======================" << std::endl;
			std::cout << "" << std::endl;
			list[i].printList();
			std::cout << "" << std::endl;
		}
	}
	std::cout << "" << std::endl;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete[] list;
}

#endif // !_PRIORITY_QUEUE_
