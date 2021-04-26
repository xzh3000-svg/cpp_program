#include<iostream>
#include "Sales_item.h"

int main(){
	Sales_item item1,item2;
	if (std::cin >> item1){
		int sum = 1;  //sum的作用域好像只在if的范围内起效，之外就会报错
		while (std::cin >> item2){
			if (item1.isbn() == item2.isbn()){
				sum++;
			}else{
				std::cout << item1.isbn() << "销售记录为：" << sum << "条" << std::endl;
				item1 = item2;
				sum = 1; 
			}
		}
		std::cout << item1.isbn() << "销售记录为：" << sum << "条" << std::endl;
	} 
	return 0;
}
