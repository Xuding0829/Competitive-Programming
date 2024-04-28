#include <bits/stdc++.h>

using i64 = long long;

int qmi(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
};

void solve()
{
    i64 n;
    std::cin >> n;

    i64 sum = (1 + n) * n / 2;
    i64 sum2 = 2 * qmi(2, (int)log2(n)) - 1;
    sum -= 2 * sum2;
    std::cout << sum << '\n';
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