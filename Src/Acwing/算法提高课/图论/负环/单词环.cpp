#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 700;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n, n)
    {
        std::vector<std::pair<int, int>> adj[N];
        for (int i = 0; i < n; i++)
        {
            std::string s;
            std::cin >> s;
            int len = s.size();
            if (len >= 2)
            {
                int u = (s[0] - 'a') * 26 + s[1] - 'a';
                int v = (s[len - 2] - 'a') * 26 + s[len - 1] - 'a';
                adj[u].push_back({v, len});
            }
        }

        auto check = [&](double mid)
        {
            int k = 0;
            std::vector<bool> st(N);
            std::vector<int> cnt(N);
            std::vector<double> dis(N);

            std::queue<int> q;
            for (int i = 0; i < 676; i++)
                q.push(i), st[i] = true;

            while (q.size())
            {
                int u = q.front();
                q.pop();
                st[u] = false;

                for (auto [v, w] : adj[u])
                {
                    if (dis[v] < dis[u] + w - mid)
                    {
                        dis[v] = dis[u] + w - mid;
                        cnt[v] = cnt[u] + 1;
                        if (++k > 10000)
                            return true;
                        if (cnt[v] >= N)
                            return true;
                        if (!st[v])
                        {
                            q.push(v);
                            st[v] = true;
                        }
                    }
                }
            }
            return false;
        };

        if (!check(0))
            std::cout << "No solution\n";
        else
        {
            double l = 0, r = 1000;
            while (r - l > 1e-4)
            {
                double mid = (l + r) / 2;
                if (check(mid))
                    l = mid;
                else
                    r = mid;
            }
            std::cout << std::fixed << std::setprecision(2) << l << '\n';
        }
    }

    return 0;
}