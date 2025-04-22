// @file Token.cpp
#include <sstream>
#include <stdexcept>
#include "postfix.h"
#include "token.h"

using namespace std;

string opToString(Operator o) {
	string result="#";
	switch (o) {
		case Operator::ADD:			result = "+"; break;
		case Operator::SUBTRACT:	result = "-"; break;
		case Operator::MULTIPLY:	result = "*"; break;
		case Operator::DIVIDE:		result = "/"; break;
		case Operator::EXP:			result = "^"; break;
		case Operator::MODULO:		result = "%"; break;
		case Operator::LPAREN:		result = "("; break;
		case Operator::RPAREN:		result = ")"; break;
		default: break;
	}
	return result;
}

ostream& operator<<(std::ostream& os, const Token& t) {
	if (t.tag)
		os << t.d << " ";
	else
		os << t.o << " ";
	return os;
}

Queue <Token> tokenize(std::string s) { // tokenize the input
	cout << setw(10) << left << "TOKENIZE:" << s << endl;
	Queue<Token> q; 
	for (int i = 0; i < s.length(); i++) {
		if (isOperand(s[i])) {
			Token t(s[i]);
			i++;
			while (isOperand(s[i])) {
				t.d = t.d*10 + ((double)(s[i]) - (int)('0'));
				i++;
			}
			q.Push(t);
		}
		else if (isOperator(s[i])) {
			Token t(s[i]);
			q.Push(t);
		}
	}
	return q;
}