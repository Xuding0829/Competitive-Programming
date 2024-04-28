#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int k = 0, m = n;

    while (m)
        m /= 10, k++;

    m = n;
    for (int i = 1; i < k; i++)
        m /= 10;

    std::cout << (k - 1) * 9 + m << '\n';
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