#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    // 完全背包 f[i,j] 表示从1-i中选，总和为j的方案数
    //  二维完全背包
    //  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
    //  f[0][0] = 1;
    //  for (int i = 1; i <= n; i++)
    //      for (int j = 0; j <= n; j++)
    //          for (int k = 0; j - k * i >= 0; k++)
    //              f[i][j] = (f[i][j] + f[i - 1][j - k * i]) % mod;
    //  std::cout << f[n][n] << '\n';

    // 完全背包一维优化
    // std::vector<int> f(n + 1);
    // f[0] = 1;
    // for (int i = 1; i <= n; i++)
    //     for (int j = i; j <= n; j++)
    //         f[j] = (f[j] + f[j - i]) % mod;
    // std::cout << f[n] << '\n';

    // 计数dp
    // f[i,j]表示总和是i，恰好分成j个数
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;

    int res = 0;
    for (int i = 1; i <= n; i++)
        (res += f[n][i]) %= mod;
    std::cout << res << '\n';
    return 0;
}