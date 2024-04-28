#include <bits/stdc++.h>

using i64 = long long;

const int N = 110, M = 10010, inf = 0x3f3f3f;

int h[N], e[M], ne[M], w[M], idx;
int L[N], dis[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa(int l, int r)
{
    memset(dis, 0x3f, sizeof(dis));
    memset(st, false, sizeof(st));
    dis[0] = 0, st[0] = true;

    std::queue<int> q;
    q.push(0);
    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (l <= L[j] && L[j] <= r && dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                if (!st[j])
                    q.push(j), st[j] = true;
            }
        }
    }
    return dis[1];
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(h, -1, sizeof(h));

    int m, n;
    std::cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        int p, x;
        std::cin >> p >> L[i] >> x;
        add(0, i, p);

        while (x--)
        {
            int t, v;
            std::cin >> t >> v;
            add(t, i, v);
        }
    }

    int res = inf;
    for (int i = L[1] - m; i <= L[1]; i++)
        res = std::min(res, spfa(i, i + m));
    std::cout << res << '\n';

    return 0;
}