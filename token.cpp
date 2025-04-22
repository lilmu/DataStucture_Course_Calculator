// @file Token.cpp
#include <sstream>
#include <stdexcept>
#include "postfix.h"
#include "token.h"

using namespace std;

string opToString(Operator o) {
	string result="#";
	switch (o) {
		case Operator::ADD:		result = "+"; break;
		case Operator::SUBTRACT:	result = "-"; break;
		case Operator::MULTIPLY:	result = "*"; break;
		case Operator::DIVIDE:	result = "/"; break;
		case Operator::EXP:		result = "^"; break;
		case Operator::MODULO:   result = "%"; break;
		case Operator::LPAREN:	result = "("; break;
		case Operator::RPAREN:	result = ")"; break;
		default: break;
	}
	return result;
}

ostream& operator<<(std::ostream& os, const Token& t) {
	return os;
}

Queue <Token> tokenize(std::string s) { // tokenize the input
	cout << setw(10) << left << "TOKENIZE:" << s << endl;
	// DIY
	Queue<Token> q; return q;
}