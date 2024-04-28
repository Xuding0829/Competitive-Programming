#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int cnt = 0;
    std::map<std::string, int> mp;
    std::vector<int> adj[1000];

    auto tos = [&](std::string t)
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] >= 'A' && t[i] <= 'Z')
                t[i] = t[i] - 'A' + 'a';
        }
        return t;
    };

    int root;
    for (int i = 0; i < n; i++)
    {
        std::string s1, s2, s;
        std::cin >> s1 >> s >> s2;
        s1 = tos(s1), s2 = tos(s2);

        if (!mp[s1])
            mp[s1] = ++cnt;
        if (!mp[s2])
            mp[s2] = ++cnt;

        if (s1 == "polycarp")
            root = mp[s1];
        if (s2 == "polycarp")
            root = mp[s2];

        adj[mp[s1]].push_back(mp[s2]);
        adj[mp[s2]].push_back(mp[s1]);
    }

    int res = 0;
    std::vector<int> deg(1000);
    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        res = std::max(res, deg[u] + 1);
        for (auto v : adj[u])
        {
            if (v == fa)
                continue;
            deg[v] = deg[u] + 1;
            dfs(v, u);
        }
    };

    dfs(root, -1);

    std::cout << res << '\n';

    return 0;
}