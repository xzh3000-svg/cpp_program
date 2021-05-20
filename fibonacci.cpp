#include<iostream>

using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int n,f;
    cout << "你想要计算菲波那切数列的n为多少：" << endl;
    cin >> n;
    f = fibonacci(n);
    cout << "计算得：" << f << endl;
    return 0;
}
