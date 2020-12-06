#include "addLeftParenthese.h"
#include <stack>
std::string addLeftParenthese(const std::string& s){
	std::stack<char> ops;
	std::stack<std::string> eval;
	for(const char i : s){
		if(i == '+' || i == '-' || i == '*' || i == '/') ops.push(i);
		else if(i >= '0' && i <= '9'){ std::string str(1, i);  eval.push(str); }
		else if(i == ')'){
			std::string s = "(";
			char op = ops.top();
			ops.pop();	
			std::string rhs = eval.top();
			eval.pop();
			std::string lhs = eval.top();
			eval.pop();
			s += lhs + op + rhs + ")";
			eval.push(s);
		}
	}
	return eval.top();
}
int main(){
	std::string s = "2 + 3) * 4 + 5) * 5 - 6)))";
	std::cout << addLeftParenthese(s) << std::endl;
}
