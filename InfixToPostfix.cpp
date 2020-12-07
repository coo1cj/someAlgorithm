#include "InfixToPostfix.h"
#include <map>
std::string InfixToPostfix(const std::string& s){
	std::stack<char> ops;
	std::string res = "";
	std::map<char, int> map = {{'-', 0}, {'+', 0}, {'*', 1}, {'/', 1} };
	for(auto i : s){
		if(i >= '0' && i <= '9') res += i;
		else if(i == '-' || i == '+' || i == '*' || i == '/'){
			while(!ops.empty() && map[ops.top()] >= map[i]){
				if(ops.top() == '(') break;
				res += ops.top();
				ops.pop();
			}
			ops.push(i);
		}
		else if(i == ')'){
			while(!ops.empty()){
				if(ops.top() == '('){ ops.pop(); break;}
				res += ops.top();
				ops.pop();
			}
		}
		else if(i == '(')
			ops.push(i);

	}
	while(!ops.empty()){
		res += ops.top();
		ops.pop();
	}
	return res;
}

int main(int argc, char* argv[]){
	std::string s = argv[1];
	std::cout << InfixToPostfix(s) << std::endl;
}
