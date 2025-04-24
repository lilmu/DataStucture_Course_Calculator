#include "queue.h"
template <class T>
Queue <T>::Queue(int MaxQueueSize) :MaxSize(MaxQueueSize) {
	queue = new T[MaxSize];
	for (int i = 0; i < MaxSize; i++) queue[i] = -1;
	front = rear = -1; top = 0;
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

template<typename T>
void Queue<T>::QueueFull() {
    cout << "The queue is empty" << endl;
}

template<typename T>
void Queue<T>::QueueEmpty() { 
    cout << "The queue is empty" << endl;
}

template<class T>
bool Queue<T>::IsFull() {
	return top = MaxSize;
}

template<typename T>
void Queue<T>::Push(const T& item) {
	if (IsFull()) {
		QueueFull();
		return;
	}
	rear++;
	rear %= MaxSize;
	queue[rear] = item;
	top++;
}

template<class T>
bool Queue<T>::IsEmpty() {
    return top==0;
}

template<typename T>
T* Queue<T>::Delete(T& x) {
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

template<typename T>
T* Queue<T>::Pop(T& x) {
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


