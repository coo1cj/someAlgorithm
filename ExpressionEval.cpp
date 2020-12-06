#include "ExpressionEval.h"
#include <stack>
#include <iostream>
int ExpressionEval(const std::string& s){
	std::stack<char> ops;
	std::stack<int> eval;
	for(auto i : s){
		if(i == '+' || i == '-' || i == '*' || i == '/') ops.push(i);
		else if(i >= '0' && i <= '9') eval.push(i - '0');
		else if(i == ')'){
			char op = ops.top();
			ops.pop();
			int d1 = eval.top();
			eval.pop();
			if(op == '+') d1 += eval.top();
			else if(op == '*') d1 *= eval.top();
			else if(op == '-') d1 = eval.top() - d1;
			else if(op == '/') d1 = eval.top() / d1;
			eval.pop();
			eval.push(d1);
		} 
	}
	return eval.top();
}

int main(){
	std::string s;
	getline(std::cin, s);
	std::cout << s << std::endl;
	std::cout << ExpressionEval(s) << std::endl;
}
