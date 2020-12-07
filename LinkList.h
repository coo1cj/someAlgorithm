#include<iostream>
struct Node;
class LinkList{
	Node* head;
public:
	LinkList(): head(nullptr){};
	LinkList(int n);
	LinkList(const LinkList& );
	LinkList operator=(const LinkList&);
	LinkList(LinkList&&) noexcept;
	LinkList operator=(LinkList&&) noexcept;
	~LinkList();
	void appendNode(int n);
	void removeAfter(Node* obj);
	void insertAfter(Node* obj, int n);
	void print();
	void remove(int n);
	void remove2(int n);
	void reverse();
	Node* getHead() const {return head;}
	void setHead(Node* p) { head = p;}
	int max();
};
Node* reverse2(Node* p);
Node* creatNode(int n);
