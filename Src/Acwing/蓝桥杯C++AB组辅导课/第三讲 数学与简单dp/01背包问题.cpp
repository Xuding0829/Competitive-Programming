#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>

using namespace std;

const int N = 1100;

int n, m;
int v[N], w[N];
int f[N];

/*

for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (j < v[i])
                // 空间放不下第i个物品
                f[i][j] = f[i - 1][j];
            else
                // 状态转移
                f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);

    cout << f[n][m] << endl;

*/

signed main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            // 为了保证f[j]只能由 i - 1行转化而来
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    return 0;
}
// 参考  https://blog.csdn.net/raelum/article/details/128996521