### A. Blackboard List

注意，每次放入的值是绝对值，那么这个值一定$>=$0

如果有负数，那么这个数就一定是最初的数；

如果无负数，那么答案应该是最大值（插入的是差的绝对值，那么这个插入值一定是一个较小数）。

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

    int res1 = 0, res2 = 0x3f3f3f3f;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if(a[i] < 0)
            flag = true, res2 = std::min(res2, a[i]);
        else
            res1 = std::max(res1, a[i]);
    }
    std::cout << (flag ? res2 : res1) << '\n';
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

### B. Minimize Permutation Subarrays

```
```

### C. No Prime Differences

```
```



