#include "UF_quickFind.h"
#include "UF_quickUnion.h"
#include <iostream>
#include "myBinarySearch.h"

int main(){
	UF_quickUnion uf_qu(10);
	uf_qu.Union(1,8);
	uf_qu.Union(2,1);
	std::cout << uf_qu.connected(2,8) << std::endl;

	std::cout << "---------------------" << std::endl;
	int a[] = { 2, 5, 7, 10, 55, 100};
	int hi = sizeof(a) / sizeof(a[0]) - 1;
	double b[] = { 2.1, 5.33, 7.2, 9.9};
	int hi2 = sizeof(b) / sizeof(b[0]) - 1;
    double x = 9.9;
	std::cout << myBinarySearch1(a, 7, 0, hi) << std::endl;
	std::cout << myBinarySearch2(b, 2.1, 0, hi2) << std::endl;
}
