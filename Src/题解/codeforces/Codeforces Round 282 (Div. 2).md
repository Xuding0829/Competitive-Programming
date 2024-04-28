#! https://zhuanlan.zhihu.com/p/655166066
## [Codeforces Round 282 (Div. 2)](https://codeforces.com/contest/495)

### [A. Digital Counter](https://www.luogu.com.cn/problem/CF495A)

题意:

数字显示有一根木棍坏了,给你一个显示的数,问这个实际的数有多少种可能

```c
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    std::map<int, int> mp;
    mp[0] = 2, mp[1] = 7, mp[2] = 2, mp[3] = 3, mp[4] = 3;
    mp[5] = 4, mp[6] = 2, mp[7] = 5, mp[8] = 1, mp[9] = 2;
    std::cout << mp[s[0] - '0'] * mp[s[1] - '0'] << '\n';

    return 0;
}
```



### [B. Modular Equations](https://www.luogu.com.cn/problem/CF495B)

题意:

给你$a,b$,问你有多少个$x$满足$a \quad mod \quad x = b$

不难发现

$a < b$,无解

$a = b$,此时有无穷个$x$

$a > b$,

$a \quad mod  \quad x = b \quad <=> \quad  a - x - x -...-x =b$

假设这边有$n$个$x, n * x = a-b$, 那么,$x$必然是$a-b$的因数

因此,枚举$a-b$的因数,统计大于$b$的因数个数

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;

    if (a == b)
    {
        std::cout << "infinity\n";
    }
    else if (a < b)
    {
        std::cout << "0\n";
    }
    else
    {
        int res = 0;
        int d = a - b;

        for (int i = 1; i <= d / i; i++)
        {
            if (d % i == 0)
            {
                if (i > b)
                    res++;
                if (d / i > b && d / i != i)
                    res++;
            }
        }
        std::cout << res << '\n';
    }

    return 0;
}
```



### [C. Treasure](https://www.luogu.com.cn/problem/CF495C)

题意:

给你一个由 ( , ) , # 组成的字符串,用1个或者多个)替换#,使得最后的`string`美丽

>对于每个位置#$i$,, $1...i$中  (  的数量大于等于  )  的数量
>
>总的  ( 的数量和  )  的数量相等  

输出每个 # 替换多少个  )  

思路:

首先要满足第一个条件,显然,把前面的  # 换成一个 ) 能够保证 (  数量大于  )

>   当然,如果已有的  )  多于  (  那么就无解
>
>   注意:
>
>   这边有个坑点,存在错位的情况  ( # ) (  这也是无解

之后,再把最后一个 # 换成 若干个 ) 使得 (  的总数 = )  的总数  


```c
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s;
    std::cin >> s;

    int a = 0, k = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            a++;
        else if (s[i] == ')')
            a--;
        else
            a--, k++;
        if (a < 0)
        {
            std::cout << "-1\n";
            return 0;
        }
    }

    int p = 0, c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            p++;
        else if (s[i] == ')')
            p--;
        else
        {
            c++;
            if (c == k)
                p -= a;
            p--;
        }
        if (p < 0)
        {
            std::cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < k - 1; i++)
        std::cout << "1\n";
    std::cout << a + 1 << '\n';

    return 0;
}
```



### [D. Obsessive String](https://www.luogu.com.cn/problem/CF495D)

题意:

给你两个字符串 $s, t$, 问 有多少种方法在 $s$中提取非重子串,且每个子串都包含$t$

解释第三个样例:

```c
ddd
下面用123表示各个位置的d
d

选择方案:
K=1 : 1; 2; 3; 12; 23; 123; ---6种
K=2 : 1, 2; 1, 3; 2, 3; 1, 23; 12, 3; ---5种
K=3 : 1, 2, 3; ---1种
```

思路:

毫无思路,只能看大佬的题解

$dp[i]$表示,以$i$结尾的方案数

假设当前我们走到了$i$,我们就需要从$i$开始从右往左匹配$T$,找到第一个能匹配的位置$pos$,那么$[i-m+1, i]与t$完全匹配,且左端点在$[1,i-m+1]$的字符串都能找到$T$

$ans= \sum_{i=1}^n dp[i]$

如果此时有两个子串,那么第二个子串的起点$[2, i-m+1]$,设这个起点为$j$,第一个子串的终点$[1,j-1]$

朴素$O(n^3)$代码如下:

```c
for(int i = 1; i <= n; i++)
{
	if(!pos[i])
		dp[i] = dp[i - 1];
	for(int j = 1; j <= i - m + 1; j++)
	{	
		dp[i]++;
		for(int k = 1; k <= j - 1; k++)
			dp[i] = (dp[i] + dp[k]) % mod;
	}
}
```

而题目所给$|s| \leqslant 1e5$,显然不满足题意要求,得想办法将时间复杂度优化到$O(n)$

然后我们可以发现`dp[i]++; `  和  `dp[i] = (dp[i] + dp[k]) % mod;`就可以用前缀和数组来优化

```c
for(int i = 1; i <= n; i++)
{
	if(!pos[i])
		dp[i] = dp[i - 1];
	for(int j = 1; j <= i - m + 1; j++)
	{	
		dp[i] = (dp[i] + sum1[j - 1] + 1) % mod;
		sum1[i] = (sum[i-1] + dp[i]) % mod;
	}
}
```

$优化为O(n^2)时间复杂度,然后依然可以使用前缀和数组继续优化$

```c
for(int i = 1; i <= n; i++)
{
	if(!pos[i])
		dp[i] = dp[i - 1];
    else 
		dp[i] = (sum2[i - m] + i - m + 1) % mod;
    sum1[i] = (sum1[i - 1] + dp[i]) % mod;
   	sum2[i] = (sum2[i - 1] + sum1[i]) %mod;
}
```



完整代码:

```c++
#include <bits/stdc++.h>

using i64 = long long;
constexpr i64 base = 233;
constexpr i64 mod = 1e9 + 7;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s, t;
    std::cin >> s >> t;

    s = " " + s, t = " " + t;

    int n = s.size() - 1, m = t.size() - 1;
    std::vector<i64> pow(n + 1), f(n + 1);
    pow[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * base + s[i] - 'a' + 1;
        pow[i] = pow[i - 1] * base;
    }

    i64 Hash = 0;
    for (int i = 1; i <= m; i++)
        Hash = Hash * base + t[i] - 'a' + 1;

    auto get = [&](int l, int r)
    {
        return (f[r] - f[l - 1] * pow[r - l + 1]);
    };

    std::vector<i64> pos(n + 1);
    for (int i = m; i <= n; i++)
    {
        if (get(i - m + 1, i) == Hash)
            pos[i] = 1;
    }

    std::vector<i64> dp(n + 1), sum1(n + 1), sum2(n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (!pos[i])
            dp[i] = dp[i - 1];
        else
            dp[i] = (sum2[i - m] + i - m + 1) % mod;
        sum1[i] = (sum1[i - 1] + dp[i]) % mod;
        sum2[i] = (sum2[i - 1] + sum1[i]) % mod;
    }
    std::cout << sum1[n] << '\n';
    return 0;
}
```



### [E. Helping People](https://www.luogu.com.cn/problem/CF495E)

题意:



```
```

