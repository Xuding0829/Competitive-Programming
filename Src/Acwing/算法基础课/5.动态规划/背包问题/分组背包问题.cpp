#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 110;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> s(n + 1);
    std::vector<std::vector<int>> v(n + 1, std::vector<int>(N)), w(n + 1, std::vector<int>(N));
    for (int i = 1; i <= n; i++)
    {
        std::cin >> s[i];
        for (int j = 1; j <= s[i]; j++)
            std::cin >> v[i][j] >> w[i][j];
    }

    std::vector<int> f(m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 1; k <= s[i]; k++)
                if (v[i][k] <= j)
                    f[j] = std::max(f[j], f[j - v[i][k]] + w[i][k]);

    std::cout << f[m] << '\n';
    return 0;
}