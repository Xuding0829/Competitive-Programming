#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<bool> vis(n);
    while (m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--, b--, c--;
        vis[b] = true;
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                std::cout << i + 1 << ' ' << j + 1 << '\n';
            }
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