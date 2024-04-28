#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 100, M = 4 * N;
int h[N], e[M], ne[M], idx;
int in[N], out[N];
int n, m, type, cnt;
bool used[M];
std::stack<int> stk;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
    for (int &i = h[u]; ~i;)
    {
        if (used[i])
        {
            i = ne[i];
            continue;
        }

        used[i] = true;
        if (type == 1)
            used[i ^ 1] = true;

        int t;
        if (type == 1)
        {
            t = i / 2 + 1;
            if (i & 1)
                t = -t;
        }
        else
            t = i + 1;

        int j = e[i];
        i = ne[i];
        dfs(j);
        stk.push(t);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    memset(h, -1, sizeof(h));
    std::cin >> type >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        add(a, b);
        if (type == 1)
            add(b, a);
        in[b]++, out[a]++;
    }

    if (type == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            if (in[i] + out[i] & 1)
            {
                std::cout << "NO\n";
                return 0;
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            if (in[i] != out[i])
            {
                std::cout << "NO\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (~h[i])
        {
            dfs(i);
            break;
        }
    }

    if (stk.size() < m)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        while (stk.size())
        {
            std::cout << stk.top() << ' ';
            stk.pop();
        }
    }
    return 0;
}