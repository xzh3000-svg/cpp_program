#include<iostream>

using namespace std;

int num = 0;    //记录选择活动的个数
int n,s[100],f[100],order[100],bestorder[100];    //n:总共有多少个活动,s[i]:第i个活动的开始时间,f[i]:第i个活动的结束时间,order[i]:第i个活动的序号
int endf = 0;    //记录公共资源占用的结束时间

//按照活动的结束时间由小排序
void sort(int l,int r)
{
    int i = l,j = r;
    int basef = f[l],bases = s[l],baseo = order[l];

    if (i < j)
    {
        while (i < j)
        {
            while (i < j && f[j] >= basef)
                j--;
            if (i < j)
            {
                f[i] = f[j];
                s[i] = s[j];
                order[i] = order[j];
                i++;
            }
            while (i < j && f[i] < basef)
                i++;
            if (i < j)
            {
                f[j] = f[i];
                s[j] = s[i];
                order[j] = order[i];
                j--;
            }
        }
        f[i] = basef;
        s[i] = bases;
        order[i] = baseo;
        sort(l,i-1);
        sort(i+1,r);
    }
}

void arrangements()
{
    for (int i = 1; i <= n; i++)
    {
        if (s[i] >= endf)
        {
            bestorder[++num] = order[i];
            endf = f[i]; 
        }
    }
}

int main()
{
    cout << "请输入活动的个数：" << endl;
    cin >> n;
    cout << "请输入每个活动的序号，开始时间和结束时间：" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> order[i] >> s[i] >> f[i];
    }
    sort(1,n);
    arrangements();

    cout << "最多能够相容的活动个数为：" << num << endl;
    cout << "相容的活动序号为：" ;
    for (int i = 1; i <= num; i++)
    {
        cout << bestorder[i] << " ";
    }
    cout << endl;

    return 0;
}
