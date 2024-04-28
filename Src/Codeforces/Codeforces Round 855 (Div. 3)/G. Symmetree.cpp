#include <bits/stdc++.h>

using i64 = long long;
using ull = unsigned long long;

constexpr int N = 2e5 + 100;

const unsigned long long seed = (std::chrono::steady_clock::now().time_since_epoch().count());
ull shift(ull x)
{
    x ^= seed;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    x ^= seed;
    return x;
}

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 哈希操作
    std::vector<ull> hash(n + 100);
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
    };

    get_hash(0, -1);

    // dfs check 操作
    std::map<ull, int> cnt[n];
    std::function<bool(int, int)> dfs = [&](int u, int fa)
    {
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            cnt[u][hash[v]]++;
        }

        int count = 0;
        ull idx = 0;
        for (auto [v, w] : cnt[u])
        {
            if (w & 1)
                count++, idx = v;
        }

        if (count > 1)
            return false;
        else if (count == 0)
            return true;
        else
        {
            for (auto v : adj[u])
            {
                if (hash[v] == idx)
                    return dfs(v, u);
            }
        }
        return true;
    };

    // 输出
    bool res = dfs(0, -1);
    std::cout << (res ? "YES\n" : "NO\n");
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