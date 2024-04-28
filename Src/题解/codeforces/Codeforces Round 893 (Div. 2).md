### [A. Buttons](https://www.luogu.com.cn/problem/CF1858A)

看$ab$谁实际可以操作的次数多

优先选择按$c$按钮，而$a$是先手，若$c$是奇数，$a$可按$（c + 1)/2$次，$b$只能$c/2$次；若$c$是偶数，则皆为$c/2$次

```c
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    a = std::ceil(c * 1.0 / 2) + a;
    b = c / 2 + b;
    if(a > b)
        std::cout << "First\n";
    else
        std::cout << "Second\n";
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

### [B. The Walkway](https://www.luogu.com.cn/problem/CF1858B)

题意:n个摊位有m个卖饼干的人,分别位于s[i],一个人从1出发，每分钟走一个摊位

如果他还没有吃过饼干，他会立刻吃一个；

如果这个摊位有卖饼干的人，吃一个；

如果距上次吃饼干已经d分钟了，吃一个；

>   在同一个摊位最多吃1 个饼干113

问删除一个卖饼干的人，最少的吃到的饼干数量以及方案数

思路：

首先考虑不删除人时，能吃到的饼干数

m个卖饼干的商人将线段分成了m+1段

从$s[i], 走到s[i+1]（不计s[i+1]处的饼干）, 能吃到$ $(s[i + 1] - s[i] - 1) / d$块饼干

由于在第一个摊位可以直接吃饼干，这边令`s[0] = 1 - d`作为起点，`s[m + 1] = n + 1`作为终点

这部分代码如下所示

```c
    int sum = 0;
    for (int i = 1; i <= m + 1; i++)
        sum += (s[i] - s[i - 1] - 1) / d;
```

通过枚举m个商人，计算删去当前商人，最后所能吃到的饼干数

删除第i个商人，少吃的饼干数有 $[s[i - 1],\quad s[i]) \quad [s[i], \quad  s[i + 1])$, 现在能吃的是$[s[i - 1], s[i + 1])$，同时还有剩余$m - 1$个摊位

```c
    for (int i = 1; i <= m; i++)
    {
        int tmp = sum;
        tmp -= (s[i] - s[i - 1] - 1) / d; 
        tmp -= (s[i + 1] - s[i] - 1) / d;
        tmp += (s[i + 1] - s[i - 1] - 1) / d;
        tmp += m - 1;
        // 更新答案
        if (tmp < res)
            res = tmp, cnt = 1; 
        else if (tmp == res)
            cnt++; 
    }
```



```c
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m, d;
    std::cin >> n >> m >> d;

    std::vector<int> s(m + 2);
    for (int i = 1; i <= m; i++)
        std::cin >> s[i];
    s[0] = 1 - d, s[m + 1] = n + 1;

    int sum = 0;
    for (int i = 1; i <= m + 1; i++)
        sum += (s[i] - s[i - 1] - 1) / d;

    int res = 1e9, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int tmp = sum;
        tmp -= (s[i] - s[i - 1] - 1) / d;
        tmp -= (s[i + 1] - s[i] - 1) / d;
        tmp += (s[i + 1] - s[i - 1] - 1) / d;
        tmp += m - 1;
        if (tmp < res)
            res = tmp, cnt = 1;
        else if (tmp == res)
            cnt++;
    }
    std::cout << res << ' ' << cnt << '\n';
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



### [C. Yet Another Permutation Problem](https://www.luogu.com.cn/problem/CF1858C)

题意:

构造一个排列,使得相邻两个元素的gcd的种类最多

```
1 2
1 2 3
1 2 4 3
1 2 4 3 6
...
1 2 4 8 3 6 (9) 12 5 10 7 (9) 11
到上面这行,我们可以发现9的位置放6后和7后对gcd的个数是没有影响的， 猜想： a[i] a[i]*2....
```

最优解即*2

```c
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<bool> vis(n + 1);
    std::vector<int> res;
    res.push_back(1);
    vis[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (vis[i])
            continue;
        for (int j = i; j <= n; j <<= 1)
        {
            if (vis[j])
                continue;
            else
            {
                res.push_back(j);
                vis[j] = true;
            }
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << res[i] << " \n"[i == n - 1];
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

### [D. Trees and Segments](https://www.luogu.com.cn/problem/CF1858D)

题意：

要种植$n$棵树，  用长度为$n$的01串表示

定义$l_0$为最长0串的长度.  $l_1$为最长1串的长度,  $美丽程度 = a * l_0 + l_1(a \in [1,n] )$

问对于每个$a \in [1, n]$,翻转不超过$k$个位置,美丽程度的最大值

数据范围$n <= 3000$, 时间复杂度可能是$n^2$



