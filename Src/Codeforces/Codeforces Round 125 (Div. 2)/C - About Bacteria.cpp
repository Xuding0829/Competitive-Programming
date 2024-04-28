#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k, b, n, t;
    std::cin >> k >> b >> n >> t;

    i64 ans = 1, time = 0;
    while (time <= n && ans <= t)
    {
        ans = ans * k + b;
        time++;
    }
    std::cout << n - time + 1 << '\n';
    return 0;
}