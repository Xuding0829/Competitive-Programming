### [A. Grouping](https://atcoder.jp/contests/abc062/tasks/abc062_a)

```c
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<int, int> mp;
    mp[1] = mp[3] = mp[5] = mp[7] = mp[8] = mp[10] = mp[12] = 1;
    mp[4] = mp[6] = mp[9] = mp[11] = 2, mp[2] = 3;

    int x, y;
    std::cin >> x >> y;
    std::cout << (mp[x] == mp[y] ? "Yes" : "No");

    return 0;
}
```



### [B. Picture Fra](https://atcoder.jp/contests/abc062/tasks/abc062_b)

```c
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < m + 2; i++)
        std::cout << "#";
    std::cout << '\n';

    for (int i = 0; i < n; i++)
        std::cout << "#" << a[i] << "#\n";

    for (int i = 0; i < m + 2; i++)
        std::cout << "#";
    std::cout << '\n';
    return 0;
}
```



### [C. Chocolate](https://atcoder.jp/contests/abc062/tasks/arc074_a)

切两刀,使得三个矩形的面积的$max-min$最小

共有四种情况?暴力模拟, 枚举横切的位置



```c
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    auto cal = [=](int n, int m)
    {
        i64 x1 = floor(m / 3.0), y1 = ceil(m / 3.0);
        i64 x2 = floor(n / 3.0), y2 = ceil(n / 3.0);
        return std::min(n * (y1 - x1), m * (y2 - x2));
    };

    auto cal2 = [=](int n, int m)
    {
        i64 res = 1e18;
        for (i64 i = 1; i < n; i++)
        {
            i64 sa = i * m, sb = (n - i) * floor(m / 2.0), sc = (n - i) * ceil(m / 2.0);
            i64 mx = std::max(sa, std::max(sb, sc)), mn = std::min(sa, std::min(sb, sc));
            res = std::min(res, mx - mn);
        }
        for (i64 i = 1; i < m; i++)
        {
            i64 sa = i * n, sb = (m - i) * floor(n / 2.0), sc = (m - i) * ceil(n / 2.0);
            i64 mx = std::max(sa, std::max(sb, sc)), mn = std::min(sa, std::min(sb, sc));
            res = std::min(res, mx - mn);
        }
        return res;
    };

    i64 res = std::min(cal(n, m), cal2(n, m));
    std::cout << res << '\n';

    return 0;
}
```



### [D. 3N Numbe](https://atcoder.jp/contests/abc062/tasks/arc074_b)

题意:一共$3n$个数,在不改变原序列的顺序的情况下,删除$n$个数,使得新数组的前$n$个数的和-后$n$个数的和最小

操作后数组为$2n$个,且,新数组的分界点在原序列中的位置为$n...2n$

```c
#include <bits/stdc++.h>

using i64 = long long;
constexpr int N = 3e5 + 10;
i64 a[N], f[N], g[N];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::priority_queue<i64, std::vector<i64>, std::greater<i64>> q;
    for (int i = 1; i <= 3 * n; i++)
    {
        std::cin >> a[i];
        f[i] = f[i - 1] + a[i];
        q.push(a[i]);
        if (q.size() > n)  // 此处实际只有n...2n的部分对答案有贡献
        {
            f[i] -= q.top();
            q.pop();
        }
    } // max

    while (q.size())
        q.pop();

    for (int i = 3 * n; i > 0; i--)
    {
        g[i] = g[i + 1] + a[i];
        q.push(-a[i]);
        if (q.size() > n)
        {
            g[i] += q.top();
            q.pop();
        }
    }

    i64 res = -1e18;
    for (int i = n ; i <= 2 * n; i++)
        res = std::max(res, f[i] - g[i + 1]);
    std::cout << res << '\n';
    return 0;
}
```

