#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::vector g(10, std::vector<char>(10));
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            std::cin >> g[i][j];

    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
        {
            if (g[i][j] == '#' && g[i - 1][j - 1] == '#' && g[i - 1][j + 1] == '#' && g[i + 1][j - 1] == '#' && g[i + 1][j + 1] == '#')
            {
                std::cout << i << ' ' << j << '\n';
                return;
            }
        }
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