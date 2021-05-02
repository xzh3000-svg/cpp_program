#include <stdio.h>
#include <stdlib.h>

void perm(char list[],int k,int m);	//list：待全排列元素。k：当前要选前缀位置，m：m+1个元素（下标：0-m） 
void swap(char *a,char *b);

int main(){
	char list[] = "abcd";
	perm(list,0,3);
	return 0;
}

void perm(char list[],int k,int m){
	int i;
	if(k == m){
		for(i = 0; i <= m; i++)
			printf("%c",list[i]);
		printf("\n");
	}else{
		for(i = k; i <= m; i++){
			swap(&list[k],&list[i]);
			perm(list,k+1,m);
			swap(&list[k],&list[i]);	//注意这里需要还原回去 
		}
	}
}

void swap(char *a,char *b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
