#ifndef QUEUE_H_
#define QUEUE_H_

#include <cmath>
#include <iostream>
#include <iomanip>
#include <ostream>
using namespace std;
#define DefaultQSize 20

template<typename T>
class Queue{
public:
	Queue<T> & operator = (const Queue<T>&rhs) {
		front = rhs.front; rear = rhs.rear;
		MaxSize = rhs.MaxSize;
		top = rhs.top;
		queue = new T[MaxSize];
		for (int i = 0; i < top; i++) queue[i] = rhs.queue[i];
		return *this;
	};
	Queue(int MaxQueueSize =DefaultQSize);
	Queue(const Queue&);
	~Queue() { delete[] queue; }
	void QueueFull();
	void QueueEmpty();
	bool IsFull();
	void Push(const T& item);
	bool IsEmpty();
	T* Delete(T&);
	T* Pop(T&);   
private:
	int front;               //front: index of the first element to be retrieved   	
	int rear;               //rear:index of the last element  	
	T *queue;			// T array	
	int MaxSize;
	int top ;
};



#endif