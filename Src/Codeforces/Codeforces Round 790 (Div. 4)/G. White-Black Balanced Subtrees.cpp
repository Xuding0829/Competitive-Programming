#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> adj[n], du(n);
    for (int i = 1, fa; i < n; i++)
    {
        std::cin >> fa;
        fa--;
        adj[i].push_back(fa);
        du[fa]++;
    }

    std::string s;
    std::cin >> s;

    std::vector<bool> st(n, false);
    std::vector<std::pair<int, int>> cnt(n);

    std::queue<int> q;
    for (int i = 0; i < n; i++)
        if (!du[i])
            q.push(i);

    while (q.size())
    {
        int u = q.front();
        q.pop();

        for (auto v : adj[u]) // u -- son  v -- father
        {
            du[v]--;

            if (s[u] == 'B')
                cnt[u].first++;
            else
                cnt[u].second++;

            cnt[v].first += cnt[u].first;
            cnt[v].second += cnt[u].second;

            if (!du[v])
                q.push(v);
        }
    }

    if (s[0] == 'B')
        cnt[0].first++;
    else
        cnt[0].second++;

    int res = 0;
    for (int i = 0; i < n; i++)
        if (cnt[i].first == cnt[i].second)
            res++;
    std::cout << res << '\n';
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