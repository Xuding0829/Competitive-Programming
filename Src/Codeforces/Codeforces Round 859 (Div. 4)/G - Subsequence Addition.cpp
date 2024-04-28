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

    i64 s = 0;
    for (int i = 0; i < n; i++)
    {
        if (s + (i == 0) < a[i])
        {
            std::cout << "NO\n";
            return;
        }
        s += a[i];
    }
    std::cout << "YES\n";
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