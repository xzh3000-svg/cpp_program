#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#define N 100
#define M 65535 //代表无穷大  

//最小生成树krim算法

//结点数据结构
typedef struct
{
	int name;	//结点的名字
	int d;	//ver[i].d表示连结结点ver[i]到已知顶点的最短弧的权
	int p;	//ver[i].p表示导致d改变的最后一个顶点
	int key;	//key = 1该结点已经被选取
}ver;


//无向图数据结构
typedef struct{
	ver vers[N];	//顶点  
	int arcs[N][N];	//邻接矩阵,或代权    
	int n,e;	//n为顶点数，e为边 
}graph;



//初始化一个无向图
void createUDG(graph *G){
	int i,j,k,a,b;
	printf("输入顶点数和边数:  ");
	scanf("%d %d",&(G->n),&(G->e));
	printf("输入顶点信息:");
	for(i = 0;i < (G->n);i++){
		// scanf("%d",&G->vers[i]);
		scanf("%d",&G->vers[i].name);
		G->vers[i].d = M;
		G->vers[i].key = 0;
		G->vers[i].p = 0;
	}
	for(i = 0;i < (G->n);i++){
		for(j = 0;j < (G->n);j++){
			G->arcs[i][j] = M;	//边初始化为无穷大
		}
	}
	printf("\n");
	for(k = 0;k < (G->e);k++){
		int x,y,key;
		printf("输入第%d条边的两个顶点和它的权值:",k+1);
		scanf("%d %d %d",&x,&y,&key);
		if(x > (G->n) || y > (G->n)){
			return;
		}else{
			for(i = 0;x != (G->vers[i].name);i++);
			for(j = 0;y != (G->vers[j].name);j++);	//找出x，y对应顶点的位置
			G->arcs[i][j] = G->arcs[j][i] = key; 
		} 
	} 
}

int main(){
	graph G;
	int i,j,min;
	int A[N][N];	//用于辅助邻接矩阵
	createUDG(&G);
	G.vers[0].d = 0;
	G.vers[0].key = 1;
	memcpy(A,G.arcs,sizeof(G.arcs));	//A用于寻找最短路径，原矩阵用于复制d和p
	for ( i = 1; i < (G.n); i++)
	{
		G.vers[i].d = G.arcs[i][0];
		G.vers[i].p = G.vers[0].name; 
	}
	// for (i = 1; i < (G.n); i++)
	// {
	// 	for ( j = 1 ; j < (G.n); j++)
	// 	{
	// 		if(G.vers[j].key == 0){
				
	// 		}else{

	// 		}
	// 	}
		
	// }
	
	// printf("Output\n");
	// for(i = 0;i < (G.n);i++){
	// 	for(j = 0;j <(G.n);j++){
	// 		printf("%d\t",G.arcs[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}
