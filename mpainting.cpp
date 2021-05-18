#include<iostream>
using namespace std;

//顶点编号默认从1到n
int g[100][100],m,x[100],sum = 0,n,edge;   //g[100][100]:邻接矩阵，m：颜色个数，x[100]:储存顶点所着颜色，sum记录着色方案,n:顶点个数,edge:代表边的个数

void backtrack(int t)
{
    int ok(int t,int i);
    if (t > n)
    {
        sum += 1;
        return;
    }else
    {
        for (int i = 1; i <= m; i++)
        {
            if (ok(t,i))
            {
                x[t] = i;
                backtrack(t + 1);
                x[t] = 0;
            }
        }
    }  
}

//t是将要图颜色的顶点，i是颜色
int ok(int t,int i)
{
    for (int j = t-1; j >= 1; j--)
    {
        if (g[t][j] == 1 && x[j] == i)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    cout << "请输入颜色的种类数，顶点个数和边得个数：" << endl;
    cin >> m >> n >> edge;
    cout << "在输入每条边的两个顶点：" << endl;
    int a,b;
    for (int i = 0; i < edge; i++)
    {
        cout << "第 " << i+1 << "条边得两个顶点：" << endl;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }

    backtrack(1);
    cout << "涂色方案有 " << sum << "种。" << endl;
    
    return 0;
}
