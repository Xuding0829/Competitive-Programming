#! https://zhuanlan.zhihu.com/p/654498213
## [Codeforces Round 892 (Div. 2)](https://codeforces.com/contest/1859)

| [A](https://codeforces.com/contest/1859/problem/A) | [United We Stand](https://codeforces.com/contest/1859/problem/A) |
| -------------------------------------------------- | ------------------------------------------------------------ |
| [B](https://codeforces.com/contest/1859/problem/B) | [Olya and Game with Arrays](https://codeforces.com/contest/1859/problem/B) |
| [C](https://codeforces.com/contest/1859/problem/C) | [Another Permutation Problem](https://codeforces.com/contest/1859/problem/C) |
| [D](https://codeforces.com/contest/1859/problem/D) | [Andrey and Escape from Capygrad](https://codeforces.com/contest/1859/problem/D) |
| [E](https://codeforces.com/contest/1859/problem/E) | [Maximum Monogonosity](https://codeforces.com/contest/1859/problem/E) |
| [F](https://codeforces.com/contest/1859/problem/F) | [Teleportation in Byteland](https://codeforces.com/contest/1859/problem/F) |

开学的第一份题解，暑假一直摆烂，根本没写题，感觉这场比赛的难度不是很大，$E$的难度可能没有$2500$

### [A](https://codeforces.com/contest/1859/problem/A)  [United We Stand](https://codeforces.com/contest/1859/problem/A)

题意: 

给你一个数组a,分成两个数组b,c.

要求:

-   b,c非空
-   任意一个c数组的元素不是b数组的因数

思路:

首先能想到一点,如果a数组的元素全部相同,那么一定是不存在分法的应该输出-1

其次,要满足c数组的元素不是b的因数,我们可以令b数组存储较小的所有元素,c数组存储较大的一个元素



```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(a.begin(), a.end());
    std::vector<int> b(n, a[n - 1]);
    if (b == a)
        std::cout << -1 << '\n';
    else
    {
        std::vector<int> b;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[n - 1])
                b.push_back(a[i]);
        }
        std::vector<int> c(n - b.size(), a[n - 1]);
        std::cout << b.size() << ' ' << c.size() << '\n';
        for (auto x : b)
            std::cout << x << ' ';
        std::cout << '\n';
        for (auto x : c)
            std::cout << x << ' ';
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



### [B](https://codeforces.com/contest/1859/problem/B)  [Olya and Game with Arrays](https://codeforces.com/contest/1859/problem/B)

题意:

多组测试数据,每组测试数据给你一个数n,代表有n个大的集合,之后在告诉你每个小的集合的元素个数以及集合元素.现在执行一种操作,每个集合移出一个元素到另一个集合,这种操作每个集合只能进行一次,且在同一时间内完成的.问你操作后,$ \sum_{i=1}^n \min_{j=1}^{m_i} a_{i,j} $的最大值.

思路:

贪心的想,要使得每个小集合的最小值之和最大,那么每个小集合的最小值要尽可能的大.那么每次操作,我们可以移出当前这个集合中的最小值,此时的集合的最小值为原来的次小值,可以发现,次小值对ans有着贡献,那么我们把所有的最小值都移到次小值最小的那个集合中去,得到的结果一定是最大的

.$ans = min + n个次小值 - 最小的次小值$

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    i64 minn = 1e18, sum = 0, smin = 1e18;
    std::vector<i64> a[n];
    for (int i = 0; i < n; i++)
    {
        int m;
        std::cin >> m;
        while(m--)
        {
            int x;
            std::cin >> x;
            a[i].push_back(x);
        }
        std::sort(a[i].begin(), a[i].end());
        minn = std::min(minn, a[i][0]);
        smin = std::min(smin, a[i][1]);
        sum += a[i][1];
    }
    std::cout << sum + minn - smin << '\n';
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



### [C](https://codeforces.com/contest/1859/problem/C)  [Another Permutation Problem](https://codeforces.com/contest/1859/problem/C)

题意: 

问你一个长度为n的排列,$(\sum_{i = 1}^{n} p_i \cdot i) - (\max_{j = 1}^{n} p_j \cdot j)$的最大值是多少

思路:

显然,正序排列的ans比逆序大,最优解可能为正序然后翻转尾部的几个数字

那就枚举翻转的长度,根据题意模拟

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::iota(a.begin(), a.end(), 1);

    i64 ans = 0;
    for (int len = 1; len <= n; len++)
    {
        i64 res = 0, tmp = 0;
        for (int i = 0; i < n - len; i++)
            res += a[i] * (i + 1), tmp = std::max(tmp, 1LL * a[i] * (i + 1));
        for (int i = n - len, j = n; i < n; i++, j--)
            res += a[i] * j, tmp = std::max(tmp, 1LL * a[i] * j);
        res -= tmp;
        ans = std::max(ans, res);
    }
    std::cout << ans << '\n';
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

### [D](https://codeforces.com/contest/1859/problem/D)  [Andrey and Escape from Capygrad](https://codeforces.com/contest/1859/problem/D)

题意:

给你n个区间$[l,r]$,对于每个区间内的点,可以跳到$[a,b],(l <= a <= b <= r)$的任意位置.

现在有q个位置问你每个位置最远可以跳到的坐标

>    第一眼看上去要区间合并

思路:

这边只考虑一段区间的情况,对于$[l,r],x$,是其中的一个点,如果$x$在$[l,b]$之间,那么$x$最远可以跳到$b$.若$x$在$(b,r]$之间,那么,最远就是$x$.那么对于每条线段,$[l,b]$是我们的有效区间

>目标是最远,要往后跳不是往前跳

那么可以进行区间合并操作,之后对于每个$x$二分查找左端点最靠近x$的线段,这条线段的右端点就是我们的$ans$



```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> segs(n);
    for (int i = 0; i < n; i++)
    {
        int l, r, a, b;
        std::cin >> l >> r >> a >> b;
        segs[i] = {l, b};
    }

    std::sort(segs.begin(), segs.end());
    int st = -1e9, ed = -1e9;
    std::vector<std::pair<int, int>> tmp;
    for (auto [x, y] : segs)
    {
        if (ed < x)
        {
            if (st != -1e9)
                tmp.push_back({st, ed});
            st = x, ed = y;
        }
        else
            ed = std::max(ed, y);
    }
    if (st != -1e9)
        tmp.push_back({st, ed});
    segs = tmp; // 区间合并

    int x;
    auto check = [&](int mid)
    {
        if (segs[mid].first <= x)
            return true;
        else
            return false;
    }; // 二分的check函数

    int q;
    std::cin >> q;
    while (q--)
    {
        std::cin >> x;

        int l = 0, r = segs.size() - 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        if (segs[l].first <= x && x <= segs[l].second)
            std::cout << segs[l].second << ' ';
        else
            std::cout << x << ' ';
    }
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

### [E](https://codeforces.com/contest/1859/problem/E)  [Maximum Monogonosity](https://codeforces.com/contest/1859/problem/E)

题意:

给定两个数组$a, b$,定义一段线段$[l,r]$的花费$|b_l - a_r| + |b_r - a_l|$

同时, 若两线段$[l,r]$ 满足$r_1 < l_2$ or $r_2 < l_1$那么我们称他们不相交

问长度为$k$的不相交线段的最大花费和

思路:

感觉是一个动态规划问题,$n<=3000$,时间复杂度可能是$n^2$级别的

$dp[i,j]$表示从前$i$个中选,且线段长度为$j$的花费之和

第$i$个不选,$dp[i,j] = dp[i-1, j]$

第$i$个选, 假定现在枚举的长度为$k$即从$i$位置开始,向前延伸长度为$k$的线段,$dp[i, j] = dp[i-k, j-k] +  cost(i - k, i)$;

>   还有另一个想法
>
>   第$i$个选,假定现在枚举的左端点为$l,dp[i,j]=dp[l][j -i + l - 1] + cost(l, i)$

状态转移方程:

$dp[i,j] = max(dp[i-1,j], max_{l=1}^jdp[i-l,j-l] + cost(i-l+1, i))$

时间复杂度为$O(n^2k)$,会$TLE$,得想办法优化到$O(nk)$



对$cost(i-l+1, i)$进行处理,$cost =|b_{i-l+1} - a_i| + |b_i - a_{i-l+1}|$

去绝对值, $cost = max(b_{i-l+1}-a_i, a_i - b_{i-l+1})+max(b_i-a_{i-l+1}, a_{i-l+1}-b_i)$

展开会有$4$种组合方式,

1.   $cost = b_{i-l+1}-a_i + b_i-a_{i-l+1} = -a_{i-l+1} +b_{i-l+1} - a_i +b_i$;
2.   $cost = b_{i-l+1}-a_i + a_{i-l+1}-b_i = a_{i-l+1} + b_{i-l+1} -a_i - b_i$;
3.   $cost = a_i - b_{i-l+1} + b_i-a_{i-l+1} = - a_{i-l+1}-b_{i-l+1} +a_i+b_i$;
4.   $cost = a_i - b_{i-l+1} + a_{i-l+1}-b_i=a_{i-l+1}-b_{i-l+1}+a_i-b_i$;

可以发现,下标为$i-l+1$的元素不是固定的,并且和前面$dp$的下标相同,可以合并,而下标为$i$的元素是固定的可以把$a_i,b_i$单独计算

下面以其中一个为例:

$dp[i,j] = max(dp[i-1,j], max_{l=1}^jdp[i-l,j-l] + a_{i-l+1}-b_{i-l+1}+a_i-b_i) \quad \\ = max(dp[i-1, j], max(dp[i-l][j-l] + a[i-l] - b[i-l]) + c)$

考虑$dp[i-k,j-k]$

>$y-(j-k)=x-(i-k)$ 
>
>$y-j=x-i$
>
>$y=x+j-i$

在所有$i-j$相同的状态上重复计算

定义一个新的数组$f[i-j][4]$记录$dp[i-k,j-k]+a_{i-k+1}+b_{i-k+1}$等的最大值



```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<i64> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    for (int i = 1; i <= n; i++)
        std::cin >> b[i];

    std::vector dp(n + 1, std::vector<i64>(k + 1));
    std::vector f(n + 1, std::vector<i64>(4, -0x3f3f3f3f3f3f3f3f));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i && j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            f[i - j][0] = std::max(f[i - j][0], dp[i - 1][j - 1] + a[i] + b[i]);
            f[i - j][1] = std::max(f[i - j][1], dp[i - 1][j - 1] + a[i] - b[i]);
            f[i - j][2] = std::max(f[i - j][2], dp[i - 1][j - 1] - a[i] + b[i]);
            f[i - j][3] = std::max(f[i - j][3], dp[i - 1][j - 1] - a[i] - b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][0] - a[i] - b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][1] + a[i] - b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][2] - a[i] + b[i]);
            dp[i][j] = std::max(dp[i][j], f[i - j][3] + a[i] + b[i]);
        }
    }
    std::cout << dp[n][k] << '\n';
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

