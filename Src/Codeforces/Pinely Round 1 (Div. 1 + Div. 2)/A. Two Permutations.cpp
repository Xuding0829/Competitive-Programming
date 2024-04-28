#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cout << (a + b <= n - 2 || n == a && n == b ? "Yes\n" : "No\n");
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