#include <bits/stdc++.h>

using i64 = long long;
using ull = unsigned long long;

constexpr int N = 1e6 + 10;
std::set<ull> tree;
ull hash[N];

ull shift(ull x)
{
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x;
}

void solve()
{
    int n;
    std::cin >> n;

    memset(hash, 0, sizeof(hash));

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::function<void(int, int)> get_hash = [&](int u, int fa)
    {
        hash[u] = 1;
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            get_hash(v, u);
            hash[u] += shift(hash[v]);
        }
        tree.insert(hash[u]);
    };

    get_hash(0, -1);
    std::cout << tree.size() << '\n';

    for (int i = 0; i < n; i++)
        std::cout << i << ' ' << hash[i] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}