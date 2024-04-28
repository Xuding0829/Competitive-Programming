### A. Matching

题意;

给你一个字符串，问你用数字代替？， 这个字符串会有多少种可能，注意代替后的数字不你能含有前导零

思路

判断第一位 若为 0 直接break  若不为零， 由于数字不含前导零故第一位有9种选法对应 123456789， 对于后面的？有10种选法

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int res = 1;
    bool flag = false;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == '?' && !i)
            res *= 9, flag = true;
        else if(s[i] == '?' && i)
            res *= 10, flag = true;
        else if(s[i] > '0' && s[i] <= '9')
            res *= 1, flag = true;
        else if (s[i] == '0' && !i)
            break;
    }
    std::cout << (flag ? res : 0)<< '\n';
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

 ### B. Sort the Subarray

题意：

给你两个数组，对第一个数组的区间（l， r) 进行排序后，变成第二个数组，问你这个最大区间的 l ， r 分别是什么

思路：

先找到不同的位置，即最小的  l  ,  r 再向前 /  向后扩展

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    int l = n, r = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
            l = std::min(l, i), r = std::max(r, i);
    }

    while(true)
    {
        if(b[l - 1] <= b[l])
            l--;
        else
            break;
    }

    while(true)
    {
        if(b[r + 1] >= b[r])
            r++;
        else
            break;
    }
    std::cout << std::max(1, l + 1) << ' ' << std::min(r + 1, n) << '\n';
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

### C. Tear It Apart

题意：

给你一个字符串，每次操作修改不相邻的字母，问你最多操作多少次可以使得字符串只含有一个字母

思路;

对于每个字母，记录其出现在字符串中的位置， 遍历一遍， 对于每个字母， 操作最大次数是该字母分割字符串后字串的最大长度log2上取整

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<int> p[26];
    for (int i = 0; i < n; i++)
        p[s[i] - 'a'].push_back(i);

    int ans = n;
    for (int x = 0; x < 26; x++)
    {
        int t = -1, res = 0;
        p[x].push_back(n);
        for (auto i : p[x])
        {
            int len = i - t - 1;
            t = i;
            if (len)
                res = std::max(res, (int)ceil(log2(len + 1)));
        }
        ans = std::min(ans, res);
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

### D.[Black Cells](https://codeforces.com/contest/1821/problem/D)

题意;

给你n， k；n 代表能涂色的区间数量， k 代表最少黑色块数目；问你最少操作多少次，可以使得黑色数量大于等于k

思路：

如果能区间全部涂成黑色的数量小于k， 输出-1；

对于长度为1的区间，涂成黑色有3步操作，要使得操作数量尽可能地少，我们一定要少用区间长的是1的区间

用优先队列记录下区间长度，用sum记录全部走完当前和之前区间的总长度，如果sum > k，为保证数量小， 我们肯定得在下一个区间之前把白色块染成黑色（走的长度也会导致操作数增加) 

用rest记录sum 超过 k 的部分， 此时假设这些区间都选择染色，当前区间就应该只染色到

l[ i ] + len - rest - 1这个位置，  此时操作数res = q.size() * 2 + l[ i ] + len - rest - 1

// q.size() * 2  ： 每个区间都染成黑色需要2次操作  

// 走到当前位置也需要一次操作

上面说到，要操作尽可能的少， 应该少用数量为一的，优先队列的队首元素一定是最小的，我们把这个部分减去（相当于当前区间多走这几步），重复上面操作，计算当前的res值与之前的res的最小值，最后输出即可

```c++
#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; i++)
        std::cin >> l[i];
    for (int i = 0; i < n; i++)
        std::cin >> r[i];

    int ans = 0x3f3f3f3f, cnt = 0, sum = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> q;
    for (int i = 0; i < n; i++)
    {
        int len = r[i] - l[i] + 1;
        sum += len;
        q.push(len);
        while(sum >= k)
        {
            int rest = sum - k;
            int res = q.size() * 2 + l[i] + len - rest - 1;
            ans = std::min(res, ans);
            sum -= q.top();
            q.pop();
        }
    }
    std::cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';
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

