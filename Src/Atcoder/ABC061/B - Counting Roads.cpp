#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> st[n];
    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        st[u].push_back({u, v});
        st[v].push_back({u, v});
    }

    for (int i = 0; i < n; i++)
        std::cout << st[i].size() << '\n';

    return 0;
}