#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];

    i64 res = 0;
    std::vector<int> num;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < i)
        {
            auto t = std::lower_bound(num.begin(), num.end(), a[i]) - num.begin();
            res += t;
            num.push_back(i);
        }
    }
    std::cout << res << '\n';
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