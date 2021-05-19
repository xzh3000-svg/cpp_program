#include<iostream>

using namespace std;

typedef struct
{
    int n;  //物品数量
    int m;  //背包容量
    int weight[100];    //物品的重量
    int worth[100]; //物品价值
    double eweight[100];   //物品真正装入背包的重量
    int order[100]; //物品编号
    double bestvalue;   //背包的最大价值
}bage;

double unitvalue[100];  //物品单位重量的价值

//初始化背包
void cin_function(bage *g)
{
    cout << "背包的容量和物品数量：" << endl;
    cin >> g->m >> g->n;
    cout << "每个物品的编号，重量和价值：" << endl;
    for (int i = 1; i <=g->n; i++)
    {
        cin >> g->order[i] >> g->weight[i] >> g->worth[i];
    }
    g->bestvalue = 0;
    
}

void sort(bage *g,double s[])
{
    double temp;
    int between;
    for (int i = 1; i <= g->n; i++)
    {
        s[i] = g->worth[i]/g->weight[i];
    }
    //按照单位重量的价值进行冒泡排序
    for (int i = 0; i < g->n - 1; i++)
    {
        for (int j = 1; j <= g->n - i -1; j++)
        {
            if (s[j] < s[j+1])
            {
                temp = s[j+1];
                s[j+1] = s[j];
                s[j] = temp;

                between = g->weight[j+1];
                g->weight[j+1] = g->weight[j];
                g->weight[j] = between;

                between = g->worth[j+1];
                g->worth[j+1] = g->worth[j];
                g->worth[j] = between;

                between = g->order[j+1];
                g->order[j+1] = g->order[j];
                g->order[j] = between;
            } 
        }  
    }
}

int bestbage(bage *g,double s[])
{
    int leftm = g->m;   //leftm:背包的剩余容量
    int x = 1;  //x=1：表示检视到第1个物品
    while (leftm >0 && x <= g->n)
    {
        if (leftm - g->weight[x] >=0)
        {
            g->eweight[x] = g->weight[x];
            g->bestvalue += g->worth[x];
            leftm -= g->weight[x];
            x++;
        }else
        {
            g->eweight[x] = leftm;
            g->bestvalue += g->eweight[x]/g->weight[x]*g->worth[x];
            leftm = 0;
        }
    }
    return x;
}

int main()
{
    int x;
    bage g;
    cin_function(&g);
    sort(&g,unitvalue);
    x = bestbage(&g,unitvalue);

    cout << "背包问题的最大价值为：" << g.bestvalue << endl;
    cout << "装载的物品的编号以及对应的重量：" << endl;
    for (int i = 1; i <= x; i++)
    {
        if (g.eweight[i] != 0)
        {
            cout << g.order[i] << " " << g.eweight[i] << endl;
        }
    }
    return 0;
}
