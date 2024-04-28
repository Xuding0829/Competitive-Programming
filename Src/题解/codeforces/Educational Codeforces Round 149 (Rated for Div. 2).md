#! https://zhuanlan.zhihu.com/p/632376681



### A. Grasshopper on a Line

判断 x % k 是否为零即可

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int x, k;
    std::cin >> x >> k;

    if (x % k)
    {
        std::cout << 1 << '\n';
        std::cout << x << '\n';
    }
    else
    {
        std::cout << 2 << '\n';
        std::cout << 1 << ' ' << x - 1 << '\n';
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



### B. Comparison String

最长连续相同字串的长度的

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int res = 1, tmp = 1;
    for (int i = 1; i < n; i++)
    {
        if(s[i] == s[i - 1])
            tmp++, res = std::max(res, tmp);
        else
            tmp = 1;
    }
    std::cout << res + 1 << '\n';
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



### C. Best Binary String

>Let's define the *cost* of the binary string as the minimum number of operations of the form "reverse an arbitrary contiguous substring of the string" required to sort the string in non-descending order.

~~赛中好难读~~，蒟蒻流泪

>让我们将二进制字符串的“成本”定义为以非降序排序字符串所需的“反转字符串的任意连续子字符串”形式的最小操作次数。

$0后为0，1后为1$ 保证最少操作次数 

````c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '?' && s[i - 1] == '0')
            s[i] = '0';
        else if (s[i] == '?' && s[i - 1] == '1')
            s[i] = '1';
        else if (!i && s[i] == '?')
            s[i] = '0';
    }
    std::cout << s << '\n';
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



### [D - Bracket Coloring](https://codeforces.com/contest/1837/problem/D)

不存在：()不能相匹配 某个符号多了

存在:  记录( & ) 分别出现的位置,然后遍历匹配



```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
    }

    if (cnt)
    {
        std::cout << -1 << '\n';
        return;
    }

    std::vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            a.push_back(i);
        else
            b.push_back(i);
    }

    std::vector<int> res(n, 2);
    for (int i = 0; i < n / 2; i++)
    {
        if (a[i] < b[i])
            res[a[i]] = res[b[i]] = 1;
        else
            res[a[i]] = res[b[i]] = 2;
    }

    if (*std::min_element(res.begin(), res.end()) == 2)
        std::fill(res.begin(), res.end(), 1);

    std::cout << *std::max_element(res.begin(), res.end()) << '\n';
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



### E. Playoff Fixing

题意：

给定一个整数k，一共有 $2^k$个队伍， 每个队伍对应编号$1...2^k$, 编号越小能力越强

要求每轮中$1.....2^{i- 1}$胜出， $2^{i -1}+ 1......2^i$被淘汰 

问有多少种组合方式 

如$k = 3$时， $0-3$在第一轮中要求胜出， $3 - 7$ 要求淘汰；第二轮 淘汰$3、4$最后一轮淘汰$2$

思路：

设队伍为 $s[i]$

考虑相邻的两个队伍为$s[i], s[i + 1]$ ，则$s[i], s[i + 1]$中，必须有一个是$0-3$, 另一个必须是$4-7$

如果$s[i] = -1, s[i + 1] = -1$  那么$4- 7$中间的数可以放在其中任何一个位置

如果一个位置是$-1$， 另一个为$4-7$，那么$-1$的位置放$0-3$可以淘汰

如果一个位置是$-1$， 另一个为$0-3$，那么$-1$的位置放$4-7$也可以满足题意

而，当这两个位置都是$0-3$或者都是$4-7$的数时， 无解

这里假设每轮淘汰的人数为$x$, 位置为$-1$的对数有$y$对，那么这一轮的$ans = x! * 2 ^{y}$;

>以下解释ans的由来
>
>淘汰的人分入不同的组，即将$x$个人排序，一共有$x!$种不同的排序方式；
>
>对于位置为$-1$的数，交换小组中的左右两个数也是一种新的方式，有$y$组， 一共有$2^y$种方式；
>
>由乘法原理知，每轮中总方案有$x!*2^y$种。

```c++
 
```

