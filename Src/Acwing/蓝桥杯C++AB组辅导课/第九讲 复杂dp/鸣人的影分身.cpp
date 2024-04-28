#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> m >> n;

    std::vector<std::vector<int>> f(m + 1, std::vector<int>(n + 1));
    f[0][0] = 1;
    for (int i = 0; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i][j - 1];
            if (i >= j)
                f[i][j] += f[i - j][j];
        }

    std::cout << f[m][n] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}