#include <bits/stdc++.h>
// #include <iostream>
// #include <algorithm>
using namespace std;

const int N = 55;

int n, m, k;
int w[N][N];
int f[N][N][13][14];
int mod = 1000000007;

/*
递归写法———超时
int dfs(int x, int y, int num, int max_value)
{
    if (x > n || y > m || num > k)
        return 0;         // 越界

    if (x == n && y == m) // 到达终点
    {
        if (num == k || (w[x][y] > max_value && num + 1 == k)) // 如果数量到达 k 不取 n, m 或者 不到 k 需要 取 n, m
            return 1;
        else
            return 0;
    }

    if (w[x][y] > max_value) // 能取 x,y 处的东西 可以选择取或者不取
        return dfs(x, y + 1, num + 1, w[x][y]) + dfs(x + 1, y, num + 1, w[x][y]) + // 取
               dfs(x + 1, y, num, max_value) + dfs(x, y + 1, num, max_value); // 不取
    else // 不能取 x,y 处的东西
        return dfs(x, y + 1, num, max_value) + dfs(x + 1, y, num, max_value);
}
*/

/*
1 ≤ n, m≤ 50
1 ≤  k  ≤ 12
0 ≤  C  ≤ 12
*/

// 状态转移 f[n][m][k][c]
// 取 f[n - 1][m][k - 1][c'] c' < c
// 不取 f[n - 1][m][k][c]
// 取 f[n][m - 1][k - 1][c'] c' < c
// 不取 f[n][m - 1][k][c]

signed main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> w[i][j];
            w[i][j]++;
        }

    // 初始化
    f[1][1][0][0] = 1;
    f[1][1][1][w[1][1]] = 1;

    // i, j 循环位置 u, v循环数量、价值
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int u = 0; u <= k; u++)
                for (int v = 0; v <= 13; v++)
                {
                    int &val = f[i][j][u][v];
                    // 引用，方便写
                    val = (val + f[i - 1][j][u][v]) % mod; // 不取 f[i - 1][j][k][c]
                    val = (val + f[i][j - 1][u][v]) % mod; // 不取 f[i][j - 1][k][c]
                    if (u > 0 && v == w[i][j])             // 取了， 此时 c 需要满足要求
                    {
                        for (int c = 0; c < v; c++)
                        {
                            val = (val + f[i - 1][j][u - 1][c]) % mod;
                            val = (val + f[i][j - 1][u - 1][c]) % mod;
                        }
                    }
                }

    // 累加统计总方案数
    int res = 0;
    for (int i = 0; i <= 13; i++)
        res = (res % mod + f[n][m][k][i] % mod) % mod;
    cout << res << endl;

    return 0;
}
/*
signed main()
{
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> w[i][j];
            w[i][j]++;
        }

    for (int i = 1; i <= 13; i++)
    {
        f[n][m][k][i] = 1;
        if (w[n][m] > i)
            f[n][m][k - 1][i] = 1;
    }

    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            for (int u = k; u >= 0; u--)
                for (int v = 13; v >= 0; v--)
                {
                    if (i == n && j == m && (u == k || u == k - 1))
                        continue;
                    if (w[i][j] > v)
                    { // 可以取/不取
                        f[i][j][u][v] = (f[i][j + 1][u][v] + f[i + 1][j][u][v] +
                                         f[i][j + 1][u + 1][w[i][j]] + f[i + 1][j][u + 1][w[i][j]]) % mod;
                    }
                    else
                    { // 不取
                        f[i][j][u][v] = (f[i][j + 1][u][v] + f[i + 1][j][u][v]) % mod;
                    }
                }

    cout << f[1][1][0][0] % mod << endl;
    return 0;
}
*/