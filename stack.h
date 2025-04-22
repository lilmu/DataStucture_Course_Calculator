#ifndef STACK_H_
#define STACK_H_
   
#include <cmath>
#include <iostream>
#include <iomanip>
#include <ostream>
using namespace std;
#define DefaultSize 20

template<typename T>
class Stack{
	friend ostream& operator<<(ostream&, const Stack <T>&);
public:
	Stack(int MaxStackSize = DefaultSize): top(-1), MaxSize(MaxStackSize){
		stack = new T[MaxStackSize];
		// Create an empty Stack whose maximum size is MaxStackSize
	};
		  ~Stack() { delete[] stack;};
		  bool IsFull();
	      // if number of elements in the Stack is equal to the maximum size of
	      // the Stack, return TRUE(1); otherwise, return FALSE(0)
		  bool IsEmpty();
		  // if number of elements in the Stack is equal to 0, return TRUE(1)
		  // else return FALSE(0)
		  void Push(const T& item);
	      // if IsFull(), then StackFull(); else insert item at rear of the Stack
		  T* Delete(T&);
	      // if IsEmpty(), then StackEmpty() and return 0;
	      // else remove the item at the front of the Stack and return a pointer to it
		  void StackFull();
		  void StackEmpty();
		  //T* Top(T&) {};
private:
	int top;     //top: index of the topmost element to be retrieved 	
	T *stack;    // T array pointer
	int MaxSize;
};

#endif

