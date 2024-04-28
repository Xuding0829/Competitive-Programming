#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    int res = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    if (a[n - 1] == a[0])
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";

        std::reverse(a.begin() + 1, a.end());

        for (int i = 0; i < n; i++)
            std::cout << a[i] << ' ';
        std::cout << '\n';
    }
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