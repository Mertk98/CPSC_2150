#ifndef _ER_H_
#define _ER_H_
#include "iostream"
#include "string"
#include "PriorityQueue.h"
#include "Patient.h"

template <typename T>
class ER
{
private:
	PriorityQueue<T> queue;
public:
	ER()=default;
	void insert(T* patient);
	void remove();
	void printEr();
	~ER()=default;
};

template <typename T>
void ER<T>::insert(T* patient)
{
	queue.insert(patient);
}

template <typename T>
void ER<T>::remove()
{
	queue.removeMin();
	queue.printQueue();
}

template <typename T>
void ER<T>::printEr()
{
	queue.printQueue();
}
#endif // !_ER_H_
