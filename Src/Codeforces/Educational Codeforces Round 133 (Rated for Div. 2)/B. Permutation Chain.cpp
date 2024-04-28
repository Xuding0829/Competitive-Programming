#include <bits/stdc++.h>

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    std::cout << n << '\n';

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1, std::cout << a[i] << " \n"[i == n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        std::swap(a[i], a[i + 1]);
        for (int j = 0; j < n; j++)
            std::cout << a[j] << " \n"[j == n - 1];
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