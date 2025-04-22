#include "postfix.h"
#include "stack.h"
   
// function to return precedence value 
// if operator is present in stack, in stack priority 
int isp(char input){ return -1;}
int isp(Token input){	return -1; }
int icp(char input) {return -1; }
int icp(Token input) {return -1; }

// to check if the input character is an operand 
int isOperand(char input) { 
	return (48 <= input && input <= 57);
}
int isOperator(char input){	
	return(input == 35 || input == 37 || input == 40 || input == 41 || input == 42 || input == 43 || input == 45 || input == 47);
	//#,%,(,),*,+,-,/
}
int isOperand(Token input) { 
	return input.tag == Tag::OPERAND;
}
int isOperator(Token input) { 
	return input.tag == Tag::OPERATOR;
} 


Queue <Token> postfix(string e){ // infix to postfix and return a queue
	Queue <Token> queue = tokenize(e);
	cout << setw(10) << left << "PFIX:" << e;
	return queue;
} 
