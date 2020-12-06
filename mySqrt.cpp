#include "mySqrt.h"
#include <math.h>
#include <iostream>
double mySqrt(double a){
	if(a < 0) return -1;
	double err = pow(10, -5);
	double res = a;
	int count = 0;
	while(abs((res - a/res)/res) > err){
		res = (res + a/res) / 2.0;
		++count;
	}
	std::cout << "count: " << count << std::endl;
	std::cout << "the sqrt of " << a << " is: " << res << std::endl;
	return res;
}
int main(){
	double a;
	std::cout << "enter a number please" << std::endl;
	std::cin >> a;
	mySqrt(a);
}
