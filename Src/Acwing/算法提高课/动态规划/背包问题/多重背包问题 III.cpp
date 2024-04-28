/*
deque写法
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n + 1), w(n + 1), s(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> v[i] >> w[i] >> s[i];

    std::vector<int> f(m + 1);

    std::deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        std::vector<int> g(f); // 被更新，但要求使用上一层i - 1更新
        for (int j = 0; j < v[i]; j++)
        {
            q.clear();
            for (int k = j; k <= m; k += v[i])
            {
                if(!q.empty() && q.front() < k - s[i] * v[i])
                    q.pop_front();
                while(!q.empty() && g[q.back()] - (q.back() - j) / v[i] * w[i] <= g[k] - (k - j) / v[i] * w[i])
                    q.pop_back();
                q.push_back(k);
                f[k] = g[q.front()] + (k - q.front()) / v[i] * w[i];
            }
        }
    }
    std::cout << f[m] << '\n';

    return 0;
}
*/
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e5 + 100;

int f[N], g[N], q[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int v, w, s;
        std::cin >> v >> w >> s;

        memcpy(g, f, sizeof(g));

        for (int j = 0; j < v; j++)
        {
            int hh = 0, tt = -1;
            for (int k = j; k <= m; k += v)
            {
                if (hh <= tt && k - q[hh] > s * v)
                    hh++;
                while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w)
                    tt--;
                q[++tt] = k;
                f[k] = g[q[hh]] + (k - q[hh]) / v * w;
            }
        }
    }
    std::cout << f[m] << '\n';

    return 0;
}