//这是我自己写的
#include<iostream>
using namespace std;

int n,sum = 0,x[10],y[11]={0,0,0,0,0,0,0,0,0,0,0};   //n:皇后个数，sum:可行解个数，x[i]:表示第i行皇后放置的位置，y[i]:标记第i列是否被使用

void backtrack(int t)
{
    int check(int j,int i);
    if (t > n)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << x[i];
        }
        cout << endl;
        sum += 1;
    }

    for (int j = 1; j <= n; j++)
    {
        if (y[j] == 1)
        {
            continue;
        }
        if (check(t,j))
        {
            x[t] = j;
            y[j] = 1;
            backtrack(t + 1);
            x[t] = 0;
            y[j] = 0;
        }
    }
    //}
}

int check(int i,int j)  //检查第i行第j列是否能插入
{
   for (int t = i-1; t >= 1; t--)
   {
       if (abs(j-x[t]) == i-t)
       {
           return 0;
       }
       
   }
   return 1;
}

int main()
{
    cin >> n;
    backtrack(1);
    cout << sum << endl;
    
    return 0;
}

//下面是我找到的代码
#include <iostream>
#include <vector>
using namespace std;

#define N 4 //N皇后
vector<int> putInf;//每一行皇后的置放位置情况
//不同行 不同列 不同斜线 |ri - rj| != |ci - cj| 第1行与
vector<int> used(N, 0);//每一列只能有一个皇后，记录每一列的状态
vector<vector<int>> ans;//存储可行方案
int curRow = 0;//当前待放皇后的行数

/*            正置放皇后行↓ 置放列↓              */
bool judgeLegalPut(int& curRow, int col) {//判断在curRow行的col列放置皇后是否合法
	for (int i = curRow - 1; i >= 0; i--) {
		//我们的解空间树已经去除一行一列置放相同元素
		//（每一个皇后被放在不同行以及不同列）的情况
		//因此我们只需要判断皇后是否成斜线即可
		if (curRow - i == abs(col - putInf[i])) {
			//当前位置与之前的皇后处于同一斜线上
			return false;
		}
	}
	return true;
}

void queensAssign(int curRow) {
	if (curRow >= N) {//递归到叶子节点，递归结束，收集结果
		ans.push_back(putInf);
		return;
	}

//i : 当前行皇后准备放的列数
	for (int i = 0; i < N; ++i) {//curRow行i列的位置
		if (used[i]) continue;//位置被使用过，直接跳过 
		//这样满足了不处于同一列的显条件 类似于全排列
		if (judgeLegalPut(curRow, i)) {
			//当前位置置放与之前不冲突 将皇后加入
			used[i] = true;
			putInf.push_back(i);
			queensAssign(curRow + 1);
			used[i] = false;//撤销之前的状态
			putInf.pop_back();
		}
	}
}


void printChessBoard(vector<int>& vec) {//输出模拟棋盘
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != vec[i])
				cout << "○";
			else
				cout << "●";
		}cout << endl;
	}cout << endl;
}
/// <author>
/// nepu_bin
/// <博客域名>
/// bincode.blog.csdn.net
int main() {
	queensAssign(0);
	int n = 1;
	cout << N << "皇后问题,方案如下:\n" << endl;
	for (vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); it++) {
		cout << "第" << n++ << "种放置方案, 皇后被放于 " << endl;
		for (int i = 0; i < it->size(); i++) {
			cout << (*it)[i] + 1 << "  ";
		}cout <<"列" << endl;
		cout << endl << "棋盘布局如下↓" << endl;
		printChessBoard(*it);
	}
	return 0;
}
