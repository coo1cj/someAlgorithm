#include "EvalutePostfix.h"
using namespace std;

int EvalutePostfix(const string& s){
	stack<int> nums;
	for(auto i : s){
		if(i >= '0' && i <= '9') nums.push(i - '0');
		else if(i == '+'){
			int rhs = nums.top();
			nums.pop();
			int lhs = nums.top();
			nums.pop();
			int res = lhs + rhs;
			nums.push(res);		
		}
		else if(i == '-'){
			int rhs = nums.top();
			nums.pop();
			int lhs = nums.top();
			nums.pop();
			int res = lhs - rhs;
			nums.push(res);
		}		
		else if(i == '*'){
			int rhs = nums.top();
			nums.pop();
			int lhs = nums.top();
			nums.pop();
			int res = lhs * rhs;
			nums.push(res);
		}		
		else if(i == '/'){
			int rhs = nums.top();
			nums.pop();
			int lhs = nums.top();
			nums.pop();
			int res = lhs / rhs;
			nums.push(res);
		}		
	}
	return nums.top();
}
int main(int argc, char* argv[]){
	string s;
	getline(cin, s);
	cout << EvalutePostfix(s) << endl; 
}
