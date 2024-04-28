#include <bits/stdc++.h>

using i64 = long long;

const int N = 1010;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n + 1), f(N);
    // f存储a[i]出现在最大下标
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], f[a[i]] = i;

    int res = -1;
    for (int i = 1; i < N; i++)
        if (f[i])
            for (int j = i; j < N; j++)
                if (f[j] && std::__gcd(i, j) == 1)
                    res = std::max(res, f[i] + f[j]);

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