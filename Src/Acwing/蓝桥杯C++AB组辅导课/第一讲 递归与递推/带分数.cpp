#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 100;

int n, m;
int res;
int num[N];
bool st[N];

// 判断函数，是否满足等式
bool check(int a, int b, int c)
{
    if (a * c + b == n * c)
        return true;
    else
        return false;
}

// cal运算函数，将num数组 i~j 的元素转换为一个整数
int cal(int l, int r)
{
    int tmp = 0;
    for (int i = l; i <= r; i++)
        tmp = tmp * 10 + num[i];
    return tmp;
}

// 枚举1~9的全排列
void dfs(int u)
{
    if (u > 9)
    {
        // 枚举完成之后，从中选择3段，每段至少有1位数
        for (int i = 1; i <= 7; i++)
            for (int j = i + 1; j <= 8; j++)
            {
                int a = cal(1, i);
                int b = cal(i + 1, j);
                int c = cal(j + 1, 9);
                if (check(a, b, c))
                    res++;
            }
    }
    // 枚举
    for (int i = 1; i <= 9; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            num[u] = i;
            dfs(u + 1);
            num[u] = 0;
            st[i] = 0;
        }
    }
}

signed main()
{
    cin >> n;
    dfs(1);
    cout << res << endl;
    return 0;
}