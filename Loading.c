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

//参考代码
#include<stdio.h>
struct box{//保存箱子重量及序号 
	int no;
	int weight;
}z[100];
int main(){
	int n,m,i,j,sum=0,cnt=0,load[100];
	printf("请输入箱子个数：");
	scanf("%d",&n);
	printf("请输入集装箱重量限制：");
	scanf("%d",&m);
	printf("请输入各箱子重量：");
	for(i=0;i<n;i++){//创建箱子信息 
		scanf("%d",&z[i].weight);
		z[i].no=i+1;
	} 
	for(i=0;i<n-1;i++){//冒泡排序，将重量轻的放在前面 
		for(j=0;j<n-i-1;j++){
			if(z[j].weight>z[j+1].weight){//交换 
				int w,a;
				w=z[j].weight;
				a=z[j].no;
				z[j].weight=z[j+1].weight;
				z[j].no=z[j+1].no;
				z[j+1].weight=w;
				z[j+1].no=a; 
			}
		}
	}
	int k=0;
	for(i=0;i<n;i++){
		if(sum+z[i].weight<=m){
			sum+=z[i].weight;
			load[k++]=z[i].no;//记录物品序号 
		}else break; 
	} 
	printf("一共可以装载%d个物体\n",k);
	for(i=0;i<k-1;i++){//序号排序 
		for(j=0;j<k-i-1;j++){
			if(load[j]>load[j+1]){
				int t=load[j];
				load[j]=load[j+1];
				load[j+1]=t;
			}
		}
	}
	printf("装载的物体序号为：");
	for(i=0;i<k;i++) printf("%d ",load[i]); 
	return 0;
}

