#ifndef STACK_H_
#define STACK_H_
   
#include <cmath>
#include <iostream>
#include <iomanip>
#include <ostream>
using namespace std;
#define DefaultSize 30

template<typename T>
class Stack{
	//friend ostream& operator<<(ostream&, const Stack <T>&);
public:
	Stack(int MaxStackSize = DefaultSize): top(-1), MaxSize(MaxStackSize){
		stack = new T[MaxStackSize];
		// Create an empty Stack whose maximum size is MaxStackSize
	};
		  ~Stack() { delete[] stack;};
		  bool IsFull() { 
			  return top + 1 == MaxSize; 
		  }
	      // if number of elements in the Stack is equal to the maximum size of
	      // the Stack, return TRUE(1); otherwise, return FALSE(0)
		  bool IsEmpty() { 
			  return top == -1;
		  }
		  // if number of elements in the Stack is equal to 0, return TRUE(1)
		  // else return FALSE(0)
		  void Push(const T& item) {
			  if (IsFull()) {
				  StackFull();
				  return;
			  }
			  stack[++top] = item;
			  return;
		  }
	      // if IsFull(), then StackFull(); else insert item at rear of the Stack
		  //T* Delete(T&);
	      // if IsEmpty(), then StackEmpty() and return 0;
	      // else remove the item at the front of the Stack and return a pointer to it
		  void StackFull() {
			  cout << " The stack is full ";
		  }
		  void StackEmpty() {
			  cout << " The stack is empty ";
		  }
		  T* Pop(T& x) {
			  if (IsEmpty()) {
				  StackEmpty();
				  return NULL;
			  }
			  x = stack[top--];
			  return &x;
		  }
private:
	int top;     //top: index of the topmost element to be retrieved 	
	T *stack;    // T array pointer
	int MaxSize;
};

#endif

