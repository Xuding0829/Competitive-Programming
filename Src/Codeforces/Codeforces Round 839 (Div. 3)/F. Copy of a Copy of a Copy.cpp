#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector s(k + 1, std::vector<std::string>(n));
    for (int i = 0; i < k + 1; i++)
        for (int j = 0; j < n; j++)
            std::cin >> s[i][j];

    std::vector<std::pair<int, int>> f(k + 1);
    for (int i = 0; i < k + 1; i++)
        for (int j = 1; j < n - 1; j++)
            for (int k = 1; k < m - 1; k++)
                if (s[i][j][k] != s[i][j][k - 1] && s[i][j][k] != s[i][j][k + 1] && s[i][j][k] != s[i][j - 1][k] && s[i][j][k] != s[i][j + 1][k])
                    f[i].first++;

    for (int i = 0; i < k + 1; i++)
        f[i].second = i;
    std::sort(f.begin(), f.end(), std::greater<>());
    std::cout << f[0].second + 1 << '\n';

    std::vector<std::vector<int>> res;
    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
            for (int k = 1; k < m - 1; k++)
                if (s[f[i].second][j][k] != s[f[i - 1].second][j][k])
                    res.push_back({1, j + 1, k + 1});
        res.push_back({2, f[i].second + 1});
    }

    std::cout << res.size() << '\n';
    for (auto x : res)
        for (int i = 0; i < x.size(); i++)
            std::cout << x[i] << " \n"[i == x.size() - 1];
    return 0;
}