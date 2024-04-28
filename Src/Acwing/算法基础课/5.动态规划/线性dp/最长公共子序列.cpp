#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::string s1, s2;
    std::cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = std::max(f[i - 1][j], f[i][j - 1]);
            if (s1[i] == s2[j])
                f[i][j] = f[i - 1][j - 1] + 1;
        }

    std::cout << f[n][m] << '\n';
    return 0;
}