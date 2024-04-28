#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    bool flag = false;
    i64 sum = 0, res = 0, ans = 1LL << 60;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (!flag)
        {
            if (sum <= 0)
                res += 1 - sum, sum = 1;
        }
        else
        {
            if (sum >= 0)
                res += sum + 1, sum = -1;
        }
        flag ^= 1;
    }
    ans = std::min(res, ans);

    res = sum = 0, flag = false;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (!flag) // target -
        {
            if (sum >= 0)
                res += sum + 1, sum = -1;
        }
        else // target +
        {
            if (sum <= 0)
                res += 1 - sum, sum = 1;
        }
        flag ^= 1;
    }
    ans = std::min(ans, res);
    std::cout << ans << '\n';
    return 0;
}