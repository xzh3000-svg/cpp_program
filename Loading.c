#include <stdio.h>
#include <stdlib.h>

//最优装载问题 
void Loading(int x[],int w[],int c,int n);	//c：轮船所能承载的重量 
void Sort(int w[],int t[],int n); //w:存放集装箱的重量，t:存放集装箱的编号，按重量的非减顺序，n为集装箱的数量 

int main(){
	int i;
	int w[4] = {6,5,7,1,3};
	int t[4];
//	for (i = 0;i <= 4;i++){
//		t[i] = 0;
//	}
	Sort(w,t,5);
//	for (i = 0;i <= 4;i++){
//		printf("%d",t[i]);
//		printf("\n");
//	}
	return 0;
}

void Loading(int x[],int w[],int c,int n){
	
}

void Sort(int w[],int t[],int n){
	int i,j,key;
	int a[n-1];
	a[0] = w[0];
	for (j = 1;j < n;j++){
		key = w[j];
		i = j-1;
		while (i >= 0 && key < a[i]){
			a[i+1] = a[i];
			i--;
		}
		a[i+1] = key;
	}
	for (i = 0;i <= 4;i++){
		printf("%d\n",a[i]);
	}
//	for (i = 0;i < n;i++){
//		int j = 0;
//		while(w[j] == a[i] || j < n){
//			if (w[j] == a[i]){
//				t[i] = j;
//				break;
//			}else{
//				j++;
//			}
//		}
//	}
}
