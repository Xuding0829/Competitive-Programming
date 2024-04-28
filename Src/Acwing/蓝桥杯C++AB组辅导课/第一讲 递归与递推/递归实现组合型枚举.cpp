#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
#define int long long

using namespace std;

const int N = 100;

int n, m;
bool st[N];
int way[N]; // 存储方案

/*

1.0版本 —— 未进行剪枝

void dfs(int u, int start)
{
    if (u > m)
    {
        for (int i = 1; i <= m; i++)
            cout << way[i] << ' ';
        puts("");
        return;
    }

    for (int i = start; i <= n; i++)
    {
        if(!st[i])
        {
            way[u] = i;
            st[i] = 1;
            dfs(u + 1, i + 1);
            st[i] = 0;
            way[u] = 0;
        }
    }
}

*/

void dfs(int u, int start) // u表示从第u位开始枚举，start表示从数字start开始枚举
{
    if (u + n - start + 1 < m)
        return;
    /*

    y总：
    if (u + n - start < m)
        return;

    */

    // 剪枝--保证有数可取

    if (u > m)
    {
        for (int i = 1; i <= m; i++)
            cout << way[i] << ' ';
        puts("");
        return;
    }
    // 打印方案

    for (int i = start; i <= n; i++)
    {
        way[u] = i;
        dfs(u + 1, i + 1);
        way[u] = 0;
    }
}

signed main()
{
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}