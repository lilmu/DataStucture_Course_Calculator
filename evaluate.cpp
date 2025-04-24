#include "postfix.h"
#include "stack.h"
#include "cmath"

double Eval(Queue <Token>& profix)
// Evaluate the postfix expression e¡CIt is assumed that the last token (a token
// is either an operator, operand, or ¡¥#¡¦) in e is ¡¥#¡¦.  A function NextToken is
// used to get the next token from e. The function uses the stack stack
{	
	Stack <Token> stack;
	Token x;
	profix.Pop(x);
	while (!(x == '#')) {
		if (isOperand(x)) {
			stack.Push(x);
		}
		else {
			Token y, z;
			stack.Pop(y);
			stack.Pop(z);
			switch (x.o) {
				case Operator::ADD:
					z.d += y.d;
					break;
				case Operator::SUBTRACT:
					z.d -= y.d;
					break;
				case Operator::MULTIPLY:
					z.d *= y.d;
					break;
				case Operator::DIVIDE:
					z.d /= y.d;
					break;
				case Operator::MODULO:
					z.d = fmod(z.d,y.d);
					break;
				case Operator::EXP:
					z.d = pow(z.d,y.d);
					break;
				default: 
					break;
			}
			stack.Push(z);
		}
		profix.Pop(x);
	}
	stack.Pop(x);
	return x.d;
}  
