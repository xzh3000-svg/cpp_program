#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int n,m,xorder[10],g[100][100],bestorder[10],best = 0,now = 0;	//n:顶点个数，m:边数，g[100][100]:记入边的权，bestorder[10]:记录最好的路线，best：记录最小的权和，xorder[10]:顶点的编号，now：目前的权和

void cin_function()
{
	cout << "请输入问题的顶点和边数：" << endl;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		xorder[i] = i;
	}
	cout << "请输入每条边的两个顶点以及它的权值：" << endl;
	int a,b,c;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = c;
	}
}

void ending(int k)
{
	if (k == n)
	{
		if ((now + g[xorder[k-1]][xorder[k]] + g[xorder[k]][1] < best || best == 0) && g[xorder[k-1]][xorder[k]] != 0 && g[xorder[k]][1] != 0)
		{
			best = now + g[xorder[k-1]][xorder[k]] + g[xorder[k]][1];
			for (int i = 1; i <= n; i++)
			{
				bestorder[i] = xorder[i];
			}
		}
		return;
	}

	for (int i = k; i < n; i++)
	{
		if (g[xorder[k - 1]][xorder[i]] != 0 && (now + g[xorder[k - 1]][xorder[i]] < best || best == 0))
		{
			swap(xorder[i],xorder[k]);
			now += g[xorder[k-1]][xorder[k]];
			ending(k+1);
			swap(xorder[i],xorder[k]);
			now -= g[xorder[k-1]][xorder[k]];
		}
	}
}

void print(){
	cout<< "最优值：" << best << endl;
	for(int i=1; i<=n; i++){
		cout << bestorder[i] << " ";
	}
	cout << bestorder[1] << endl;
}

int main()
{
	cin_function();
	ending(2);
	print();

	return 0;
}
