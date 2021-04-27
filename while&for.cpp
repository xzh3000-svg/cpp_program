#include <iostream>
#include "Sales_item.h"

int main() 
{
	//错误，变量u永远也不会小于0，循环条件一直成立 
//	for (unsigned u = 10; u >= 0; --u){
//		std::cout << u << std::endl;
//	}
	//while与for的区别，while让我们能够在变量输出之前使变量-1. 
	unsigned u = 11;
	while (u > 0){
		--u;
		std::cout << u << std::endl;
	}
    return 0;
}
