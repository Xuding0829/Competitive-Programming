#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 100;

int h[N], e[N], w[N], ne[N], idx;
int n, m;
int dis[N], cnt[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool spfa()
{
    std::queue<int> q;

    for (int i = 1; i <= n; i++)
        st[i] = true, q.push(i);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dis[j] > dis[t] + w[i])
            {
                dis[j] = dis[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n)
                    return true;
                if (!st[j])
                    q.push(j), st[j] = true;
            }
        }
    }
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(h, -1, sizeof(h));

    std::cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa())
        puts("Yes");
    else
        puts("No");
}