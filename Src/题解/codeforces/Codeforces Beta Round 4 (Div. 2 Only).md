#! https://zhuanlan.zhihu.com/p/654665718
## [Codeforces Beta Round 4 (Div. 2 Only) ](https://codeforces.com/contest/4)

### [A. Watermelon](https://www.luogu.com.cn/problem/CF4A)

题意:

判断一个数是不是大于等于$4$的偶数

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    if (n % 2 == 0 && n >= 4)
        std::cout << "YES\n";
    else
        std::cout << "NO\n";

    return 0;
}
```



### [B. Before an Exam](https://www.luogu.com.cn/problem/CF4B)

题意:

一个人$d$天进行考前复习,每天学习时间在区间$[mintime,maxtime]$内,且总和等于$sumtime$,问如何分配每天时间

思路:

如果每天学$max$都不够总时间或者每天学$min$都超过,就不行

下面就是模拟了,首先,保证每天学习的最少时间,剩下该学习的时间为`sumtime -= suml` .

如果这天还能多学`r-l`,`sum-=r-l`,当天学习时间`l+=r-l`;如果不能多学了,`l+=sum`



```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int d, sumtime;
    std::cin >> d >> sumtime;

    int suml = 0, sumr = 0;
    std::vector<int> l(d), r(d);
    for (int i = 0; i < d; i++)
        std::cin >> l[i] >> r[i], suml += l[i], sumr += r[i];

    if (suml > sumtime || sumr < sumtime)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        if (sumr == sumtime)
        {
            for (int i = 0; i < d; i++)
                std::cout << r[i] << ' ';
        }
        else
        {
            sumtime -= suml;
            for (int i = 0; i < d; i++)
            {
                if (sumtime >= r[i] - l[i])
                {
                    sumtime -= r[i] - l[i];
                    l[i] += r[i] - l[i];
                }
                else
                    l[i] += sumtime, sumtime -= sumtime;
            }

            for (int i = 0; i < d; i++)
                std::cout << l[i] << ' ';
        }
    }

    return 0;
}
```



### [C. Registration System](https://codeforces.com/contest/4/problem/C)

题意:

重命名,如果字符串已经出现了,后面跟一个数字

`map`记录出现次数即可

```c++
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::map<std::string, int> mp;
    while (n--)
    {
        std::string s;
        std::cin >> s;

        if (!mp[s])
        {
            std::cout << "OK\n";
            mp[s] = 1;
        }
        else
        {
            mp[s]++;
            std::cout << s << mp[s] - 1 << '\n';
        }
    }

    return 0;
}
```



### [D. Mysterious Present](https://codeforces.com/contest/4/problem/D)

题意:

给你$n$个信封,要求嵌套起来最后的数量最多

思路:

第一眼看上去是最长上升子序列的模板题

定义数组$f[i]$表示,以$i$结尾的最长链,$pre[i]$记录$i$的前驱位置

排序后,直接转移即可

```c++
#include <bits/stdc++.h>

using i64 = long long;
struct node
{
    int w, h, id;
    bool operator<(const node &t)
    {
        if (w != t.w)
            return w < t.w;
        else
            return h < t.h;
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, W, H;
    std::cin >> n >> W >> H;

    std::vector<node> letter;
    for (int i = 0; i < n; i++)
    {
        int w, h;
        std::cin >> w >> h;
        if (w <= W || h <= H)
            continue;
        letter.push_back({w, h, i});
    }

    std::sort(letter.begin(), letter.end());
    // for (auto [u, v, w] : letter)
    //     std::cout << u << ' ' << v << ' ' << w << '\n';
    n = letter.size();

    if (!n)
    {
        std::cout << "0\n";
        return 0;
    }

    int res = 0, pos;
    std::vector<int> f(n), pre(n, -1);
    for (int i = 0; i < n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (letter[j].w < letter[i].w && letter[j].h < letter[i].h && f[j] + 1 > f[i])
            {
                f[i] = f[j] + 1;
                pre[i] = j;
            }
        }
        if (f[i] > res)
            res = f[i], pos = i;
    }

    std::cout << res << '\n';
    std::vector<int> ans;
    while (pos != -1)
    {
        ans.push_back(letter[pos].id);
        pos = pre[pos];
    }
    std::reverse(ans.begin(), ans.end());
    for (auto x : ans)
        std::cout << x + 1 << ' ';
    return 0;
}
```

