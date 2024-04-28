### [A - A+B?](https://codeforces.com/contest/1772/problem/A)

跳过，不说了

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b;
    scanf("%d+%d", &a, &b);
    std::cout << a + b << '\n';
}

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
```



### [B - Matrix Rotation](https://codeforces.com/contest/1772/problem/B)

题意：

给你一个$2 * 2$ 的矩阵，问经过变换后是否满足一个性质 

>-   in each row, the first element is smaller than the second element;
>-   in each column, the first element is smaller than the second element.
>-   每行第一个元素小于第二个元素，每列第一个元素小于第二个元素

思路：

a   b      -->     c   a  -->    d    c    -->   b   d

c   d                d   b          b    a           a    c

模拟一下变换过程，可以发现要满足这个性质，a   b   和  c  d  同号 并且   a  c  和  b  d  同号

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if ((a - b) * (c - d) > 0 && (a - c) * (b - d) > 0)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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



### [ C - Different Differences](https://codeforces.com/contest/1772/problem/C)

题意：

你给k，n

请你构造一个k个数的严格递增数列， 使得这个数组中相邻两个元素的不同差的数量最多且，每个元素不得超过n

思路：

首先，要使得差不同，肯定会想到 $1 、2、 4、 7、 11....$这样构造，但是这个有不超过$n$的限制，所以我们也可以取一个min 

$a[i] = std::min(a[i - 1] + i - 1, n - k + 1)$; 这里为什么取n - k + 1, 看下一步就会明白。然后对$a[i]$ 每个数都加上一个$i$, 后面取值为$n - k + 1$的数就会变成一个连续的数列，同时最大值为n，满足题目要求



```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int k, n;
    std::cin >> k >> n;

    std::vector<int> a(k);
    a[0] = 1;
    for (int i = 1; i < k; i++)
        a[i] = std::min(a[i - 1] + i - 1, n - k + 1);
    for (int i = 0; i < k; i++)
        a[i] += i;

    for (int i = 0; i < k; i++)
        std::cout << a[i] << " \n"[i == k - 1];
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



### [D - Absolute Sorting](https://codeforces.com/contest/1772/problem/D)

````c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int l = 0, r = 1e9;
    for (int i = 0; i < n - 1; i++)
    {
        int x = a[i], y = a[i + 1];
        if (x < y)
            r = std::min(r, (x + y) >> 1);
        if (x > y)
            l = std::max(l, (x + y + 1) >> 1);
    }

    if (l <= r)
        std::cout << l << '\n';
    else
        std::cout << -1 << '\n';
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
````



### [E - Permutation Game](https://codeforces.com/contest/1772/problem/E)

题意：

给定一个排列，初始都为红色，两个人$a, b$玩游戏，有3个操作

$1.$选择一个数，染成蓝色

$2.$选择蓝色的数，排序

$3.$ 跳过

若最后排列递增则$a$赢，递减$b$赢，否则平局。问最后的结果如何

思路：

对于$a$来说，如果$a[i] == i$ 那么这个不需要染成蓝色，而对于$b$来说，这个位置要染成蓝色

 对于$b$来说，如果$a[i]  ==  n - i + 1 $ 那么这个不需要染成蓝色，而对于$a$来说，这个位置要染成蓝色

如果$a[i]$即不等于$i 也不等于 n - i + 1$两个人都要染色

所以$winner$一定是染色次数少的

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int a = 0, b = 0, c = 0;
    for (int i = 1, x; i <= n; i++)
    {
        std::cin >> x;
        if (x == i)
            a++;
        else if (x == n - i + 1)
            b++;
        else
            c++;
    }

    if (b + c <= a)
        std::cout << "First\n";
    else if (a + c < b)
        std::cout << "Second\n";
    else
        std::cout << "Tie\n";
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



### [F - Copy of a Copy of a Copy](https://codeforces.com/contest/1772/problem/F)

题意：给$n, m, k$   对应$ k + 1 幅 n * m$ 的土图片，

两种操作：

$1.$ 把四周字符不同的的字符翻转

$2.$ 复制

问你最初的图片是哪一幅，且是经过怎样的变换最后变成输入的图

思路：

先统计每一幅图片可以进行变换的次数，第一幅图片一定是可以进行变换次数最多的图，排序一下，就可以确定图片变化的顺序，这里经过了排序，所以要存储下排序后图片的原序号，我这边是使用了$pair$类型来存储；

用一个二维的vector存储操作

然后遍历每个图，如果图片的  $i, j$  位置与上一幅不同，说明这个点进行了翻转，向$vector$中存入$(i, j)$ 一幅图遍历结束之后，一定要复制一遍



```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector s(k + 1, std::vector<std::string>(n));
    for (int i = 0; i < k + 1; i++)
        for (int j = 0; j < n; j++)
            std::cin >> s[i][j];

    std::vector<std::pair<int, int>> f(k + 1);
    for (int i = 0; i < k + 1; i++)
        for (int j = 1; j < n - 1; j++)
            for (int k = 1; k < m - 1; k++)
                if (s[i][j][k] != s[i][j][k - 1] && s[i][j][k] != s[i][j][k + 1] && s[i][j][k] != s[i][j - 1][k] && s[i][j][k] != s[i][j + 1][k])
                    f[i].first++;

    for (int i = 0; i < k + 1; i++)
        f[i].second = i;
    std::sort(f.begin(), f.end(), std::greater<>());
    std::cout << f[0].second + 1 << '\n';

    std::vector<std::vector<int>> res;
    for (int i = 1; i < k + 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
            for (int k = 1; k < m - 1; k++)
                if (s[f[i].second][j][k] != s[f[i - 1].second][j][k])
                    res.push_back({1, j + 1, k + 1});
        res.push_back({2, f[i].second + 1});
    }

    std::cout << res.size() << '\n';
    for (auto x : res)
        for (int i = 0; i < x.size(); i++)
            std::cout << x[i] << " \n"[i == x.size() - 1];
    return 0;
}
```



 ### [G - Gaining Rating](https://codeforces.com/contest/1772/problem/G)

这个题我是看ygg的题解做的，觉得大佬讲得非常好。[https://zhuanlan.zhihu.com/p/592799038];

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    i64 n, x, y;
    std::cin >> n >> x >> y;

    std::vector<i64> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a.begin(), a.end());

    i64 change = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= x)
            b[i] = 1, x++, change++, ans++;
        else
            b[i] = -1, x--, change--, ans++;
        if (x >= y)
        {
            std::cout << ans << '\n';
            return;
        }
    }

    if (change <= 0)
    {
        std::cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {

        if (b[i] == -1)
        {
            i64 k = ceil((a[i] - i - x) * 1.0 / change);
            i64 t = ceil((y - i - x) * 1.0 / change);

            if (t <= k)
            {
                ans += t * n;
                x += t * change;

                for (int j = 0; j < n; j++)
                {
                    ans++;
                    if (a[j] <= x)
                        x++;
                    else
                        x--;
                    if (x >= y)
                    {
                        std::cout << ans << '\n';
                        return;
                    }
                }
            }

            ans += k * n;
            x += k * change;
            change += 2;
        }
    }
    std::cout << ans + y - x << '\n';
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



