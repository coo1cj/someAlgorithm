#include <iostream>
#include <string>
using namespace std;
#define N 26
struct Node {
	Node(): next((Node**)malloc(N*sizeof(Node*))), val(-1){ 
	    for(int i = 0; i < N; ++i) 
	        next[i] = nullptr;
	    cout << "yes" << endl;
	}
	Node** next;
	int val;
};
Node* put(Node* x, const string& str, int d, int value){
    if(!x) x = new Node();
    if(d == str.length() - 1){
        x->val = value;
        return x;
    }
    char ch = str.at(d);
    (x->next)[ch] = put((x->next)[ch], str, d + 1, value);
    return x;
}

Node* get(Node* x, const string& str, int d){
    if(!x) return nullptr;
    if(d == str.length() - 1) return x;
    char ch = str.at(d);
    return get((x->next)[ch], str, d+1);
}

int main() {
    Node* n = new Node();
    put(n, "hello", 0, 100);
    Node* res = get(n, "hell", 0);
    if(res)
        cout << res->val << endl;
    else
        cout << "nullptr" << endl;
	return 0;
}
