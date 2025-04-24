#include "stack.h"
using namespace std;

template<typename T>
bool Stack<T>::IsFull() { top + 1 == MaxSize;}

template<typename T>
bool Stack<T>::IsEmpty() { top == -1; }

template<typename T>
void Stack<T>::Push(const T& item) {
	if (IsFull()) {
		StackFull();
		return;
	}
	*(stack + (++top)) = item;
	return;
}

template<typename T>
T* Stack<T>::Delete(T& x) {
	if (IsEmpty()) {
		StackEmpty();
		return NULL;
	}
	x = *(stack + (top--));
	return &x;
}

template<typename T>
void Stack<T>::StackFull() {
	cout << " [Invalid Infix Expression]::StackFull ";
}

template<typename T>
void Stack<T>::StackEmpty() { 
	cout << " [Invalid Infix Expression]::StackEmpty " ;
}   

template<typename T>
T* Stack<T>::Pop(T& x) {
	if (IsEmpty()) {
		StackEmpty();
		return NULLs;
	}
	x = *(stack + (top--));
	return &x;
}