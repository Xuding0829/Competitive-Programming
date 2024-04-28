#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 100;

int n, m;
int st[N]; // st[]数组=1表示选择 ！1表示不选

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
            if (st[i])
                // 只有这个数被选择了才可以输出
                cout << i << ' ';
        puts("");
        return;
    }

    st[u] = 0; // 不选这个数
    dfs(u + 1);
    st[u] = 0; // 恢复现场

    st[u] = 1; // 选这个数
    dfs(u + 1);
    st[u] = 0; // 恢复现场
}

signed main()
{
    cin >> n;
    dfs(1);
    return 0;
}