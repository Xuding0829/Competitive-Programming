#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    i64 res = 1;
    for (int i = 1; i <= n; i++)
        res = res * i % mod;
    std::cout << res << '\n';

    return 0;
}