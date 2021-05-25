#include <stdio.h>


#define M 65535 //代表一个无穷大的数
#define N 5	//顶点个数 

//单源最短路径，Dijkstra算法
//cost[i][j]表示边(i,j)的权
//distance[i]表示从源到顶点vi的最短特殊路径长度
//prev[i]表示从源到顶点i的最短路径上i的前一个顶点
//点的下标其实表示的是指向字符串数组的指针存放该点的下标，但是存放的点的名字的下标其实比点的下标多一        点的下标   名字的下标 
//void Dijkstra(int cost[][N]，int v0,int distance[],int prev[]) //v0表示源的下标 

//Dijkstra算法，求解给定顶点到其余各点的最短路径
void Dijkstra(int cost[][N],int v0,int distance[],int prev[]);
void PrintPrev(int prev[],int v0,int vn);

//主函数
int main()
{
    //给出有向图的顶点数组
    char *Vertex[N]={"V1", "V2", "V3", "V4", "V5"};
    //给出有向图的邻接矩阵
    int cost[N][N]={
		{0, 10, M, 30, 100},
        {M, 0, 50, M, M},
        {M, M, 0, M, 10},
        {M, M, 20, 0, 60},
        {M, M, M, M, 0},
    };
    int distance[N]; //存放求得的最短路径长度
    int prev[N];  //存放求得的最短路径
    int i;
    //调用Dijkstra算法函数，求顶点V1到其余各点的最短路径
    //参数：邻接矩阵、顶点数、出发点的下标、 结果数组
    Dijkstra(cost, 0, distance, prev);
    for(i=0; i < N; i++)
    {
        //输出最短路径长度
        printf("%s-->%s:%d\t", Vertex[0], Vertex[i], distance[i]);
        //输出最短路径
        PrintPrev(prev, 0, i);
        printf("\n");
    }
 
    return 0;
}


 
void Dijkstra(int cost[][N],int v0,int distance[],int prev[]){
	int s[N];	//s[i]=1表示下标魏i的顶点在选取的集合内
	int mindis,dis;
	int i,j,u;
	//初始化,1.使s数组全为0，2.初始化源点到每个顶点的距离 
	for(i = 0;i < N;i++){
		distance[i] = cost[v0][i];	//表示源点v0到下标为i的顶点的距离
		s[i] = 0;
		//如果源点到下标为i的顶点的距离为无穷大时，则下标为i的顶点的前一个顶点没有，故初始化prev[i] = -1 
		if(distance[i] == M){
			prev[i] = -1;
		}else{
			prev[i] = v0;
		} 
	}
	distance[v0] = 0;	//源点到源点的距离为0
	s[v0] = 1;	//源点进入到选取的集合中
	//在当前还未找到的最短路径的顶点中，寻找具有最短距离的顶点
	for(i = 1;i < N;i++){
		//这个循环每循环一次，就求得一个最短路径
		//应为已经把v0选取到集合了，所以i从1开始，找 N-1 条路径
		mindis = M;
		u = v0;
		//先求离出发点最近的顶点
		//我觉得这里j从1开始也可以，应为我不应该计算出发点
		//需要考虑源点下标不是0的情况
		for(j = 0;j < N;j++){
			if(s[j] == 0 && distance[j] < mindis){	//这里s[j] == 0就已经排除了源点，以及已经找到最短路径的顶点 
				mindis = distance[i];	//找出最小值 
				u = j;	//u用来记录距离出发点最近顶点的下标 
			}
		}
		s[u] = 1;
		//选取了最短顶点（下标为i）之后，需要更新源点到其他没有选取顶点的最短距离 
		for(j = 0;j < N;j++){
			if(s[j] == 0 && cost[u][j] < M){
				dis = distance[u] + cost[u][j];
				//如果新的路径更短，就替换掉原来的路径
				if(distance[j] > dis){
					distance[j] = dis;
					prev[j] = u;	//并记录下标为j的顶点的前一个顶点为u（点的下标） 
				} 
			} 
		}
	} 
}

//输出最短路径
//vn表示到达点的下标 
void PrintPrev(int prev[],int v0,int vn){
	int tmp = vn;
	int i,j;
	int tmpprv[N];	//用于临时存放路径
	//初始化tmpprv数组
	for(i = 0;i < N;i++){
		tmpprv[i] = 0;
	}
	//先记录到达点的名字下标
	tmpprv[0] = vn+1;
	//记录中间点
	for(i = 0,j = 1;j < N;j++){
		//下面这段循环条件没有弄得很清楚 
		if(prev[tmp] != -1 && tmp!= 0){
			tmpprv[i] = prev[tmp] + 1;
			tmp = prev[tmp];
			i++; 
		}else{
			break;
		}
	}
	//输出路径，数组逆向输出
	for(i = N-1;i >= 0;i--){
		if(tmpprv[i] != 0){	//排出零元素，因为之前初始化过数组tmpprv
			printf("V%d",tmpprv[i]);
			if(i){
				printf("-->");	
			}	 
		}
	}
	printf("-->V%d",vn+1); 
} 
