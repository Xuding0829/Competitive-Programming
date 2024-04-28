#include <bits/stdc++.h>

using i64 = long long;

const i64 mod = 1e9 + 7;

i64 power(i64 a, i64 b, i64 p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::cout << power(2, n, mod) << '\n';

    return 0;
}