#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int even = 0, odd = 0;
    for (int i = 0, x; i < n; i++)
    {
        std::cin >> x;
        if (x & 1)
            odd += x;
        else
            even += x;
    }
    std::cout << (even > odd ? "YES\n" : "NO\n");
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