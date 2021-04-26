#include <stdio.h>
#include <stdlib.h>

void INSERTION_SORT(int *A, int A_length);

int main(){
	int A[5];
	int A_length = 6,i;
	for(i = 0; i < 6; i++){
		scanf("%d",&A[i]);
	}
	printf("排序前：");
	for(i = 0; i < 6; i++){
		printf("%d ",A[i]);
	}
	INSERTION_SORT(A,A_length);
	printf("\n排序后：");
	for(i = 0; i < 6; i++){
		printf("%d ",A[i]);
	}
	
	return 0;
}

//插入排序函数
//对数组A[1...n]排序，A中元素的个数n我们用A_length来表示 
void INSERTION_SORT(int *A,int A_length){
	int j,key,i;
	for (j = 1; j <= A_length-1; j++){
		key = A[j];
		i = j - 1;
		while (i >= 0 && key < A[i]){
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key; 
	}
}
