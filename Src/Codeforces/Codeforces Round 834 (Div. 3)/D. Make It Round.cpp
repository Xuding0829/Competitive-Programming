#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    int cnt0 = 0, cnt2 = 0, cnt5 = 0;

    // 预处理n
    int tmp = n;
    while (tmp % 10 == 0)
        cnt0++, tmp /= 10;
    while (tmp % 2 == 0)
        cnt2++, tmp /= 2;
    while (tmp % 5 == 0)
        cnt5++, tmp /= 5;

    // 寻找k
    i64 k = 1, del = std::abs(cnt2 - cnt5);
    if (cnt2 > cnt5)
    {
        while (k * 5 <= m && del)
            k *= 5, cnt5++, del--;

        while (k * 10 <= m)
            k *= 10, cnt0++;
        k = m / k * k;
    }
    else
    {
        while (k * 2 <= m && del)
            k *= 2, cnt2++, del--;

        while (k * 10 <= m)
            k *= 10, cnt0++;
        k = m / k * k;
    }

    i64 maxn = (i64)n * k;
    std::cout << maxn << '\n';
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