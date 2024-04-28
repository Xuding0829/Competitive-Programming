#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(a.begin(), a.end());
    std::vector<int> b(n, a[n - 1]);
    if (b == a)
        std::cout << -1 << '\n';
    else
    {
        std::vector<int> b;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != a[n - 1])
                b.push_back(a[i]);
        }
        std::vector<int> c(n - b.size(), a[n - 1]);
        std::cout << b.size() << ' ' << c.size() << '\n';
        for (auto x : b)
            std::cout << x << ' ';
        std::cout << '\n';
        for (auto x : c)
            std::cout << x << ' ';
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