#ifndef QUEUE_H_
#define QUEUE_H_

#include <cmath>
#include <iostream>
#include <iomanip>
#include <ostream>
using namespace std;
#define DefaultQSize 30

template<typename T>
class Queue{
public:
	Queue<T> & operator = (const Queue<T>&rhs) {
		front = rhs.front; rear = rhs.rear;
		MaxSize = rhs.MaxSize;
		top = rhs.top;
		queue = new T[MaxSize];
		for (int i = 0; i < top; i++)
			queue[i] = rhs.queue[i];
		return *this;
	};
	Queue(int MaxQueueSize = DefaultQSize) :MaxSize(MaxQueueSize) {
		queue = new T[MaxSize];
		for (int i = 0; i < MaxSize; i++) queue[i] = -1;
		front = rear = -1; top = 0;
	}
	Queue(const Queue& rhs) {
		front = rhs.front; rear = rhs.rear;
		MaxSize = rhs.MaxSize;
		top = rhs.top;
		queue = new T[MaxSize];
		for (int i = 0; i < top; i++) queue[i] = rhs.queue[i];
	}
	~Queue() { delete[] queue; }
	void QueueFull() {
		cout << "The queue is full" << endl;
	}
	void QueueEmpty() {
		cout << "The queue is empty" << endl;
	}
	bool IsFull() {
		return top == MaxSize;
	}
	bool IsEmpty() {
		return top == 0;
	}
	void Push(const T& item) {
		if (IsFull()) {
			cout <<endl << item;
			QueueFull();
			return;
		}
		rear++;
		rear %= MaxSize;
		queue[rear] = item;
		top++;
	}
	//T* Delete(T&);
	T* Pop(T& x) {
		if (IsEmpty()) {
			QueueEmpty();
			return NULL;
		}
		front++;
		front %= MaxSize;
		x = queue[front];
		top--;
		return &x;
	}
private:
	int front;               //front: index of the first element to be retrieved   	
	int rear;               //rear:index of the last element  	
	T *queue;			// T array	
	int MaxSize;
	int top ;
};



#endif