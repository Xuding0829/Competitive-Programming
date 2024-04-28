#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    std::sort(a.begin() + 1, a.end());

    auto check = [&](int mid)
    {
        if (a[mid] >= k)
            return 1;

        std::bitset<10010> sum;
        sum[0] = 1;
        for (int i = 1; i <= n; i++)
            if (i != mid)
                sum |= (sum << a[i]); // 求a[i]的前缀和sum1，即把sum的前sum1位均赋值1

        for (int i = k - a[mid]; i <= k - 1; i++)
            if (sum[i])
                return 1;
        return 0;
    };

    int l = 1, r = n + 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) // 判断是不是必须的数
            r = mid;
        else
            l = mid + 1;
    }

    std::cout << l - 1 << '\n';
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}