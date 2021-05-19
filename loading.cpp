#include<iostream>

using namespace std;

int num = 0;    //num表示最多能够装载多少集装箱
//轮船结构
typedef struct
{
    int c;  //c：轮船载重量
    int n;  //n表示集装箱的数量
    int w[100]; //w[i]：集装箱i的重量
    int x[100]; //x[i]=1：表示集装箱i装载
}load;

void cin_function(load *g)
{
    cout << "请输入轮船的载重量和集装箱的数量：" << endl;
    cin >> g->c >> g->n;
    cout << "请输入每个集装箱的重量：" << endl;
    for (int i = 1; i <= g->n; i++)
    {
        cin >> g->w[i];
    }
}

void loading(load *g)
{
    void quick_sort(int s[],int l,int r);
    //对集装箱的重量做一次快速排序，从小到大
    quick_sort(g->w,1,g->n);

    int leftc = g->c;    //leftc表示轮船剩余载重量
    int m = 1;  //m表示检视到第几个集装箱

    while (leftc > 0 && m <= g->n)
    {
        if (leftc - g->w[m] >=0)
        {
            num += 1;
            leftc -= g->w[m];
            g->x[m] = 1;
        }
        m++;
    }

    cout << "最多能够装载的集装箱数目：" << num << endl;
    cout << "并且装载的重量分别为：";
    for (int i = 1; i <= g->n; i++)
    {
        if (g->x[i] == 1)
        {
            cout << g->w[i] << " ";
        }
    }
    cout << endl;
}

//区别与一般的快排，采用挖坑方式快排
void quick_sort(int s[],int l,int r)
{
    int i = l,j = r;
    int x = s[l];
    if (i < j)
    {
        while (i < j)
        {
            while (i < j && s[j] >= x)
                j--;
            if (i < j)
                s[i++] = s[j];
            while (i < j && s[i] < x)
                i++;
            if (i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s,l,i-1);
        quick_sort(s,i+1,r);
    }
}

int main()
{
    load g;
    cin_function(&g);
    loading(&g);

    return 0;
}
