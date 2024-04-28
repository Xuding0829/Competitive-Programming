## Codeforces Round 874 (Div. 3)

### [A - Musical Puzzle](https://codeforces.com/contest/1833/problem/A)

看相邻字符的种类

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;

    std::set<std::string> st;
    for (int i = 1; i < n; i++)
    {
        std::string t;
        t += s[i - 1];
        t += s[i];
        st.insert(t);
    }
    std::cout << st.size() << '\n';
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
```

### [B - Restore the Weather](https://codeforces.com/contest/1833/problem/B)

排序后，大小对应，只需输出相应的日期的温度即可

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], v[i] = {a[i], i};
    std::sort(v.begin(), v.end());

    std::vector<int> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    std::sort(b.begin(), b.end());

    std::vector<int> c(n);
    for (int i = 0; i < n; i++)
        c[v[i].second] = b[i];
    for (auto x : c)
        std::cout << x << ' ';
    std::cout << '\n';
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
```

### [C - Vlad Building Beautiful Array](https://codeforces.com/contest/1833/problem/C)



```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int odd = 0, even = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int k = a[0];
    if (k % 2)
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] % 2 == 0 && (a[i] - k) % 2 == 0)
            {
                std::cout << "NO\n";
                return;
            }
        }
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] % 2 && (a[i] - k) % 2)
            {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
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
```

### [D - Flipper](https://codeforces.com/contest/1833/problem/D)

模拟

字典序最大必然是n在最前面，但考虑到第一个为n，进行操作后n一定不在第一个位置，此时最大的是n-1;

找到最大值值$n / n - 1$的位置$r$，（如果n在最后，r可为n）模拟反转过程

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    int pos = std::find(a.begin(), a.end(), n) - a.begin();
    if (pos == 1)
        pos = std::find(a.begin(), a.end(), n - 1) - a.begin();

    int r = pos == n ? pos : pos - 1;
    auto get = [&](int l, int r)
    {
        std::vector<int> res;
        for (int i = r + 1; i <= n; i++)
            res.push_back(a[i]);
        for (int i = r; i >= l; i--)
            res.push_back(a[i]);
        for (int i = 1; i <= l - 1; i++)
            res.push_back(a[i]);
        return res;
    };

    std::vector<int> ans(n, 1);
    for (int l = 1; l <= r; l++)
        ans = std::max(ans, get(l, r));

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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
```

### [E - Round Dance](https://codeforces.com/contest/1833/problem/E)

并查集

最大值：连通块数量（连通块组成环）

最小值：链 + 环

```c++
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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i], a[i]--;

    DSU dsu(n);
    for (int i = 0; i < n; i++)
        dsu.merge(i, a[i]);

    bool chain = false;
    int minn = 0, maxn = 0;

    std::vector<int> e(n);
    for (int i = 0; i < n; i++)
    {
        if (a[a[i]] == i)
            e[dsu.leader(i)] = 1, chain = true; // 判链
    }

    for (int i = 0; i < n; i++)
    {
        if (dsu.leader(i) == i)
        {
            if (!e[i]) // 判环
                minn++;
            maxn++; // 最大：连通块数量
        }
    }

    minn += chain; // 最小：环 + 链（0/1）
    std::cout << minn << ' ' << maxn << '\n';
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
```

### [F - Ira and Flamenco](https://codeforces.com/contest/1833/problem/F)

模拟

题意等价于在数组中寻找连续的m个数，使得他们的极差小于等于m的种类

这里用qmi求逆元计算

```c++
#include <bits/stdc++.h>

using i64 = unsigned long long;

const i64 mod = 1e9 + 7;

i64 qmi(i64 a, i64 b, i64 p)
{
    i64 res = 1;
    while (b)
    {
        if (b & 1)
            res = (i64)res * a % p;
        a = (i64)a * a % p;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::map<int, int> cnt;
    for (int i = 0, x; i < n; i++)
        std::cin >> x, cnt[x]++;

    std::vector<std::pair<int, int>> v;
    for (auto x : cnt)
        v.push_back(x);
    std::sort(v.begin(), v.end());

    n = v.size();

    i64 res = 0, tmp = 1;
    for (int i = 0, j = 0; i < n;)
    {
        while (j < n && v[j].first < v[i].first + m)
            tmp = (i64)tmp * v[j++].second % mod;
        if (j - i == m)
            res = (res + tmp) % mod;
        tmp = (i64)tmp * qmi(v[i++].second, mod - 2, mod) % mod;
    }
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
```

### [G - Ksyusha and Chinchilla](https://codeforces.com/contest/1833/problem/G)

dfs

将一棵树分成含3个节点的树，问需截断哪些边

有解， 树的顶点数量必须是3的倍数

dfs遍历整棵树，计算节点k所含子树的个数 $siz[k]$ 如果等于3，截断k和其父节点

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> adj[n];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    std::vector<int> siz(n);
    std::vector<int> res;
    std::function<void(int, int, int)> dfs = [&](int u, int fa, int idx)
    {
        siz[u] = 1;
        for (auto [v, id] : adj[u])
        {
            if (v == fa)
                continue;
            dfs(v, u, id);
            siz[u] += siz[v];
        }

        if (siz[u] == 3)
        {
            siz[u] = 0;
            if (idx)
                res.push_back(idx);
        }
    };

    dfs(0, -1, 0);

    // for (int i = 0; i < n; i++)
    //     std::cout << i << ' ' << siz[i] << '\n';

    if (siz[0] != 0)
    {
        std::cout << "-1\n";
        return;
    }
    else
    {
        std::cout << res.size() << '\n';
        for (auto x : res)
            std::cout << x << " ";
        std::cout << '\n';
    }
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
```

