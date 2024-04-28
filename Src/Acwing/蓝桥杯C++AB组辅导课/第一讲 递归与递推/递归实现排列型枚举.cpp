#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 10;

int n, m;
int st[N];  // st数组表示状态，是否使用
int way[N]; // way数组存储方案

void dfs(int u)
{
    if (u > n)
    {
        for (int i = 1; i <= n; i++)
            cout << way[i] << ' ';
        puts("");
        // 打印方案
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!st[i])
        { 
            // 如果i没有使用过，u这个位置放i
            st[i] = 1;
            way[u] = i;
            dfs(u + 1);
            // 恢复现场
            way[u] = 0;
            st[i] = 0;
        }
    }
}

signed main()
{
    cin >> n;
    dfs(1);
    return 0;
}