#! https://zhuanlan.zhihu.com/p/655386452
## Codeforces Round 125 (Div. 2)

### [A. Hexadecimal's theorem](https://www.luogu.com.cn/problem/CF199A)

题意:
给你一个数$n$,将这个数拆成3个斐波那契数

易知, $0 \quad 0 \quad n$ 满足题意

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cout << 0 << ' ' << 0 << ' ' << n << '\n';

    return 0;
}
```



### [B. Special Olympics](https://www.luogu.com.cn/problem/CF199B)

题意:

在一个平面有两个圆,问沿着黑色的轮廓可以找到几个圆

思路:

可以发现,同一个圆的两个环不会相互影响,就考虑其中一个环与另外一个圆的两个环的影响

两个圆的位置关系有这几种

-   相离: $r1 +r2 < d$
-   相切:$r1 + r2 = d(外切)$ $r1 - r2 = d(内切)$
-   相交:$r1 + r2 > d$

这边,如果$r$与$R1$相离或相切,必定有一个圆, ` if (R2 + r1 <= dis || r2 - r1 >= dis || r1 - R2 >= dis)`用这条语句判断即可

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x1, y1, r1, R1;
    int x2, y2, r2, R2;
    std::cin >> x1 >> y1 >> r1 >> R1;
    std::cin >> x2 >> y2 >> r2 >> R2;

    double dis = std::sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    auto check = [&](int r1, int r2, int R2)
    {
        if (R2 + r1 <= dis || r2 - r1 >= dis || r1 - R2 >= dis)
            return true;
        else
            return false;
    };

    int res = 0;
    res += check(r1, r2, R2);
    res += check(R1, r2, R2);
    res += check(r2, r1, R1);
    res += check(R2, r1, R1);
    std::cout << res << '\n';
    return 0;
}
```



### [C. About Bacteria](https://www.luogu.com.cn/problem/CF199C)

题意:

第一次实验,一个细菌每过一秒会变成$k+b$个细菌,经过$n$秒,恰好有$z$个细菌

第二次实验放入$t$个细菌,问经过多少秒,细菌的数量至少有$z$个

思路:

第一想法是数学做法

第一次实验,$k^n +k^{n-1}b +...+ kb + b = z$

设经过$x$秒,数量达到$z$

第二次实验,经过$x$秒达到的细菌数$tk^x + k^{x-1}b + ... +kb + b$

$tk^x + k^{x-1}b + ... +kb + b >= k^n +k^{n-1}b +...+ kb + b$

$tk^x >= k^n + k^{n-1}b + ...+ k^xb$

$t >= k^{n-x} + k^{n-1-x}b + ...+ b$

令$s = k^{n-1-x}b + ... + b$

运用等比数列求和公式:

$s = \frac{(k^{n-1-x}-1) * b}{k - 1}$

$t >= k^{n-x} +  \frac{(k^{n-1-x}-1) * b}{k - 1}$

$(k-1)t >= k^{n-x}(k-1) + (k^{n-1-x}-1) *b = k^{n-x}(k-1 + \frac{b}{k}) -b$

$(k-1)t +b >= k^{n-x}(k-1 + \frac{b}{k})$

$\frac{k(k-1)t +kb}{k^2-k+b} >= k^{n-x}$

$ln(\frac{k(k-1)t +kb}{k^2-k+b}) >= (n-x)lnk$

$\frac{ln(\frac{k(k-1)t +kb}{k^2-k+b})}{lnk} >= n - x$

$x >= n - \frac{ln(\frac{k(k-1)t +kb}{k^2-k+b})}{lnk}$

$x >= n + \frac{ln(\frac{1 + \frac{b}{k-1}}{t + \frac{b}{k-1}})}{lnk}$

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    double k, b, n, t;
    std::cin >> k >> b >> n >> t;

    if (k > 1)
    {
        b /= k - 1;
        std::cout << std::max(0, (int)std::ceil(std::log((1 + b) / (t + b)) / std::log(k)) + (int)n) << '\n';
    }
    else
        std::cout << std::max(0, (int)n - (int)floor((t - 1) / b)) << '\n';

    return 0;
}
```

另外简单的一种思路

考虑从1个细菌到t个细菌的用时

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int k, b, n, t;
    std::cin >> k >> b >> n >> t;

    i64 ans = 1, time = 0;
    while (time <= n && ans <= t)
    {
        ans = ans * k + b;
        time++;
    }
    std::cout << n - time + 1 << '\n';  
    return 0;
}
```





### [D. Jumping on Walls](https://www.luogu.com.cn/problem/CF199D)

题意:

峡谷高为$n$, 人从$1$开始每秒有三种操作:

-   向上跳一格
-   向下跳一格
-   跳到对面比自己当前高$k$的地方, 当前为$x$, 跳过之后为$x + k$

最初,人位于左侧下方区域

如果存在一个时间点,这个人跳的高度大于$n$,表明他能离开峡谷

峡谷的水最初位于第一个区域的下边界.人不能在水中.人先跳后,水会上涨一个单位

思路:

bfs求最短路

起点位置$(0, 1, 0) ---$左边/右边, 当前坐标, 水的坐标

能跳的条件: 目标格子无障碍, 人不在水中

-   `s[id][high + 1] != 'X' && high + 1 > water + 1`

-   >   第一种跳法

-   `high - 1 > 0 && s[ i ][high - 1] != 'X' && high - 1 > water + 1`

-   `s[1 - id][high + k] != 'X' && high + k > water + 1`

此处还有一个优化的技巧,`s[id][high + 1] = 'X';`将目标点标记,防止走重复的路径

```c++
#include <bits/stdc++.h>

using i64 = long long;
struct node
{
    int i, high, water;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::string s[2];
    std::cin >> s[0] >> s[1];
    s[0] = ' ' + s[0];
    s[1] = ' ' + s[1];
    auto bfs = [&]()
    {
        std::queue<node> q;
        q.push({0, 1, 0});
        s[0][1] = 'X';
        while (q.size())
        {
            auto [id, high, water] = q.front();
            q.pop();

            if (high + 1 > n)
                return true;

            if (s[id][high + 1] != 'X' && high + 1 > water + 1)
            {
                s[id][high + 1] = 'X';
                q.push({id, high + 1, water + 1});
            }

            if (high - 1 > 0 && s [id][high - 1] != 'X' && high - 1 > water + 1)
            {
                s[id][high - 1] = 'X';
                q.push({id, high - 1, water + 1});
            }

            if (high + k > n)
                return true;
            if (s[1 - id][high + k] != 'X' && high + k > water + 1)
            {
                s[1 - id][high + k] = 'X';
                q.push({1 - id, high + k, water + 1});
            }
        }
        return false;
    };

    std::cout << (bfs() ? "YES\n" : "NO\n");

    return 0;
}
```



### [E. Delivering Carcinogen](https://www.luogu.com.cn/problem/CF199E)

题意:

一个点在离原点为$R$的圆周上以速度$v_p$运动,开始坐标$(x_p, y_p)$,另一个点在离原点半径为$r$的圆周上以速度为$v$运动开始坐标为$(x,y)$

问相遇的最短时间

```
```

