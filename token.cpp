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
	if (t.tag == Tag::OPERAND)
		os << t.d << "  ";
	else
		os << opToString(t.o) << "  ";
		
	return os;
}

Queue <Token> tokenize(std::string s) { // tokenize the input
	std::cout << setw(10) << left << "TOKENIZE:" ;
	Queue<Token> q; 
	enum class preToken { ADDnSUBTRACT = 0, MULTIPLYnDIVIDEnMODULOnEXP, LPAREN, RPAREN, OPERAND, UNARY, DEFUALT};
	preToken pre = preToken::DEFUALT;
	bool unary = 1; // 0/1:negative/positive
	int Paren_c = 0; //Left++/Right--
	for (int i = 0; i < s.length(); i++) {
		if (isOperand(s[i])) {
			if (pre == preToken::RPAREN) {
				Token t('*');
				q.Push(t);
				std::cout << t ;
			}
			if (!unary) {
				Token t(s[i]);
				t.d = -t.d;
				while (isOperand(s[++i])) {
					t.d = t.d * 10 - ((double)(s[i]) - (int)('0'));
				}
				i--;
				q.Push(t);
				std::cout << t;
			}
			else {
				Token t(s[i]);
				while (isOperand(s[++i])) {
					t.d = t.d * 10 + ((double)(s[i]) - (int)('0'));
				}
				i--;
				q.Push(t);
				std::cout << t;
			}
			pre = preToken::OPERAND;
		}
		else if (isOperator(s[i])) {
			if (pre == preToken::UNARY) {
				cerr << "\n[Invalid Infix Expression]\n";
				return NULL;
			}
			else if (pre == preToken::ADDnSUBTRACT || pre == preToken::MULTIPLYnDIVIDEnMODULOnEXP || pre == preToken::LPAREN || pre == preToken::DEFUALT) {
				if (pre == preToken::ADDnSUBTRACT && (s[i] == '+' || s[i] == '-')) {
					cerr << "\n[Invalid Infix Expression]\n";
					return NULL;
				}
				else if (s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^' || s[i] == ')') {
					cerr << "\n[Invalid Infix Expression]\n";
					return NULL;
				}
				else if (s[i] == '+') {
					unary = 1;
					pre = preToken::UNARY;
				}
				else if (s[i] == '-') {
					unary = 0;
					pre = preToken::UNARY;
				}
				else {
					Token t(s[i]);
					q.Push(t);
					std::cout << t;
					pre = preToken::LPAREN;
					Paren_c++;
				}
			}
			else if (pre == preToken::RPAREN || pre == preToken::OPERAND) {
				unary = 1;
				if (s[i] == '(') {
					Token t('*');
					q.Push(t);
					std::cout << t;
					pre = preToken::LPAREN;
					Paren_c++;
				}
				else if (s[i] == '+' || s[i] == '-') {
					pre = preToken::ADDnSUBTRACT;
				}
				else if (s[i] == ')') {
					pre = preToken::RPAREN;
					Paren_c--;
					if (Paren_c < 0) {
						cerr << "\n[Missing a left parentheses]\n";
						return NULL;
					}
				}
				else {
					pre = preToken::MULTIPLYnDIVIDEnMODULOnEXP;
				}
				Token t(s[i]);
				q.Push(t);
				std::cout << t;
			}
		}
		else if (s[i] == ' ') {
			if (pre == preToken::OPERAND && isOperand(s[i + 1])) {
				cerr << "\n[Invalid Infix Expression]\n";
				return NULL;
			}
			else {
				continue;
			}
		}
		else {
			cerr << "\n[Invalid Infix Expression]\n";
			return NULL;
		}
	}
	if (Paren_c > 0) {
		cerr << "\n[Missing a Right parentheses]\n";
		return NULL;
	}
	Token t('#');
	q.Push(t);
	std::cout << t;
	std::cout << endl;
	return q;
}