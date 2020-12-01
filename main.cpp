#include "UF_quickFind.h"
#include "UF_quickUnion.h"
#include <iostream>

int main(){
	UF_quickUnion uf_qu(10);
	uf_qu.Union(1,8);
	uf_qu.Union(2,1);
	std::cout << uf_qu.connected(2,8) << std::endl;
}
