#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 1010;

// 二维
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int n, m;
//     std::cin >> n >> m;

//     std::vector<int> v(n + 1), w(n + 1);
//     std::vector<std::vector<int>> f(n + 1, std::vector<int>(N));
//     for (int i = 1; i <= n; i++)
//         std::cin >> v[i] >> w[i];

//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j <= m; j++)
//             if (v[i] > j)
//                 f[i][j] = f[i - 1][j];
//             else
//                 f[i][j] = std::max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);

//     std::cout << f[n][m] << '\n';
//     return 0;
// }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1), w(N);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];

    std::vector<int> f(m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);

    std::cout << f[m] << '\n';
}