#include <stdio.h>
#include <stdlib.h>

//正整数的划分 还得自己写一次
//现在是实现汉诺塔问题 
void hanoi(int n, int a, int b, int c);//n：盘子的个数，a：原先处于的柱子，b：最终要移动到的柱子，c:辅助柱子 
int main(){
	if(n > 0){
		hanoi(n-1,a,c,b);
		move(a,b);
		hanoi(n-1,c,b,a);
	} 
	return 0;
}

