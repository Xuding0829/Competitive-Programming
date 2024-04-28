#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
// #define int long long
using namespace std;
typedef long long ll;

const int N = 55;
int a[N];
ll f[N][N][N * N];

// 题目大意： 给定一个数组，问从中选择i个数，使得i个数之和为xi
// 第一眼：二进制枚举
// 实际：动态规划

// f[i][j][k] 表示 从前i个物品中选择j个且总价值为k的方案数
// 状态转移方程: f[i][j][k] = f[i - 1][j - 1][k - a[i]](选择第i个物体) + f[i - 1][j][k]（不选择第i个物体）

signed main()
{
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]); // 背包问题输入从1开始，否则后面会re

    // int res = 0;
    // for (int op = 0; op < 1 << n; op++)
    // {
    //     int sum = 0;

    //     int k = __builtin_popcount(op);

    //     if (k == 0)
    //         continue;

    //     for (int i = 0; i < n; i++)
    //         if (op >> i & 1)
    //             sum += a[i];
    //     cout << "op = " << op << " k = " << k << " sum = " << sum << endl;
    //     if (sum == x * k)
    //         res++;
    // }

    // cout << res << endl;

    // 初始化
    for (int i = 0; i <= n; i++)
        f[i][0][0] = 1; // 注意 0 也要初始化

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            for (int k = 0; k <= x * n; k++)
            {
                if (k >= a[i] && j >= 1)
                    f[i][j][k] = f[i - 1][j - 1][k - a[i]] + f[i - 1][j][k];
                else
                    f[i][j][k] = f[i - 1][j][k];
            }
        }
    }

    // 求和 答案即从前n个物品种选择i个，且总价值为x*i的方案数
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += f[n][i][x * i];
    printf("%lld\n", res);
    return 0;
}
