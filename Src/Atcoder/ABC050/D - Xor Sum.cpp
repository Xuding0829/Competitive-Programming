#include <bits/stdc++.h>

using i64 = long long;
const int mod = 1e9 + 7;

// a ^ b = u;
// a + b = v;

// 必要性 ： u <= v <= N
// a b都为 奇数时
// (2a1 + 1) + (2b1 + 1) = v
// (2a1 + 1) ^ (2b1 + 1) = u
// (2a1 + 1) + (b1 + 1) <= n;
// a1 + b1 <= (n - 2) / 2;

// a b都为偶数时
// (2a1) + (2a2) = v;
// 2a1 ^ 2b1 = u;
// 2a1 + 2b1 <= n;
// a1 + b1 <= n / 2;

// a b 一奇一偶
//(2a + 1) + 2b = v;
//(2a + 1) ^ 2b = u;
// 2a + 1 + 2b <= n;
// a + b <= (n - 1) / 2

std::map<i64, i64> dp;


i64 f(i64 u)
{
    dp[0] = 1, dp[1] = 2;
    if(dp[u])
        return dp[u];
    else
        return dp[u] = (f(u / 2) + f((u - 1) / 2) + f((u - 2) / 2)) % mod;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 n;
    std::cin >> n;

    std::cout << f(n) << '\n';

    return 0;
}