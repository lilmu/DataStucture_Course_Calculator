#include "postfix.h"
#include "stack.h"
   
// function to return precedence value 
// if operator is present in stack, in stack priority 
int isp(char input){
	switch (input) {
		case '+': case '-': return 1;
		case '*': case '/': case '%': return 2;
		case '^': return 3;
		case '(': return 0;
		default: return -1;
	}
}
int isp(Token input){	
	switch (input.o) {
		case Operator::ADD: case Operator::SUBTRACT: return 1;
		case Operator::MULTIPLY: case Operator::DIVIDE: case Operator::MODULO: return 2;
		case Operator::EXP: return 3;
		case Operator::LPAREN : return 0;
		default: return -1;
	}
}
int icp(char input) {
	switch (input) {
		case '+': case '-': return 1;
		case '*': case '/': case '%': return 2;
		case '^': return 3;
		case '(': return 5;
		default: return -1;
	}
}
int icp(Token input) {
	switch (input.o) {
		case Operator::ADD: case Operator::SUBTRACT: return 1;
		case Operator::MULTIPLY: case Operator::DIVIDE: case Operator::MODULO: return 2;
		case Operator::EXP: return 3;
		case Operator::LPAREN: return 5;
		default: return -1;
	}
}

// to check if the input character is an operand 
int isOperand(char input) { 
	return (48 <= input && input <= 57);
}
int isOperator(char input){	
	return(input == '#' || input == '%' || input == '(' || input == ')' || input == '*' || input == '+' || input == '-' || input == '/' || input == '^');
	//#,%,(,),*,+,-,/,^
}
int isOperand(Token input) { 
	return input.tag == Tag::OPERAND;
}
int isOperator(Token input) { 
	return input.tag == Tag::OPERATOR;
} 


Queue <Token> postfix(string e){ // infix to postfix and return a queue
	Queue <Token> queue = tokenize(e);
	cout << setw(10) << left << "PFIX: ";
	Queue <Token> Output;
	Stack <Token> stack;
	Token nextToken,x;
	stack.Push('#');
	queue.Pop(nextToken);
	while (!(nextToken == '#')) {
		if (isOperand(nextToken)) {
			Output.Push(nextToken);
			cout << nextToken << " ";
		}
		else if (nextToken == ')') {
			stack.Pop(x);
			while (!(x == '(')) {
				Output.Push(x);
				cout << x << " ";
				stack.Pop(x);
			}
		}
		else {
			stack.Pop(x);
			while (isp(x) >= icp(nextToken)) {
				Output.Push(x);
				cout << x << " ";
				stack.Pop(x);
			}
			stack.Push(x);
			stack.Push(nextToken);
		}
		queue.Pop(nextToken);
	}
	stack.Pop(x);
	while (!(x == '#')) {
		Output.Push(x);
		cout << x << " ";
		stack.Pop(x);
	}
	Output.Push(x);
	cout << x << " ";
	return Output;
} 
