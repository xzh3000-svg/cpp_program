#include<iostream>
int main()
{
	///前缀std::指出名字cout和endl是定义在名为std的命名空间（namespace）中的，::是作用域运算符
	///后面有更加简单的访问标准库中名字的方法 
	std::cout << "Enter teo numbers:" << std::endl; ///这是一个表达式，c++中一个表达式产生一个计算结果，由一个或多个运算对象和一个运算符组成。<<(输出运算符)  
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;	///>>(输入运算符) 
	std::cout << "The sum of " << v1 << " and " << v2
			<< " is " << v1 + v2 << std::endl;	/// endl结束当前行，并清除缓冲区
	return 0;
} 
