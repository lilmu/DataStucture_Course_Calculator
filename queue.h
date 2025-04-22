#ifndef QUEUE_H_
#define QUEUE_H_

#include <cmath>
#include <iostream>
#include <iomanip>
#include <ostream>
using namespace std;
#define DefaultQSize 20
extern void QueueEmpty();
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
	Queue(Queue&);
	Queue(const Queue&);
	~Queue();
	void QueueFull() {};
	bool IsFull() { return 0; };
	void Push(const T& item) {};
	bool IsEmpty() ;
	T* Delete(T&) {};
	T* Pop(T&) {};   
private:
	int front;               //front: index of the first element to be retrieved   	
	int rear;               //rear:index of the last element  	
	T *queue;			// T array	
	int MaxSize;
	int top ;
};

template <class T>
Queue <T>::Queue(int MaxQueueSize):MaxSize(MaxQueueSize) {
   queue = new T[MaxSize];
   for(int i=0;i<MaxSize; i++) queue[i]=-1;
   front = rear = -1; top = 0;
}

template <class T>
Queue <T>::Queue(Queue& rhs) {
	front = rhs.front; rear = rhs.rear;
	MaxSize = rhs.MaxSize;
	top = rhs.top;
	queue = new T[MaxSize]; 
	for (int i = 0; i < top; i++) queue[i] = rhs.queue[i];
}

// copy constructor 
template <class T>
Queue <T>::Queue(const Queue& rhs) {
	front = rhs.front; rear = rhs.rear;
	MaxSize = rhs.MaxSize;
	top = rhs.top;
	queue = new T[MaxSize];
	for (int i = 0; i < top; i++) queue[i] = rhs.queue[i];
}

template <class T>
Queue <T>::~Queue() {
  delete [] queue;
}

template<class T>
bool Queue<T>::IsEmpty() {
      if(front == rear) return true;
      else return false;
}

#endif