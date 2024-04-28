#include <bits/stdc++.h>

using i64 = long long;
const int N = 2e5 + 100;

int h[N], e[N], ne[N];
int idx, n, m, res;
bool st[N];

void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void dfs(int u, int sum)
{
    if (sum == n)
    {
        res++;
        return;
    }
    st[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = 1;
            dfs(j, sum + 1);
            st[j] = 0;
        }
    }
    st[u] = 0;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(h, -1, sizeof(h));

    std::cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        add(x, y), add(y, x);
    }

    dfs(1, 1);
    std::cout << res << '\n';

    return 0;
}