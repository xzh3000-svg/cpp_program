#include<stdio.h>
#include<string.h>
#define N 10
int n,m,x,y,sum,num=0;
int p[N][N];
int x1[]={-2, -2, -1, 1, 2, 2, 1, -1};
int y1[]={-1, 1, 2, 2, 1, -1, -2, -2};
void dfs(int x,int y,int sum);
int main(){
    scanf("%d %d %d %d",&n,&m,&x,&y);
    dfs(x,y,1);
    printf("%d",num);
}
void dfs(int x,int y,int sum){
    if(sum==n*m){
        num++ ;
        return;
    }
    p[x][y]=1;
    for(int i=0;i<8;i++){
        int a=x1[i]+x,b=y1[i]+y;
        if(a<0||a>=n||b<0||b>=m)
		    continue;
        if(p[a][b])
		    continue;
        dfs(a,b,sum+1);
    }
    p[x][y]=0;
}
