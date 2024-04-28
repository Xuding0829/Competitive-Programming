#! https://zhuanlan.zhihu.com/p/657680254
### Codeforces Round 304 (Div. 2)

#### A. Soldier and Bananas

```c++
#include<bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, n, w;
    std::cin >> k >> n >> w;
    std::cout << std::max(0, (1 + w) * w / 2 * k - n) << '\n';

    return 0;
}
```

#### B. Soldier and Badges

题意:

给你n个数,你可以对每个数执行+1的操作,最后要求每个数都不同

先对数组进行排序,然后遍历.

如果当前i位置的数大于i-1的数,这是符合题意的;如果i位置的数不等于前一个数,那么先把i位置的数变成i-1,这样两个数是相同的再+1则不同

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if(a[i] > a[i  - 1])
            continue;
        else
            res += a[i - 1] - a[i] + 1, a[i] += a[i - 1] - a[i] + 1;
    }
    std::cout << res << '\n';
    return 0;
}
```

#### C. Soldier and Cards

简单模拟,根据题意来即可

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int k1;
    std::cin >> k1;
    std::queue<int> q;
    while (k1--)
    {
        int x;
        std::cin >> x;
        q.push(x);
    }

    int k2;
    std::cin >> k2;
    std::queue<int> q2;
    while (k2--)
    {
        int x;
        std::cin >> x;
        q2.push(x);
    }

    int t = 0;
    while (q.size() && q2.size())
    {
        t++;
        if (t >= 1000)
        {
            std::cout << -1 << '\n';
            return 0;
        }

        int x = q.front();
        q.pop();
        int y = q2.front();
        q2.pop();

        if (x > y)
            q.push(y), q.push(x);
        else
            q2.push(x), q2.push(y);
    }
    std::cout << t << ' ' << (q.size() ? 1 : 2);

    return 0;
}
```

#### D. Soldier and Number Game

题意:

给你$a,b$,设初始值为$\frac{a!}{b!}$, 每次用将这个数除以它的因数,直到1问能除几次

易知$\frac{a!}{b!}=a*(a-1)*...*(b+1)$,由整数分解定理,$a = p_1^{k^1}*p_2^{k^2}*...p_n^{k_n}$,问题可以转化为求这段区间的质因数个数

```c++
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 5e6 + 10;

int cnt, primes[N], f[N];
bool st[N];

void get_primes()
{
    for (int i = 2; i <= N; i++)
    {
        if (!st[i])
            primes[cnt++] = i, f[i] = 1;
        for (int j = 0; primes[j] <= N / i; j++)
        {
            st[primes[j] * i] = true;
            f[primes[j] * i] = f[i] + 1;
            if (i % primes[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= N; i++)
        f[i] += f[i - 1];
}

void solve()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << f[a] - f[b] << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    get_primes();

    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```

#### E. Soldier and Traveling

题意:

有n个点,m条边,每个点初始有$a_i$个人,每个点上的人可以沿着边走,问能不能通过移动,使得 $a_i$ 变成$b_i$

网络流

首先建立一个源点,将这个源点与这$n$个点建一条边, 将所有目标点$b_i$与汇点建立一条边,之后在u,v有边的建边

人生第一道网络流,呜呜~

```c++
#include <bits/stdc++.h>

using i64 = long long;
static constexpr int inf = 1e9;
template <typename T>
struct Flow
{
    int n;
    struct Edge
    {
        int to;
        T cap;
        T flo;
        Edge(int to, T cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, dep;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t)
    {
        dep.assign(n, -1);
        std::queue<int> q;
        q.push(s);
        dep[s] = 0;
        while (q.size())
        {
            int u = q.front();
            q.pop();

            for (int i : g[u])
            {
                int v = e[i].to;
                int c = e[i].cap;
                if (dep[v] == -1 && c > 0)
                {
                    dep[v] = dep[u] + 1;
                    if (v == t)
                        return true;
                    q.push(v);
                }
            }
        }
        return false;
    }
    T dfs(int u, int t, T f)
    {
        if (u == t)
            return f;
        T r = f;
        for (int &i = cur[u]; i < int(g[u].size()); i++)
        {
            int j = g[u][i];
            int v = e[j].to;
            T c = e[j].cap;
            if (c > 0 && dep[v] == dep[u] + 1)
            {
                T a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, T c)
    {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    T maxFlow(int s, int t)
    {
        T ans = 0;
        while (bfs(s, t))
        {
            cur.assign(n, 0);
            ans += dfs(s, t, inf);
        }
        return ans;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    Flow<int> flow(2 * n + 3);

    int sa = 0, sb = 0;
    int s = 0, t = 2 * n + 1;
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        flow.addEdge(s, i, x);
        sa += x;
    }
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        flow.addEdge(i + n, t, x);
        sb += x;
    }
    for (int i = 1; i <= n; i++)
        flow.addEdge(i, i + n, inf);

    while (m--)
    {
        int u, v;
        std::cin >> u >> v;
        flow.addEdge(u, v + n, inf);
        flow.addEdge(v, u + n, inf);
    }

    int mf = flow.maxFlow(s, t);
    // std::cout << mf << ' ' << sa << ' ' << sb << '\n';
    if (mf == sa && mf == sb)
    {
        std::cout << "YES\n";
        std::vector g(n + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i < flow.e.size(); i++)
        {
            int v = flow.e[i].to;
            int c = flow.e[i].cap;
            int u = flow.e[i ^ 1].to;
            if (u >= 1 && u <= n && v > n) 
                g[u][v - n] = inf - c;
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                std::cout << g[i][j] << " \n"[j == n];
    }
    else
        std::cout << "NO\n";

    return 0;
}
```

