#include <stdio.h>
#include <stdlib.h>


//现在二分瘦素 
int BinarySearch(int a[],int x,int l,int r);
int BinarySearch1(int a[],int x,int l,int r);
int main(){
	int type[5] = {0,3,5,7,8,10};
	printf("%d",BinarySearch(type,8,0,5));
	printf("%d",BinarySearch1(type,8,0,5));
	return 0;
}

//非递归算法的实现 
int BinarySearch(int a[],int x,int l,int r){
	while(l <= r){
		int m = (l+r)/2;
		if (x == a[m])
			return m;
		if (x < a[m])
			r = m-1;
		else l = m+1;
	}
	return -1; 
}

//递归算法实现
int  BinarySearch1(int a[],int x,int l,int r){
	if(l <= r){
		int m = (l+r)/2;
		if (x == a[m]){
			return m;
		}
		if (x < a[m]){
			r = m-1; 
			return BinarySearch1(a,x,l,r);
		}else{
			l = m+1;
			return BinarySearch1(a,x,l,r);
		}
	}else{
		return -1;
	}
}
