#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::vector g(10, std::vector<char>(10));
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            std::cin >> g[i][j];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (g[i][j] == '1')
                g[i][j] = '2';

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            std::cout << g[i][j];
            if (j == 8)
                std::cout << '\n';
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