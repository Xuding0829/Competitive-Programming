#include <bits/stdc++.h>

using i64 = long long;

// 二维 必然 TLE
// int main()
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);

//     int n, m;
//     std::cin >> n >> m;

//     std::vector<int> v(n + 1), w(n + 1);
//     for (int i = 1; i <= n; i++)
//         std::cin >> v[i] >> w[i];

//     std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j <= m; j++)
//             for (int k = 0; k * v[i] <= j; k++)
//                 f[i][j] = std::max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);

//     std::cout << f[n][m] << '\n';
//     return 0;
// }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i];

    std::vector<int> f(m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = std::max(f[j], f[j - v[i]] + w[i]);

    std::cout << f[m] << '\n';
    return 0;
}