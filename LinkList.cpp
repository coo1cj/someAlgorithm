#include "LinkList.h"

struct Node{
	int data;
	Node* next;
};

LinkList::LinkList(int n){
	head = creatNode(n);
}

LinkList::LinkList(LinkList&& l) noexcept{
	head = l.head;
	l.head = nullptr;
}

LinkList::LinkList(const LinkList& l){
	head = new Node();
	head->data = l.head->data;
	Node* p = l.head;
	Node* q = head;
	while(p->next){
		q->next = creatNode(p->next->data);
		q = q->next;
		p = p->next;
	}
}

LinkList LinkList::operator=(const LinkList& l){
	if(this != &l){
		head = new Node();
		head->data = l.head->data;
		Node* p = l.head;
		Node* q = head;
		while(p->next){
			q->next = creatNode(p->next->data);
			q = q->next;
			p = p->next;
		}
	}
	return *this;
}

LinkList LinkList::operator=(LinkList&& l) noexcept{
	if(this != & l){
		head = l.head;
		l.head = nullptr;
	}
	return *this;
}

Node* creatNode(int n){
	Node* p = new Node();
	p->data = n;
	p->next = nullptr;
	return p;
}
void LinkList::appendNode(int n){
	Node* p = head;
	while(p){
		if(p->next == nullptr){
			p->next = creatNode(n);
			return ;
		}
		p = p->next;
	}
}

void LinkList::insertAfter(Node* obj, int n){
	Node* p = head;
	while(p){
		if(p->data == obj->data){
			Node* tmp = creatNode(n);
			tmp->next = p->next;
			p->next = tmp;
			return;
		}
		p = p->next;
	}
}

void LinkList::removeAfter(Node* obj){
	Node* p = head;
	while(p){
		if(p->data == obj->data && p->next){
			p->next = p->next->next;
			return ;
		}
		p = p->next;
	}
}

void LinkList::print(){
	Node* p = head;
	while(p){
		if(p->next != nullptr)
			std::cout << p->data << "->";
		else
			std::cout << p->data << std::endl;
		p = p->next;
	}
}

void LinkList::remove2(int n){
	while(head && head->data == n){
		Node* tmp = head;
		head = head->next;
		delete tmp;
	}
	Node* cur = head->next, *pre = head;
	while(cur){
		if(cur->data == n){
			pre->next = cur->next;
			cur = cur->next;
		}else{
			pre = cur;
			cur = cur->next;
		}
		
	} 
}

void LinkList::remove(int n){
	Node* p = head;
	Node* pre = head;
	while(p){
		if(p->data == n){
			if(pre == head){
				head = head->next;
				pre = head;
				p = head;
				continue;
			}else{
				pre->next = p->next;
				p = p->next;
				continue;
			}
		}
		pre = p;
		p = p->next;
	}

}
LinkList::~LinkList(){
	Node* tmp = head;
	while(tmp){
		head = head->next;
		delete tmp;
		tmp = head;
	}
	std::cout << "all is destroied" << std::endl;
}

void LinkList::reverse(){
	Node* first = head;
	Node* reverse = nullptr;
	while(first){
		Node* second = first->next;
		first->next = reverse;
		reverse = first;
		first = second;
	}
	head = reverse;
}

Node* reverse2(Node* first){
	if(!first) return nullptr;
	if(!first->next) return first;
	Node* second = first->next;
	Node* rest = reverse2(second);
	second->next = first;
	first->next = nullptr;
	return rest;
}

int LinkList::max(){
	Node* p = head;
	int max = 0;
	while(p){
		if(p->data > max)
			max = p->data;
		p = p->next;
	}
	return max;
}


int main(){
	LinkList head(5);
	head.appendNode(5);
	head.appendNode(5);
	head.appendNode(2);
	head.appendNode(7);
	head.appendNode(9);
	head.appendNode(3);
	
	Node* obj = creatNode(5);
	Node* obj1 = creatNode(3);
	head.insertAfter(obj, 4);
	std::cout << "---------------" << std::endl;
	std::cout << "insertAfter 5: " << std::endl;
	head.print();

	head.removeAfter(obj);
	head.removeAfter(obj1);
	std::cout << "---------------" << std::endl;
	std::cout << "removeAfter 5 and 3: " << std::endl;
	head.print();
	head.remove2(5);
	head.remove(4);
	std::cout << "---------------" << std::endl;
	std::cout << "remove 5 and 4 : " << std::endl;
	head.print();
	head.reverse();
	std::cout << "---------------" << std::endl;
	std::cout << "After reverse: " << std::endl;
	head.print();
	std::cout << head.max() << std::endl;
	Node* p = head.getHead();
	std::cout << p->next->data << std::endl;
	head.print();
	head.setHead(reverse2(p));
	head.print();
}


