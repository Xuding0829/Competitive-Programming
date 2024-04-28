#include <bits/stdc++.h>

using i64 = long long;

struct DSU
{
    std::vector<int> f, siz;
    DSU(int n) : f(n), siz(n, 1)
    {
        std::iota(f.begin(), f.end(), 0);
    }
    int leader(int x)
    {
        return x == f[x] ? x : f[x] = leader(f[x]);
    }
    bool same(int x, int y)
    {
        return leader(x) == leader(y);
    }
    void merge(int x, int y)
    {
        x = leader(x), y = leader(y);
        if (x != y)
        {
            siz[x] += siz[y];
            f[y] = x;
        }
    }
    int size(int x)
    {
        return siz[leader(x)];
    }
};

void solve()
{
    int n;
    std::cin >> n;

    DSU dsu(26);
    std::vector<int> in(26), out(26);
    std::vector<bool> vis(26);
    while (n--)
    {
        std::string s;
        std::cin >> s;
        int a = s[0] - 'a', b = s.back() - 'a';
        vis[a] = vis[b] = true;
        out[a]++, in[b]++;
        dsu.merge(a, b);
    }

    bool flag = true;
    int st = 0, ed = 0;
    for (int i = 0; i < 26; i++)
    {
        if (in[i] != out[i])
        {
            if (in[i] == out[i] + 1)
                ed++;
            else if (out[i] == in[i] + 1)
                st++;
            else
            {
                flag = false;
                break;
            }
        }
    }

    if (flag && !(!st && !ed || st == 1 && ed == 1))
        flag = false;

    int res = -1;
    for (int i = 0; i < 26; i++)
    {
        if (vis[i])
        {

            if (res == -1)
                res = dsu.leader(i);
            else if (res != dsu.leader(i))
            {
                flag = false;
                break;
            }
        }
    }

    // for (int i = 0; i < 26; i++)
    //     std::cout << dsu.leader(i) << " \n"[i == 25];

    std::cout << (flag ? "Ordering is possible.\n" : "The door cannot be opened.\n");
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