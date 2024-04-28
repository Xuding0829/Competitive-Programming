#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1), w(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i] >> s[i];

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = std::max(f[i][j], f[i - 1][j - k * v[i]] + w[i * k]);

    std::cout << f[n][m] << '\n';

    return 0;
}

/*
一维优化
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1), w(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i] >> s[i];

    std::vector<int> f(m + 1);
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[j] = std::max(f[j], f[j - k * v[i]] + k * w[i]);
    std::cout << f[m] << '\n';

    return 0;
}
*/