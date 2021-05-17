#include<iostream>
#include<stdio.h>
#include<conio.h>

using namespace std;

int n;  //物品数量
double c;   //背包容量
int order[100]; //物品编号
double value[100];   //各个物品的价值
double weight[100]; //各个物品的重量
double cw = 0.0;    //当前背包重量
double cp = 0.0;    //当前背包的总价值
double bestprice = 0.0; //当前最优价值
int bestput[100]; //记录最优价值的物品编号
double perprice[100];   //单位物品价值（按照从大到小排序）
int put[100];   //设置是否装入该物品（排序后）---我是不是应该初始化为0


//按单位价值降序
void knapsack()
{
    int i,j;
    double temp =0.0;
    int temporder = 0;
    
    //算出单位价值
    for ( i = 1; i <= n; i++)
    {
        perprice[i] = value[i]/weight[i];
    }

    //使用冒泡排序按照单位价值排序
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 1; j <= n-1-i ; j++)
        {
            if (perprice[j] < perprice[j+1])
            {
                temp = perprice[j+1];
                perprice[j+1] = perprice[j];
                perprice[j] = temp;

                temporder = order[j+1];
                order[j+1] = order[j];
                order[j] = temporder;

                temp = weight[j+1];
                weight[j+1] = weight[j];
                weight[j] = temp;

                temp = value[j+1];
                value[j+1] = value[j];
                value[j] = temp; 
            }
        }
    }
}

//回溯函数
void backtrack(int i)
{
    double bound(int i);
    if (i > n)
    {
        if (cp > bestprice)
        {
            bestprice = cp;
            for ( int j = 1; j <= n; j++)
            {
                bestput[j] = put[j]; 
            }
            return;
        }
    }
    
    //如若左子节点可行，则直接搜索左子树;
    //对于右子树，先计算上界函数，以判断是否将其减去

    //搜索左子树
    if (cw + weight[i] <= c)
    {
        cw += weight[i];
        put[i] = 1;
        cp += value[i];
        backtrack(i+1);
        //回溯
        cw -= weight[i];
        cp -= value[i];
        put[i] = 0; 
    }
    //搜索右子树
    if (bound(i+1) > bestprice) //如若符合条件则搜索右子树
    {
        put[i] = 0;
        backtrack(i+1);
    }
}


//上界函数（上界函数一般只对右子树使用）
double bound(int i)
{   
    //判断当前背包的总价值cp＋剩余容量可容纳的最大价值<=当前最优价值
    double leftw = c-cw;    //剩余背包容量
    double b = cp;      //用于记录当前背包总价值，计算出上界


    for ( i; i <= n; i++)
    {
        if (leftw >= weight[i])
        {
            leftw -= weight[i];
            b += value[i];
        }
    }

    if (i <= n)
    {
        b += value[i]/weight[i]*leftw;
    }

    return b;
}

int main()
{
    int i;
    cout << "请输入物品数量和背包容量：" << endl;
    cin >> n >> c;
    cout << "请输入各个物品的重量，价值和编号：" << endl;
    for ( i = 1; i <= n; i++)
    {
        cin >> weight[i];
        cin >> value[i];
        cin >> order[i];
    }

    knapsack();
    //debug
    for ( i = 1; i <= n; i++)
    {
        cout << order[i] << endl;;
    }
    
    backtrack(1);

    cout << "最优价值为：" << bestprice << "\n" << endl;
    cout << "需要装入的物品编号是：" << endl;
    for ( i = 1; i <= n; i++)
    {
        if (bestput[i] == 1)
        {
            cout << order[i] <<endl;
        }
    }
    
    return 0;
}
